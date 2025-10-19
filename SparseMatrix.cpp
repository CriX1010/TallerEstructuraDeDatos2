#include "SparseMatrix.h"
#include <iostream>

using namespace std;


SparseMatrix::SparseMatrix() {
    head = new Nodo(0, 0, 0);
    numColumnas = 0;
    numFilas = 0;
}
SparseMatrix::~SparseMatrix() {
    Nodo* filaPtr = head;

    Nodo* colPtr = filaPtr->derecha;
    while (colPtr != filaPtr) {
        Nodo* tmp = colPtr;
        colPtr = colPtr->derecha;
        delete tmp;
    }
    Nodo* tmpFila = filaPtr;
    if (filaPtr != filaPtr->abajo) {
        filaPtr = filaPtr->abajo;
        delete tmpFila;
    } else {
        delete filaPtr;
        return;
    }

    while (filaPtr != head) {
        colPtr = filaPtr->derecha;
        while (colPtr != filaPtr) {
            Nodo* tmp = colPtr;
            colPtr = colPtr->derecha;
            delete tmp;
        }
        tmpFila = filaPtr;
        filaPtr = filaPtr->abajo;
        delete tmpFila;
    }
    delete head;
}

Nodo* SparseMatrix::crearNodo(int f, int c, double v) {
    return new Nodo(f, c, v);
}
double SparseMatrix::cantNodos()  const{
    double cont = 0;
    Nodo* filaPtr = head->abajo;
    while (filaPtr != head) {
        Nodo* colPtr = filaPtr->derecha;
        while (colPtr != filaPtr) {
            cont++;
            colPtr = colPtr->derecha;
        }
        filaPtr = filaPtr->abajo;
    }
    return cont;
}
bool SparseMatrix::existe(int fila,int columna) {

    if (fila > numFilas || columna > numColumnas || fila < 0 || columna < 0) {
        return false;
    }
    Nodo* AuxPtr = head->abajo;
    while (AuxPtr->fila != fila) {
        AuxPtr = AuxPtr->abajo;
    }

    Nodo* temp = AuxPtr;
    AuxPtr = AuxPtr->derecha;
    while (AuxPtr->columna != columna && AuxPtr != temp) {
        AuxPtr = AuxPtr->derecha;
    }

    if (AuxPtr == temp) {return false;}
    else {return true;}

}

void SparseMatrix::add(int fila, int columna, double valor) {

    Nodo* filaPtr = head -> abajo;
    Nodo* colPtr = head -> derecha;

    if (existe(fila,columna)) {
        cout << "Posición ya utilizada.\n";
        return;
    }

    if (fila < 0 || columna < 0) {
        cout << "Posición fuera de rango.\n";
        return;
    }

    // Crear Nodos Auxiliares de posicion
    if (fila > numFilas) {
        while (fila > numFilas) {
            if (filaPtr->abajo == head) {
                filaPtr->abajo = new Nodo(filaPtr->fila +1 , filaPtr->columna, 0);
                filaPtr->abajo->abajo = head;
                numFilas++;
            } else {
                filaPtr = filaPtr->abajo;
            }
        }
    }
    if (columna > numColumnas) {
        while (columna > numColumnas) {
            if (colPtr->derecha == head) {
                colPtr->derecha = new Nodo(colPtr->fila, colPtr->columna +1 , 0);
                colPtr->derecha->derecha = head;
                numColumnas++;
            } else {
                colPtr = colPtr->derecha;
            }
        }
    }

    Nodo* nuevo = crearNodo(fila, columna, valor);

    filaPtr = head;
    while (filaPtr->fila != fila) {
        filaPtr = filaPtr->abajo;
    }
    colPtr = head;
    while (colPtr->columna != columna) {
        colPtr = colPtr->derecha;
    }

    Nodo* temp = filaPtr;
    while (filaPtr->derecha->columna < columna && filaPtr->derecha != temp) {
        filaPtr = filaPtr->derecha;
    }
    Nodo* temp2 = filaPtr->derecha;
    filaPtr->derecha = nuevo;
    filaPtr->derecha->derecha = temp2;

    temp = colPtr;
    while (colPtr->abajo->fila < fila && colPtr->abajo != temp) {
        colPtr = colPtr->abajo;
    }
    temp2 = colPtr->abajo;
    colPtr->abajo = nuevo;
    colPtr->abajo->abajo = temp2;

}

