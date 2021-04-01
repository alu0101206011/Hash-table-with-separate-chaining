template <class Clave> class Lista;
template <class Clave> std::ostream& operator<<(std::ostream&, const Lista<Clave>&);

template <class Clave>
class Lista {
 private:
  std::list<Clave> lista_;
 public:
  Lista(void);

  std::list<Clave> get_lista(void) const;

  bool Buscar(const Clave&) const;
  bool Insertar(const Clave&);

  friend std::ostream& operator<<(std::ostream& os, const Lista<Clave>& kLista) {
    if (!kLista.get_lista().empty()) {
      os << kLista.get_lista().front();
    } else {
      os << "NULL";
    }
    for (const Clave& elemento_lista : kLista.get_lista()) {
      if (kLista.get_lista().front() != elemento_lista)
        os << " | " << elemento_lista;
    }
    return os;
  }
};