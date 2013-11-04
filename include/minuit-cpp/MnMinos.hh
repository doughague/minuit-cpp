// @(#)root/minuit2:$Id: MnMinos.h 23654 2008-05-06 07:30:34Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnMinos
#define MINUITCPP_MnMinos

#include "minuit-cpp/MnStrategy.hh"

#include <utility>

 

   namespace MinuitCpp {


class FCNBase;
class FunctionMinimum;
class MinosError;
class MnCross;

//__________________________________________________________________
/** 
    API class for Minos Error analysis (asymmetric errors);
    minimization has to be done before and Minimum must be valid;
    possibility to ask only for one side of the Minos Error;
 */

class MnMinos {

public:


   /// construct from FCN + Minimum + strategy
   MnMinos(const FCNBase& fcn, const FunctionMinimum& min, unsigned int stra = 1);  

   /// construct from FCN + Minimum + strategy
   MnMinos(const FCNBase& fcn, const FunctionMinimum& min, const MnStrategy& stra); 

   ~MnMinos() {}
  
   /// returns the negative (pair.first) and the positive (pair.second) 
   /// Minos Error of the Parameter
   std::pair<double,double> operator()(unsigned int, unsigned int maxcalls = 0) const;

   /// calculate one side (negative or positive Error) of the Parameter
   double Lower(unsigned int, unsigned int maxcalls = 0) const;
   double Upper(unsigned int, unsigned int maxcalls = 0) const;

   MnCross Loval(unsigned int, unsigned int maxcalls = 0) const;
   MnCross Upval(unsigned int, unsigned int maxcalls = 0) const;

   /// ask for MinosError (Lower + Upper)
   /// can be printed via std::cout  
   MinosError Minos(unsigned int, unsigned int maxcalls = 0) const;

protected: 
   
   /// internal method to get crossing value via MnFunctionCross
   MnCross FindCrossValue(int dir , unsigned int, unsigned int maxcalls = 0) const;
  
private:
  
   const FCNBase& fFCN;
   const FunctionMinimum& fMinimum;
   MnStrategy fStrategy;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnMinos
