#include <iostream>
#include <set>

#include "../include/vectorclave.h"
#include "../include/funciondispersion.h"
#include "../include/funcionexploracion.h"
#include "../include/tablahash.h"
#include "../include/funcionmenu.h"


void Usage(int argc, char *argv[]) {
  if (argc == 2)
    if((std::string)argv[1] == "-h" || (std::string)argv[1] == "--help") {
      std::cout << "Uso: " << argv[0] << " [Sin opciones]\n";
      exit(0);
    }
  if (argc != 1) {
    std::cout << "Tiene argumentos inválidos.\nEscriba "
              << "--help para más ayuda\n";
    exit(1);
  } 
}


void cabecera(void) {
  system("clear");
  std::cout << "----------------------------------"
            << "\n|                                |\n"
            << "|           Tabla Hash           |"
            << "\n|                                |\n"
            << "----------------------------------\n\n";
}


TablaHash<int> crear_tabla(void) {
  std::cout << "Creación de tabla.\n";
  std::cout << "\tIntroduzca el tamaño de la tabla: ";
  int size = 0;
  while (size == 0) {
    size = control_errores_int();
    if (size <= 0) {
      size = 0; 
      std::cout << "Tamaño no válido. Introduzca otro tamaño: ";
    }
  }
  FuncionDispersion<int>* fd = crear_fd(size);
  FuncionExploracion<int>* fe = crear_fe(size, fd);
  TablaHash<int> tabla(size, fd, size - 1, fe);
  std::cout << "¡Tabla creada!\n";
  presione_una_tecla();
  return tabla;
}


FuncionDispersion<int>* crear_fd(int size) {
  int option = 0;
  FuncionDispersion<int>* fd;
  do {
    std::cout << "\n\t1.- Función de dispersión modulo.\n"
              << "\t2.- Función de dispersión pseudoaleatoria.\n";
    std::cout << "\n\t\tIntroduzca la función de dispersión que desee: ";
    option = control_errores_int();
    switch (option) {
    case 1:
      fd = new fdModulo<int>((unsigned)size);
      break;
    case 2:
      fd = new fdPseudoAleatoria<int>((unsigned)size);
      break;    
    default:
      std::cout << "\n\t\tFunción de dispersión no válida, introduzca un valor de 1 al 2.\n";
      option = 0;
      break;
    }
  } while (option == 0);
  return fd;
}


FuncionExploracion<int>* crear_fe(int size, FuncionDispersion<int>* fd) {
  int option = 0;
  FuncionExploracion<int>* fe;
  do {
    std::cout << "\n\t1.- Función de exploración lineal.\n"
              << "\t2.- Función de exploración cuadrática.\n"
              << "\t3.- Función de exploración de dispersion doble\n"
              << "\t4.- Función de exploración de redispersion\n";
    std::cout << "\n\t\tIntroduzca la función de dispersión que desee: ";
    option = control_errores_int();
    switch (option) {
    case 1:
      fe = new feLineal<int>();
      break;
    case 2:
      fe = new feCuadratica<int>();
      break;    
    case 3:
      fe = new feDispersionDoble<int>(size, fd->which_dispersion());
      break;    
    case 4:
      fe = new feReDispersion<int>(size);
      break;    
    default:
      std::cout << "\n\t\tFunción de exploración no válida, introduzca un valor de 1 al 2.\n";
      option = 0;
      break;
    }
  } while (option == 0);
  return fe;
}


void probar_insertar(TablaHash<int>& tabla, int numero) {
  if (tabla.Insertar(numero)) {
    std::cout << "Se ha insertado un " << numero << ".\n";
  } else {
    std::cout << "No se ha podido insertar un " << numero << ".\n";
  }
}


void probar_buscar(TablaHash<int>& tabla, int numero) {
  if (tabla.Buscar(numero)) {
    std::cout << "Se ha encontrado un " << numero << ".\n";
  } else {
    std::cout << "No se ha encontrado un " << numero << ".\n";
  }
}


int control_errores_int(void) {
  std::string param;
  std::cin >> param;
  do {
    if (!isdigit(param[0])) {
      if (param[0] == '-' && param.length() > 1) {
        if (isdigit(param[1])) {
          break;
        }
      } else {
        std::cout << "\nSe ha introducido una opción no válida\n";
        std::cout << "Introduzca la opción otra vez: ";
        std::cin >> param;
      }
    }
  } while (!isdigit(param[0]));
  int number = stoi(param);
  return number;
}


void presione_una_tecla(void) {
  std::cout << "\n\n\tPresione enter para continuar.\n";
  std::cin.ignore();
  std::cin.get();
}