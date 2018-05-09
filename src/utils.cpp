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