// ---------------------- Get ----------------------
double SparseMatrix::get(int fila, int columna) {

    if (fila > numFilas || columna > numColumnas || fila < 0 || columna < 0) {
        cout << "El valor esta fuera de rango" << endl;
    }
    Nodo* AuxPtr = head->abajo;
    while (AuxPtr->fila != fila) {
        AuxPtr = AuxPtr->abajo;
    }

    Nodo* temp = AuxPtr;
    AuxPtr = AuxPtr->derecha;
    while (AuxPtr->columna != columna && AuxPtr != temp) {
        AuxPtr = AuxPtr->derecha;
    }

    return AuxPtr->valor;
}
// ---------------------- Remove ----------------------
void SparseMatrix::remove(int fila, int columna) {

    if (fila > numFilas || columna > numColumnas || fila < 0 || columna < 0) {
        cout << "El valor esta fuera de rango" << endl;
        return;
    }

    Nodo* filaPtr = head->abajo;
    Nodo* colPtr = head->derecha;

    while (filaPtr->fila != fila) {
        filaPtr = filaPtr->abajo;
    }
    while (colPtr->columna != columna) {
        colPtr = colPtr->derecha;
    }

    Nodo* temp = filaPtr;
    while (filaPtr->derecha->columna != columna && filaPtr->derecha != temp) {
        filaPtr = filaPtr->derecha;
    }
    if (filaPtr->derecha == temp) {
        return;
    }
    temp = filaPtr->derecha;

    while (colPtr->abajo != temp) {
        colPtr = colPtr->abajo;
    }

    filaPtr->derecha = temp ->derecha;
    colPtr->abajo = temp->abajo;
    delete temp;

    while (filaPtr-> derecha == filaPtr) {
        Nodo* PtrAux = head->abajo;
        while (PtrAux->abajo != filaPtr) {
            PtrAux = PtrAux->abajo;
        }
        PtrAux->abajo = filaPtr->abajo;
        delete filaPtr;
        filaPtr = PtrAux;
        numFilas-=1;
    }

    while (colPtr-> abajo == colPtr) {
        Nodo* PtrAux = head->derecha;
        while (PtrAux->derecha != colPtr) {
            PtrAux = PtrAux->derecha;
        }
        PtrAux->derecha = colPtr->derecha;
        delete colPtr;
        colPtr = PtrAux;
        numColumnas-=1;
    }

}

void SparseMatrix::printValues() const {
    Nodo* filaPtr = head->abajo;
    while (filaPtr != head) {
        Nodo* colPtr = filaPtr->derecha;
        while (colPtr != filaPtr) {
            cout << "(" << colPtr->fila << "," << colPtr->columna << ") = " << colPtr->valor << "\n";
            colPtr = colPtr->derecha;
        }
        filaPtr = filaPtr->abajo;
    }
}

double SparseMatrix::density() const{
    return cantNodos() / (numFilas * numColumnas);
}

SparseMatrix* SparseMatrix::multiply(const SparseMatrix& otra) {

    if (this->numColumnas != otra.numFilas) {
        cout << "Estas matrices son incompatibles para multiplicar" << endl;
        return nullptr;
    }

    SparseMatrix* MatrizAux = new SparseMatrix();

    Nodo* filaPtr = head->abajo;
    Nodo* colPtr = otra.head->derecha;

    while (filaPtr != head) {
        while (colPtr != otra.head) {

            Nodo* temp = filaPtr;
            Nodo* temp2 = colPtr;

            filaPtr = filaPtr->derecha;
            colPtr = colPtr->abajo;

            int suma = 0;

            while (filaPtr != temp && colPtr != temp2) {

                if (filaPtr-> columna == colPtr->fila) {
                    suma += filaPtr->valor * colPtr->valor;
                    filaPtr = filaPtr->derecha;
                    colPtr = colPtr->abajo;
                }
                else if (filaPtr-> columna > colPtr->fila) {
                    colPtr = colPtr->abajo;
                }
                else if (filaPtr-> columna < colPtr->fila) {
                    filaPtr = filaPtr->derecha;
                }
            }
            while (filaPtr != temp || colPtr != temp2) {
                if (filaPtr != temp) {
                    filaPtr = filaPtr->derecha;
                }
                if (colPtr != temp2) {
                    colPtr = colPtr->abajo;
                }
            }

            MatrizAux-> add(temp->fila,temp2->columna,suma);

            colPtr = colPtr->derecha;
        }
        colPtr = colPtr->derecha;
        filaPtr = filaPtr->abajo;
    }

    return MatrizAux;
}
