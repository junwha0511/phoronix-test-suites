/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright 2009- The GROMACS Authors
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
/*! \internal \file
 * \brief
 * Declares private implementation class for gmx::SelectionCollection.
 *
 * This header also defines ::gmx_ana_selcollection_t, which is used in the old
 * C code for handling selection collections.
 *
 * \author Teemu Murtola <teemu.murtola@gmail.com>
 * \ingroup module_selection
 */
#ifndef GMX_SELECTION_SELECTIONCOLLECTION_IMPL_H
#define GMX_SELECTION_SELECTIONCOLLECTION_IMPL_H

#include <memory>
#include <string>
#include <vector>

#include "gromacs/onlinehelp/ihelptopic.h"
#include "gromacs/selection/indexutil.h"
#include "gromacs/selection/selection.h" // For gmx::SelectionList
#include "gromacs/selection/selectioncollection.h"

#include "poscalc.h"
#include "selelem.h"

struct gmx_mtop_t;
struct gmx_sel_mempool_t;
struct t_pbc;
struct t_trxframe;

namespace gmx
{

//! Smart pointer for managing an internal selection data object.
typedef std::unique_ptr<internal::SelectionData> SelectionDataPointer;
//! Container for storing a list of selections internally.
typedef std::vector<SelectionDataPointer> SelectionDataList;

class SelectionParserSymbolTable;
struct SelectionTopologyProperties;

} // namespace gmx

/*! \internal \brief
 * Information for a collection of selections.
 *
 * \ingroup module_selection
 */
struct gmx_ana_selcollection_t
{
    //! Position calculation collection used for selection position evaluation.
    gmx::PositionCalculationCollection pcc;
    //! Root of the selection element tree.
    gmx::SelectionTreeElementPointer root;
    /*! \brief
     * Array of compiled selections.
     *
     * Has the responsibility of managing the memory for the contained objects,
     * but note that gmx::Selection instances also hold pointers to the
     * objects.
     */
    gmx::SelectionDataList sel;
    /** Number of variables defined. */
    int nvars;
    /** Selection strings for variables. */
    char** varstrs;

    /** Topology for the collection. */
    const gmx_mtop_t* top;
    /** Index group that contains all the atoms. */
    gmx_ana_index_t gall;
    /** Memory pool used for selection evaluation. */
    gmx_sel_mempool_t* mempool;
    //! Parser symbol table.
    // Never releases ownership.
    std::unique_ptr<gmx::SelectionParserSymbolTable> symtab;
    //! Root of help topic tree (NULL is no help yet requested).
    gmx::HelpTopicPointer rootHelp;
};

namespace gmx
{

class ExceptionInitializer;

/*! \internal \brief
 * Private implemention class for SelectionCollection.
 *
 * \ingroup module_selection
 */
class SelectionCollection::Impl
{
public:
    /*! \brief
     * Creates a new selection collection.
     *
     * \throws  std::bad_alloc if out of memory.
     */
    Impl();
    ~Impl();

    /*! \brief
     * Clears the symbol table of the selection collection.
     *
     * Does not throw.
     */
    void clearSymbolTable();
    /*! \brief
     * Replace group references by group contents.
     *
     * \param[in]    root    Root of selection tree to process.
     * \param        errors  Object for reporting any error messages.
     * \throws std::bad_alloc if out of memory.
     *
     * Recursively searches the selection tree for unresolved external
     * references.  If one is found, finds the referenced group in
     * \a grps_ and replaces the reference with a constant element that
     * contains the atoms from the referenced group.  Any failures to
     * resolve references are reported to \p errors.
     */
    void resolveExternalGroups(const gmx::SelectionTreeElementPointer& root, ExceptionInitializer* errors);

    //! Whether forces have been requested for some selection.
    bool areForcesRequested() const;
    /*! \brief
     * Returns topology properties needed for a certain position type.
     */
    static SelectionTopologyProperties requiredTopologyPropertiesForPositionType(const std::string& post,
                                                                                 bool forces);

    //! Describes the available debugging levels
    enum class DebugLevel : int
    {
        //! No debugging
        None,
        //! Print selection trees after parsing and compilation
        Basic,
        //! As PrintCompiled, also print intermediate compilation trees
        Compiled,
        //! As PrintCompiled, also print the tree after evaluation
        Evaluated,
        //! Combine Compiled and Evaluated
        Full,
        //! Ends the enumeration
        Count
    };

    //! Internal data, used for interfacing with old C code.
    gmx_ana_selcollection_t sc_;
    //! Default reference position type for selections.
    std::string rpost_;
    //! Default output position type for selections.
    std::string spost_;
    //! Atoms needed for evaluating the selections.
    gmx_ana_index_t requiredAtoms_;
    //! Debugging level for the collection.
    DebugLevel debugLevel_;
    //! Whether setIndexGroups() has been called.
    bool bExternalGroupsSet_;
    //! External index groups (can be NULL).
    gmx_ana_indexgrps_t* grps_;
};

/*! \internal
 * \brief
 * Implements selection evaluation.
 *
 * This class is used to implement SelectionCollection::evaluate() and
 * SelectionCollection::evaluateFinal().
 *
 * \ingroup module_selection
 */
class SelectionEvaluator
{
public:
    SelectionEvaluator();

    /*! \brief
     * Evaluates selections in a collection.
     */
    void evaluate(SelectionCollection* sc, t_trxframe* fr, t_pbc* pbc);
    /*! \brief
     * Evaluates the final state for dynamic selections.
     */
    void evaluateFinal(SelectionCollection* sc, int nframes);
};

} // namespace gmx

#endif
