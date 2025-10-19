//
// Created by CriX on 14-10-2025.
//

#pragma once

class Nodo {

private:

    int fila;
    int columna;
    double valor;
    Nodo* derecha;
    Nodo* abajo;
    Nodo* izquierda;
    Nodo* arriba;

public :
    Nodo(int f, int c, double v);
    ~Nodo();

    int getFila() const;
    int getColumna() const;
    int getValor() const;
    Nodo* getDerecha() const;
    Nodo* getAbajo() const;
    Nodo* getIzquierda() const;
    Nodo* getArriba() const;

    void setValor(int v);
    void setAbajo(Nodo* sig);
    void setDerecha(Nodo* sig);
    void setIzquierda(Nodo* sig);
    void setArriba(Nodo* sig);
};