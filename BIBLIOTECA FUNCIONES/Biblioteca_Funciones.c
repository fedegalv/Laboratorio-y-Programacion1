
void limpiarPantalla()
{
    system("pause"); // pausa el programa, para limpiar
    system("cls"); // se limpia la consola
}
float esFloat(char* floatNumber)
{
    int esFloat; // esFloat funcionara como booleano, para validar si el numero es valido o no, en caso que no sea valido se volvera a pedirlo
    float floatDevolver; // Numero a devolver
    char auxfloat[20];
    float validate;
    strcpy(auxfloat,floatNumber);
    do
    {
        //COMPROBACION DEL NUMERO INGRESADO
        validate= atof(auxfloat); // validate toma la conversion de atof
        if(validate<=0) // Si validate es menor o igual a 0, entonces atof no pudo convertir el string a float y devolvio 0, por lo tanto no es float
        {
            esFloat= 0;
            printf("No ingreso un numero valido. Reintentelo otra vez\n");
            printf("Ingrese salario del empleado: ");
            gets(auxfloat);
            fflush(stdin); // Limpiar el buffer de teclado
        }
        else
        {
            esFloat =1;
            floatDevolver = validate; // Variable que guarda el numero a retornar
            fflush(stdin); // Limpiar el buffer de teclado
        }
    }
    while(esFloat == 0); // Realizar el pedido mientras el numero no sea valido.

    return floatDevolver;

}

int ingresoNumero()
{
    int numero;
    int esNumero; // esNumero funcionara como booleano, para validar si el numero es valido o no, en caso que no sea valido se volvera a pedirlo
    int numeroDevolver; // Numero a devolver
    do
    {
        //COMPROBACION DEL NUMERO INGRESADO
        char aux;
        if(scanf("%d%c", &numero, &aux) != 2 || aux != '\n') // Comprueba si lo ingresado valido o no
        {
            esNumero= 0;
            printf("No ingreso un numero valido. Reintentelo otra vez\n");
            fflush(stdin); // Limpiar el buffer de teclado
        }
        else
        {
            esNumero =1;
            numeroDevolver = numero; // Variable que guarda el numero a retornar
            fflush(stdin); // Limpiar el buffer de teclado
        }
    }
    while(esNumero == 0); // Realizar el pedido mientras el numero no sea valido.

    return numeroDevolver;
}

int verificarCadena(char cadena[51])
{
    int largoCadena;
    int i;
    largoCadena= strlen(cadena); // SE TOMA EL LARGO DEL NOMBRE
    int banderaCadena=0; // BANDERA PARA MARCAR QUE SE ENCONTRO UN CARACTER NO ALFABETICO, INICIALIZADO EN 0
    do
    {

        fflush(stdin);
        for(i=0; i<largoCadena; i++) // RECORRE EL STRING
        {
            if( isalpha(cadena[i]) || isspace(cadena[i]) ) // isalpha DEVUELVE UN VALOR DISTINTO A CERO SI EL CARACTER ES ALFABETICO, SI NO 0
            {
                banderaCadena = 1; // banderaCadena MARCARA 1 SI ES QUE EL CARACTER ANALIZADO ES ALFABETICO
            }
            else
            {
                banderaCadena=0; // EN CASO DE ENCONTRAR UN CARACTER NO ALFABETICO , SE BAJA LA BANDERA
                break;
            }
        }
        if(banderaCadena== 0) // SI EN ALGUN MOMENTO LA BANDERA FUE BAJADA, O NUNCA FUE SUBIDA, SE PIDE QUE REINGRESE EL NOMBRE Y SE VERIFICARA EN EL PROXIMO LOOP
        {
            printf("INGRESO ALGUN CARACTER INVALIDO. Reingrese de manera correcta:");
            scanf("%[^\n]",cadena);
        }
        //banderaCadena= 0;
        largoCadena= strlen(cadena); // SE VUELVE A MEDIR EL LARGO DEL NUEVO STRING

    }
    while(banderaCadena == 0);

    return 0;
}

void formateoCadenas(char* texto)
{
    int i; // VARIABLE CONTROL
    int largo; // VARIABLE ALMACENA LARGO DEL STRING
    for(i = 0; texto[i]; i++) // POR SI ACASO PASAMOS TODOS LOS CARACTERES A MINUSCULA
    {
        texto[i] = tolower(texto[i]);
    }
    texto[0]=toupper(texto[0]); // SE CAMBIA LA PRIMERA LETRA A MAYUSCULA
    largo = strlen(texto); // SE ALMACENA EN largo LA CANTIDAD DE CARACTERES DEL STRING
    for(i=0; i< largo; i++) // SE RECORRE EL STRING
    {
        if(texto[i]==' ') // SI ENCUENTRA UN ESPACIO EN LA CADENA, ENTRA EN EL IF
        {
            texto[i+1]=toupper(texto[i+1]); // SE PONE EN MAYUSCULA EL CARACTER QUE LE SIGUE A EL ESPACIO(i ES EL ESPACIO, i+1 ES EL CARACTER QUE LE SIGUE)
        }
    }

}

int pedirDatos(sEmployee eLista[], int id)
{
    char nombre[51];
    char apellido[51];
    char auxFloat[20];
    float salario;
    int sector;
    int opRealizada= -1;
    printf("EMPLEADO NUMERO DE ID: %d\n", id);
    fflush(stdin);

    printf("Ingrese nombre del empleado: ");
    gets(nombre);
    verificarCadena(nombre);
    formateoCadenas(nombre);

    fflush(stdin);

    printf("Ingrese apellido del empleado: ");
    gets(apellido);
    verificarCadena(apellido);
    formateoCadenas(apellido);
    fflush(stdin);

    printf("Ingrese salario del empleado: ");
    gets(auxFloat);
    salario= esFloat(auxFloat);
    fflush(stdin);

    printf("Ingrese sector del empleado: ");
    //scanf("%d", &sector);
    sector=ingresoNumero();

    // AGREGAR VERIFICACION DE DATOS, AL VERIFICAR TODOS LOS DATOS Y QUE ESTOS DEN 3, DEVOLVER VALIDO 0, SI NO DEVOLVER OTRO VALOR

    opRealizada= addAEmployees( eLista, id, ELEMENTS, nombre,apellido,salario, sector);
    return opRealizada;
}

float calculoTotalYPromedio(sEmployee eLista[],int elementos,float* promedio)
{
    int j;
    float cantidad;
    float total;
    total = 0;
    cantidad = 0 ;

    for(j=0; j<elementos; j++)
    {

        if(eLista[j].isEmpty == 0)
        {
            total= total+ eLista[j].salary;
            cantidad++;
        }
    }

    *promedio= total / cantidad;

    return total;
}
void mostrarTotalYPromedio(float total, float promedio,int cantidadSupPromedio)
{
    printf("EL TOTAL DE SALARIOS ES: %.2f \nEL PROMEDIO ES: %.2f\nCantidad de empleados que superan el promedio: %d\n", total, promedio,cantidadSupPromedio);
}
int superanPromedio (sEmployee eLista[], int elementos, float promedio)
{
    int i;
    int cantidadSuperaPromedio;
    cantidadSuperaPromedio = 0;

    for(i=0; i<elementos; i++)
    {
        if(eLista[i].isEmpty == 0)
        {
            if(eLista[i].salary > promedio)
            {
                cantidadSuperaPromedio++;
            }
        }
    }
    return cantidadSuperaPromedio;
}






