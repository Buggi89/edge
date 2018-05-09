#include <main.h>

#include <grid.h>
#include <field.h>
#include <polynomial.h>
#include <vector.h>
#include <utils.h>

int main() {

    monomial mo4(3,2.5,2,1,1);
    monomial mo5(2,4.0,2,2);
    monomial mo6 = mo4 * mo5;

    cout << mo6.value_at(2.5,3.0,-1.0) << "\n";

    monomial mo1(0,1.0);       // 1
    monomial mo2(1,2.0,1);     // 2x
    polynomial p1 = mo1 + mo2; // 1 + 2x
    cout << p1.value_at(2.5) << "\n";

    monomial mo3(2,4.0,1,2);   // 4xy^2
    polynomial p2 = p1 + mo3;  // 1 + 2x + 4xy^2
    cout << p2.value_at(2.5,3.0);

}
