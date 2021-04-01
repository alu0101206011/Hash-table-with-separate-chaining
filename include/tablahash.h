template <class Clave> 
class TablaHash;

template <class Clave> 
std::ostream& operator<<(std::ostream&, const TablaHash<Clave>&);


template <class Clave>
class TablaHash {
 private:
  unsigned nDatos_;
  Lista<Clave>* vDatos_;
  FuncionDispersion<Clave>* fd_;
  
 public:
  TablaHash(unsigned, FuncionDispersion<Clave>*);
  ~TablaHash();

  unsigned get_nDatos(void) const;
  Lista<Clave>* get_vDatos(void) const;
  FuncionDispersion<Clave>* get_fd(void) const;

  bool Buscar(Clave& X) const;
  bool Insertar(const Clave& X);

  friend std::ostream& operator<<(std::ostream& os, const TablaHash<Clave>& kTabla) {
    os << "-----------------------------------------\n";
    for (unsigned i = 0; i < kTabla.get_nDatos(); i++) {
      os << "Contenedor número " << i << ": ";
      os << kTabla.get_vDatos()[i] << "\n";
    }
    os << "-----------------------------------------\n\n";
    return os;
  }
};