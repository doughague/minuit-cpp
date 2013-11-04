// @(#)root/minuit2:$Id: SimplexMinimizer.h 21530 2007-12-20 11:14:35Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_SimplexMinimizer
#define MINUITCPP_SimplexMinimizer

#include "minuit-cpp/MnConfig.hh"
#include "minuit-cpp/ModularFunctionMinimizer.hh"
#include "minuit-cpp/SimplexBuilder.hh"
#include "minuit-cpp/SimplexSeedGenerator.hh"

#include <vector>

 

   namespace MinuitCpp {

//_____________________________________________________________
/**
   Class implementing the required methods for a minimization using Simplex.
   API is provided in the upper MinuitCpp::ModularFunctionMinimizer class
 */

class SimplexMinimizer : public ModularFunctionMinimizer {

public:

   SimplexMinimizer() : fSeedGenerator(SimplexSeedGenerator()), 
                        fBuilder(SimplexBuilder()) {}

   ~SimplexMinimizer() {}

   const MinimumSeedGenerator& SeedGenerator() const {return fSeedGenerator;}
   const MinimumBuilder& Builder() const {return fBuilder;}

private:

   SimplexSeedGenerator fSeedGenerator;
   SimplexBuilder fBuilder;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_SimplexMinimizer
