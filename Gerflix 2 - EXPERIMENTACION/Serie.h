
typedef struct
{
    int idSerie;
    char titulo[50];
    char genero[20];
    int temporadas;
    int estado;
}eSerie;

void inicializarSeriesEstado(eSerie[], int);
void inicializarSeriesHardCode(eSerie[]);
void mostrarListaSeries(eSerie[], int);



