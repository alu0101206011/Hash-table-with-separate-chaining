
template <class Clave>
class TablaHash {
 private:
  unsigned nDatos_;
  Vector<Clave>** vDatos_;
  FuncionDispersion<Clave>* fd_;
  FuncionExploracion<Clave>* fe_;
  
 public:
  TablaHash(unsigned, FuncionDispersion<Clave>*, unsigned, FuncionExploracion<Clave>*);
  ~TablaHash();

  unsigned get_nDatos(void) const;
  Vector<Clave>** get_vDatos(void) const;
  FuncionDispersion<Clave>* get_fd(void) const;

  bool Buscar(const Clave& X) const;
  bool Insertar(const Clave& X);

  friend std::ostream& operator<<(std::ostream& os, const TablaHash<Clave>& kTabla) {
    os << "-----------------------------------------\n";
    for (unsigned i = 0; i < kTabla.get_nDatos(); i++) {
      os << "Contenedor número " << i << ": ";
      os << *(kTabla.get_vDatos()[i]) << "\n";
    }
    os << "-----------------------------------------\n\n";
    return os;
  }
};