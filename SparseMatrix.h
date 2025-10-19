#pragma once
#include "Nodo.h"

class SparseMatrix {
private:
    Nodo* head;
    int numFilas;
    int numColumnas;

    Nodo* crearNodo(int f, int c, double v = 0);
    double cantNodos() const;
    bool existe(int fila, int columna);

public:

    SparseMatrix();
    ~SparseMatrix();

    // Funciones principales
    void add(int fila, int columna, double valor);
    double get(int fila, int columna);
    void remove(int fila, int columna);
    void printValues() const;
    double density() const;
    SparseMatrix* multiply(const SparseMatrix& otra);
};