// @(#)root/minuit2:$Id: BasicMinimumParameters.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_BasicMinimumParameters
#define MINUITCPP_BasicMinimumParameters

#include "minuit-cpp/MnMatrix.hh"

#include "minuit-cpp/StackAllocator.hh"

 

   namespace MinuitCpp {


//extern StackAllocator gStackAllocator;

class BasicMinimumParameters {

public:

  BasicMinimumParameters(unsigned int n) : fParameters(MnAlgebraicVector(n)), fStepSize(MnAlgebraicVector(n)), fFVal(0.), fValid(false), fHasStep(false) {}
  
  BasicMinimumParameters(const MnAlgebraicVector& avec, double fval) : 
    fParameters(avec), fStepSize(avec.size()), fFVal(fval), fValid(true), fHasStep(false) {}
  
  BasicMinimumParameters(const MnAlgebraicVector& avec, const MnAlgebraicVector& dirin, double fval) : fParameters(avec), fStepSize(dirin), fFVal(fval), fValid(true), fHasStep(true) {}
  
  ~BasicMinimumParameters() {}

  BasicMinimumParameters(const BasicMinimumParameters& par) : fParameters(par.fParameters), fStepSize(par.fStepSize), fFVal(par.fFVal), fValid(par.fValid), fHasStep(par.fHasStep) {}

  BasicMinimumParameters& operator=(const BasicMinimumParameters& par) {
    fParameters = par.fParameters;
    fStepSize = par.fStepSize;
    fFVal = par.fFVal;
    fValid = par.fValid; 
    fHasStep = par.fHasStep;
    return *this;
  }

  void* operator new(size_t nbytes) {
    return StackAllocatorHolder::Get().Allocate(nbytes);
  }
  
  void operator delete(void* p, size_t /*nbytes*/) {
    StackAllocatorHolder::Get().Deallocate(p);
  }

  const MnAlgebraicVector& Vec() const {return fParameters;}
  const MnAlgebraicVector& Dirin() const {return fStepSize;}
  double Fval() const {return fFVal;}
  bool IsValid() const {return fValid;}
  bool HasStepSize() const {return fHasStep;}

private:

  MnAlgebraicVector fParameters;
  MnAlgebraicVector fStepSize;
  double fFVal;
  bool fValid;
  bool fHasStep;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_BasicMinimumParameters
