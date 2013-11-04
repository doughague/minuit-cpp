// @(#)root/minuit2:$Id: SqrtUpParameterTransformation.cxx 29068 2009-06-17 16:28:51Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

// Project   : LCG
// Package   : Minuit
// Author    : Lorenzo.MONETA@cern.ch 
// Created by: moneta  at Thu Apr  8 10:26:22 2004


#include "minuit-cpp/SqrtUpParameterTransformation.hh"
#include "minuit-cpp/MnMachinePrecision.hh"

 

   namespace MinuitCpp {



double SqrtUpParameterTransformation::Int2ext(double value, double upper) const {
   // internal to external transformation
   double val = upper + 1. - sqrt( value*value + 1.);
   return val; 
}


double SqrtUpParameterTransformation::Ext2int(double value, double upper, const MnMachinePrecision& ) const {
   // external to internal transformation  
   double yy = upper - value + 1.; 
   double yy2 = yy*yy; 
   if (yy2 < 1.  ) 
      return 0; 
   else 
      return sqrt( yy2 -1); 
}


double SqrtUpParameterTransformation::DInt2Ext(double value, double) const {
   // derivative of internal to external transofrmation :  d (Int2Ext ) / d Int   
   double val = - value/( sqrt( value*value + 1.) );
   return val; 
}

   }  // namespace MinuitCpp

 
