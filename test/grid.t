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
  assert_equal(cut.getLength(), 5.0, "Length of the edge", EPSILON);

  vertex v1(1.0,1.0,0.0);
  vertex v2(4.0,5.0,0.0);
  edge cut2(&v1,&v2);
  assert_equal(cut2.getLength(), 5.0, "Length of the edge", EPSILON);

}

void edge_scalar_product() {

  edge e1(1.0,1.0,0.0,1.0,2.0,0.0);
  edge e2(1.0,1.0,0.0,2.0,1.0,0.0);
  assert_equal(scalarp(&e1,&e2), 0.0, "Scalar product of edges 1", EPSILON);

  edge e3(1.0,1.0,0.0,1.0,1.5,0.0);
  assert_equal(scalarp(&e1,&e3), 0.5, "Scalar product of edges 2", EPSILON);

  edge e4(3.0,1.5,3.0,2.0,9.5,4.0);
  edge e5(1.0,1.0,0.0,6.0,2.5,4.0);
  assert_equal(scalarp(&e4,&e5), 11.0, "Scalar product of edges 3", EPSILON);

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
  assert_equal(cut.getLength(), 5.0, "Reset edge vertices", EPSILON);

}

void face_init() {

  vertex v1(1.0,1.0);
  vertex v2(2.0,1.0);
  vertex v3(1.0,2.0);

  face cut(&v1,&v2,&v3);
  assert_equal(cut.getArea(), 0.5, "Area of 2D face", EPSILON);

  vertex v7( 1.2,0.8,2.4);
  vertex v8(-7.6,2.3,8.4);
  vertex v9(-3.4,0.0,5.8);

  face cut3(&v7,&v8,&v9);
  assert_equal(cut3.getArea(), 8.62722435085584, "Area of complex face", EPSILON);

  vertex v4(1.0,1.0);
  vertex v5(2.0,2.0);
  vertex v6(-1.5,-1.5);

  assert_fail_message(face cut2(&v4,&v5,&v6), "Face has no area. Edges are collinear.", "Collinear points form no face");

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
