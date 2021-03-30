template <class Clave>
class fdModulo: public FuncionDispersion<Clave> {
 private:
  unsigned nDatos_;
 public:
  fdModulo(const unsigned);
  unsigned operator()(const Clave&) const;
};