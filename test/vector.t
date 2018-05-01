#include <main.h>
#include <test.h>

#include <vector.h>

void vector_plus() {

  vector v1( 1.2,4.5, 9.6);
  vector v2(-0.8,2.6,-4.5);
  vector v3 = v1+v2;

  assert_equal(v3.x, 0.4, "Vector plus - x", EPSILON);
  assert_equal(v3.y, 7.1, "Vector plus - y", EPSILON);
  assert_equal(v3.z, 5.1, "Vector plus - z", EPSILON);
}

void vector_minus() {

  vector v1( 1.2,4.5, 9.6);
  vector v2(-0.8,2.6,-4.5);
  vector v3 = v1-v2;

  assert_equal(v3.x, 2.0, "Vector minus - x", EPSILON);
  assert_equal(v3.y, 1.9, "Vector minus - y", EPSILON);
  assert_equal(v3.z,14.1, "Vector minus - z", EPSILON);

}

void vector_times_scalar() {

  vector v1( 1.2,4.5, 9.6);
  vector v2 = 2.5*v1;

  assert_equal(v2.x, 3.0 , "Vector scalar multiplication - x", EPSILON);
  assert_equal(v2.y,11.25, "Vector scalar multiplication - y", EPSILON);
  assert_equal(v2.z,24.0,  "Vector scalar multiplication - z", EPSILON);

  vector v3 = v1*2.5;

  assert_equal(v3.x, 3.0 , "Vector scalar multiplication - x", EPSILON);
  assert_equal(v3.y,11.25, "Vector scalar multiplication - y", EPSILON);
  assert_equal(v3.z,24.0,  "Vector scalar multiplication - z", EPSILON);

}

void vector_scalar_product() {

  vector v1(1.0,0.0,0.0);
  vector v2(0.0,1.0,0.0);

  assert_equal(v1^v2, 0.0, "Simple scalar product", EPSILON);

  vector v4( 1.2,4.5, 9.6);
  vector v5(-0.8,2.6,-4.5);

  assert_equal(v4^v5, -32.46, "Complex scalar product", EPSILON);

}

void vector_cross_product() {

  vector v1(1.0,0.0,0.0);
  vector v2(0.0,1.0,0.0);
  vector v3 = v1%v2;

  assert_equal(v3.x, 0.0, "Simple cross product x", EPSILON);
  assert_equal(v3.y, 0.0, "Simple cross product y", EPSILON);
  assert_equal(v3.z, 1.0, "Simple cross product z", EPSILON);

  vector v4( 1.2,4.5, 9.6);
  vector v5(-0.8,2.6,-4.5);
  vector v6 = v4%v5;

  assert_equal(v6.x,-45.21, "Complex cross product x", EPSILON);
  assert_equal(v6.y, -2.28, "Complex cross product y", EPSILON);
  assert_equal(v6.z,  6.72, "Complex cross product z", EPSILON);

}

void vector_tests() {

  cout << "Testing class vector: \n";
  vector_plus();
  vector_minus();
  vector_times_scalar();
  vector_scalar_product();
  vector_cross_product();

}
