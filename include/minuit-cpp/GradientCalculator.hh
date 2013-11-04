// @(#)root/minuit2:$Id: GradientCalculator.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_GradientCalculator
#define MINUITCPP_GradientCalculator

 

   namespace MinuitCpp {


class MinimumParameters;
class FunctionGradient;


/**
   interface class for gradient calculators
 */
class GradientCalculator {

public:
  
  virtual ~GradientCalculator() {}

  virtual FunctionGradient operator()(const MinimumParameters&) const = 0;

  virtual FunctionGradient operator()(const MinimumParameters&,
				      const FunctionGradient&) const = 0;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_GradientCalculator
