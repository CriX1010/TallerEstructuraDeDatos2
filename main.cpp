#include <iostream>

#include "SparseMatrix.h"
using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    SparseMatrix Mx;
    SparseMatrix Mx2;

    Mx.add(1,1,1);
    Mx.add(1,2,2);
    Mx.add(1,3,3);
    Mx.add(2,1,4);
    Mx.add(2,2,5);
    Mx.add(2,3,6);
    Mx.add(3,1,7);
    Mx.add(3,2,8);
    Mx.add(3,3,9);

    Mx2.add(1,1,3);
    Mx2.add(1,2,2);
    Mx2.add(1,3,1);
    Mx2.add(2,1,4);
    Mx2.add(2,3,8);
    Mx2.add(3,2,7);
    Mx2.add(3,3,9);

    Mx.remove(1,3);
    Mx.remove(2,2);
    Mx.remove(3,1);

    Mx2.remove(1,2);
    Mx2.remove(2,3);
    Mx2.remove(3,1);

    Mx.remove(3,2);
    Mx.remove(3,3);

    Mx2.remove(1,3);
    Mx2.remove(3,3);

    SparseMatrix* Mx3 = Mx.multiply(Mx2);

    Mx3->printValues();

    delete Mx3;
    delete &Mx;
    delete &Mx2;

    return 0;
}