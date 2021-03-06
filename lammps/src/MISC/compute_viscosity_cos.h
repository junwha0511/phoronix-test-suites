/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   https://www.lammps.org/, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------
   Contributing author: Zheng GONG (ENS de Lyon, z.gong@outlook.com)
------------------------------------------------------------------------- */

#ifdef COMPUTE_CLASS
// clang-format off
ComputeStyle(viscosity/cos,ComputeViscosityCos);
// clang-format on
#else

#ifndef LMP_COMPUTE_VISCOSITY_COS_H
#define LMP_COMPUTE_VISCOSITY_COS_H

#include "compute.h"

namespace LAMMPS_NS {

class ComputeViscosityCos : public Compute {
 public:
  ComputeViscosityCos(class LAMMPS *, int, char **);
  ~ComputeViscosityCos() override;
  void init() override {}
  void setup() override;
  double compute_scalar() override;
  void compute_vector() override;

  void remove_bias(int, double *) override;
  void remove_bias_thr(int, double *, double *) override;
  void remove_bias_all() override;
  void restore_bias(int, double *) override;
  void restore_bias_thr(int, double *, double *) override;
  void restore_bias_all() override;

 protected:
  double tfactor;
  double V;

  void dof_compute();
  void calc_V();
};

}    // namespace LAMMPS_NS

#endif
#endif

/* ERROR/WARNING messages:

E: Illegal ... command

Self-explanatory.  Check the input script syntax and compare to the
documentation for the command.  You can use -echo screen as a
command-line option when running LAMMPS to see the offending line.

E: Temperature compute degrees of freedom < 0

This should not happen if you are calculating the temperature
on a valid set of atoms.

*/
