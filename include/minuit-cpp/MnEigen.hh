// @(#)root/minuit2:$Id: MnEigen.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnEigen
#define MINUITCPP_MnEigen

#include "minuit-cpp/MnConfig.hh"
#include <vector>

 

   namespace MinuitCpp {


class MnUserCovariance;

/**
   API class for calculating the eigenvalues of symmetric matrix
 */

class MnEigen {

public:

  MnEigen() {}

  ~MnEigen() {}

  /// calculate the eigenvalues
  std::vector<double> operator()(const MnUserCovariance&) const;

private:

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnEigen
