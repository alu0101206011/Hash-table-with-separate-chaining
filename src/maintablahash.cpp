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


void Usage(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  Usage(argc, argv);

  return 0;
}


void Usage(int argc, char *argv[]) {
  if (argc == 2)
    if((std::string)argv[1] == "-h" || (std::string)argv[1] == "--help") {
      std::cout << "Uso: " << argv[0] << " [Sin opciones]\n";
      exit(0);
    }
  if (argc != 1) {
    std::cout << "Tiene argumentos invalidos.\nEscriba "
              << "--help para más ayuda\n";
    exit(1);
  } 
}