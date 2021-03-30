template <class Clave>
class TablaHash {
 private:
  unsigned nDatos_;
  Lista<Clave>* vDatos_;
  FuncionDispersion<Clave>* fd_;
  
 public:
  TablaHash(unsigned, FuncionDispersion<Clave>&);

  unsigned get_nDatos(void) const;
  Lista<Clave>* get_vDatos(void) const;
  FuncionDispersion<Clave>* get_fd(void) const;

  bool Buscar(Clave& X) const;
  bool Insertar(const Clave& X);
};