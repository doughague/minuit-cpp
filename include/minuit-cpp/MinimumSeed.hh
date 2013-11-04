// @(#)root/minuit2:$Id: MinimumSeed.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MinimumSeed
#define MINUITCPP_MinimumSeed

#include "minuit-cpp/MnRefCountedPointer.hh"
#include "minuit-cpp/BasicMinimumSeed.hh"

 

   namespace MinuitCpp {


class MinimumState;
class MinimumParameters;
class MinimumError;
class FunctionGradient;
class MnUserTransformation;

/** MinimumSeed contains the starting values for the minimization produced 
    by the SeedGenerator.
 */

class MinimumSeed {

public:
  
  MinimumSeed(const MinimumState& st, const MnUserTransformation& trafo) : fData(MnRefCountedPointer<BasicMinimumSeed>(new BasicMinimumSeed(st, trafo))) {}
  
  ~MinimumSeed() {}

  MinimumSeed(const MinimumSeed& seed) : fData(seed.fData) {}
  
  MinimumSeed& operator=(const MinimumSeed& seed) {
    fData = seed.fData;
    return *this;
  }

  const MinimumState& State() const {return fData->State();}
  const MinimumParameters& Parameters() const {return fData->Parameters();}
  const MinimumError& Error() const {return fData->Error();}
  const FunctionGradient& Gradient() const {return fData->Gradient();}
  const MnUserTransformation& Trafo() const {return fData->Trafo();}
  const MnMachinePrecision& Precision() const {return fData->Precision();}
  double Fval() const {return fData->Fval();}
  double Edm() const {return fData->Edm();}
  unsigned int NFcn() const {return fData->NFcn();}
  bool IsValid() const {return fData->IsValid();}

private:

  MnRefCountedPointer<BasicMinimumSeed> fData;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MinimumSeed
