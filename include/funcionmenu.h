void Usage(int argc, char *argv[]);

void cabecera(void);

// Creación de tabla
TablaHash<int> crear_tabla(void);
// Creación función dispersion
FuncionDispersion<int>* crear_fd(int size);

void probar_insertar(TablaHash<int>& tabla, int numero);
void probar_buscar(TablaHash<int>& tabla, int numero);

// Errores int
int control_errores_int(void);

void presione_una_tecla(void);