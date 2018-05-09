#include <main.h>

#include <polynomial.h>

monomial::monomial(int dim, double c, int x, int y, int z) {

  if(dim>3) throw new string("Monomial dimension higher than 3 is invalid.");

  d = dim;
  n = x+y+z;
  coeff = c;
  exp = new int[3];
  exp[0] = x;
  exp[1] = y;
  exp[2] = z;

}

monomial::~monomial() {

  delete[] exp;

}

monomial monomial::operator *(const monomial& other) {

  monomial result(imax(d,other.d), coeff * other.coeff,
                  exp[0] + other.exp[0],
                  exp[1] + other.exp[1],
                  exp[2] + other.exp[2]);
  return result;

}

polynomial monomial::operator +(const monomial& other) {

  polynomial result(this);
  result.add_monomial(other);
  return result;

}

double monomial::value_at(void) {

  if(d>0) throw new string("Number of given coordinates (0) is lower than variables in monomial.");
  return coeff;

}

double monomial::value_at(double x) {

  if(d>1) throw new string("Number of given coordinates (1) is lower than variables in monomial.");
  return coeff * pow(x, 1.0*exp[0]);

}

double monomial::value_at(double x, double y) {

  if(d>2) throw new string("Number of given coordinates (2) is lower than variables in monomial.");
  return coeff * pow(x, 1.0*exp[0]) * pow(y, 1.0*exp[1]);

}

double monomial::value_at(double x, double y, double z) {

  if(d>3) throw new string("Number of given coordinates (3) is lower than variables in monomial.");
  return coeff * pow(x, 1.0*exp[0]) * pow(y, 1.0*exp[1]) * pow(z, 1.0*exp[2]);

}

polynomial::polynomial() {

  n =0;
  d =1;
  nm=1;

  ml = new monomial_list;
  ml->next = nullptr;
  ml->prev = nullptr;
  ml->m    = new monomial(0,0.0);

}

polynomial::polynomial(monomial *mo) {

  n = mo->n;
  d = mo->d;
  nm= 1;

  ml = new monomial_list;
  ml->next = nullptr;
  ml->prev = nullptr;
  ml->m    = new monomial(mo->d, mo->coeff, mo->exp[0], mo->exp[1], mo->exp[2]);

}

polynomial::polynomial(const polynomial &p) {

  n = p.n;
  d = p.d;
  nm= 0;

  ml = new monomial_list;
  ml->next = nullptr;
  ml->prev = nullptr;
  ml->m    = new monomial(p.ml->m->d, p.ml->m->coeff, p.ml->m->exp[0], p.ml->m->exp[1], p.ml->m->exp[2]);
  monomial_list *tmp = p.ml->next;
  while(tmp != nullptr) {
    add_monomial(*tmp->m);
    tmp = tmp->next;
  }

}

polynomial::~polynomial() {

  monomial_list *tmp = ml, *next;
  while(tmp != nullptr) {
    next = tmp->next;
    delete tmp->m;
    delete tmp;
    tmp = next;
  }

}

void polynomial::add_monomial(const monomial &mo) {

  n = imax(n, mo.n);
  d = imax(d, mo.d);
  nm++;

  monomial_list *first = new monomial_list;
  first->next = ml;
  first->prev = nullptr;
  first->m    = new monomial(mo.d, mo.coeff, mo.exp[0], mo.exp[1], mo.exp[2]);
  ml->prev = first;
  ml = first;

}

polynomial polynomial::operator +(const monomial &mo) {

  polynomial result = *this;
  result.add_monomial(mo);
  return result;

}

double polynomial::value_at() {

  double result = 0.0;
  monomial_list *tmp = ml;
  while(tmp != nullptr) {
    result += tmp->m->value_at();
    tmp = ml->next;
  }
  return result;

}

double polynomial::value_at(double x) {

  double result = 0.0;
  monomial_list *tmp = ml;
  while(tmp != nullptr) {
    result += tmp->m->value_at(x);
    tmp = tmp->next;
  }
  return result;

}

double polynomial::value_at(double x, double y) {

  double result = 0.0;
  monomial_list *tmp = ml;
  while(tmp != nullptr) {
    result += tmp->m->value_at(x,y);
    tmp = tmp->next;
  }
  return result;

}
