// @(#)root/minuit2:$Id: MinimumBuilder.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MinimumBuilder
#define MINUITCPP_MinimumBuilder

 

   namespace MinuitCpp {


class FunctionMinimum;
class MnFcn;
class GradientCalculator;
class MinimumSeed;
class MnStrategy;

class MinimumBuilder {

public:
  
  virtual ~MinimumBuilder() {}

  virtual FunctionMinimum Minimum(const MnFcn&, const GradientCalculator&, const MinimumSeed&, const MnStrategy&, unsigned int, double) const = 0;

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MinimumBuilder
