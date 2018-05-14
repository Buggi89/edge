#include <main.h>

#include <polynomial.h>
#include <utils.h>

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

void monomial::operator *=(const double& a) {

  coeff *= a;

}

void monomial::operator *=(const monomial& m) {

  d = imax(d, m.d);
  n = n + m.n;

  coeff = coeff * m.coeff;
  exp[0]= exp[0] + m.exp[0];
  exp[1]= exp[1] + m.exp[1];
  exp[2]= exp[2] + m.exp[2];

}

monomial operator*(const double& a, const monomial& m) {

  return monomial(m.d, m.coeff * a, m.exp[0], m.exp[1], m.exp[2]);

}

polynomial monomial::operator *(const polynomial& p) {

  polynomial result = p;
  return result * *this;

}

polynomial monomial::operator +(const monomial& other) {

  polynomial result = *this;
  result.add_monomial(other);
  return result;

}

polynomial monomial::operator +(const polynomial& p) {

  polynomial result = p;
  result.add_monomial(*this);
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

polynomial::polynomial(const monomial &mo) {

  n = mo.n;
  d = mo.d;
  nm= 1;

  ml = new monomial_list;
  ml->next = nullptr;
  ml->prev = nullptr;
  ml->m    = new monomial(mo.d, mo.coeff, mo.exp[0], mo.exp[1], mo.exp[2]);

}

polynomial::polynomial(const polynomial &p) {

  n = p.n;
  d = p.d;
  nm= 1;

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

polynomial polynomial::operator +(const polynomial &p) {

  polynomial result = *this;
  monomial_list *tmp = p.ml;
  while(tmp != nullptr) {
    result.add_monomial(*tmp->m);
    tmp = tmp->next;
  }
  return result;

}

polynomial polynomial::operator -(const monomial &mo) {

  polynomial result = *this;
  result.add_monomial((-1.0) * mo);
  return result;

}

polynomial polynomial::operator -(const polynomial &p) {

  polynomial result = *this;
  monomial_list *tmp = p.ml;
  while(tmp != nullptr) {
    result.add_monomial((-1.0) * *tmp->m);
    tmp = tmp->next;
  }
  return result;

}

polynomial operator *(const double &a, const polynomial &p) {

  polynomial result = p;
  polynomial::monomial_list *tmp = result.ml;
  while(tmp != nullptr) {
    *tmp->m *= a;
    tmp = tmp->next;
  }
  return result;

}

polynomial polynomial::operator *(const monomial &m) {

  polynomial result = *this;
  monomial_list *tmp  = result.ml;
  while(tmp != nullptr) {
    *tmp->m *= m;
    tmp = tmp->next;
  }
  return result;

}

polynomial polynomial::operator *(const polynomial &p) {

  polynomial result;
  monomial_list *tmp  = ml;
  monomial_list *ptmp = p.ml;
  while(ptmp != nullptr) {
    tmp  = ml;
    while(tmp != nullptr) {
      result.add_monomial(*ptmp->m * *tmp->m);
      tmp = tmp->next;
    }
    ptmp = ptmp->next;
  }
  return result;

}

void polynomial::simplify() {

  monomial_list *tmp1  = ml;
  monomial_list *tmp2  = ml;
  monomial_list *next;
  while(tmp1 != nullptr) {
    tmp2 = ml;
    while(tmp2 != nullptr) {
      next = tmp2->next;
      if(tmp1!=tmp2) {
        if((tmp1->m->exp[0] == tmp2->m->exp[0]) &&
           (tmp1->m->exp[1] == tmp2->m->exp[1]) &&
           (tmp1->m->exp[2] == tmp2->m->exp[2])) {

            tmp1->m->coeff  += tmp2->m->coeff;
            if(tmp2->prev) tmp2->prev->next = tmp2->next;
            if(tmp2->next) tmp2->next->prev = tmp2->prev;
            delete tmp2->m;
            delete tmp2;
            nm--;
        }
      }
      tmp2 = next;
    }
    tmp1 = tmp1->next;
  }

  sort();

}

double polynomial::value_at() {

  double result = 0.0;
  monomial_list *tmp = ml;
  while(tmp != nullptr) {
    result += tmp->m->coeff;
    if(tmp->m->exp[0]>0 || tmp->m->exp[1]>0 || tmp->m->exp[2]>0)
      throw new string("Number of given coordinates (0) is lower than variables in polynomial.");
    tmp = tmp->next;
  }
  return result;

}

double polynomial::value_at(double x) {

  simplify();

  double result;
  monomial_list *tmp = ml;

  int n = ml->m->exp[0];
  double *a = new double[n+1];
  for(int i=0;i<=n;i++) a[i]=0.0;
  while(tmp != nullptr) {
    a[tmp->m->exp[0]] = tmp->m->coeff;
    if(tmp->m->exp[1]>0 || tmp->m->exp[2]>0)
      throw new string("Number of given coordinates (1) is lower than variables in polynomial.");
    tmp = tmp->next;
  }
  result = horner1D(x, a, n);
  delete []a;

  return result;

}

double polynomial::value_at(double x, double y) {

  simplify();

  double result = 0.0;
  monomial_list *tmp = ml;
  int n = ml->m->exp[0]+1;
  int m = ml->m->exp[1]+1;

  double *a = new double[n];
  for(int i=0;i<n;i++) a[i] = 0.0;

  double *b = new double[m];
  for(int j=0;j<m;j++) b[j] = 0.0;

  while(tmp != nullptr) {
    if(tmp->m->exp[0]+1 < n) {
      a[n-1] = horner1D(y,b,m-1);
      n = tmp->m->exp[0]+1;
      m = tmp->m->exp[1]+1;
      delete []b;
      b = new double[m];
      for(int j=0;j<m;j++) b[j] = 0.0;
    }
    b[tmp->m->exp[1]] = tmp->m->coeff;
    if(tmp->m->exp[2]>0)
      throw new string("Number of given coordinates (2) is lower than variables in polynomial.");
    tmp = tmp->next;
  }
  a[n-1] = horner1D(y, b, m-1);
  result = horner1D(x, a, ml->m->exp[0]);
  delete []a; delete []b;
  return result;

}

double polynomial::value_at(double x, double y, double z) {

  simplify();

  double result = 0.0;
  monomial_list *tmp = ml;
  int n = ml->m->exp[0]+1;
  int m = ml->m->exp[1]+1;
  int o = ml->m->exp[2]+1;

  int n0 = n;
  int m0 = m;

  double *a = new double[n];
  for(int i=0;i<n;i++) a[i] = 0.0;

  double *b = new double[m];
  for(int j=0;j<m;j++) b[j] = 0.0;

  double *c = new double[o];
  for(int k=0;k<o;k++) c[k] = 0.0;

  while(tmp != nullptr) {
    if(tmp->m->exp[0]+1 < n) {
      b[m-1] = horner1D(z,c,o-1);
      a[n-1] = horner1D(y,b,m0-1);
      n = tmp->m->exp[0]+1;
      m = m0 = tmp->m->exp[1]+1;
      o = tmp->m->exp[2]+1;
      delete []b; delete []c;
      b = new double[m];
      for(int j=0;j<m;j++) b[j] = 0.0;
      c = new double[o];
      for(int k=0;k<o;k++) c[k] = 0.0;
    } else if(tmp->m->exp[1]+1 < m) {
      b[m-1] = horner1D(z,c,o-1);
      m = tmp->m->exp[1]+1;
      o = tmp->m->exp[2]+1;
      delete []c;
      c = new double[o];
      for(int k=0;k<o;k++) c[k] = 0.0;
    }
    c[tmp->m->exp[2]] = tmp->m->coeff;
    tmp = tmp->next;
  }
  b[m-1] = horner1D(z, c, o-1);
  a[n-1] = horner1D(y, b, m0-1);
  result = horner1D(x, a, n0-1);
  delete []a; delete []b; delete []c;
  return result;

}

void polynomial::horner1DEFT(double x, double *a, double *sum, double *p, double *q, int n) {

  double tmp, s = a[n];
  for(int i = n-1; i>=0; i--) {
      TwoProduct(s,x,&tmp,&p[i]);
      TwoSum(tmp,a[i],&s,&q[i]);
  }
  *sum = s;

}

double polynomial::horner1D(double x, double *a, int n) {

  double sum;
  double *p = new double[n+1];
  double *q = new double[n+1];
  horner1DEFT(x, a, &sum, p, q, n);

  double correction = 0.0;
  for(int i=n-1;i>=0;i--) {
    correction = correction * x + (p[i]+q[i]);
  }

  delete []p;
  delete []q;

  return sum+correction;

}

void polynomial::print(string *s) {

  monomial_list *tmp = ml;

  if(s) {
    ostringstream os;
    while(tmp != nullptr) {
      os << ((tmp->m->coeff>=0)?"  +":"  ") << tmp->m->coeff;
      if(tmp->m->exp[0]) os << " x^" << tmp->m->exp[0];
      if(tmp->m->exp[1]) os << " y^" << tmp->m->exp[1];
      if(tmp->m->exp[2]) os << " z^" << tmp->m->exp[2];
      tmp = tmp->next;
    }
    os << "\n";
    *s = os.str();
  } else {
    while(tmp != nullptr) {
      cout << ((tmp->m->coeff>=0)?"  +":"  ") << tmp->m->coeff;
      if(tmp->m->exp[0]) cout << " x^" << tmp->m->exp[0];
      if(tmp->m->exp[1]) cout << " y^" << tmp->m->exp[1];
      if(tmp->m->exp[2]) cout << " z^" << tmp->m->exp[2];
      tmp = tmp->next;
    }
    cout << "\n";
  }

}

void polynomial::sort() {

  quicksort(&ml, nm);

}

void polynomial::quicksort(monomial_list **start, int nm) {

  if(nm<2) return;
  monomial_list *tmp = (*start)->next, *pivot = *start, *next;
  int i = 0, shifts = 0;

  while(i<nm-1) {
    next = tmp->next;

    polynomial p1 = *tmp->m;
    polynomial p2 = *pivot->m;

    if((tmp->m->exp[0] >  pivot->m->exp[0]) ||
      ((tmp->m->exp[0] == pivot->m->exp[0]) && (tmp->m->exp[1] >  pivot->m->exp[1])) ||
      ((tmp->m->exp[0] == pivot->m->exp[0]) && (tmp->m->exp[1] == pivot->m->exp[1]) && (tmp->m->exp[2] > pivot->m->exp[2]))) {

      polynomial p = *tmp->m;

      if(tmp->prev) tmp->prev->next = tmp->next;
      if(tmp->next) tmp->next->prev = tmp->prev;
      tmp->prev = nullptr;
      tmp->next = *start;
      (*start)->prev = tmp;
      *start = tmp;
      shifts++;
    }
    i++;
    tmp = next;
  }

  quicksort(start,shifts);
  quicksort(&pivot->next,nm-shifts-1);

}
