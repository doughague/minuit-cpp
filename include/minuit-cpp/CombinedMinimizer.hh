// @(#)root/minuit2:$Id: CombinedMinimizer.h 21530 2007-12-20 11:14:35Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_CombinedMinimizer
#define MINUITCPP_CombinedMinimizer

#include "minuit-cpp/ModularFunctionMinimizer.hh"
#include "minuit-cpp/MnSeedGenerator.hh"
#include "minuit-cpp/CombinedMinimumBuilder.hh"

 

   namespace MinuitCpp {

//__________________________________________________________________________
/**
   Combined minimizer: combination of Migrad and Simplex. I
   If the Migrad method fails at first attempt, a simplex
   minimization is performed and then migrad is tried again.
  
    
*/

class CombinedMinimizer : public ModularFunctionMinimizer {

public:

   CombinedMinimizer() : fMinSeedGen(MnSeedGenerator()),
                         fMinBuilder(CombinedMinimumBuilder()) {}
  
   ~CombinedMinimizer() {}

   const MinimumSeedGenerator& SeedGenerator() const {return fMinSeedGen;}
   const MinimumBuilder& Builder() const {return fMinBuilder;}

private:

   MnSeedGenerator fMinSeedGen;
   CombinedMinimumBuilder fMinBuilder;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_CombinedMinimizer
