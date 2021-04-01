#include <iostream>
#include <list>

#include "../include/listaclave.h"
#include "../include/funciondispersion.h"
#include "../include/tablahash.h"

template <class Clave>
TablaHash<Clave>::TablaHash(unsigned nDatos, FuncionDispersion<Clave>* fd)
  : nDatos_(nDatos), fd_(fd) {
  vDatos_ = new Lista<Clave>[nDatos_];
}

template <class Clave>
TablaHash<Clave>::~TablaHash() {
  delete[] vDatos_;
}

template <class Clave>
unsigned TablaHash<Clave>::get_nDatos(void) const {
  return nDatos_;
}


template <class Clave>
Lista<Clave>* TablaHash<Clave>::get_vDatos(void) const {
  return vDatos_;
}


template <class Clave>
FuncionDispersion<Clave>* TablaHash<Clave>::get_fd(void) const {
  return fd_;
}


template <class Clave>
bool TablaHash<Clave>::Buscar(Clave& X) const {
  return vDatos_[(*fd_)(X)].Buscar(X);  // Cuidado con esto que el hijo de Función dispersión puede tener otro nDatos porque se declara en el main.
}


template <class Clave>
bool TablaHash<Clave>::Insertar(const Clave& X) {
  if (!vDatos_[(*fd_)(X)].Buscar(X)) 
    return vDatos_[(*fd_)(X)].Insertar(X);
  return false;
}



// Declaración explicita de instanciación de template class
template class TablaHash<int>;