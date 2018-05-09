#include <main.h>
#include <test.h>

#include <polynomial.h>

void monomial_init() {

  monomial mo1;
  assert_equal_d(mo1.value_at(), 0.0, "Value of constant monomial");

  monomial mo2(1,2.3,3);
  assert_equal_d(mo2.value_at(0.56), 0.4039168,"Value of 1D monomial");

  monomial mo3(2,2.4,4,5);
  assert_equal_d(mo3.value_at(-0.43,0.78), 0.02368961907958264,"Value of 2D monomial");

  monomial mo4(3,2.6,3,4,6);
  assert_equal_d(mo4.value_at(0.41,-0.9,-0.31),0.0001043434324143631,"Value of 3D monomial");

  monomial mo5(2,1.0,1,1);
  assert_equal_d(mo5.value_at(1.0,2.0,3.0),2.0,"More coordinates than in monomial");

  monomial mo6(2,1.0,1,1);
  assert_fail_message(mo6.value_at(1.0),
  "Number of given coordinates (1) is lower than variables in monomial.", "Less coordinates than in monomial");

  assert_fail_message(monomial mo7(4,1.0,1,1);, "Monomial dimension higher than 3 is invalid.", "Monomial dimension > 3");

}

void monomial_multiply() {

  monomial mo1(2,2.0,1,1);
  monomial mo2(2,4.0,2,0);
  monomial mo3 = mo1 * mo2;

  assert_equal_d(mo3.value_at(2.5,3.0), 375.0, "Monomial multiplication - 1");

  monomial mo4(3,2.5,2,1,1);
  monomial mo5(2,4.0,2,2);
  monomial mo6 = mo4 * mo5;

  assert_equal_d(mo6.value_at(2.5,3.0,-1.0), -10546.875, "Monomial multiplication - 2");

  monomial mo8 = 5.0 * mo3;
  monomial mo9 = mo8 * 5.0;

  assert_equal_d(mo8.value_at(2.5,3.0), 1875.0, "Scalar * Monomial multiplication");
  assert_equal_d(mo9.value_at(2.5,3.0), 9375.0, "Monomial * Scalar multiplication");

  mo9 *= 1.0 / 9375.0;
  assert_equal_d(mo9.value_at(2.5,3.0), 1.0, "Monomial *= Scalar multiplication");

}

void polynomial_init() {

  polynomial p1;
  assert_equal_d(p1.value_at(), 0.0, "Value of constant polynomial - 0D");
  assert_equal_d(p1.value_at(1.0), 0.0, "Value of constant polynomial - 1D");
  assert_equal_d(p1.value_at(1.0,2.0), 0.0, "Value of constant polynomial - 2D");
  assert_equal_d(p1.value_at(1.0,2.0,4.0), 0.0, "Value of constant polynomial - 3D");

  monomial mo2(1,2.0,2);
  polynomial p2 = mo2;
  assert_fail_message(p2.value_at(), "Number of given coordinates (0) is lower than variables in monomial.", "Polynomial from monomial - 0D");
  assert_equal_d(p2.value_at(2.5), 12.5, "Polynomial from monomial - 1D");
  assert_equal_d(p2.value_at(2.5,1.0), 12.5, "Polynomial from monomial - 2D");
  assert_equal_d(p2.value_at(2.5,1.0,2.0), 12.5, "Polynomial from monomial - 3D");

}

void polynomial_add() {

  monomial mo1(0,1.0);
  monomial mo2(1,2.0,1);
  polynomial p1 = mo1 + mo2;
  assert_equal_d(p1.value_at(2.5), 6.0, "Monomial + Monomial = Polynomial");

  monomial mo3(2,4.0,1,2);
  polynomial p2 = p1 + mo3;
  assert_equal_d(p2.value_at(2.5,3.0), 96.0, "Polynomial + Monomial = Polynomial");

  monomial mo4(3,-4.0,1,1,1);
  polynomial p3 = mo4 + p2;
  assert_equal_d(p3.value_at(2.5,3.0,4.0), -24.0, "Monomial + Polynomial = Polynomial");

  polynomial p4 = monomial(3,-2.0,1,2,1) + monomial(2,-1.5,1,3);
  polynomial p5 = p3 + p4;
  assert_equal_d(p5.value_at(2.5,3.0,4.0), -305.25, "Polynomial + Polynomial = Polynomial");

}

void polynomial_multiply() {

  polynomial p1 = monomial(3,-2.0,1,2,1) + monomial(2,-1.5,1,3);
  polynomial p2 = 5.0 * p1;
  polynomial p3 = p2 * (-2.5);
  assert_equal_d(p2.value_at(2.5,3.0,4.0), -1406.25, "scalar * Polynomial = Polynomial");
  assert_equal_d(p3.value_at(2.5,3.0,4.0), 3515.625, "Polynomial * scalar = Polynomial");

}

void monomial_tests() {

  cout << "Testing class monomial: \n";
  monomial_init();
  monomial_multiply();

}

void polynomial_tests() {

  cout << "Testing class polynomial: \n";
  polynomial_init();
  polynomial_add();
  polynomial_multiply();

}
