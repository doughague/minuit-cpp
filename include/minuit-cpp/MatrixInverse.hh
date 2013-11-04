// @(#)root/minuit2:$Id: MatrixInverse.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MatrixInverse
#define MINUITCPP_MatrixInverse

#include "minuit-cpp/ABTypes.hh"
#include "minuit-cpp/ABObj.hh"

 

   namespace MinuitCpp {


template<class mtype, class M, class T>
class MatrixInverse {

public:

  MatrixInverse(const M& obj) : fObject(obj) {}

  ~MatrixInverse() {}

  typedef mtype Type;

  const M& Obj() const {return fObject;}

private:

  M fObject;
};

template<class M, class T>
class MatrixInverse<vec, M, T> {

private:

  MatrixInverse(const M& obj) : fObject(obj) {}

public:

  ~MatrixInverse() {}

  typedef vec Type;

  const M& Obj() const {return fObject;}

private:

  M fObject;
};

template<class mt, class M, class T>
inline ABObj<mt, MatrixInverse<mt, ABObj<mt, M, T>, T>, T> Inverse(const ABObj<mt, M, T>& obj) {
  return ABObj<mt, MatrixInverse<mt, ABObj<mt, M, T>, T>, T>(MatrixInverse<mt, ABObj<mt, M, T>, T>(obj));
}

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MatrixInverse
