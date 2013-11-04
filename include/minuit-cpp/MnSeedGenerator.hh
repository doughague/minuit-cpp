// @(#)root/minuit2:$Id: MnSeedGenerator.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnSeedGenerator
#define MINUITCPP_MnSeedGenerator

#include "minuit-cpp/MinimumSeedGenerator.hh"

 

   namespace MinuitCpp {


/** concrete implementation of the MinimumSeedGenerator interface; used within
    ModularFunctionMinimizer;
 */

class MnSeedGenerator : public MinimumSeedGenerator {

public:

  MnSeedGenerator() {}

  virtual ~MnSeedGenerator() {}

  virtual MinimumSeed operator()(const MnFcn&, const GradientCalculator&, const MnUserParameterState&, const MnStrategy&) const;

  virtual MinimumSeed operator()(const MnFcn&, const AnalyticalGradientCalculator&, const MnUserParameterState&, const MnStrategy&) const;

private:

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnSeedGenerator
