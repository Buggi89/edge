#ifndef VECTOR_H
#define VECTOR_H

class vertex;
class edge;

class vector {

  public:
    vector() : vector(1.0,0.0,0.0) {}
    vector(double ax) : vector(ax,0.0,0.0) {}
    vector(double ax, double ay) : vector(ax,ay,0.0) {}
    vector(double, double, double);
    vector(edge *e);
    vector(vertex *v1, vertex *v2);

    vector operator+(const vector&);
    vector operator-(const vector&);

    double x,y,z;

    friend vector operator *(const double&, const vector&);
    friend vector operator *(const vector &vec, const double &a) { return a*vec; }
    friend double dot(const vector&, const vector&);
    friend vector cross(const vector&, const vector&);
};

#endif // VECTOR_H

