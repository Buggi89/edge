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

void vertex_in_edge() {

  edge e(1.0,1.0,0.0,2.0,2.0,0.0);
  vertex v1(1.5,1.5,0.0);
  assert_equal(v1.in_edge(&e), 1, "Vertex in edge");

  vertex v2(1.0,0.5,0.0);
  assert_equal(v2.in_edge(&e), 0, "Vertex not in edge");

}

void edge_init_fail() {

  assert_fail_message(edge cut(1.0,1.0,0.0,1.0,1.0,0.0), "Points for edge are identical.", "Edge initialisation fails");

}

void edge_init_success() {

  edge cut(1.0,1.0,0.0,4.0,5.0,0.0);
  assert_equal(cut.getLength(), 5.0, "Length of the edge");

  vertex v1(1.0,1.0,0.0);
  vertex v2(4.0,5.0,0.0);
  edge cut2(&v1,&v2);
  assert_equal(cut2.getLength(), 5.0, "Length of the edge");

}

void edge_scalar_product() {

  edge e1(1.0,1.0,0.0,1.0,2.0,0.0);
  edge e2(1.0,1.0,0.0,2.0,1.0,0.0);
  assert_equal(scalarp(&e1,&e2), 0.0, "Scalar product of edges 1");

  edge e3(1.0,1.0,0.0,1.0,1.5,0.0);
  assert_equal(scalarp(&e1,&e3), 0.5, "Scalar product of edges 2");

  edge e4(3.0,1.5,3.0,2.0,9.5,4.0);
  edge e5(1.0,1.0,0.0,6.0,2.5,4.0);
  assert_equal(scalarp(&e4,&e5), 11.0, "Scalar product of edges 3");

}

void edge_contains() {

  edge e(1.0,1.0,0.0,2.0,2.0,0.0);
  vertex v1(1.5,1.5,0.0);
  assert_equal(e.contains(&v1), 1, "Edge does contain vertex");

  vertex v2(1.0,0.5,0.0);
  assert_equal(e.contains(&v2), 0, "Edge doesnt contain vertex");

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
  vertex_in_edge();
  cout << "Testing class edge: \n";
  edge_init_fail();
  edge_init_success();
  edge_setVertices();
  edge_scalar_product();
  edge_contains();
  cout << "Testing class face: \n";
  face_init();

}
