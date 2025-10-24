#include <iostream>

#include "SparseMatrix.h"
using namespace std;

void RellenarMatriz(SparseMatrix* Mx, int x, int y, int n) {
    for (int i = 1; i < x+1; i++) {
        for (int j = 1; j < y+1; j++) {
            Mx -> add(i,j,1);
            n-=1;
            if (n==1) {
                break;
            }
        }
        if (n==1) {
            break;
        }
    }
    Mx ->add(x,y,1);
}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    int Aux = -1;
    int Aux2 = -1;
    int x;
    int y;
    int n;
    SparseMatrix* M;
    SparseMatrix* M2;
    SparseMatrix* A = new SparseMatrix();
    SparseMatrix* B = new SparseMatrix();
    SparseMatrix* C = new SparseMatrix();


    while ( Aux2 != 8) {

        cout << "Menú Matrices dinamicas" << endl;
        cout << "1-Rellenar Matriz" << endl;
        cout << "2-Agregar Dato" << endl;
        cout << "3-Eliminar Dato" << endl;
        cout << "4-Mostrar Dato" << endl;
        cout << "5-Mostrar Matriz" << endl;
        cout << "6-Consultar Densidad" << endl;
        cout << "7-Multiply" << endl;
        cout << "8-Salir" << endl;
        cin >> Aux2;

        switch (Aux2) {
            case 1:
                cout << "Rellenar Matriz" << endl;

                while (Aux != 1 && Aux != 2 && Aux != 3) {
                    cout << "Que matriz desea rellenar (1) A, (2) B, (3) C" << endl;
                    cin >> Aux;
                }
                if (Aux == 1) {M = A;}
                if (Aux == 2) {M = B;}
                if (Aux == 3) {M = C;}
                Aux = -1;
                cout << "Tamaño de la matriz en x" << endl;
                cin >> x;
                cout << "Tamaño de la Matriz en Y" << endl;
                cin >> y;
                cout << "Cantidad de datos en la matriz" << endl;
                cin >> n;
                RellenarMatriz(M,x,y,n);
                break;
            case 2:
                cout << "Agregar Dato" << endl;
                while (Aux != 1 && Aux != 2 && Aux != 3) {
                    cout << "en que matriz desea agregar dato (1) A, (2) B, (3) C" << endl;
                    cin >> Aux;
                }
                if (Aux == 1) {M = A;}
                if (Aux == 2) {M = B;}
                if (Aux == 3) {M = C;}
                Aux = -1;
                cout << "Cordenada en X:" << endl;
                cin >> x;
                cout << "Cordenada en Y:" << endl;
                cin >> y;
                cout << "Valor del dato" << endl;
                cin >> n;

                M -> add(x,y,n);
                break;
            case 3:
                cout << "Eliminar Dato" << endl;
                while (Aux != 1 && Aux != 2 && Aux != 3) {
                    cout << "En que matriz desea eliminar Dato (1) A, (2) B, (3) C" << endl;
                    cin >> Aux;
                }
                if (Aux == 1) {M = A;}
                if (Aux == 2) {M = B;}
                if (Aux == 3) {M = C;}
                Aux = -1;
                cout << "Cordenada en X:" << endl;
                cin >> x;
                cout << "Cordenada en Y:" << endl;
                cin >> y;
                M -> remove(x,y);
                break;
            case 4:
                cout << "Mostrar Dato" << endl;
                while (Aux != 1 && Aux != 2 && Aux != 3) {
                    cout << "De que matriz desea mostrar dato(1) A, (2) B, (3) C" << endl;
                    cin >> Aux;
                }
                if (Aux == 1) {M = A;}
                if (Aux == 2) {M = B;}
                if (Aux == 3) {M = C;}
                Aux = -1;
                cout << "Cordenada en X:" << endl;
                cin >> x;
                cout << "Cordenada en Y:" << endl;
                cin >> y;
                cout << M -> get(x,y) << endl;
                break;
            case 5:
                cout << "Mostrar Matriz" << endl;
                while (Aux != 1 && Aux != 2 && Aux != 3) {
                    cout << "Que matriz desea mostrar (1) A, (2) B, (3) C" << endl;
                    cin >> Aux;
                }
                if (Aux == 1) {M = A;}
                if (Aux == 2) {M = B;}
                if (Aux == 3) {M = C;}
                Aux = -1;
                M -> printStoredValues();
                break;
            case 6:
                cout << "Consultar Densidad" << endl;
                while (Aux != 1 && Aux != 2 && Aux != 3) {
                    cout << "Que matriz desea consultar densidad (1) A, (2) B, (3) C" << endl;
                    cin >> Aux;
                }
                if (Aux == 1) {M = A;}
                if (Aux == 2) {M = B;}
                if (Aux == 3) {M = C;}
                Aux = -1;
                cout << M -> density() << endl;
                break;
            case 7:
                cout << "Multiply" << endl;
                while (Aux != 1 && Aux != 2 && Aux != 3) {
                    cout << "Matriz 1 para multiplicar (1) A, (2) B, (3) C" << endl;
                    cin >> Aux;
                }
                if (Aux == 1) {M = A;}
                if (Aux == 2) {M = B;}
                if (Aux == 3) {M = C;}
                Aux = -1;

                while (Aux != 1 && Aux != 2 && Aux != 3) {
                    cout << "Matriz 2 para multiplicar (1) A, (2) B, (3) C" << endl;
                    cin >> Aux;
                }
                if (Aux == 1) {M2 = A;}
                if (Aux == 2) {M2 = B;}
                if (Aux == 3) {M2 = C;}
                Aux = -1;

                SparseMatrix* M3 = M2 -> multiply(*M2);
                M3-> printStoredValues();
                break;
        }



    }


    return 0;
}

