#ifndef GRID_H
#define GRID_H

class vertex;
class edge;
class face;
class body;
class grid;
class vector;

class vertex {

  public:
    double x,y,z;

    vertex() {}
    ~vertex() {}
    vertex(double ax) : vertex(ax,0.0,0.0) {}
    vertex(double ax,double ay) : vertex(ax,ay,0.0) {}
    vertex(double,double,double);

    bool operator==(const vertex &other);
    vertex operator+(const vector &vec);

    int in_edge(class edge*);

  private:
    class edge *edges;
    class face *faces;
    class body *bodies;

    friend void addVertexToEdge(vertex*, edge*);

};

class edge {

  public:
    edge() : edge(0.0,0.0,0.0,1.0,0.0,0.0) {}
    ~edge();
    edge(vertex *a, vertex *b);
    edge(double ax, double bx) : edge(ax,0.0,0.0,bx,0.0,0.0) {}
    edge(double ax, double ay, double bx, double by) : edge(ax,ay,0.0,bx,by,0.0) {}
    edge(double, double, double, double, double, double);
    void setVertices(vertex *a, vertex *b) { setVertices(a->x,a->y,a->z,b->x,b->y,b->z); }
    void setVertices(double ax, double bx) { setVertices(ax,0.0,0.0,bx,0.0,0.0); }
    void setVertices(double ax, double ay, double bx, double by) { setVertices(ax,ay,0.0,bx,by,0.0); }
    void setVertices(double, double, double, double, double, double);
    double getLength();

    int contains(vertex*);

  private:
    int my_vertices;
    vertex *vertices[2];
    double length;
    class face *faces;
    class body *bodies;

    void cleanup();

  friend class vector;
  friend void addEdgeToFace(edge*, face*);

};

class face {

  public:
    face(vertex*, vertex*, vertex*);
    face(edge*, edge*, edge*);
    face(double ax, double ay, double bx, double by, double cx, double cy) : face(ax,ay,0.0,bx,by,0.0,cx,cy,0.0) {}
    face(double, double, double, double, double, double, double, double, double);
    ~face();
    void setVertices(vertex *a, vertex *b, vertex *c) { setVertices(a->x,a->y,a->z,b->x,b->y,b->z,c->x,c->y,c->z); }
    void setVertices(double ax, double ay, double bx, double by, double cx, double cy) { setVertices(ax,ay,0.0,bx,by,0.0,cx,cy,0.0); }
    void setVertices(double, double, double, double, double, double, double, double, double);
    void setEdges(edge, edge, edge);
    double getArea();
    double distToCircumcenter(vertex *a);

  private:
    int my_vertices;
    int my_edges;
    vertex *vertices[3];
    vertex circumcenter;
    edge *edges[3];
    double area;
    class body *bodies;

    void cleanup();

    friend void addEdgeToFace(edge*, face*);
    friend void addFaceToBody(face*, body*);
};

class body {

};

class grid {
  
  public:

    enum Symmetry {
      NSYM     =0,
      XSYM     =1,
      YSYM     =2,
      ZSYM     =4,
      XYSYM    =3,
      XZSYM    =5,
      YZSYM    =6,
      XYZSYM   =7,
      XCARTOON =8,
      YCARTOON =9,
      ZCARTOON =10,
      XYCARTOON=11,
      XZCARTOON=12,
      YZCARTOON=13
    };

};

double scalarp(edge*, edge*);
edge crossp(edge*, edge*);

void addEdgeToFace(edge*, face*);
void addFaceToBody(face*, body*);


#endif // GRID_H
