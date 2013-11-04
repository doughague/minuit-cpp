// @(#)root/minuit2:$Id: VariableMetricEDMEstimator.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_VariableMetricEDMEstimator
#define MINUITCPP_VariableMetricEDMEstimator

 

   namespace MinuitCpp {


class FunctionGradient;
class MinimumError;

class VariableMetricEDMEstimator {

public:

  VariableMetricEDMEstimator() {}
  
  ~VariableMetricEDMEstimator() {}

  double Estimate(const FunctionGradient&, const MinimumError&) const;

private:

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_VariableMetricEDMEstimator
