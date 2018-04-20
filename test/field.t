#include <main.h>
#include <test.h>

#include <field.h>

void scalar_field_init();

void field_tests() {
  
  cout << "Testing class scalar_field: \n";
  scalar_field_init();

}

void scalar_field_init() {

  scalar_field cut("psi");
  assert_equal(cut.name, "psi", "Name of the scalar field");

}
