#ifndef H_polynomial
#define H_polynomial
#include <cmath>
#include <iostream>
#include <string>
#include<vector>
#include<complex>
using namespace std;
class Polynomial//This polynomial class is used for computation of integral and roots of any given Polynomial function
{
 private:
  vector<double> a; // coefficients of polynomial
 public:
  Polynomial();//default constructor with a[0]=0.0
  
  Polynomial(const vector<double>&b);// constructor 2

  Polynomial(const Polynomial&p);//copy constructor

  void print_parameters(); // Print the parameters

  int get_order() const; // Returning the order of polynomial function
  void set_parameters(const vector<double>b);//Parameters setting by vector

  void set_parameter(int i, double b);//Parameter setting
  
  double get_parameter(int i)const;// Returning coefficients of polynomial
  double analytical_integrate(double xmin,double xmax)const;//Analytical integration of polynomial function
  complex<double> complex_function(const complex<double> &z);
  complex<double> derivative( const Polynomial& p );
  Polynomial     derivative( );

  double operator()( double x) const;// Evaluating the polynomial function
  complex<double> Derivative(const complex<double> &z);

   
};
 ostream& operator<<(ostream & out,const Polynomial &P);//Overloading the << operator
 double numerical_integrate( const Polynomial &P, double xmin, double  xmax);//Numerical integration of polynomial function
  
 vector <complex<double>>find_roots(const Polynomial&p);// Finding the roots of polynomial function


#endif
  
  
  
