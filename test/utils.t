#include <main.h>
#include <test.h>

#include <utils.h>

void utils_tests() {

  cout << "Testing utils: \n";
  assert_equal_i(fac(0), 1,   "Factorial 0");
  assert_equal_i(fac(1), 1,   "Factorial 1");
  assert_equal_i(fac(3), 6,   "Factorial 3");
  assert_equal_i(fac(5), 120, "Factorial 5");

  assert_equal_i(binom(5,3), 10, "Binomial 5 3");

}
