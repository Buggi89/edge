#include <main.h>
#include <test.h>

#include <polynomial.h>

void monomial_init() {

  monomial mo1;
  assert_equal(mo1.value_at(), 1.0, "Value of constant monomial", EPSILON);

  monomial mo2(1,2.3,3);
  assert_equal(mo2.value_at(0.56), 0.4039168,"Value of 1D monomial", EPSILON);

  monomial mo3(2,2.4,4,5);
  assert_equal(mo3.value_at(-0.43,0.78), 0.02368961907958264,"Value of 2D monomial", EPSILON);

  monomial mo4(3,2.6,3,4,6);
  assert_equal(mo4.value_at(0.41,-0.9,-0.31),0.0001043434324143631,"Value of 3D monomial", EPSILON);

  monomial mo5(2,1.0,1,1);
  assert_fail_message(mo5.value_at(1.0,2.0,3.0),
  "Number of given coordinates (3) and variables in monomial does not match.", "Too many coordinates");

}

void monomial_multiply() {

  monomial mo1(2,2.0,1,1);
  monomial mo2(2,4.0,2,0);
  monomial mo3 = mo1 * mo2;

  assert_equal(mo3.value_at(2.5,3.0), 375.0, "Monomial multiplication - 1", EPSILON);

  monomial mo4(3,2.5,2,1,1);
  monomial mo5(2,4.0,2,2);
  monomial mo6 = mo4 * mo5;

  assert_equal(mo6.value_at(2.5,3.0,-1.0), -10546.875, "Monomial multiplication - 2", EPSILON);

}

void monomial_tests() {

  cout << "Testing class monomial: \n";
  monomial_init();
  monomial_multiply();

}
