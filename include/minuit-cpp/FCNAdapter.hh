// @(#)root/minuit2:$Id$
// Author: L. Moneta    10/2006  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2006 ROOT Foundation,  CERN/PH-SFT                   *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_FCNAdapter
#define MINUITCPP_FCNAdapter

#ifndef MINUITCPP_FCNBase
#include "minuit-cpp/FCNBase.hh"
#endif

 

namespace MinuitCpp {

/** 


template wrapped class for adapting to FCNBase signature

@author Lorenzo Moneta

@ingroup Minuit

*/

template< class Function> 
class FCNAdapter : public FCNBase {

public:

   FCNAdapter(const Function & f, double up = 1.) : 
      fFunc(f) , 
      fUp (up)
   {}

   ~FCNAdapter() {}

  
   double operator()(const std::vector<double>& v) const { 
      return fFunc.operator()(&v[0]); 
   }
   double operator()(const double *  v) const { 
      return fFunc.operator()(v); 
   }
   double Up() const {return fUp;}

   void SetErrorDef(double up) { fUp = up; } 
  
   //virtual std::vector<double> Gradient(const std::vector<double>&) const;

   // forward interface
   //virtual double operator()(int npar, double* params,int iflag = 4) const;

private:
   const Function & fFunc; 
   double fUp; 
};

} // end namespace MinuitCpp

#endif //MINUITCPP_FCNAdapter
