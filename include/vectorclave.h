template <class Clave> class Vector;
template <class Clave> std::ostream& operator<<(std::ostream&, const Vector<Clave>&);

template <class Clave>
class Vector {
 private:
  Clave* vector_;
  unsigned nSinonimos_;
 public:
  Vector(void);
  Vector(unsigned);
  Vector(const Vector<Clave>&);

  ~Vector();

  Clave* get_vector(void) const;
  unsigned get_nSinonimos(void) const;

  bool Buscar(const Clave&) const;
  bool Insertar(const Clave&);
  bool empty(void) const;
  bool estaLlena(void) const;

  Vector<Clave>& operator=(const Vector<Clave>&);
  Clave& operator[](const unsigned&);
  Clave operator[](const unsigned&) const;


  friend std::ostream& operator<<(std::ostream& os, const Vector<Clave>& kVector) {
    if (kVector[0] != 0) {
      os << kVector[0];
    } else {
      os << "-";
    }
    for (unsigned i = 1; i < kVector.get_nSinonimos(); i++) {
      os << " | ";
      if (kVector[i] != 0) {
        os << kVector[i];
      } else {
        os << "-";
      }
    }
    return os;
  }
};