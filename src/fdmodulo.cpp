#include "../include/funciondispersion.h"
#include "../include/fdmodulo.h"

template <class Clave>
fdModulo<Clave>::fdModulo(const unsigned n): nDatos_(n) {}


template <class Clave>
unsigned fdModulo<Clave>::operator()(const Clave& k) const {
return k % nDatos_;
}


// Declaración explicita de instanciación de template class
template class fdModulo<int>;