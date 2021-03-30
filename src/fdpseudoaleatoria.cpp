#include <random>

#include "../include/funciondispersion.h"
#include "../include/fdpseudoaleatoria.h"

template <class Clave>
fdPseudoAleatoria<Clave>::fdPseudoAleatoria(const unsigned n): nDatos_(n) {}


template <class Clave>
unsigned fdPseudoAleatoria<Clave>::operator()(const Clave& k) const {
  srand(2 * k - 1);
  return rand() % nDatos_;
}


// Declaración explicita de instanciación de template class
template class fdPseudoAleatoria<int>;