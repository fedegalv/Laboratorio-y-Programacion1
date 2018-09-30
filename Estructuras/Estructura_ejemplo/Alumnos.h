
typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;
typedef struct // DECLARACION
{
    int legajo; // DECLARACION CAMPOS, ATRIBUTOS
    char nombre[50]; // CADENA DE CHAR
    float promedio;
    int estado;
    eFecha fechaDeNacimiento;

} eAlumno; // NOMBRE ESTRUCTURA

void mostrarAlumno(eAlumno);
eAlumno cargarAlumno();
void mostrarListado(eAlumno [],int );
int cargarAlumnoEnListado(eAlumno [], int );
void inicializarAlumnos(eAlumno [],int , int );
void inicializarAlumnosConDatos(eAlumno [],int );
int buscarEspacio(eAlumno[], int);
int borrarAlumno(eAlumno[], int);
int modificarAlumno(eAlumno[], int);
