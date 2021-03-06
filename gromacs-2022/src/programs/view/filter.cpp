/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright 1991- The GROMACS Authors
 * and the project initiators Erik Lindahl, Berk Hess and David van der Spoel.
 * Consult the AUTHORS/COPYING files and https://www.gromacs.org for details.
 *
 * GROMACS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * GROMACS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GROMACS; if not, see
 * https://www.gnu.org/licenses, or write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.
 *
 * If you want to redistribute modifications to GROMACS, please
 * consider that scientific software is very special. Version
 * control is crucial - bugs must be traceable. We will be happy to
 * consider code for inclusion in the official distribution, but
 * derived work must not be called official GROMACS. Details are found
 * in the README & COPYING files - if they are missing, get the
 * official version at https://www.gromacs.org.
 *
 * To help us fund GROMACS development, we humbly ask that you cite
 * the research papers on the package. Check out https://www.gromacs.org.
 */
#include "gmxpre.h"

#include <cstdio>
#include <cstring>

#include <algorithm>

#include "gromacs/topology/index.h"
#include "gromacs/utility/cstringutil.h"
#include "gromacs/utility/dir_separator.h"
#include "gromacs/utility/fatalerror.h"
#include "gromacs/utility/futil.h"
#include "gromacs/utility/smalloc.h"

#include "dialogs.h"
#include "xdlghi.h"

t_filter* init_filter(t_atoms* atoms, const char* fn, int natom_trx)
{
    t_filter* f;
    int       g, i;

    snew(f, 1);
    if (fn != nullptr)
    {
        f->grps = init_index(fn, &f->grpnames);
    }
    else
    {
        snew(f->grps, 1);
        snew(f->grps->index, 1);
        analyse(atoms, f->grps, &f->grpnames, false, false);
    }
    snew(f->bDisable, f->grps->nr);
    for (g = 0; g < f->grps->nr; g++)
    {
        for (i = f->grps->index[g]; i < f->grps->index[g + 1] && !f->bDisable[g]; i++)
        {
            f->bDisable[g] = (f->grps->a[i] >= natom_trx);
        }
    }

    snew(f->bShow, f->grps->nr);

    return f;
}

static void FilterCB(t_x11* x11, int dlg_mess, int /*item_id*/, char* set, void* data)
{
    int       nset;
    t_filter* f;
    t_gmx*    gmx;
    t_dlg*    dlg;

    gmx = (t_gmx*)data;
    dlg = gmx->dlgs[edFilter];
    f   = gmx->filter;

#ifdef DEBUG
    std::printf("item_id: %d, set: %s\n", item_id, set);
#endif
    switch (dlg_mess)
    {
        case DLG_SET:
            if (set)
            {
                if (sscanf(set, "%10d", &nset) == 1)
                {
                    f->bShow[nset] = !f->bShow[nset];
                }
            }
            break;
        case DLG_EXIT:
            HideDlg(dlg);
            write_gmx(x11, gmx, IDDOFILTER);
            break;
    }
}

t_dlg* select_filter(t_x11* x11, t_gmx* gmx)
{
    static const char* title = "Group";
    static const char* dummy = "\"FALSE\"";
    static const char* ok    = "\"Ok\"";
    FILE*              tmp;
    t_dlg*             dlg;
    char               tmpfile[STRLEN];
    int                i, j, k, len, tlen, ht, ncol, nrow, x0;

    len = std::strlen(title);
    for (i = 0; (i < (int)gmx->filter->grps->nr); i++)
    {
        len = std::max(len, static_cast<int>(std::strlen(gmx->filter->grpnames[i])));
    }
    len += 2;

    ncol = 1 + (gmx->filter->grps->nr / 15);
    nrow = gmx->filter->grps->nr / ncol;
    if (nrow * ncol < gmx->filter->grps->nr)
    {
        nrow++;
    }
    if (ncol > 1)
    {
        ht = 1 + (nrow + 1) * 2 + 3;
    }
    else
    {
        ht = 1 + (gmx->filter->grps->nr + 1) * 2 + 3;
    }
    std::strcpy(tmpfile, "filterXXXXXX");
    tmp = gmx_fopen_temporary(tmpfile);
#ifdef DEBUG
    std::fprintf(stderr, "file: %s\n", tmpfile);
#endif
    tlen = 1 + ncol * (1 + len);
    std::fprintf(tmp, "grid %d %d {\n\n", tlen, ht);

    for (k = j = 0, x0 = 1; (j < ncol); j++, x0 += len + 1)
    {
        std::fprintf(tmp, "group \"%s-%d\" %d 1 %d %d {\n", title, j + 1, x0, len, ht - 5);
        for (i = 0; (i < nrow) && (k < gmx->filter->grps->nr); i++, k++)
        {
            if (!gmx->filter->bDisable[k])
            {
                std::fprintf(
                        tmp, "checkbox \"%s\" \"%d\" %s %s %s\n", gmx->filter->grpnames[k], k, dummy, dummy, dummy);
            }
            else
            {
                std::fprintf(tmp,
                             "statictext { \"  %s\" } \"%d\" %s %s %s\n",
                             gmx->filter->grpnames[k],
                             k,
                             dummy,
                             dummy,
                             dummy);
            }
        }
        std::fprintf(tmp, "}\n\n");
    }
    std::fprintf(tmp, "simple 1 %d %d 2 {\n", ht - 3, tlen - 2);
    std::fprintf(tmp, "defbutton %s %s %s %s %s\n", ok, ok, dummy, dummy, dummy);
    std::fprintf(tmp, "}\n\n}\n");
    gmx_ffclose(tmp);

    dlg = ReadDlg(x11, gmx->wd->self, title, tmpfile, 0, 0, true, false, FilterCB, gmx);

    std::remove(tmpfile);

    return dlg;
}
