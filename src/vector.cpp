#include <main.h>

#include <vector.h>

vector::vector(double ax, double ay, double az) {

  x = ax; y = ay; z = az;

}

double vector::operator *(const vector &v2) {

  return x*v2.x + y*v2.y + z*v2.z;

}

vector vector::operator %(const vector &v2) {

  vector result;

  result.x = y*v2.z - z*v2.y;
  result.y = z*v2.x - x*v2.z;
  result.z = x*v2.y - y*v2.x;

  return result;

}
