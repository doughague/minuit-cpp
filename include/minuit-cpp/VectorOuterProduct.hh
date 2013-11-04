// @(#)root/minuit2:$Id: VectorOuterProduct.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_VectorOuterProduct
#define MINUITCPP_VectorOuterProduct

#include "minuit-cpp/ABTypes.hh"
#include "minuit-cpp/ABObj.hh"

 

   namespace MinuitCpp {


template<class M, class T>
class VectorOuterProduct {

public:

  VectorOuterProduct(const M& obj) : fObject(obj) {}

  ~VectorOuterProduct() {}

  typedef sym Type;

  const M& Obj() const {return fObject;}

private:

  M fObject;
};

template<class M, class T>
inline ABObj<sym, VectorOuterProduct<ABObj<vec, M, T>, T>, T> Outer_product(const ABObj<vec, M, T>& obj) {
  return ABObj<sym, VectorOuterProduct<ABObj<vec, M, T>, T>, T>(VectorOuterProduct<ABObj<vec, M, T>, T>(obj));
}

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_VectorOuterProduct
