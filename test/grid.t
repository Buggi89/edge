#include <main.h>
#include <test.h>

#include <grid.h>

void vertex_compare();
void edge_init();
void edge_setVertices();
void face_init();

void grid_tests() {
  
  cout << "Testing class vertex: \n";
  vertex_compare();
  cout << "Testing class edge: \n";
  edge_init();
  edge_setVertices();
  cout << "Testing class face: \n";
  face_init();

}

void vertex_compare() {

  vertex cut1(1.0,2.0,3.524);
  vertex cut2(1.0,2.0,3.524);

  assert_equal(cut1==cut2, 1, "Vertices are equal");
  cut1.z = 3.523;
  assert_equal(cut1==cut2, 0, "Vertices are almost equal");
  cut2.z = 3.523+3.e-15;
  assert_equal(cut1==cut2, 1, "Vertices are equal within precision");

}

void edge_init() {

  edge cut(1.0,1.0,0.0,4.0,5.0,0.0);
  assert_equal(cut.getLength(), 5.0, "Length of the edge",1e-15);

}

void edge_setVertices() {

  edge cut(1.0,1.0,1.0,2.0,2.0,2.0);
  cut.setVertices(1.0,1.0,0.0,4.0,5.0,0.0);
  assert_equal(cut.getLength(), 5.0, "Reset edge vertices",1e-15);

}

void face_init() {

  vertex v1(1.0,1.0);
  vertex v2(2.0,1.0);
  vertex v3(1.0,2.0);

  //face cut(v1,v2,v3);

}
