#include <main.h>
#include <test.h>

#include <grid.h>
#include <vector.h>

void vertex_compare() {

  vertex cut1(1.0,2.0,3.524);
  vertex cut2(1.0,2.0,3.524);

  assert_equal_i(cut1==cut2, 1, "Vertices are equal");
  cut1.z = 3.523;
  assert_equal_i(cut1==cut2, 0, "Vertices are almost equal");
  cut2.z = 3.523+3.e-15;
  assert_equal_i(cut1==cut2, 1, "Vertices are equal within precision");

}

void vertex_in_edge() {

  edge e(1.0,1.0,0.0,2.0,2.0,0.0);
  vertex v1(1.5,1.5,0.0);
  assert_equal_i(v1.in_edge(&e), 1, "Vertex in edge");

  vertex v2(1.0,0.5,0.0);
  assert_equal_i(v2.in_edge(&e), 0, "Vertex not in edge");

}

void vertex_plus_vector() {

  vertex v1(1.5,1.5,0.0);
  vector vec1(1.0,1.0,-4.0);

  vertex v2 = v1 + vec1;
  assert_equal_d(v2.x, 2.5, "Vertex + Vector x");
  assert_equal_d(v2.y, 2.5, "Vertex + Vector y");
  assert_equal_d(v2.z,-4.0, "Vertex + Vector z");

}

void edge_init_fail() {

  assert_fail_message(edge cut(1.0,1.0,0.0,1.0,1.0,0.0), "Points for edge are identical.", "Edge initialisation fails");

}

void edge_init_success() {

  edge cut(1.0,1.0,0.0,4.0,5.0,0.0);
  assert_equal_d(cut.getLength(), 5.0, "Length of the edge");

  vertex v1(1.0,1.0,0.0);
  vertex v2(4.0,5.0,0.0);
  edge cut2(&v1,&v2);
  assert_equal_d(cut2.getLength(), 5.0, "Length of the edge");

}

void edge_contains() {

  edge e(1.0,1.0,0.0,2.0,2.0,0.0);
  vertex v1(1.5,1.5,0.0);
  assert_equal_i(e.contains(&v1), 1, "Edge does contain vertex");

  vertex v2(1.0,0.5,0.0);
  assert_equal_i(e.contains(&v2), 0, "Edge doesnt contain vertex");

}

void edge_setVertices() {

  edge cut(1.0,1.0,1.0,2.0,2.0,2.0);
  cut.setVertices(1.0,1.0,0.0,4.0,5.0,0.0);
  assert_equal_d(cut.getLength(), 5.0, "Reset edge vertices");

}

void face_init() {

  vertex v1(1.0,1.0);
  vertex v2(2.0,1.0);
  vertex v3(1.0,2.0);

  face cut(&v1,&v2,&v3);
  assert_equal_d(cut.getArea(), 0.5, "Area of 2D face");

  vertex v7( 1.2,0.8,2.4);
  vertex v8(-7.6,2.3,8.4);
  vertex v9(-3.4,0.0,5.8);

  face cut2(&v7,&v8,&v9);
  assert_equal_d(cut2.getArea(), 8.62722435085584, "Area of complex face");

  double d1 = cut2.distToCircumcenter(&v7);
  double d2 = cut2.distToCircumcenter(&v8);
  double d3 = cut2.distToCircumcenter(&v9);

  assert_equal_d(d1,d2, "Circumcenter test 1-2");
  assert_equal_d(d1,d3, "Circumcenter test 1-3");

  vertex v4(1.0,1.0);
  vertex v5(2.0,2.0);
  vertex v6(-1.5,-1.5);

  assert_fail_message(face cut3(&v4,&v5,&v6), "Face has no area. Edges are collinear.", "Collinear points form no face");

}

void grid_tests() {

  cout << "Testing class vertex: \n";
  vertex_compare();
  vertex_plus_vector();
  vertex_in_edge();
  cout << "Testing class edge: \n";
  edge_init_fail();
  edge_init_success();
  edge_setVertices();
  edge_contains();
  cout << "Testing class face: \n";
  face_init();

}
