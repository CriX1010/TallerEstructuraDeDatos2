#include <iostream>

#include "SparseMatrix.h"
using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    SparseMatrix Mx;

    Mx.add(5,5,10);
    Mx.add(5,3,8);
    Mx.add(5,7,9);
    Mx.add(3,5,6);
    Mx.add(7,5,1);

    cout << Mx.get(5,5)<< endl;
    cout << Mx.get(5,3)<< endl;
    cout << Mx.get(5,7)<< endl;
    cout << Mx.get(3,5)<< endl;
    cout << Mx.get(7,5)<< endl;

    Mx.remove(5,5);

    cout << Mx.get(5,5)<< endl;
    cout << Mx.get(5,3)<< endl;
    cout << Mx.get(5,7)<< endl;
    cout << Mx.get(3,5)<< endl;
    cout << Mx.get(7,5)<< endl;

    return 0;
}