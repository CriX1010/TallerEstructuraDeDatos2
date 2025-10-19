//
// Created by CriX on 14-10-2025.
//

#pragma once

struct Nodo {

    int fila;
    int columna;
    double valor;
    Nodo* derecha;
    Nodo* abajo;

    Nodo(int f, int c, double v);

    int getFila() const;
    int getColumna() const;
    double getValor() const;
    Nodo* getSiguiente() const;

    void setValor(double v);
    void setAbajo(Nodo* sig);
    void setDerecha(Nodo* sig);
};