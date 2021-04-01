/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Algoritmos y Estructuras de Datos avanzadas
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @date 26 Jan 2021
/// @brief Programa que simule el comportamiento de la hormiga 
/// de Langton durante un número indefinido de pasos de tiempo
///
/// @see https://es.wikipedia.org/wiki/Hormiga_de_Langton
///
/// To compile: make
/// To clean files: make clean
/// To debug: make debug

#include <iostream>
#include <list>

#include "../include/listaclave.h"
#include "../include/funciondispersion.h"
#include "../include/fdmodulo.h"
#include "../include/fdpseudoaleatoria.h"
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


