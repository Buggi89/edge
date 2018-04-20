#include <main.h>

#include <field.h>

field::field(string name, int n1, int n2, field::Type type) {
 
  this->name = name; 
  n[0]       = n1;
  n[1]       = n2; 
  n_total    = n1*n2;
  this->type = type;

  value       = new double[n_total]; 
  symmetry[0] = new field::Symmetry[n_total];
  symmetry[1] = new field::Symmetry[n_total];
  symmetry[2] = new field::Symmetry[n_total];

  for(int i=0; i<n_total; i++) {
    value      [i] = 0.0;
    symmetry[0][i] = NOSYM;
    symmetry[1][i] = NOSYM;
    symmetry[2][i] = NOSYM;
  }

}

field::~field() {

  delete[] value;
  delete[] symmetry[0];
  delete[] symmetry[1];
  delete[] symmetry[2];

}

double scalar_field::getValue() {

  return value[0];

}

void scalar_field::setValue(double val) {

  value[0] = val;

}
