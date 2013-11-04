// @(#)root/minuit2:$Id: MnCross.h 23522 2008-04-24 15:09:19Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnCross
#define MINUITCPP_MnCross

#include "minuit-cpp/MnUserParameterState.hh"

 

   namespace MinuitCpp {


class MnCross {

public:
  
  class CrossParLimit {};
  class CrossFcnLimit {};
  class CrossNewMin {};

public:
  
  MnCross() : fValue(0.), fState(MnUserParameterState()), fNFcn(0), fValid(false), fLimset(false), fMaxFcn(false), fNewMin(false) {} 
  
  MnCross(unsigned int nfcn) : fValue(0.), fState(MnUserParameterState() ), fNFcn(nfcn), fValid(false), fLimset(false), fMaxFcn(false), fNewMin(false) {} 

  MnCross(const  MnUserParameterState& state, unsigned int nfcn) : fValue(0.), fState(state), fNFcn(nfcn), fValid(false), fLimset(false), fMaxFcn(false), fNewMin(false) {} 
  
  MnCross(double value, const MnUserParameterState& state, unsigned int nfcn) : fValue(value), fState(state), fNFcn(nfcn), fValid(true), fLimset(false), fMaxFcn(false), fNewMin(false) {}
  
  MnCross(const MnUserParameterState& state, unsigned int nfcn, CrossParLimit) : fValue(0.), fState(state), fNFcn(nfcn), fValid(true), fLimset(true), fMaxFcn(false), fNewMin(false) {}

  MnCross(const MnUserParameterState& state, unsigned int nfcn, CrossFcnLimit) : fValue(0.), fState(state), fNFcn(nfcn), fValid(false), fLimset(false), fMaxFcn(true), fNewMin(false) {}

  MnCross(const MnUserParameterState& state, unsigned int nfcn, CrossNewMin) : fValue(0.), fState(state), fNFcn(nfcn), fValid(false), fLimset(false), fMaxFcn(false), fNewMin(true) {}

  ~MnCross() {}

  MnCross(const MnCross& cross) : fValue(cross.fValue), fState(cross.fState), fNFcn(cross.fNFcn), fValid(cross.fValid), fLimset(cross.fLimset), fMaxFcn(cross.fMaxFcn), fNewMin(cross.fNewMin) {}

  MnCross& operator()(const MnCross& cross) {
    fValue = cross.fValue;
    fState = cross.fState;
    fNFcn = cross.fNFcn;
    fValid = cross.fValid;
    fLimset = cross.fLimset;
    fMaxFcn = cross.fMaxFcn;
    fNewMin = cross.fNewMin;
    return *this;
  }

  double Value() const {return fValue;}  
  const MnUserParameterState& State() const {return fState;}
  bool IsValid() const {return fValid;}
  bool AtLimit() const {return fLimset;}
  bool AtMaxFcn() const {return fMaxFcn;}
  bool NewMinimum() const {return fNewMin;}
  unsigned int NFcn() const {return fNFcn;}

private:

  double fValue;
  MnUserParameterState fState;
  unsigned int fNFcn;
  bool fValid;
  bool fLimset;
  bool fMaxFcn;
  bool fNewMin;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnCross
