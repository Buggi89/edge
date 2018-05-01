#include <main.h>

#include <vector.h>
#include <grid.h>

vector::vector(double ax, double ay, double az) {

  x = ax; y = ay; z = az;

}

vector::vector(vertex *v1, vertex *v2) {

  x = v2->x - v1->x;
  y = v2->y - v1->y;
  z = v2->z - v1->z;

}

vector::vector(edge *e) {

  x = e->vertices[1]->x - e->vertices[0]->x;
  y = e->vertices[1]->y - e->vertices[0]->y;
  z = e->vertices[1]->z - e->vertices[0]->z;

}

vector vector::operator +(const vector &v2) {

  vector result;

  result.x = x + v2.x;
  result.y = y + v2.y;
  result.z = z + v2.z;

  return result;

}

vector vector::operator -(const vector &v2) {

  vector result;

  result.x = x - v2.x;
  result.y = y - v2.y;
  result.z = z - v2.z;

  return result;

}

vector operator *(const double &a, const vector &vec) {

  vector result;

  result.x = a*vec.x;
  result.y = a*vec.y;
  result.z = a*vec.z;

  return result;

}

double vector::operator ^(const vector &v2) {

  return x*v2.x + y*v2.y + z*v2.z;

}

vector vector::operator %(const vector &v2) {

  vector result;

  result.x = y*v2.z - z*v2.y;
  result.y = z*v2.x - x*v2.z;
  result.z = x*v2.y - y*v2.x;

  return result;

}
