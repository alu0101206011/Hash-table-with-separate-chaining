#include <list>

#include "../include/listaclave.h"

template <class Clave>
Lista<Clave>::Lista(void) {}


template <class Clave>
bool Lista<Clave>::Buscar(const Clave& elemento) const {
  // BUSCAR element DENTRO DE lista_
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