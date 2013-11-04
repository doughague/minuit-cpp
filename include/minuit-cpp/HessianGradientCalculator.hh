// @(#)root/minuit2:$Id: HessianGradientCalculator.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_HessianGradientCalculator
#define MINUITCPP_HessianGradientCalculator

#include "minuit-cpp/GradientCalculator.hh"
#include "minuit-cpp/MnMatrix.hh"
#include <utility>

 

   namespace MinuitCpp {



class MnFcn;
class MnUserTransformation;
class MnMachinePrecision;
class MnStrategy;

/**
   HessianGradientCalculator: class to calculate Gradient for Hessian
 */

class HessianGradientCalculator : public GradientCalculator {
  
public:
  
  HessianGradientCalculator(const MnFcn& fcn, const MnUserTransformation& par,
			    const MnStrategy& stra) : 
    fFcn(fcn), fTransformation(par), fStrategy(stra) {}
  
  virtual ~HessianGradientCalculator() {}

  virtual FunctionGradient operator()(const MinimumParameters&) const;

  virtual FunctionGradient operator()(const MinimumParameters&,
				      const FunctionGradient&) const;

  std::pair<FunctionGradient, MnAlgebraicVector> DeltaGradient(const MinimumParameters&, const FunctionGradient&) const;

  const MnFcn& Fcn() const {return fFcn;}
  const MnUserTransformation& Trafo() const {return fTransformation;} 
  const MnMachinePrecision& Precision() const;
  const MnStrategy& Strategy() const {return fStrategy;}
 
  unsigned int Ncycle() const;
  double StepTolerance() const;
  double GradTolerance() const;

private:

  const MnFcn& fFcn;
  const MnUserTransformation& fTransformation; 
  const MnStrategy& fStrategy;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_HessianGradientCalculator
