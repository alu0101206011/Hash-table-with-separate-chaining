# Tabla Hash
Algoritmos y Estructuras de Datos Avanzadas.

Curso 2020-2021.

## Práctica 5: Tabla Hash con dispersión abierta
### Objetivo 
El objetivo de esta práctica es trabajar con los algoritmos de búsqueda y realizar la implementación en lenguaje C++ de la técnica de hashing con dispersión cerrada. Se utilizará la definición de tipos genéricos, el polimorfismo dinámico y la sobrecarga de operadores.


### Entrega
La entrega se realizará en la sesión de laboratorio entre el 12 y el 16 de abril. Durante esta sesión se podrán solicitar modificaciones sobre el enunciado de la práctica.

En el actual escenario de presencialidad adaptada, la entrega se realizará en tareas separadas para la rotación con asistencia presencial y la rotación con asistencia online. Si la ULL cambiase al escenario 2, docencia online, se comunicará la forma de entrega a través del aula virtual.


### Enunciado
Se pide desarrollar un tipo de dato genérico ``TablaHash<class Clave>`` para almacenar valores de tipo ``Clave`` utilizando la técnica de búsqueda por dispersión cerrada.

En esta técnica, al igual que la técnica de dispersión abierta implementada en la práctica anterior, se utiliza una función de dispersión para calcular la posición de la tabla en la cual corresponde almacenar cada valor de clave insertada; pero a diferencia de aquella, en la técnica de dispersión cerrada se establece un número máximo de valores de claves sinónimas que pueden almacenarse en cada posición de la tabla. A este número lo denominaremos ``nSinonimos`` y su valor se especificará como parámetro en el constructor de la tabla.

- Se necesita cambiar las listas por ``class Vector<Clave>`` la cual tenga un atributo ``std::set<Clave> vector_;``.

- Esta clase tiene un ``constructor`` para inicializar el objeto vacío un método bool para buscar una clave ``bool Buscar(Clave& X) const``.
- Insertar exactamente igual que antes.
- Método ``bool estaLleno () const`` que retorna ``true`` si el vector está lleno.
Si el vector está lleno hay que buscar un hueco libre para insertar el valor en otra posición de la tabla.
- Hacer clase ``FuncionExploración<Clave>`` igual que con las funciones de dispersión.

**CLASE BASE DE FUNCIONES DE EXPLORACIÓN**
```
template<class Clave>
class FuncionExploracion {
  public:
    unsigned operator()(const Clave& k, unsigned i) const = 0;
};
```
**CLASE FUNCIÓN LINEAL EJEMPLO**
```
template<class Clave>
class feLineal: public FuncionExploracion<Clave> {
  public:
    unsigned operator()(const Clave& k, unsigned i) const {
      return i;
    }
};
```

Se pide implementar 4 funciones de **exploración**: 
- exploración lineal: g(k, i) = i
- exploración cuadratica: g(k, i) = i^2
- doble dispersión: g(k, i) = f(k) * i
- Redispersión: g(k, i) = f^(i)(k)

g(k, i) = función de exploración.
k = valor de la Clave.
i = contador de desbordamientos o numero de intentos de exploración.

`` // Página 61 en los apuntes del tema 2 ``

`` // Van funcion a funcion a partir de la 72``

Al llegar al final de la tabla, se trata como una tabla circular y se reinicia la búsqueda por el principio.

Exploración cuadrática:
  - Si se produce un desbordamiento se se va incrementando donde buscas en i^2 (empiezas en 1 y vas sumando mientras la i sea menor que el numero de celdas). https://www.youtube.com/watch?v=e4DqU1sqHWQ (Minuto 3:24)

  - ESTO LO PONE EN LA PRÁCTICA:
  En la implementación de la función de exploración cuadrática sólo se tendrá en cuenta los desplazamiento positivos respecto a la posición inicial.


Exploración doble dispersión:
  En la función de exploración de dispersión doble, la función de dispersión f(k) utilizada para la exploración se pasará como parámetro en el constructor de la clase derivada. 

```
template<class Clave>
class FExploracionDispDoble : public FExploracionBase<Clave> {
private:
  FDispersionBase* fdispersion_;
  
public:
  FExploracionDoble(int t, int fdispersion = MODULO) : FExploracionBase<Clave>(tam) {
  fdispersion_ = FDispersionBase<Clave>::createDispersion(tam, fdispersion);
  }
  virtual int operator() (const Clave& x, int i) {
    return i * fdispersion_(x);
  }
};
```
Exploración Redispersión:
  Para la implementación de la estrategia de exploración de redispersión se utilizará el generador de números pseudo-aleatorios. Se inicializa la semilla del generador con el valor de la clave, y se utiliza el valor de la i-ésima llamada a rand() como el valor del desplazamiento f^(i)(k) respecto a la posición inicial.
  
```
template <class Clave>
class FExploracionReDisp : public FExploracionBase<Clave> {
private:
  FDispersionBase* fdispersion_;

public:
  FExploracionReDisp (int tam) : FExploracionBase<Clave>(tam) {
    fdispersion_ = FDispersionBase<Clave>::createDispersion(tam, PSEUDOALEATORIO);
  }
  virtual int operator() (const Clave& x, int i) {
    return fdispersion_(i * x);
  }
};
```

Para buscar un valor: 
  - Primero se busca normal en la dirección que le corresponde.
  - Si el valor no se encuentra en ningún registro de la celda y la celda no está llena pues no se encuentra el valor.
  - Si el valor no se encuentra y la lista está llena se busca según la estrategia de exploración (si era lineal pues en la siguiente celda...).


Para insertar un valor:

Por ejemplo, si estamos usando la exploración lineal.
    Se mete el valor en la posición definida por la función de dispersión. Si está llena la celda vas buscando celda por celda hasta encontrar un hueco libre.
    *La tabla se considera circular así que si llegas al final se vuelve al principio para seguir buscando hueco*


El programa principal pide el tamaño de la tabla como antes y ahora el del set. También pide la función dispersión y la de exploración. De resto, todo es prácticamente
igual que la anterior.


