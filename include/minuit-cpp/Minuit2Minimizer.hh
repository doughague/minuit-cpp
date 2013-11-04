// @(#)root/minuit2:$Id$
// Author: L. Moneta Wed Oct 18 11:48:00 2006

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2006  LCG ROOT Math Team, CERN/PH-SFT                *
 *                                                                    *
 *                                                                    *
 **********************************************************************/

// Header file for class MinuitCppMinimizer

#ifndef MINUITCPP_MinuitCppMinimizer
#define MINUITCPP_MinuitCppMinimizer

#ifndef ROOT_Math_Minimizer
#include "Math/Minimizer.hh"
#endif

#ifndef MINUITCPP_MnUserParameterState
#include "minuit-cpp/MnUserParameterState.hh"
#endif

#ifndef ROOT_Math_IFunctionfwd
#include "Math/IFunctionfwd.hh"
#endif

#ifndef ROOT_Math_IParamFunctionfwd
#include "Math/IParamFunctionfwd.hh"
#endif





  

namespace MinuitCpp { 

  class ModularFunctionMinimizer; 
  class FCNBase; 
  class FunctionMinimum;

  // enumeration specifying the type of MinuitCpp minimizers
  enum EMinimizerType { 
    kMigrad, 
    kSimplex, 
    kCombined, 
    kScan,
    kFumili
  };

}

namespace MinuitCpp { 

//_____________________________________________________________________________________________________
/** 
   MinuitCppMinimizer class implementing the ROOT::Math::Minimizer interface for 
   MinuitCpp minimization algorithm. 
   In ROOT it can be instantiated using the plug-in manager (plug-in "MinuitCpp")
   Using a string  (used by the plugin manager) or via an enumeration 
   an one can set all the possible minimization algorithms (Migrad, Simplex, Combined, Scan and Fumili).  
*/ 
class MinuitCppMinimizer : public ROOT::Math::Minimizer {

public: 

   /** 
      Default constructor
   */ 
   MinuitCppMinimizer (MinuitCpp::EMinimizerType type = MinuitCpp::kMigrad); 

   /** 
      Constructor with a char (used by PM) 
   */ 
   MinuitCppMinimizer (const char *  type); 

   /** 
      Destructor (no operations)
   */ 
   virtual ~MinuitCppMinimizer (); 

private:
   // usually copying is non trivial, so we make this unaccessible

   /** 
      Copy constructor
   */ 
   MinuitCppMinimizer(const MinuitCppMinimizer &); 

   /** 
      Assignment operator
   */ 
   MinuitCppMinimizer & operator = (const MinuitCppMinimizer & rhs); 

public: 

   // clear resources (parameters) for consecutives minimizations
   virtual void Clear();

   /// set the function to minimize
   virtual void SetFunction(const ROOT::Math::IMultiGenFunction & func); 

   /// set gradient the function to minimize
   virtual void SetFunction(const ROOT::Math::IMultiGradFunction & func); 

   /// set free variable 
   virtual bool SetVariable(unsigned int ivar, const std::string & name, double val, double step); 

   /// set lower limit variable  (override if minimizer supports them )
   virtual bool SetLowerLimitedVariable(unsigned int  ivar , const std::string & name , double val , double step , double lower );
   /// set upper limit variable (override if minimizer supports them )
   virtual bool SetUpperLimitedVariable(unsigned int ivar , const std::string & name , double val , double step , double upper ); 
   /// set upper/lower limited variable (override if minimizer supports them )
   virtual bool SetLimitedVariable(unsigned int ivar , const std::string & name , double val , double step , double /* lower */, double /* upper */); 
   /// set fixed variable (override if minimizer supports them )
   virtual bool SetFixedVariable(unsigned int /* ivar */, const std::string & /* name */, double /* val */);  
   /// set variable
   virtual bool SetVariableValue(unsigned int ivar, double val);
   virtual bool SetVariableValues(const double * val);

   /// get name of variables (override if minimizer support storing of variable names)
   virtual std::string VariableName(unsigned int ivar) const;

   /// get index of variable given a variable given a name
   /// return -1 if variable is not found
   virtual int VariableIndex(const std::string & name) const;

   /** 
       method to perform the minimization. 
       Return false in case the minimization did not converge. In this case a 
       status code different than zero is set 
       (retrieved by the derived method Minimizer::Status() )" 
       
       status = 1    : Covariance was made pos defined
       status = 2    : Hesse is invalid
       status = 3    : Edm is above max 
       status = 4    : Reached call limit
       status = 5    : Any other failure 
   */
   virtual  bool Minimize(); 

   /// return minimum function value
   virtual double MinValue() const { return fState.Fval(); } 

   /// return expected distance reached from the minimum
   virtual double Edm() const { return fState.Edm(); }

