#include "Polynomial.h"
#include <cmath>
using namespace std;

Polynomial:: Polynomial()//Defult constructor with a[0]=0.0
{
  a.push_back(0.0);
 
}
Polynomial:: Polynomial(const vector<double>&b)// Constructor 2
{
  a=b;
  //for( int i = 0; i<b.size(); i++)  a.push_back(b[i]);
 
}  
Polynomial:: Polynomial(const Polynomial&p)// Copy constructor
{
   
  a = p.a; 

}
void Polynomial:: set_parameters(const vector<double>b)//Parameters setting by vector
{
 
  a = b;  
}

void Polynomial:: set_parameter(int i, double b)//Parameter setting
{
  for(int j=a.size(); j<=i; j++){
    a.push_back(0.0);
  }
  a[i]=b;
}

double Polynomial:: get_parameter(int i)const// Getting the coefficients of polynomial
{
  if ( i <a.size() )
    return a[i];
  else
    return 0.0; ;
}

double Polynomial:: operator()( double x)const// Evaluating the polynomial function
// Evaluates the polynomial at a particular point

{
  double sum = 0.0;
  double xPow = 1.0;	
  for(int i=0; i<a.size(); i++)
    {			
      sum +=a[i]* xPow;// add  the terms in function
      xPow *= x;// constructing the power of x term to term
    }	

  return sum; 
}

int Polynomial:: get_order() const // returning the order of polynomial
{
  return a.size()-1 ;
}

// evaluate the polynomial at a complex point z (member function)
complex<double> Polynomial::complex_function(const complex<double> & z )
{
  complex<double> sum = 0.0;
  complex<double> zPow = 1.0;	
  for(int i=0; i<a.size(); i++)
    {			
      sum +=a[i]* zPow;// add  the terms in function
      zPow *= z;// constructing the power of x term to term
    }
  return sum;
}
complex<double>  Polynomial:: Derivative(const complex<double> &z)
{

  complex<double> deriv=0;
  for (int i=0;i<=a.size();i++){
  complex<double> derivative=a[i]*i*pow(z,i-1);
  deriv+=derivative;
  }
  return deriv;
}

// Add a derivative class that returns a new Polynomial that is the derivative of the one passed.
  Polynomial  Polynomial:: derivative( ){
  Polynomial p2;
   vector <double> vect;
  for (int i=1; i<=a.size();i++)
    //  p2.set_parameter(i-1,a[i]*i);
     vect.push_back(a[i]*i);
    p2.set_parameters(vect);
      return p2;
}
double Polynomial:: analytical_integrate(double xmin,double xmax) const{
  double ana_integ=0;
  for (int i=0; i<=a.size();i++){
    double  ana_integration=(a[i]*pow(xmax,i+1)-a[i]*pow(xmin,i+1))/(i+1);
    ana_integ+=ana_integration;
  }
  return ana_integ;
}



void Polynomial::print_parameters()
{
  cout << "f(x) =";
  for(int i=0; i<a.size(); i++){
    cout << " " << a[i] << "*x^" << i;
  }
  cout << endl;
};

ostream&  operator<<(ostream &out,const Polynomial &P)
{
  for (int i=0; i < P.get_order( )+1; i++)
    {
      if (i==0)
	out<<P.get_parameter(0);
      else  if (P.get_parameter(i) > 0)
	{	 out << " + " ;
	  out<<P.get_parameter(i);
	  out << "*x^" <<i;
	}
      
      else if ( P.get_parameter(i)<0.0){
	out<<P.get_parameter(i);
	out << "*x^" << i;
      }
    }

  return out;
}





double numerical_integrate(const  Polynomial &P, double xmin, double  xmax)//Integration of polynomial
{
  double ssum=0;
  int n=100000;
  double dx;
  dx=(xmax-xmin)/n;
  for (int i=0; i<n;i++){
    double xi=xmin+i*dx;
    double functionValue=P.operator()(xi);
    double integral=functionValue*dx;
    ssum+=integral;
  }
  return ssum;
}


/*vector <complex<double>>find_roots(const Polynomial&p)// Finding the roots of polynomial using Newton approximation
  {
  int i;
  double ac,x,xi,f,fi;
  
  cout.precision(5);// Number of decimals
  vector <int>vect;
  for(int i=1;i<=degree){
  x=xi;//initial guess
  f=operator(xi);//The value of  Polynomial function in initial guess
  fi=operator.Derivative(xi);// Derivative of polynomial function in initial guess
  xi=x-(f/fi);// Next initial guess
  cin>ac;//acuracy of calculation
  while(operatorabs(xi-x))>ac);
  cout<<xi<<"is a root";
  vect.push_back(xi);
  }
  return vect;
  }
*/
