// @(#)root/minuit2:$Id: AnalyticalGradientCalculator.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_AnalyticalGradientCalculator
#define MINUITCPP_AnalyticalGradientCalculator

#include "minuit-cpp/GradientCalculator.hh"

 

   namespace MinuitCpp {


class FCNGradientBase;
class MnUserTransformation;

class AnalyticalGradientCalculator : public GradientCalculator {

public:

  AnalyticalGradientCalculator(const FCNGradientBase& fcn, const MnUserTransformation& state) : fGradCalc(fcn), fTransformation(state) {}

  ~AnalyticalGradientCalculator() {}

 
  virtual FunctionGradient operator()(const MinimumParameters&) const;

  virtual FunctionGradient operator()(const MinimumParameters&,
				      const FunctionGradient&) const;

  virtual bool CheckGradient() const;

private:

  const FCNGradientBase& fGradCalc;
  const MnUserTransformation& fTransformation;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_AnalyticalGradientCalculator
