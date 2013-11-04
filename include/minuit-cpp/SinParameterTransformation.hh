// @(#)root/minuit2:$Id: SinParameterTransformation.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_SinParameterTransformation
#define MINUITCPP_SinParameterTransformation

 

   namespace MinuitCpp {


class MnMachinePrecision;

/**
   class for the transformation for double-limited parameter
   Using a sin function one goes from a double-limited parameter range to 
   an unlimited one 
 */
class SinParameterTransformation {

public:

  SinParameterTransformation() {}

  ~SinParameterTransformation() {}

  double Int2ext(double Value, double Upper, double Lower) const;
  double Ext2int(double Value, double Upper, double Lower, 
		 const MnMachinePrecision&) const;
  double DInt2Ext(double Value, double Upper, double Lower) const;

private:

};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_SinParameterTransformation
