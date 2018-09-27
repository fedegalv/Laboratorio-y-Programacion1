
typedef struct
{
    int id;
    char nombre[51];
    int duracion;
    char profesor[51];
}eCursos;

void inicializarCursos(eCursos []);
void mostrarCursos(eCursos);
void mostrarTodosLosCursos(eCursos[], int );
