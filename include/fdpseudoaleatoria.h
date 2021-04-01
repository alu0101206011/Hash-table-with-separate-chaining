template <class Clave>
class fdPseudoAleatoria: public FuncionDispersion<Clave> {
 private:
  unsigned nDatos_;
 public:
  fdPseudoAleatoria(const unsigned);
  unsigned operator()(const Clave&) const;
};