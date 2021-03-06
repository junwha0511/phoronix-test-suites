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
#ifndef GMX_FILEIO_OENV_H
#define GMX_FILEIO_OENV_H

#include <string>

#include "gromacs/utility/basedefinitions.h"
#include "gromacs/utility/real.h"

struct gmx_output_env_t;

/* output_env member functions */

/* The output_env structure holds information about program name, cmd
   line, default times, etc. along with verbosity levels for code
   components that use this structure for regulating output.

   There are still legacy functions for the program name, and the command
   line, but the output_env versions are now preferred.*/

namespace gmx
{

/*! \brief
 * Time values for TimeUnitManager and legacy oenv module.
 *
 * \inpublicapi
 */
enum class TimeUnit : int
{
    Femtoseconds,
    Picoseconds,
    Nanoseconds,
    Microseconds,
    Milliseconds,
    Seconds,
    Count,
    Default = Picoseconds
};

} // namespace gmx

//! The xvg output format
enum class XvgFormat : int
{
    // Select,
    Xmgrace,
    Xmgr,
    None,
    Count
};

void output_env_init_default(gmx_output_env_t** oenvp);
/* initialize an output_env structure, with reasonable default settings.
    (the time unit is set to time_ps, which means no conversion).  */

void output_env_done(gmx_output_env_t* oenv);
/* free memory allocated for an output_env structure. */


int output_env_get_verbosity(const gmx_output_env_t* oenv);
/* return the verbosity */

int output_env_get_trajectory_io_verbosity(const gmx_output_env_t* oenv);
/* return the verbosity for trajectory IO handling */

std::string output_env_get_time_unit(const gmx_output_env_t* oenv);
/* return time unit (e.g. ps or ns) */

std::string output_env_get_time_label(const gmx_output_env_t* oenv);
/* return time unit label (e.g. "Time (ps)") */

std::string output_env_get_xvgr_tlabel(const gmx_output_env_t* oenv);
/* return x-axis time label for xmgr */

real output_env_get_time_factor(const gmx_output_env_t* oenv);
/* return time conversion factor from ps (i.e. 1e-3 for ps->ns) */

real output_env_get_time_invfactor(const gmx_output_env_t* oenv);
/* return inverse time conversion factor to ps (i.e. 1e3 for ns->ps) */

real output_env_conv_time(const gmx_output_env_t* oenv, real time);
/* return converted time */

void output_env_conv_times(const gmx_output_env_t* oenv, int n, real* time);
/* convert array of times */

gmx_bool output_env_get_view(const gmx_output_env_t* oenv);
/* Return TRUE when user requested viewing of the file */

XvgFormat output_env_get_xvg_format(const gmx_output_env_t* oenv);
/* Returns enum (see above) for xvg output formatting */

/*! \brief
 * Returns display name for the currently running program.
 */
const char* output_env_get_program_display_name(const gmx_output_env_t* oenv);

namespace gmx
{
class IProgramContext;
} // namespace gmx

void output_env_init(gmx_output_env_t**          oenvp,
                     const gmx::IProgramContext& context,
                     gmx::TimeUnit               tmu,
                     gmx_bool                    view,
                     XvgFormat                   xvgFormat,
                     int                         verbosity);
/* initialize an output_env structure, setting the command line,
   the default time value a gmx_boolean view that is set to TRUE when the
   user requests direct viewing of graphs,
   the graph formatting type, the verbosity, and debug level */

/*! \brief
 * Returns gmx::IProgramContext from an output_env structure.
 */
const gmx::IProgramContext& output_env_get_program_context(const gmx_output_env_t* oenv);

#endif
