// @(#)root/minuit2:$Id: MnLineSearch.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnLineSearch
#define MINUITCPP_MnLineSearch

#include "minuit-cpp/MnMatrix.hh"

 

   namespace MinuitCpp {


class MnFcn;
class MinimumParameters;
class MnMachinePrecision;
class MnParabolaPoint;




/** 

Implements a 1-dimensional minimization along a given direction 
(i.e. quadratic interpolation) It is independent of the algorithm 
that generates the direction vector. It brackets the 1-dimensional 
Minimum and iterates to approach the real Minimum of the n-dimensional
function.


@author Fred James and Matthias Winkler; comments added by Andras Zsenei
and Lorenzo Moneta

@ingroup Minuit

*/




class MnLineSearch  {

public:

  MnLineSearch() {}

  ~MnLineSearch() {}

  MnParabolaPoint operator()(const MnFcn&, const MinimumParameters&, const MnAlgebraicVector&, double, const MnMachinePrecision&, bool debug = false) const;

#ifdef USE_OTHER_LS
  MnParabolaPoint CubicSearch(const MnFcn&, const MinimumParameters&, const MnAlgebraicVector&, double, double, const MnMachinePrecision&, bool debug = false) const;

  MnParabolaPoint BrentSearch(const MnFcn&, const MinimumParameters&, const MnAlgebraicVector&, double, double, const MnMachinePrecision&, bool debug = false) const;
#endif

private:

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnLineSearch
