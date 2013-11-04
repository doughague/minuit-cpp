// @(#)root/minuit2:$Id: ABProd.h 23970 2008-05-22 13:37:25Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_ABProd
#define MINUITCPP_ABProd

#include "minuit-cpp/ABObj.hh"

 

   namespace MinuitCpp {


template<class M1, class M2>
class ABProd {

private:

  ABProd() : fA(M1()), fB(M2()) {}

  ABProd& operator=(const ABProd&) {return *this;}

  template<class MI1, class MI2>
  ABProd& operator=(const ABProd<MI1,MI2>&) {return *this;}
  
public:

  ABProd(const M1& a, const M2& b): fA(a), fB(b) {}

  ~ABProd() {}

  ABProd(const ABProd& prod) : fA(prod.fA), fB(prod.fB) {}

  template<class MI1, class MI2>
  ABProd(const ABProd<MI1,MI2>& prod) : fA(M1(prod.A() )), fB(M2(prod.B() )) {}

  const M1& A() const {return fA;}
  const M2& B() const {return fB;}
 
private:

  M1 fA;
  M2 fB;
};

// ABObj * ABObj
template<class atype, class A, class btype, class B, class T>
inline ABObj<typename AlgebraicProdType<atype, btype>::Type, ABProd<ABObj<atype,A,T>, ABObj<btype,B,T> >,T> operator*(const ABObj<atype,A,T>& a, const ABObj<btype,B,T>& b) {

  return ABObj<typename AlgebraicProdType<atype,btype>::Type, ABProd<ABObj<atype,A,T>, ABObj<btype,B,T> >,T>(ABProd<ABObj<atype,A,T>, ABObj<btype,B,T> >(a, b));
}

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_ABProd
