#include <main.h>
#include <test.h>

void field_tests();
void grid_tests();
void monomial_tests();
void polynomial_tests();
void vector_tests();
void utils_tests();

int tests_success = 0;
int tests_failed  = 0;

int main() {

  field_tests();
  grid_tests();
  vector_tests();
  monomial_tests();
  polynomial_tests();
  utils_tests();

  cout << "\033[1;30mRan tests       : " << tests_success + tests_failed << "\n";
  cout << "\033[1;30mFailed tests    : \033[1;31m" << tests_failed << "\n";
  cout << "\033[1;30mSuccessful tests: \033[1;32m" << tests_success<< "\n\033[0m";

}

void f_assert_equal_i(int act, int exp, string message, int line, const string file) {

  int success = (act==exp);
  cout << (success ? "\033[32m" : "\033[1;31m") << message << " ... " << (success ? "SUCCESS\033[0m" : "FAILED") << "\n";
  if(!success) {
    cout << "Expected [" << exp << "], got [" << act << "] in " << file << ", line " << line << "\033[0m\n";
    tests_failed++;
  } else tests_success++;

}

void f_assert_equal_d(double act, double exp, string message, double precision, int line, const string file) {

  int success = dpequal(act,exp,precision);
  cout << (success ? "\033[32m" : "\033[1;31m") << message << " ... " << (success ? "SUCCESS\033[0m" : "FAILED") << "\n";
  if(!success) {
    cout << "Expected [" << exp << "], got [" << act << "], relative error ["
         << fabs((act-exp)/(fabs(exp)<fabs(act)?fabs(act):fabs(exp))) << "] is bigger than precision [" << precision  << "] in " << file << ", line " << line << "\033[0m\n";
    tests_failed++;
  } else tests_success++;

}

void f_assert_equal_s(string act, string exp, string message, int line, const string file) {

  int success = (act==exp);
  cout << (success ? "\033[32m" : "\033[1;31m") << message << " ... " << (success ? "SUCCESS\033[0m" : "FAILED") << "\n";
  if(!success) {
    cout << "Expected [" << exp << "], got [" << act  << "] in " << file << ", line " << line << "\033[0m\n";
    tests_failed++;
  } else tests_success++;

}
