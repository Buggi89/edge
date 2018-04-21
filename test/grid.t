#include <main.h>
#include <test.h>

#include <grid.h>

void vertex_compare() {

  vertex cut1(1.0,2.0,3.524);
  vertex cut2(1.0,2.0,3.524);

  assert_equal(cut1==cut2, 1, "Vertices are equal");
  cut1.z = 3.523;
  assert_equal(cut1==cut2, 0, "Vertices are almost equal");
  cut2.z = 3.523+3.e-15;
  assert_equal(cut1==cut2, 1, "Vertices are equal within precision");

}

void edge_init_fail() {

  assert_fail_message(edge cut(1.0,1.0,0.0,1.0,1.0,0.0), "Points for edge are identical.", "Edge initialisation fails");

}

void edge_init_success() {

  edge cut(1.0,1.0,0.0,4.0,5.0,0.0);
  assert_equal(cut.getLength(), 5.0, "Length of the edge");

  vertex v1(1.0,1.0,0.0);
  vertex v2(4.0,5.0,0.0);
  edge cut2(v1,v2);
  assert_equal(cut2.getLength(), 5.0, "Length of the edge");

}

void edge_contains_point_yes() {

  edge e(1.0,1.0,0.0,2.0,2.0,0.0);
  vertex v(1.5,1.5,0.0);
  assert_equal(e.contains(&v), 1, "Edge does contain vertex");


}

void edge_contains_point_no() {

  edge e(1.0,1.0,0.0,2.0,2.0,0.0);
  vertex v(1.0,0.5,0.0);
  assert_equal(e.contains(&v), 0, "Edge doesnt contain vertex");

}

void edge_setVertices() {

  edge cut(1.0,1.0,1.0,2.0,2.0,2.0);
  cut.setVertices(1.0,1.0,0.0,4.0,5.0,0.0);
  assert_equal(cut.getLength(), 5.0, "Reset edge vertices");

}

void face_init() {

  vertex v1(1.0,1.0);
  vertex v2(2.0,1.0);
  vertex v3(1.0,2.0);

  //face cut(v1,v2,v3);

}

void grid_tests() {

  cout << "Testing class vertex: \n";
  vertex_compare();
  cout << "Testing class edge: \n";
  edge_init_fail();
  edge_init_success();
  edge_setVertices();
  edge_contains_point_no();
  edge_contains_point_yes();
  cout << "Testing class face: \n";
  face_init();

}
