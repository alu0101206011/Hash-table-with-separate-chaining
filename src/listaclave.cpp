#include <iostream>
#include <list>

#include "../include/listaclave.h"

template <class Clave>
Lista<Clave>::Lista(void) {}


template <class Clave>
std::list<Clave> Lista<Clave>::get_lista(void) const {
  return lista_;
}


template <class Clave>
bool Lista<Clave>::Buscar(const Clave& elemento) const {
  for (const Clave& elemento_lista : lista_)
    if (elemento == elemento_lista)
      return true;
  return false;
}


template <class Clave>
bool Lista<Clave>::Insertar(const Clave& elemento) {  // Al ser de dispersión abierta, no tiene limite
  if (!Buscar(elemento)) {
    lista_.push_back(elemento);
    return true;
  } else {
    return false;
  }
}


// Declaración explicita de instanciación de template class
template class Lista<int>;