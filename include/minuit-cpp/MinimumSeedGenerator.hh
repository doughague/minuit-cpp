// @(#)root/minuit2:$Id: MinimumSeedGenerator.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MinimumSeedGenerator
#define MINUITCPP_MinimumSeedGenerator

 

   namespace MinuitCpp {


class MinimumSeed;
class MnFcn;
class GradientCalculator;
class MnUserParameterState;
class MnStrategy;
class AnalyticalGradientCalculator;

/** base class for seed generators (starting values); the seed generator 
    prepares initial starting values from the input (MnUserParameterState)
    for the minimization;
 */

class MinimumSeedGenerator {

public:

  virtual ~MinimumSeedGenerator() {}

  virtual MinimumSeed operator()(const MnFcn&, const GradientCalculator&, const MnUserParameterState&, const MnStrategy&) const = 0;

  virtual MinimumSeed operator()(const MnFcn&, const AnalyticalGradientCalculator&, const MnUserParameterState&, const MnStrategy&) const = 0;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MinimumSeedGenerator
