#include <main.h>

#include <grid.h>

vertex::vertex(double ax, double ay, double az) {

  x=ax; y=ay; z=az;

}

bool vertex::operator ==(vertex &other) {

  return (fabs(x - other.x) + fabs(y - other.y) + fabs(z - other.z) <
          (fabs(x)+fabs(other.x)+fabs(y)+fabs(other.y)+fabs(z)+fabs(other.z))*1.e-14 / 6.0);

}

edge::edge(double ax, double ay, double az, double bx, double by, double bz) {

  setVertices(ax,ay,az,bx,by,bz);

  bodies = nullptr;
  faces  = nullptr;

}

void edge::setVertices(double ax, double ay, double az, double bx, double by, double bz) {

  vertices[0].x = ax;
  vertices[0].y = ay;
  vertices[0].z = az;

  vertices[1].x = bx;
  vertices[1].y = by;
  vertices[1].z = bz;

  length = sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay) + (bz-az)*(bz-az));

}

double edge::getLength() {

    return length;

}

edge::~edge() {

  delete[] bodies;
  delete[] faces;

}

face::face(double ax, double ay, double az, double bx, double by, double bz, double cx, double cy, double cz) {

}

face::face(edge a, edge b, edge c) {



}

face::~face() {

}
