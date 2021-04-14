#include <iostream>

#include "../include/vectorclave.h"
#include "../include/funcionexploracion.h"
#include "../include/funciondispersion.h"
#include "../include/tablahash.h"

template <class Clave>
TablaHash<Clave>::TablaHash(unsigned nDatos, FuncionDispersion<Clave>* fd, unsigned nSinonimos, FuncionExploracion<Clave>* fe)
  : nDatos_(nDatos), fd_(fd), fe_(fe) {
  vDatos_ = new Vector<Clave>*[nDatos_];
  for (unsigned i = 0; i < nDatos_; i++)
    vDatos_[i] = new Vector<Clave>(nSinonimos);
}

template <class Clave>
TablaHash<Clave>::~TablaHash() {
  for (unsigned i = 0; i < nDatos_; i++)
    delete vDatos_[i];
  delete[] vDatos_;
}

template <class Clave>
unsigned TablaHash<Clave>::get_nDatos(void) const {
  return nDatos_;
}


template <class Clave>
Vector<Clave>** TablaHash<Clave>::get_vDatos(void) const {
  return vDatos_;
}


template <class Clave>
FuncionDispersion<Clave>* TablaHash<Clave>::get_fd(void) const {
  return fd_;
}


template <class Clave>
bool TablaHash<Clave>::Buscar(const Clave& X) const {
  if ((*vDatos_[(*fd_)(X)]).Buscar(X)) {
    return true;
  } else {
    unsigned i = 0; 
    while (i < nDatos_) {
      if ((*vDatos_[((*fd_)(X) + (*fe_)(X, i)) % nDatos_]).Buscar(X))
        return true;
      i++;
    }
  }
  return false;
}


template <class Clave>
bool TablaHash<Clave>::Insertar(const Clave& X) {  // inserta dos veces el mismo elemento y siempre hace la lineal
  if (Buscar(X))
    return false;
  if ((*vDatos_[(*fd_)(X)]).Insertar(X)) {
    return true;
  } else {
    unsigned i = 0; 
    while (i < nDatos_) {
      if ((*vDatos_[((*fd_)(X) + (*fe_)(X, i)) % nDatos_]).Insertar(X))
        return true;
      i++;
    }
  }
  return false;
}



// Declaración explicita de instanciación de template class
template class TablaHash<int>;