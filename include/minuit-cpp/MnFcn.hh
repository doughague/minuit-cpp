// @(#)root/minuit2:$Id: MnFcn.h 23654 2008-05-06 07:30:34Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnFcn
#define MINUITCPP_MnFcn

#include "minuit-cpp/MnConfig.hh"
#include "minuit-cpp/MnMatrix.hh"

#include <vector>

 

   namespace MinuitCpp {


class FCNBase;
/**
   Wrapper class to FCNBase interface used internally by Minuit.
   Apply conversion from calling the function from a Minuit Vector (MnAlgebraicVector) to a std::vector  for 
   the function coordinates. 
   The class counts also the number of function calls. By default counter strart from zero, but a different value
   might be given if the class is  instantiated later on, for example for a set of different minimizaitons
   Normally the derived class MnUserFCN should be instantiated with performs in addition the transformatiopn 
   internal-> external parameters 
 */
class MnFcn {

public:

   /// constructor of 
   explicit MnFcn(const FCNBase& fcn, int ncall = 0) : fFCN(fcn), fNumCall(ncall) {}

  virtual ~MnFcn();

  virtual double operator()(const MnAlgebraicVector&) const;
  unsigned int NumOfCalls() const {return fNumCall;}

  //
  //forward interface
  //
  double ErrorDef() const;
  double Up() const;

  const FCNBase& Fcn() const {return fFCN;}

private:

  const FCNBase& fFCN;

protected:

  mutable int fNumCall;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnFcn
