// @(#)root/minuit2:$Id: MnVectorTransform.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnVectorTransform
#define MINUITCPP_MnVectorTransform

#include "minuit-cpp/MnMatrix.hh"

 

   namespace MinuitCpp {


class MnVectorTransform {

public:

  MnVectorTransform() {}

  ~MnVectorTransform() {}

  std::vector<double> operator()(const MnAlgebraicVector& avec) const {

    std::vector<double> result; result.reserve(avec.size());

    for(unsigned int i = 0; i < avec.size(); i++) result.push_back(avec(i));
    
    return result;
  }
  
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnVectorTransform
