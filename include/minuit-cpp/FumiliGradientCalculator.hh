// @(#)root/minuit2:$Id: FumiliGradientCalculator.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_FumiliGradientCalculator
#define MINUITCPP_FumiliGradientCalculator

#include "minuit-cpp/GradientCalculator.hh"
#include "minuit-cpp/MnMatrix.hh"

 

   namespace MinuitCpp {



class FumiliFCNBase;
class MnUserTransformation;

class FumiliGradientCalculator : public GradientCalculator {

public:

  FumiliGradientCalculator(const FumiliFCNBase& fcn, const MnUserTransformation& state, int n) : 
    fFcn(fcn), 
    fTransformation(state), 
    fHessian(MnAlgebraicSymMatrix(n) ) 
  {}

  ~FumiliGradientCalculator() {}
	       
  FunctionGradient operator()(const MinimumParameters&) const;

  FunctionGradient operator()(const MinimumParameters&,
				      const FunctionGradient&) const;

  const MnUserTransformation& Trafo() const {return fTransformation;} 

  const MnAlgebraicSymMatrix & Hessian() const { return fHessian; }

private:

  const FumiliFCNBase& fFcn;
  const MnUserTransformation& fTransformation;
  mutable MnAlgebraicSymMatrix fHessian;

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_FumiliGradientCalculator
