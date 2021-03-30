#include <list>

#include "../include/listaclave.h"
#include "../include/funciondispersion.h"
#include "../include/tablahash.h"

template <class Clave>
TablaHash<Clave>::TablaHash(unsigned nDatos, FuncionDispersion<Clave>& fd)
  : nDatos_(nDatos_), fd_(&fd) {
  vDatos_ = new Lista<Clave>[nDatos_];
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

}


template <class Clave>
bool TablaHash<Clave>::Insertar(const Clave& X) {

}


// Declaración explicita de instanciación de template class
template class TablaHash<int>;