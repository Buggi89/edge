#ifndef POLYNOMIAL
#define POLYNOMIAL

class monomial {

  public:
    monomial() : monomial(0,1.0,0,0,0) {}
    monomial(int d, double c) : monomial(d,c,0,0,0) {}
    monomial(int d, double c, int x) : monomial(d,c,x,0,0) {}
    monomial(int d, double c, int x, int y) : monomial(d,c,x,y,0) {}
    monomial(int, double, int, int, int);
    ~monomial();

    double value_at(void);
    double value_at(double);
    double value_at(double, double);
    double value_at(double, double, double);

  private:
    int d;
    double coeff;
    int *exp;

};


#endif // POLYNOMIAL

