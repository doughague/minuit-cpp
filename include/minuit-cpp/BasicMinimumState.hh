// @(#)root/minuit2:$Id: BasicMinimumState.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_BasicMinimumState
#define MINUITCPP_BasicMinimumState

#include "minuit-cpp/MinimumParameters.hh"
#include "minuit-cpp/MinimumError.hh"
#include "minuit-cpp/FunctionGradient.hh"

#include "minuit-cpp/StackAllocator.hh"

 

   namespace MinuitCpp {


//extern StackAllocator gStackAllocator;

class BasicMinimumState {

public:

  BasicMinimumState(unsigned int n) : 
    fParameters(MinimumParameters(n)), fError(MinimumError(n)), 
    fGradient(FunctionGradient(n)), fEDM(0.), fNFcn(0) {}
  BasicMinimumState(const MinimumParameters& states, const MinimumError& err, 
	       const FunctionGradient& grad, double edm, int nfcn) : 
    fParameters(states), fError(err), fGradient(grad), fEDM(edm), fNFcn(nfcn) {}
  
  BasicMinimumState(const MinimumParameters& states, double edm, int nfcn) : fParameters(states), fError(MinimumError(states.Vec().size())), fGradient(FunctionGradient(states.Vec().size())), fEDM(edm), fNFcn(nfcn) {}
  
  ~BasicMinimumState() {}

  BasicMinimumState(const BasicMinimumState& state) : 
    fParameters(state.fParameters), fError(state.fError), fGradient(state.fGradient), fEDM(state.fEDM), fNFcn(state.fNFcn) {}
  
  BasicMinimumState& operator=(const BasicMinimumState& state) {
    fParameters = state.fParameters; 
    fError = state.fError;
    fGradient = state.fGradient;
    fEDM = state.fEDM;
    fNFcn = state.fNFcn;
    return *this;
  }

  void* operator new(size_t nbytes) {
    return StackAllocatorHolder::Get().Allocate(nbytes);
  }
  
  void operator delete(void* p, size_t /*nbytes */) {
    StackAllocatorHolder::Get().Deallocate(p);
  }

  const MinimumParameters& Parameters() const {return fParameters;}
  const MnAlgebraicVector& Vec() const {return fParameters.Vec();}
  int size() const {return fParameters.Vec().size();}

  const MinimumError& Error() const {return fError;}
  const FunctionGradient& Gradient() const {return fGradient;}
  double Fval() const {return fParameters.Fval();}
  double Edm() const {return fEDM;}
  int NFcn() const {return fNFcn;}

  bool IsValid() const {    
    if(HasParameters() && HasCovariance()) 
      return Parameters().IsValid() && Error().IsValid();
    else if(HasParameters()) return Parameters().IsValid();
    else return false;
  }  
  bool HasParameters() const {return fParameters.IsValid();}
  bool HasCovariance() const {return fError.IsAvailable();}
  
private:
  
  MinimumParameters fParameters;
  MinimumError fError;
  FunctionGradient fGradient;
  double fEDM;
  int fNFcn;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_BasicMinimumState
