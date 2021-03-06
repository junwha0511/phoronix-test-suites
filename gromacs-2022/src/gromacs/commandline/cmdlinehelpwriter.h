/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright 2010- The GROMACS Authors
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
/*! \file
 * \brief
 * Declares gmx::CommandLineHelpWriter.
 *
 * \author Teemu Murtola <teemu.murtola@gmail.com>
 * \inpublicapi
 * \ingroup module_commandline
 */
#ifndef GMX_COMMANDLINE_CMDLINEHELPWRITER_H
#define GMX_COMMANDLINE_CMDLINEHELPWRITER_H

#include <memory>
#include <string>

namespace gmx
{

class CommandLineHelpContext;
class Options;

template<typename T>
class ArrayRef;

/*! \brief
 * Writes help information for Options.
 *
 * \inpublicapi
 * \ingroup module_commandline
 */
class CommandLineHelpWriter
{
public:
    /*! \brief
     * Creates an object that writer ascii-formatted help for Options.
     *
     * \param[in] options  Options for which help should be printed.
     */
    explicit CommandLineHelpWriter(const Options& options);
    ~CommandLineHelpWriter();

    /*! \brief
     * Sets the help text to print as description.
     *
     * \param[in] help  Help text to show.
     * \throws    std::bad_alloc if out of memory.
     *
     * If `help` is empty, or this method is not called, only a list of
     * options is printed.
     * Formatting for the help text is described on \ref page_onlinehelp.
     */
    CommandLineHelpWriter& setHelpText(const std::string& help);
    //! \copydoc setHelpText(const std::string &)
    CommandLineHelpWriter& setHelpText(const ArrayRef<const char* const>& help);
    /*! \brief
     * Sets the list of known bugs/limitations.
     *
     * \param[in] bugs  Array of bugs/limitations.
     *
     * Each entry in the input array identifies a separate issue.
     * The array passed should remain valid for the lifetime of the writer
     * object.
     */
    CommandLineHelpWriter& setKnownIssues(const ArrayRef<const char* const>& bugs);

    /*! \brief
     * Sets text for known bugs.
     *
     * \param[in] bug  Text for bugs to show.
     * \throws    std::bad_alloc if out of memory.
     *
     * Formatting for the text is described on \ref page_onlinehelp.
     */
    CommandLineHelpWriter& setKnownIssues(ArrayRef<const std::string> bug);

    /*! \brief
     * Writes the help.
     *
     * \param[in] context  Context object for writing the help.
     * \throws    std::bad_alloc if out of memory.
     * \throws    FileIOError on any I/O error.
     */
    void writeHelp(const CommandLineHelpContext& context);

private:
    class Impl;

    std::unique_ptr<Impl> impl_;
};

} // namespace gmx

#endif
