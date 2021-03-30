template <class Clave>
class Lista {
 private:
  std::list<Clave> lista_;
 public:
  Lista(void);

  bool Buscar(const Clave&) const;
  bool Insertar(const Clave&);
};