   /// return  pointer to X values at the minimum 
   virtual const double *  X() const { 
      fValues = fState.Params(); 
      return (fValues.size() ) ? &fValues.front() : 0; 
   }

   /// return pointer to gradient values at the minimum 
   virtual const double *  MinGradient() const { return 0; } // not available in MinuitCpp 

   /// number of function calls to reach the minimum 
   virtual unsigned int NCalls() const { return fState.NFcn(); } 

   /// this is <= Function().NDim() which is the total 
   /// number of variables (free+ constrained ones) 
   virtual unsigned int NDim() const { return fDim; }   

   /// number of free variables (real dimension of the problem) 
   /// this is <= Function().NDim() which is the total 
   virtual unsigned int NFree() const { return fState.VariableParameters(); }  

   /// minimizer provides error and error matrix
   virtual bool ProvidesError() const { return true; } 

   /// return errors at the minimum 
   virtual const double * Errors() const; 

   /** 
       return covariance matrices elements 
       if the variable is fixed or const the value is zero
       The ordering of the variables is the same as in errors and parameter value. 
       This is different from the direct interface of MinuitCpp or TMinuit where the 
       values were obtained only to variable parameters
   */ 
   virtual double CovMatrix(unsigned int i, unsigned int j) const;  

   /**
      return the status of the covariance matrix 
    */
   virtual int CovMatrixStatus() const;
   /**
      return correlation coefficient between variable i and j.
      If the variable is fixed or const the return value is zero
    */
   virtual double Correlation(unsigned int i, unsigned int j ) const; 

   /**
      get global correlation coefficient for the variable i. This is a number between zero and one which gives 
      the correlation between the i-th variable  and that linear combination of all other variables which 
      is most strongly correlated with i.
      If the variable is fixed or const the return value is zero
    */
   virtual double GlobalCC(unsigned int i) const;

   /**
      get the minos error for parameter i, return false if Minos failed
      A minimizaiton must be performed befre, return false if no minimization has been done
      In case of Minos failed the status error is updated as following 
      status += 10 * minosStatus where the minos status is:
       status = 1    : maximum number of function calls exceeded when running for lower error
       status = 2    : maximum number of function calls exceeded when running for upper error
       status = 3    : new minimum found when running for lower error
       status = 4    : new minimum found when running for upper error
       status = 5    : any other failure 

   */
   virtual bool GetMinosError(unsigned int i, double & errLow, double & errUp, int = 0); 

   /**
      scan a parameter i around the minimum. A minimization must have been done before, 
      return false if it is not the case
    */
   virtual bool Scan(unsigned int i, unsigned int & nstep, double * x, double * y, double xmin = 0, double xmax = 0); 

   /**
      find the contour points (xi,xj) of the function for parameter i and j around the minimum
      The contour will be find for value of the function = Min + ErrorUp();
    */
   virtual bool Contour(unsigned int i, unsigned int j, unsigned int & npoints, double *xi, double *xj); 

   
   /**
      perform a full calculation of the Hessian matrix for error calculation
      If a valid minimum exists the calculation is done on the minimum point otherwise is performed 
      in the current set values of parameters
      Status code of minimizer is updated according to the following convention (in case Hesse failed)
      status += 100*hesseStatus where hesse status is: 
      status = 1 : hesse failed
      status = 2 : matrix inversion failed
      status = 3 : matrix is not pos defined 
    */
   virtual bool Hesse();


   /// return reference to the objective function
   ///virtual const ROOT::Math::IGenFunction & Function() const; 

   /// print result of minimization
   virtual void PrintResults(); 

protected: 
   
   // protected function for accessing the internal MinuitCpp object. Needed for derived classes

   virtual const MinuitCpp::ModularFunctionMinimizer * GetMinimizer() const { return fMinimizer; } 

   virtual void SetMinimizer( MinuitCpp::ModularFunctionMinimizer * m)  { fMinimizer = m; } 

   void SetMinimizerType( MinuitCpp::EMinimizerType type);

   virtual const  MinuitCpp::FCNBase * GetFCN() const { return fMinuitFCN; } 

   /// examine the minimum result 
   bool ExamineMinimum(const MinuitCpp::FunctionMinimum & min); 

private: 
   
   unsigned int fDim;       // dimension of the function to be minimized 
   bool fUseFumili;     

   MinuitCpp::MnUserParameterState fState;
   // std::vector<MinuitCpp::MinosError> fMinosErrors;
   MinuitCpp::ModularFunctionMinimizer * fMinimizer;
   MinuitCpp::FCNBase * fMinuitFCN;
   MinuitCpp::FunctionMinimum * fMinimum;
   mutable std::vector<double> fValues;
   mutable std::vector<double> fErrors;

}; 

} // end namespace MinuitCpp



#endif /* MINUITCPP_MinuitCppMinimizer */
