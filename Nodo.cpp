//
// Created by CriX on 14-10-2025.
//

#include "Nodo.h"
#pragma once

// Constructor
Nodo::Nodo(int f, int c, double v) {
        fila = f;
        columna = c;
        valor = v;
        abajo = this;
        derecha = this;
}

// Getters
int Nodo::getFila() const {
        return fila;
}

int Nodo::getColumna() const {
        return columna;
}

double Nodo::getValor() const {
        return valor;
}

// Setters
void Nodo::setValor(double v) {
        valor = v;
}

void Nodo::setAbajo(Nodo* sig) {
        abajo = sig;
}
void Nodo::setDerecha(Nodo* sig) {
        derecha = sig;
}