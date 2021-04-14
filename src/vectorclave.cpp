#include <iostream>

#include "../include/vectorclave.h"

template <class Clave>
Vector<Clave>::Vector(void): nSinonimos_(0) { 
  vector_ = 0;
}

template <class Clave>
Vector<Clave>::Vector(unsigned nSinonimos): nSinonimos_(nSinonimos) {
  vector_ = new Clave[nSinonimos_];
}

template <class Clave> 
Vector<Clave>::Vector(const Vector<Clave>& kNewVector) {
  nSinonimos_ = kNewVector.get_nSinonimos();
  vector_ = new Clave[nSinonimos_];
  for (unsigned i = 0; i < nSinonimos_; i++) {
    (*this)[i] = kNewVector[i];
  }  
}

template <class Clave> 
Vector<Clave>::~Vector() {
  delete[] vector_;
}

template <class Clave> 
Vector<Clave>& Vector<Clave>::operator=(const Vector<Clave>& kNewVector) {
  delete[] vector_;
  nSinonimos_ = kNewVector.get_nSinonimos();
  vector_ = new Clave[nSinonimos_];
  for (unsigned i = 0; i < nSinonimos_; i++) {
    (*this)[i] = kNewVector[i];
  }  
  return *this;
}

template <class Clave> 
Clave& Vector<Clave>::operator[](const unsigned& i) {
  if (i < 0 || i >= nSinonimos_) {
    std::cout << "Vector fuera de rango.\n";
    exit(1);
  } else {
    return vector_[i];
  }
}

template <class Clave> 
Clave Vector<Clave>::operator[](const unsigned& i) const {
  if (i < 0 || i >= nSinonimos_) {
    std::cout << "Vector fuera de rango.\n";
    exit(1);
  } else {
    return vector_[i];
  }
}

template <class Clave>
Clave* Vector<Clave>::get_vector(void) const {
  return vector_;
}


template <class Clave>
unsigned Vector<Clave>::get_nSinonimos(void) const {
  return nSinonimos_;
}


template <class Clave>
bool Vector<Clave>::Buscar(const Clave& elemento) const {
  for (unsigned i = 0; i < nSinonimos_; i++)
    if ((*this)[i] == elemento)
      return true;
  return false;
}


template <class Clave>
bool Vector<Clave>::Insertar(const Clave& elemento) {
  if (Buscar(elemento))
    return false;
  for (unsigned i = 0; i < nSinonimos_; i++) 
    if ((*this)[i] == 0) {
      (*this)[i] = elemento;
      return true;
    }
  return false;
}


template <class Clave>
bool Vector<Clave>::empty(void) const {
  for (unsigned i = 0; i < nSinonimos_; i++) 
    if ((*this)[i] != 0)
      return false;
  return true;
}

template <class Clave>
bool Vector<Clave>::estaLlena(void) const {
  for (unsigned i = 0; i < nSinonimos_; i++) 
    if ((*this)[i] == 0)
      return false;
  return true;
}


// Declaración explicita de instanciación de template class
template class Vector<int>;