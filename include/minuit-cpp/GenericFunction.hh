// @(#)root/minuit2:$Id: GenericFunction.h 21530 2007-12-20 11:14:35Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_GenericFunction
#define MINUITCPP_GenericFunction

#include "minuit-cpp/MnConfig.hh"

#include <vector>

 

   namespace MinuitCpp {


//_____________________________________________________________________
/** 

Class from which all the other classes, representing functions,
inherit. That is why it defines only one method, the operator(),
which allows to call the function.

@author Andras Zsenei and Lorenzo Moneta, Creation date: 23 Sep 2004

@ingroup Minuit

 */

class GenericFunction {

public:

   virtual ~GenericFunction() {}


   /**

      Evaluates the function using the vector containing the input values.

      @param x vector of the coordinates (for example the x coordinate for a 
      one-dimensional Gaussian)

      @return the result of the evaluation of the function.

   */

   virtual double operator()(const std::vector<double>& x) const=0;



};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_GenericFunction
