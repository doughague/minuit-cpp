// @(#)root/minuit2:$Id: SimplexSeedGenerator.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_SimplexSeedGenerator
#define MINUITCPP_SimplexSeedGenerator

#include "minuit-cpp/MinimumSeedGenerator.hh"

 

   namespace MinuitCpp {


class MinimumSeed;
class MnFcn;
class MnUserParameterState;
class MnStrategy;

/**
   generate Simplex starting point (state)
 */
class SimplexSeedGenerator : public MinimumSeedGenerator {

public:

  SimplexSeedGenerator() {}

  ~SimplexSeedGenerator() {}

  virtual MinimumSeed operator()(const MnFcn&, const GradientCalculator&, const MnUserParameterState&, const MnStrategy&) const;

  virtual MinimumSeed operator()(const MnFcn&, const AnalyticalGradientCalculator&, const MnUserParameterState&, const MnStrategy&) const;

private:

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_SimplexSeedGenerator
