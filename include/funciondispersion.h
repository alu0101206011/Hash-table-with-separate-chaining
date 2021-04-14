#ifndef DISPERSION
#define DISPERSION

#include <random>

enum dispersiones {MODULO, PSEUDOALEATORIA};

template <class Clave> class FuncionDispersion;
template <class Clave> class fdModulo;
template <class Clave> class fdPseudoAleatoria;


// Clase abstracta
template <class Clave>
class FuncionDispersion {
 public:
  static FuncionDispersion<Clave>* createDispersion(unsigned nDatos, unsigned fdispersion) {
    switch (fdispersion) {
      case MODULO: return new fdModulo<Clave>(nDatos);
      case PSEUDOALEATORIA: return new fdPseudoAleatoria<Clave>(nDatos);
      default: return nullptr;
    }
  }
  virtual unsigned operator()(const Clave& k) const = 0;
  virtual unsigned which_dispersion(void) const = 0;
};


template <class Clave>
class fdModulo: public FuncionDispersion<Clave> {
 private:
  unsigned nDatos_;
 public:
  fdModulo(const unsigned n): nDatos_(n) {}
  unsigned operator()(const Clave& k) const {
    return k % nDatos_;
  }
  unsigned which_dispersion(void) const {
    return MODULO;
  }
};


template <class Clave>
class fdPseudoAleatoria: public FuncionDispersion<Clave> {
 private:
  unsigned nDatos_;
 public:
  fdPseudoAleatoria(const unsigned n): nDatos_(n) {}
  unsigned operator()(const Clave& k) const {
    srand(2 * k - 1);
    return rand() % nDatos_;
  }
  unsigned which_dispersion(void) const {
    return PSEUDOALEATORIA;
  }
};

#endif