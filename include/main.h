#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <math.h>
#include <cstddef>
#include <stdexcept>
#include <stdlib.h>

using namespace std;

#define EPSILON 1.e-14
#define dequal(a,b) (fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * EPSILON))

#endif // MAIN_H
