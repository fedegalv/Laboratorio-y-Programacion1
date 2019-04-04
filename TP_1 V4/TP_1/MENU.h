/** \brief Menu en donde se selecciona la operacion a realizar, recibe dos variables del tipo float ya validados .
 *
 * \param float numeroA, variable que contiene primer numero ingresado por el usuario.
 * \param float numeroB, variable que contiene segundo numero ingresado por el usuario.
 * \return float devuelve una variable que contiene el resultado de la operacion realizada, esta se muestra al seleccionar la opcion de informar resultado en el menu correspondiente.
 *
 */
float menuOperaciones(float, float,char*,unsigned int*,unsigned int*);

/** \brief Funcion que al ser llamada muestra el resultado obtenido previamente en menuOperaciones.
 *
 * \param double se uso double especialmente por su mayor capacidad para guardar datos comparado a float , para almacenar un posible resultado de factorial y guardar posibles resultados en decimal resultantes de haber realizados una division
 * \return void no se retorna naada
 *
 */
void menuResultados(double,char*,int,int,unsigned int*,unsigned int*);
int ingresoNumero(char);

// JUNTAR LAS OPERACIONES Y LAS RESPUESTAS EN UN SOLO ARCHIVO, Y QUE LA FUNCION LLAMAR
