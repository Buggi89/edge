#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <math.h>
#include <cstddef>
#include <stdexcept>
#include <stdlib.h>
#include <sstream>
#include <typeinfo>

using namespace std;

#define EPSILON 1.e-14
#define  dequal(a,b)      (fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * EPSILON))
#define dpequal(a,b,prec) (fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * prec))
#define imax(a,b) ((a>b)?a:b)

#endif // MAIN_H
