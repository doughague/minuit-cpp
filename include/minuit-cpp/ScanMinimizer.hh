// @(#)root/minuit2:$Id: ScanMinimizer.h 21530 2007-12-20 11:14:35Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_ScanMinimizer
#define MINUITCPP_ScanMinimizer

#include "minuit-cpp/MnConfig.hh"
#include "minuit-cpp/ModularFunctionMinimizer.hh"
#include "minuit-cpp/ScanBuilder.hh"
#include "minuit-cpp/SimplexSeedGenerator.hh"

#include <vector>

 

   namespace MinuitCpp {

//_____________________________________________________________
/**
   Class implementing the required methods for a minimization using SCAN
   API is provided in the upper MinuitCpp::ModularFunctionMinimizer class
 */

class ScanMinimizer : public ModularFunctionMinimizer {

public:

   ScanMinimizer() : fSeedGenerator(SimplexSeedGenerator()), 
                     fBuilder(ScanBuilder()) {}
  
   ~ScanMinimizer() {}
  
   const MinimumSeedGenerator& SeedGenerator() const {return fSeedGenerator;}
   const MinimumBuilder& Builder() const {return fBuilder;}
  
private:
  
   SimplexSeedGenerator fSeedGenerator;
   ScanBuilder fBuilder;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_ScanMinimizer
