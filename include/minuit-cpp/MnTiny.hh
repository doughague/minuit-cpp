// @(#)root/minuit2:$Id: MnTiny.h 20880 2007-11-19 11:23:41Z rdm $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnTiny
#define MINUITCPP_MnTiny

 

   namespace MinuitCpp {


class MnTiny {
  
public:
  
  MnTiny() : fOne(1.) {}
  
  ~MnTiny() {}
  
  double One() const;
  
  double operator()(double epsp1) const;
  
private:
  
  double fOne;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnTiny
