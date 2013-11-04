// @(#)root/minuit2:$Id: LaOuterProduct.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MA_LaOuterProd_H_
#define MA_LaOuterProd_H_

/** LAPACK Algebra
    specialize the Outer_product function for LAVector;
 */

#include "minuit-cpp/VectorOuterProduct.hh"
#include "minuit-cpp/ABSum.hh"
#include "minuit-cpp/LAVector.hh"
#include "minuit-cpp/LASymMatrix.hh"

 

   namespace MinuitCpp {


inline ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, double>, double>, double> Outer_product(const ABObj<vec, LAVector, double>& obj) {
//   std::cout<<"ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, double>, double>, double> Outer_product(const ABObj<vec, LAVector, double>& obj)"<<std::endl;
  return ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, double>, double>, double>(VectorOuterProduct<ABObj<vec, LAVector, double>, double>(obj));
}

// f*outer
template<class T>
inline ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T> operator*(T f, const ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>& obj) {
//   std::cout<<"ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T> operator*(T f, const ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>& obj)"<<std::endl;
  return ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>(obj.Obj(), obj.f()*f);
}

// outer/f
template<class T>
inline ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T> operator/(const ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>& obj, T f) {
//   std::cout<<"ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T> operator/(const ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>& obj, T f)"<<std::endl;
  return ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>(obj.Obj(), obj.f()/f);
}
 
// -outer
template<class T>
inline ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T> operator-(const ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>& obj) {
//   std::cout<<"ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T> operator/(const ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>& obj, T f)"<<std::endl;
  return ABObj<sym, VectorOuterProduct<ABObj<vec, LAVector, T>, T>, T>(obj.Obj(), T(-1.)*obj.f());
}

void Outer_prod(LASymMatrix&, const LAVector&, double f = 1.);

  }  // namespace MinuitCpp

 

#endif //MA_LaOuterProd_H_
