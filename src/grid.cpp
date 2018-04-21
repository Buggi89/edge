#include <main.h>

#include <grid.h>

vertex::vertex(double ax, double ay, double az) {

  x=ax; y=ay; z=az;

}

bool vertex::operator ==(vertex &other) {

  return (dequal(x,other.x) && dequal(y,other.y) && dequal(z,other.z));

}

edge::edge(double ax, double ay, double az, double bx, double by, double bz) {

  setVertices(ax,ay,az,bx,by,bz);

  if(vertices[0] == vertices[1]) throw new string("Points for edge are identical.");

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

int edge::contains(vertex *v) {

  double sp = (vertices[1].x-vertices[0].x)*(v->x-vertices[0].x)+
              (vertices[1].y-vertices[0].y)*(v->y-vertices[0].y)+
              (vertices[1].z-vertices[0].z)*(v->z-vertices[0].z);

  edge v_to_v0(*v, vertices[0]);

  return dequal(sp, v_to_v0.getLength() * length);

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
