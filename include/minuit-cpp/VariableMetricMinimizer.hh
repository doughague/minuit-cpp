// @(#)root/minuit2:$Id: VariableMetricMinimizer.h 21530 2007-12-20 11:14:35Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_VariableMetricMinimizer
#define MINUITCPP_VariableMetricMinimizer

#include "minuit-cpp/MnConfig.hh"
#include "minuit-cpp/ModularFunctionMinimizer.hh"
#include "minuit-cpp/MnSeedGenerator.hh"
#include "minuit-cpp/VariableMetricBuilder.hh"

 

   namespace MinuitCpp {

//______________________________________________________________________________
/** 
    Instantiates the SeedGenerator and MinimumBuilder for
    Variable Metric Minimization method.
    API is provided in the upper MinuitCpp::ModularFunctionMinimizer class
 
 */

class VariableMetricMinimizer : public ModularFunctionMinimizer {

public:

   VariableMetricMinimizer() : fMinSeedGen(MnSeedGenerator()),
                               fMinBuilder(VariableMetricBuilder()) {}
  
   ~VariableMetricMinimizer() {}

   const MinimumSeedGenerator& SeedGenerator() const {return fMinSeedGen;}
   const MinimumBuilder& Builder() const {return fMinBuilder;}

private:

   MnSeedGenerator fMinSeedGen;
   VariableMetricBuilder fMinBuilder;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_VariableMetricMinimizer
