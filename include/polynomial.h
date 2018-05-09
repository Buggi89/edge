#ifndef POLYNOMIAL
#define POLYNOMIAL

class polynomial;

class monomial {

  public:
    monomial() : monomial(0,0.0,0,0,0) {}
    monomial(int d, double c) : monomial(d,c,0,0,0) {}
    monomial(int d, double c, int x) : monomial(d,c,x,0,0) {}
    monomial(int d, double c, int x, int y) : monomial(d,c,x,y,0) {}
    monomial(int, double, int, int, int);
    ~monomial();

    double value_at(void);
    double value_at(double);
    double value_at(double, double);
    double value_at(double, double, double);

    polynomial operator +(const monomial&);
    polynomial operator +(const polynomial&);
    monomial operator *(const monomial&);
    void operator *=(const double&);

  private:
    int n;
    int d;
    double coeff;
    int *exp;

  friend class polynomial;
  friend monomial operator *(const double&, const monomial&);
  friend monomial operator *(const monomial& m, const double& a) { return a*m; }

};

class polynomial {

  public:
    polynomial();
    polynomial(const monomial& mo);
    polynomial(const polynomial& p);
    ~polynomial();

    void add_monomial(const monomial& mo);
    double value_at(void);
    double value_at(double);
    double value_at(double, double);
    double value_at(double,double,double);
    double get_coeff(int,int,int);
    void simplify();

    polynomial operator +(const monomial& other);
    polynomial operator +(const polynomial& other);

  private:
    struct monomial_list {
      monomial *m;
      monomial_list *prev;
      monomial_list *next;
    } *ml;
    int n;
    int d;
    int nm;

  friend polynomial operator *(const double&, const polynomial&);
  friend polynomial operator *(const polynomial& p, const double& a) { return a*p; }

};

#endif // POLYNOMIAL

