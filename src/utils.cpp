#include <main.h>

#include <utils.h>

int fac(int n) {

  double res = 1;
  for(int i=1; i<=n; i++) res *= i;
  return res;

}

int binom(int n, int k) {

  if(n<k) throw new string("n<k in binomial coefficient (n k)");
  return fac(n)/(fac(n-k)*fac(k));

}

void TwoSum(double a, double b, double *x, double *y) {

  *x = a+b;
  double z = *x-a;
  *y = (a-(*x-z))+(b-z);

}

void Split(double a, double *x, double *y) {

  double z = a * 134217729.0;
  *x = z - (z-a);
  *y = a - *x;

}

void TwoProduct(double a, double b, double *x, double *y) {

  double ah, al, bh, bl;
  *x = a*b;
  Split(a,&ah,&al);
  Split(b,&bh,&bl);
  *y = al*bl - (((*x-ah*bh)-al*bh)-ah*bl);

}
