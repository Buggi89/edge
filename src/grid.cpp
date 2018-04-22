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

  length = sqrt((v2->x-v1->x)*(v2->x-v1->x) + (v2->y-v1->y)*(v2->y-v1->y) + (v2->z-v1->z)*(v2->z-v1->z));

  if(*v1 == *v2) throw new string("Points for edge are identical.");

  bodies = nullptr;
  faces  = nullptr;

}

edge::edge(double ax, double ay, double az, double bx, double by, double bz) {

  vertices[0] = new vertex(ax,ay,az);
  vertices[1] = new vertex(bx,by,bz);
  my_vertices= 1;

  length = sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay) + (bz-az)*(bz-az));

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

face::face(vertex *v1, vertex *v2, vertex *v3) {

  vertices[0] = v1;
  vertices[1] = v2;
  vertices[2] = v3;
  my_vertices = 0;

  double crx = (v2->y-v1->y)*(v3->z-v1->z) - (v2->z-v1->z)*(v3->y-v1->y);
  double cry = (v2->z-v1->z)*(v3->x-v1->x) - (v2->x-v1->x)*(v3->z-v1->z);
  double crz = (v2->x-v1->x)*(v3->y-v1->y) - (v2->y-v1->y)*(v3->x-v1->x);
  area = 0.5 * sqrt(crx*crx + cry*cry + crz*crz);

  edges[0] = new edge(v1,v2);
  edges[1] = new edge(v2,v3);
  edges[2] = new edge(v3,v1);
  my_edges = 1;

  if( dequal(area, 0.0) ) throw new string("Face has no area. Edges are collinear.");

  bodies = nullptr;

}

face::face(edge *a, edge *b, edge *c) {

}

face::face(double ax, double ay, double az, double bx, double by, double bz, double cx, double cy, double cz) {

    vertices[0] = new vertex(ax,ay,az);
    vertices[1] = new vertex(bx,by,bz);
    vertices[2] = new vertex(cx,cy,cz);
    my_vertices = 1;

    double crx = (by-ay)*(cz-az) - (bz-az)*(cy-ay);
    double cry = (bz-az)*(cx-ax) - (bx-ax)*(cz-az);
    double crz = (bx-ax)*(cy-ay) - (by-ay)*(cx-ax);
    area = 0.5 * sqrt(crx*crx + cry*cry + crz*crz);

    edges[0] = new edge(vertices[0],vertices[1]);
    edges[1] = new edge(vertices[1],vertices[2]);
    edges[2] = new edge(vertices[2],vertices[0]);
    my_edges = 1;

    if( dequal(area, 0.0) ) throw new string("Face has no area. Edges are collinear.");

    bodies = nullptr;

}

double face::getArea() {

  return area;

}

face::~face() {

  delete[] bodies;

  if(my_vertices) {
    delete vertices[0];
    delete vertices[1];
    delete vertices[2];
  }

  if(my_edges) {
    delete edges[0];
    delete edges[1];
    delete edges[2];
  }

}
