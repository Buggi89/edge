#include <main.h>
#include <test.h>

int field_tests();
int grid_tests();

int main() {

  field_tests();
  grid_tests();

}

void assert_equal(int act, int exp, string message) {

  int success = (act==exp);
  cout << message << " ... " << (success ? "SUCCESS" : "FAILED") << "\n";
  if(!success) {
    cout << "Expected [" << exp << "], got [" << act << "]\n";
    exit(1);
  }

}

void assert_equal(double act, double exp, string message, double precision = 1e-15) {

  int success = (fabs(act-exp) < precision);
  cout << message << " ... " << (success ? "SUCCESS" : "FAILED") << "\n";
  if(!success) {
    cout << "Expected [" << exp << "], got [" << act << "], difference [" << fabs(act-exp) << "] is bigger than precision [" << precision << "]\n";
    exit(1);
  }

}

void assert_equal(string act, string exp, string message) {

  int success = (act==exp);
  cout << message << " ... " << (success ? "SUCCESS" : "FAILED") << "\n";
  if(!success) {
    cout << "Expected [" << exp << "], got [" << act << "]\n";
    exit(1);
  }

}
