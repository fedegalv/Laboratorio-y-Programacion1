

typedef struct
{
    float promedio;
    int legajo;
    char nombre[35];
    int edad;

} sAlumno;

/** \brief
 *
 * \param sAlumno
 * \return void
 *
 */
void mostrarUnAlumno(sAlumno);
sAlumno pedirAlumno();

void cargarListadoDeAlumnos(sAlumno[], int);
void mostrarListadoDeAlumnos(sAlumno[], int);
void ordenarListadoDeAlumnosPorNombre(sAlumno[], int);

