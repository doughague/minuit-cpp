// @(#)root/minuit2:$Id: MnStrategy.h 21530 2007-12-20 11:14:35Z moneta $
// Authors: M. Winkler, F. James, L. Moneta, A. Zsenei   2003-2005  

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2005 LCG ROOT Math team,  CERN/PH-SFT                *
 *                                                                    *
 **********************************************************************/

#ifndef MINUITCPP_MnStrategy
#define MINUITCPP_MnStrategy

 

   namespace MinuitCpp {

//_________________________________________________________________________
/** 
    API class for defining three levels of strategies: low (0), medium (1), 
    high (>=2);
    acts on: Migrad (behavioural), 
             Minos (lowers strategy by 1 for Minos-own minimization), 
	     Hesse (iterations), 
	     Numerical2PDerivative (iterations)
 */

class MnStrategy {

public:

   //default strategy
   MnStrategy();

   //user defined strategy (0, 1, >=2)
   explicit MnStrategy(unsigned int);

   ~MnStrategy() {}

   unsigned int Strategy() const {return fStrategy;}

   unsigned int GradientNCycles() const {return fGradNCyc;}
   double GradientStepTolerance() const {return fGradTlrStp;}
   double GradientTolerance() const {return fGradTlr;}

   unsigned int HessianNCycles() const {return fHessNCyc;}
   double HessianStepTolerance() const {return fHessTlrStp;}
   double HessianG2Tolerance() const {return fHessTlrG2;}
   unsigned int HessianGradientNCycles() const {return fHessGradNCyc;}
  
   bool IsLow() const {return fStrategy == 0;}
   bool IsMedium() const {return fStrategy == 1;}
   bool IsHigh() const {return fStrategy >= 2;}

   void SetLowStrategy();
   void SetMediumStrategy();
   void SetHighStrategy();
  
   void SetGradientNCycles(unsigned int n) {fGradNCyc = n;}
   void SetGradientStepTolerance(double stp) {fGradTlrStp = stp;}
   void SetGradientTolerance(double toler) {fGradTlr = toler;}

   void SetHessianNCycles(unsigned int n) {fHessNCyc = n;}
   void SetHessianStepTolerance(double stp) {fHessTlrStp = stp;}
   void SetHessianG2Tolerance(double toler) {fHessTlrG2 = toler;}
   void SetHessianGradientNCycles(unsigned int n) {fHessGradNCyc = n;}
  
private:

   unsigned int fStrategy;

   unsigned int fGradNCyc;
   double fGradTlrStp;
   double fGradTlr;
   unsigned int fHessNCyc;
   double fHessTlrStp;
   double fHessTlrG2;
   unsigned int fHessGradNCyc;
};

  }  // namespace MinuitCpp

 

#endif  // MINUITCPP_MnStrategy
