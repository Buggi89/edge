#include <main.h>
#include <test.h>

#include <vector.h>

void vector_plus() {

  vector v1( 1.2,4.5, 9.6);
  vector v2(-0.8,2.6,-4.5);
  vector v3 = v1+v2;

  assert_equal_d(v3.x, 0.4, "Vector plus - x");
  assert_equal_d(v3.y, 7.1, "Vector plus - y");
  assert_equal_d(v3.z, 5.1, "Vector plus - z");
}

void vector_minus() {

  vector v1( 1.2,4.5, 9.6);
  vector v2(-0.8,2.6,-4.5);
  vector v3 = v1-v2;

  assert_equal_d(v3.x, 2.0, "Vector minus - x");
  assert_equal_d(v3.y, 1.9, "Vector minus - y");
  assert_equal_d(v3.z,14.1, "Vector minus - z");

}

void vector_times_scalar() {

  vector v1( 1.2,4.5, 9.6);
  vector v2 = 2.5*v1;

  assert_equal_d(v2.x, 3.0 , "Vector scalar multiplication - x");
  assert_equal_d(v2.y,11.25, "Vector scalar multiplication - y");
  assert_equal_d(v2.z,24.0,  "Vector scalar multiplication - z");

  vector v3 = v1*2.5;

  assert_equal_d(v3.x, 3.0 , "Vector scalar multiplication - x");
  assert_equal_d(v3.y,11.25, "Vector scalar multiplication - y");
  assert_equal_d(v3.z,24.0,  "Vector scalar multiplication - z");

}

void vector_scalar_product() {

  vector v1(1.0,0.0,0.0);
  vector v2(0.0,1.0,0.0);

  assert_equal_d(dot(v1,v2), 0.0, "Simple scalar product");

  vector v4( 1.2,4.5, 9.6);
  vector v5(-0.8,2.6,-4.5);

  assert_equal_d(dot(v4,v5), -32.46, "Complex scalar product");

}

void vector_cross_product() {

  vector v1(1.0,0.0,0.0);
  vector v2(0.0,1.0,0.0);
  vector v3 = cross(v1,v2);

  assert_equal_d(v3.x, 0.0, "Simple cross product x");
  assert_equal_d(v3.y, 0.0, "Simple cross product y");
  assert_equal_d(v3.z, 1.0, "Simple cross product z");

  vector v4( 1.2,4.5, 9.6);
  vector v5(-0.8,2.6,-4.5);
  vector v6 = cross(v4,v5);

  assert_equal_d(v6.x,-45.21, "Complex cross product x");
  assert_equal_d(v6.y, -2.28, "Complex cross product y");
  assert_equal_d(v6.z,  6.72, "Complex cross product z");

}

void vector_tests() {

  cout << "Testing class vector: \n";
  vector_plus();
  vector_minus();
  vector_times_scalar();
  vector_scalar_product();
  vector_cross_product();

}
