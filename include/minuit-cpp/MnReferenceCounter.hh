// @(#)root/minuit2:$Id: MnReferenceCounter.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnReferenceCounter
#define MINUITCPP_MnReferenceCounter

#include <cassert>

#include "StackAllocator.hh"

 

   namespace MinuitCpp {


//extern StackAllocator gStackAllocator;

class MnReferenceCounter {

public:

  MnReferenceCounter() : fReferences(0) {}

  MnReferenceCounter(const MnReferenceCounter& other) : 
    fReferences(other.fReferences) {}

  MnReferenceCounter& operator=(const MnReferenceCounter& other) {
    fReferences = other.fReferences;
    return *this;
  }
  
  ~MnReferenceCounter() {assert(fReferences == 0);}
  
  void* operator new(size_t nbytes) {
    return StackAllocatorHolder::Get().Allocate(nbytes);
  }
  
  void operator delete(void* p, size_t /*nbytes */) {
    StackAllocatorHolder::Get().Deallocate(p);
  }

  unsigned int References() const {return fReferences;}

  void AddReference() const {fReferences++;}

  void RemoveReference() const {fReferences--;}
  
private:
  
  mutable unsigned int fReferences;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnReferenceCounter
