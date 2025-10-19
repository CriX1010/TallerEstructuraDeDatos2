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
        izquierda = this;
        arriba = this;
}

int Nodo::getColumna() const {
        return columna;
}
int Nodo::getFila() const {
        return fila;
}
int Nodo::getValor() const {
        return valor;
}

Nodo *Nodo::getAbajo() const {
        return abajo;
}
Nodo *Nodo::getIzquierda() const {
        return izquierda;
}
Nodo *Nodo::getDerecha() const {
       return derecha;
}
Nodo *Nodo::getArriba() const {
        return arriba;
}

void Nodo::setValor(int v) {
        valor = v;
}

void Nodo::setAbajo(Nodo *sig) {
        abajo = sig;
}
void Nodo::setIzquierda(Nodo *sig) {
        izquierda = sig;
}
void Nodo::setDerecha(Nodo *sig){
        derecha = sig;
}
void Nodo::setArriba(Nodo *sig) {
        arriba = sig;
}

Nodo::~Nodo() = default;
