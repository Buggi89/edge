#include <main.h>

#include <grid.h>
#include <vector.h>

vertex::vertex(double ax, double ay, double az) {

  x=ax; y=ay; z=az;

}

bool vertex::operator ==(const vertex &other) {

  return (dequal(x,other.x) && dequal(y,other.y) && dequal(z,other.z));

}

vertex vertex::operator +(const vector &vec) {

  vertex result;

  result.x = x + vec.x;
  result.y = y + vec.y;
  result.z = z + vec.z;

  return result;

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

  bodies = nullptr;
  faces  = nullptr;

  if(*vertices[0] == *vertices[1]) throw new string("Points for edge are identical.");

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

  vector v1(this);
  vector v2(vertices[0], v);

return dequal((v1^v2), sqrt(v2^v2) * length);

}

edge::~edge() {

  delete[] bodies;
  delete[] faces;

  if(my_vertices) {
    delete vertices[0];
    delete vertices[1];
  }

}

face::face(vertex *v1, vertex *v2, vertex *v3) {

  vertices[0] = v1;
  vertices[1] = v2;
  vertices[2] = v3;
  my_vertices = 0;

  edges[0] = new edge(v1,v2);
  edges[1] = new edge(v2,v3);
  edges[2] = new edge(v3,v1);
  my_edges = 1;

  vector vec1(v1,v2);
  vector vec2(v1,v3);
  vector vec3 = vec1%vec2;

//  circumcenter = v1 + circ_vec;

  area = 0.5 * sqrt(vec3^vec3);

  if(dequal(area,0.0)) throw new string("Face has no area. Edges are collinear.");

  bodies = nullptr;

}

face::face(edge *a, edge *b, edge *c) {

}

face::face(double ax, double ay, double az, double bx, double by, double bz, double cx, double cy, double cz) {

    vertices[0] = new vertex(ax,ay,az);
    vertices[1] = new vertex(bx,by,bz);
    vertices[2] = new vertex(cx,cy,cz);
    my_vertices = 1;

    vector vec1(vertices[0], vertices[1]);
    vector vec2(vertices[0], vertices[2]);
    vector vec3 = vec1%vec2;

    area = 0.5 * sqrt(vec3^vec3);

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

double face::distToCircumcenter(vertex *a) {

  vector vec1(a, &circumcenter);
  return sqrt(vec1^vec1);

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
