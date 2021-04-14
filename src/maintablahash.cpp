/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Algoritmos y Estructuras de Datos avanzadas
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @date 10 April 2021
/// @brief Programa de tabla hash de dispersión cerrada.
///
///
/// To compile: make
/// To clean files: make clean
/// To debug: make debug

#include <iostream>

#include "../include/vectorclave.h"
#include "../include/funciondispersion.h"
#include "../include/funcionexploracion.h"
#include "../include/tablahash.h"
#include "../include/funcionmenu.h"


int main(int argc, char *argv[]) {
  Usage(argc, argv);
  int option = 0, num = 0;
  cabecera();
  TablaHash<int> tabla = crear_tabla();
  do {
    cabecera();
    std::cout << "\nBienvenido al menú de la tabla Hash.\n";
    std::cout << "\t1.- Visualizar tabla.\n"
              << "\t2.- Insertar elemento.\n"
              << "\t3.- Buscar elemento.\n"
              << "\t0.- Para salir.\n"
              << "\t\tElija una opción: ";   
    option = control_errores_int(); 
    switch (option) {
    case 1:
      std::cout << std::endl << tabla;
      presione_una_tecla();
      break;
    case 2:
      std::cout << "Inserte un número: ";
      num = control_errores_int();
      probar_insertar(tabla, num);
      presione_una_tecla();
      break;
    case 3:
      std::cout << "Inserte un número: ";
      num = control_errores_int();
      probar_buscar(tabla, num);
      presione_una_tecla();
      break;   
    case 0: break;
    default:
      std::cout << "\n\t\tOpción no válida.\n";
      presione_una_tecla();
      break;
    }
  } while (option != 0);

  

  return 0;
}


