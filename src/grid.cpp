#include <main.h>

#include <grid.h>

vertex::vertex(double ax, double ay, double az) {

  x=ax; y=ay; z=az;

}

bool vertex::operator ==(vertex &other) {

  return (dequal(x,other.x) && dequal(y,other.y) && dequal(z,other.z));

}

int vertex::in_edge(edge *e) {

  return e->contains(this);

}

edge::edge(vertex *v1, vertex *v2) {

  vertices[0] = v1;
  vertices[1] = v2;
  my_vertices=0;

  setVertices(v1,v2);

  if(*v1 == *v2) throw new string("Points for edge are identical.");

  bodies = nullptr;
  faces  = nullptr;

}

edge::edge(double ax, double ay, double az, double bx, double by, double bz) {

  vertices[0] = new vertex();
  vertices[1] = new vertex();
  my_vertices= 1;

  setVertices(ax,ay,az,bx,by,bz);

  if(*vertices[0] == *vertices[1]) throw new string("Points for edge are identical.");

  bodies = nullptr;
  faces  = nullptr;

}

void edge::setVertices(double ax, double ay, double az, double bx, double by, double bz) {

  vertices[0]->x = ax;
  vertices[0]->y = ay;
  vertices[0]->z = az;

  vertices[1]->x = bx;
  vertices[1]->y = by;
  vertices[1]->z = bz;

  length = sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay) + (bz-az)*(bz-az));

}

double edge::getLength() {

  return length;

}

int edge::contains(vertex *v) {

  edge v_to_v0(vertices[0], v);

  double sp = scalarp(this, &v_to_v0);

  return dequal(sp, v_to_v0.getLength() * length);

}

edge::~edge() {

  delete[] bodies;
  delete[] faces;

  if(my_vertices) {
    delete vertices[0];
    delete vertices[1];
  }

}

double scalarp(edge *e1, edge *e2) {

  return (e1->vertices[1]->x - e1->vertices[0]->x) * (e2->vertices[1]->x - e2->vertices[0]->x) +
         (e1->vertices[1]->y - e1->vertices[0]->y) * (e2->vertices[1]->y - e2->vertices[0]->y) +
         (e1->vertices[1]->z - e1->vertices[0]->z) * (e2->vertices[1]->z - e2->vertices[0]->z);

}

face::face(double ax, double ay, double az, double bx, double by, double bz, double cx, double cy, double cz) {

}

face::face(edge a, edge b, edge c) {



}

face::~face() {

}
