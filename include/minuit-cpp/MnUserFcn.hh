// @(#)root/minuit2:$Id: MnUserFcn.h 23654 2008-05-06 07:30:34Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnUserFcn
#define MINUITCPP_MnUserFcn

#include "minuit-cpp/MnFcn.hh"

 

   namespace MinuitCpp {


class MnUserTransformation;

 /**
    Wrapper used by Minuit of FCN interface 
    containing a reference to the transformation object
  */
class MnUserFcn : public MnFcn {

public:

   MnUserFcn(const FCNBase& fcn, const MnUserTransformation& trafo, int ncall = 0) :
      MnFcn(fcn,ncall), fTransform(trafo) {}

  ~MnUserFcn() {}

  virtual double operator()(const MnAlgebraicVector&) const;

private:

  const MnUserTransformation& fTransform;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnUserFcn
