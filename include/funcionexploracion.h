#include "funciondispersion.h"

// clase abstracta
template<class Clave>
class FuncionExploracion {
 public:
  virtual unsigned operator()(const Clave& k, unsigned i) const = 0;
};


template<class Clave>
class feLineal: public FuncionExploracion<Clave> {
 public:
  unsigned operator()(const Clave& k, unsigned i) const {
    return i;
  }
};


template<class Clave>
class feCuadratica: public FuncionExploracion<Clave> {
 public:
  unsigned operator()(const Clave& k, unsigned i) const {
    return i * i;
  }
};


template<class Clave>
class feDispersionDoble : public FuncionExploracion<Clave> {
private:
  FuncionDispersion<Clave>* fdispersion_;
public:
  feDispersionDoble(int tam, int fdispersion = MODULO) {
    fdispersion_ = FuncionDispersion<Clave>::createDispersion(tam, fdispersion);
  }
  unsigned operator()(const Clave& k, unsigned i) const {
    return i * (*fdispersion_)(k);
  }
};


template <class Clave>
class feReDispersion : public FuncionExploracion<Clave> {
private:
  FuncionDispersion<Clave>* fdispersion_;
public:
  feReDispersion(int tam) {
    fdispersion_ = FuncionDispersion<Clave>::createDispersion(tam, PSEUDOALEATORIA);
  }
  unsigned operator()(const Clave& k, unsigned i) const { 
    return (*fdispersion_)(k * i);
  }
};