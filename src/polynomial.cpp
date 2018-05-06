#include <main.h>

#include <polynomial.h>

monomial::monomial(int dim, double c, int x=0, int y=0, int z=0) {

  d = dim;
  coeff = c;
  exp = new int[d];
  if(d>0) exp[0] = x;
  if(d>1) exp[1] = y;
  if(d>2) exp[2] = z;

}

monomial::~monomial() {

  delete[] exp;

}

double monomial::value_at(void) {

  if(d!=0) throw "Number of given coordinates (0) and variables in monomial does not match.";
  return coeff;

}

double monomial::value_at(double x) {

  if(d!=1) throw "Number of given coordinates (1) and variables in monomial does not match.";
  return coeff * pow(x, 1.0*exp[0]);

}

double monomial::value_at(double x, double y) {

  if(d!=2) throw "Number of given coordinates (2) and variables in monomial does not match.";
  return coeff * pow(x, 1.0*exp[0]) * pow(y, 1.0*exp[1]);

}

double monomial::value_at(double x, double y, double z) {

  if(d!=3) throw new string("Number of given coordinates (3) and variables in monomial does not match.");
  return coeff * pow(x, 1.0*exp[0]) * pow(y, 1.0*exp[1]) * pow(z, 1.0*exp[2]);

}
