// @(#)root/minuit2:$Id: MnCovarianceSqueeze.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnCovarianceSqueeze
#define MINUITCPP_MnCovarianceSqueeze

#include "minuit-cpp/MnMatrix.hh"

 

   namespace MinuitCpp {


class MnUserCovariance;
class MinimumError;

/**
   class to reduce the covariance matrix when a parameter is fixed by 
   removing the corresponding row and index
 */
class MnCovarianceSqueeze {

public:

  MnCovarianceSqueeze() {}

  ~MnCovarianceSqueeze() {}

  MnUserCovariance operator()(const MnUserCovariance&, unsigned int) const;

  MinimumError operator()(const MinimumError&, unsigned int) const;

  MnAlgebraicSymMatrix operator()(const MnAlgebraicSymMatrix&, unsigned int) const;

private:

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnCovarianceSqueeze
