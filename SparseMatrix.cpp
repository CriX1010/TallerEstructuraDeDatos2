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

    Nodo* colPtr = filaPtr-> getDerecha();
    while (colPtr != filaPtr) {
        Nodo* tmp = colPtr;
        colPtr = colPtr-> getDerecha();
        delete tmp;
    }
    filaPtr = filaPtr-> getAbajo();
    while (filaPtr != head) {
        colPtr = filaPtr->getDerecha();
        while (colPtr != filaPtr) {
            Nodo* tmp = colPtr;
            colPtr = colPtr->getDerecha();
            delete tmp;
        }
        Nodo* tmpFila = filaPtr;
        filaPtr = filaPtr->getAbajo();
        delete tmpFila;
    }
    delete head;
}

Nodo* SparseMatrix::crearNodo(int f, int c, double v) {
    return new Nodo(f, c, v);
}
void SparseMatrix::optimizar() {
    Nodo* filaPtr = head -> getArriba();
    Nodo* colPtr = head -> getIzquierda();
    while (filaPtr-> getDerecha() == filaPtr) {
        Nodo* PtrAux = filaPtr -> getArriba();
        PtrAux->setAbajo(filaPtr -> getAbajo());
        filaPtr ->getAbajo()->setArriba(PtrAux);
        filaPtr = PtrAux;
        numFilas-=1;
    }
    while (colPtr-> getAbajo() == colPtr) {
        Nodo* PtrAux = colPtr->getIzquierda();
        PtrAux->setDerecha(colPtr -> getDerecha());
        colPtr ->getDerecha()->setIzquierda(PtrAux);
        delete colPtr;
        colPtr = PtrAux;
        numColumnas-=1;
    }
}


double SparseMatrix::cantNodos()  const{
    double cont = 0;
    Nodo* filaPtr = head->getAbajo();
    while (filaPtr != head) {
        Nodo* colPtr = filaPtr->getDerecha();
        while (colPtr != filaPtr) {
            cont++;
            colPtr = colPtr->getDerecha();
        }
        filaPtr = filaPtr->getAbajo();
    }
    return cont;
}
bool SparseMatrix::existe(int fila,int columna) {

    if (fila > numFilas || columna > numColumnas || fila < 0 || columna < 0) {
        return false;
    }
    Nodo* AuxPtr = head->getAbajo();
    while (AuxPtr->getFila() != fila) {
        AuxPtr = AuxPtr->getAbajo();
    }

    Nodo* temp = AuxPtr;
    AuxPtr = AuxPtr->getDerecha();
    while (AuxPtr->getColumna() != columna && AuxPtr != temp) {
        AuxPtr = AuxPtr->getDerecha();
    }

    if (AuxPtr == temp) {return false;}
    else {return true;}

}

void SparseMatrix::add(int fila, int columna, double valor) {

    Nodo* filaPtr = head -> getAbajo();
    Nodo* colPtr = head -> getDerecha();

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
            if (filaPtr->getAbajo() == head) {
                filaPtr-> setAbajo(new Nodo(filaPtr->getFila() +1 , filaPtr->getColumna(), 0));
                filaPtr-> getAbajo()-> setAbajo(head);
                filaPtr-> getAbajo()-> setArriba(filaPtr);
                numFilas++;
            } else {
                filaPtr = filaPtr->getAbajo();
            }
        }
    }
    if (columna > numColumnas) {
        while (columna > numColumnas) {
            if (colPtr->getDerecha() == head) {
                colPtr->setDerecha(new Nodo(colPtr->getFila(), colPtr->getColumna() +1 , 0));
                colPtr->getDerecha()->setDerecha(head);
                colPtr->getDerecha()->setIzquierda(colPtr);
                numColumnas++;
            } else {
                colPtr = colPtr->getDerecha();
            }
        }
    }

    Nodo* nuevo = crearNodo(fila, columna, valor);

    filaPtr = head;
    while (filaPtr->getFila() != fila) {
        filaPtr = filaPtr->getAbajo();
    }
    colPtr = head;
    while (colPtr->getColumna() != columna) {
        colPtr = colPtr->getDerecha();
    }

    Nodo* temp = filaPtr;
    while (filaPtr->getDerecha()->getColumna() < columna && filaPtr->getDerecha() != temp) {
        filaPtr = filaPtr->getDerecha();
    }
    Nodo* temp2 = filaPtr->getDerecha();
    filaPtr->setDerecha(nuevo);
    filaPtr->getDerecha()->setDerecha(temp2);
    filaPtr->getDerecha()->setIzquierda(filaPtr);

    temp = colPtr;
    while (colPtr->getAbajo()->getFila() < fila && colPtr->getAbajo() != temp) {
        colPtr = colPtr->getAbajo();
    }
    temp2 = colPtr->getAbajo();
    colPtr->setAbajo(nuevo);
    colPtr->getAbajo()->setAbajo(temp2);
    colPtr->getAbajo()->setArriba(colPtr);

}

// ---------------------- Get ----------------------
int SparseMatrix::get(int fila, int columna) {

    if (fila > numFilas || columna > numColumnas || fila < 0 || columna < 0) {
        cout << "El valor esta fuera de rango" << endl;
    }
    Nodo* AuxPtr = head->getAbajo();
    while (AuxPtr->getFila() != fila) {
        AuxPtr = AuxPtr->getAbajo();
    }

    Nodo* temp = AuxPtr;
    AuxPtr = AuxPtr->getDerecha();
    while (AuxPtr->getColumna() != columna && AuxPtr != temp) {
        AuxPtr = AuxPtr->getDerecha();
    }

    return AuxPtr->getValor();
}
// ---------------------- Remove ----------------------
void SparseMatrix::remove(int fila, int columna) {

    if (fila > numFilas || columna > numColumnas || fila < 0 || columna < 0) {
        cout << "El valor esta fuera de rango" << endl;
        return;
    }

    Nodo* filaPtr = head->getAbajo();
    Nodo* colPtr = head->getDerecha();

    while (filaPtr->getFila() != fila) {
        filaPtr = filaPtr->getAbajo();
    }
    while (colPtr->getColumna() != columna) {
        colPtr = colPtr->getDerecha();
    }

    Nodo* temp = filaPtr;
    while (filaPtr->getDerecha()->getColumna() != columna && filaPtr->getDerecha() != temp) {
        filaPtr = filaPtr->getDerecha();
    }
    if (filaPtr->getDerecha() == temp) {
        return;
    }
    temp = filaPtr->getDerecha();

    while (colPtr->getAbajo() != temp) {
        colPtr = colPtr->getAbajo();
    }

    filaPtr->setDerecha(temp -> getDerecha());
    colPtr->setAbajo(temp -> getAbajo());
    temp->getDerecha() ->setIzquierda(filaPtr);
    temp->getAbajo() ->setArriba(colPtr);
    delete temp;

    optimizar();

}

void SparseMatrix::printValues() const {
    Nodo* filaPtr = head->getAbajo();
    while (filaPtr != head) {
        Nodo* colPtr = filaPtr->getDerecha();
        while (colPtr != filaPtr) {
            cout << "(" << colPtr->getFila() << "," << colPtr->getColumna() << ") = " << colPtr->getValor() << "\n";
            colPtr = colPtr->getDerecha();
        }
        filaPtr = filaPtr->getAbajo();
    }
}

double SparseMatrix::density() const{
    return cantNodos() / (numFilas * numColumnas);
}

SparseMatrix* SparseMatrix::multiply(const SparseMatrix& otra) {

    Nodo* filaPtr = otra.head->getAbajo();
    Nodo* colPtr = this -> head->getDerecha();

    while (this-> numColumnas > otra.numFilas) {
        if (filaPtr->getAbajo() == head) {
            filaPtr-> setAbajo(new Nodo(filaPtr->getFila() +1 , filaPtr->getColumna(), 0));
            filaPtr-> getAbajo()-> setAbajo(head);
            filaPtr-> getAbajo()-> setArriba(filaPtr);
            numFilas++;
        } else {
            filaPtr = filaPtr->getAbajo();
        }
    }


    while (this -> numColumnas < otra.numFilas) {
        if (colPtr->getDerecha() == head) {
            colPtr->setDerecha(new Nodo(colPtr->getFila(), colPtr->getColumna() +1 , 0));
            colPtr->getDerecha()->setDerecha(head);
            colPtr->getDerecha()->setIzquierda(colPtr);
            numColumnas++;
        } else {
            colPtr = colPtr->getDerecha();
        }
    }

    SparseMatrix* MatrizAux = new SparseMatrix();

    filaPtr = head->getAbajo();
    colPtr = otra.head->getDerecha();


    while (filaPtr != head) {
        while (colPtr != otra.head) {

            Nodo* temp = filaPtr;
            Nodo* temp2 = colPtr;

            filaPtr = filaPtr->getDerecha();
            colPtr = colPtr->getAbajo();

            int suma = 0;

            while (filaPtr != temp && colPtr != temp2) {

                if (filaPtr-> getColumna() == colPtr->getFila()) {
                    suma += filaPtr->getValor()  * colPtr->getValor();
                    filaPtr = filaPtr->getDerecha();
                    colPtr = colPtr->getAbajo();
                }
                else if (filaPtr-> getColumna() > colPtr->getFila()) {
                    colPtr = colPtr->getAbajo();
                }
                else if (filaPtr-> getColumna() < colPtr->getFila()) {
                    filaPtr = filaPtr->getDerecha();
                }
            }
            while (filaPtr != temp || colPtr != temp2) {
                if (filaPtr != temp) {
                    filaPtr = filaPtr->getDerecha();
                }
                if (colPtr != temp2) {
                    colPtr = colPtr->getAbajo();
                }
            }

            MatrizAux-> add(temp->getFila(),temp2->getColumna(),suma);

            colPtr = colPtr->getDerecha();
        }
        colPtr = colPtr->getDerecha();
        filaPtr = filaPtr->getAbajo();
    }

    optimizar();

    return MatrizAux;
}
