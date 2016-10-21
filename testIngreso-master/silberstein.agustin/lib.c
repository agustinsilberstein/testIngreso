#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lib.h"



/**
 * \brief Inicializa el Id en un array de clientes
 * \param clienteArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setid(cliente clienteArray[], int arrayLenght)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
       clienteArray[i].id = i+1;
    }
}


/**
 * \brief Inicializa el Id en un array de clientes
 * \param clienteArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setMaquinariaid(cliente clienteArray[],int arrayLenght)
{
    int i,j;
    for(i=0;i < arrayLenght; i++)
    {


        for(j=0;j < 20; j++)
            {

                    clienteArray[i].maquinasAlquiladas[j].idAlquiler = 1+j+i*20;
            }
    }

}
/**
 * \brief Inicializa el status en un array de clientes
 * \param clienteArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setStatus(cliente clienteArray[],int arrayLenght,int value)
{
    int i;
    for(i=0;i < arrayLenght; i++)
        {

       clienteArray[i].status = value;
        }
}



/**
 * \brief Inicializa el status en un array de maquinas
 * \param clienteArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param value Es el valor que se asignara a status
 * \return -
 *
 */
void setAlquilerStatus(cliente clienteArray[],int arrayLenght,int value)
{
    int i, j;

        for(i=0;i<arrayLenght;i++)
        {


        for(j=0;j < 20; j++)
        {
              clienteArray[i].maquinasAlquiladas[j].estadoAlquiler = value;

        }
}
}



/**
 * \brief Busca la primer ocurrencia de un cliente mediante su id
 * \param clienteArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \param code Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int findclienteById(cliente clienteArray[],int arrayLenght,int id)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(clienteArray[i].id == id && clienteArray[i].status == 1)
        {
            return i;
        }
    }
    return -1;
}




/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findEmptyPlace(cliente clienteArray[],int arrayLenght)
{
    int i;
    for(i=0;i < arrayLenght; i++)
    {
        if(clienteArray[i].status == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param bookArray Es el array en el cual buscar
 * \param arrayLenght Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 *
 */
int findEmptyPlaceMaquinaria(cliente clienteArray[],int i, int arrayLenght)
{
    int j;
    i=i-1;


        for(j=0;j<20;j++)
            {
            if(clienteArray[i].maquinasAlquiladas[j].estadoAlquiler == 0)
            {
                return j+i*20;
            }
    }
    return -1;
}





/**
 * \brief Carga los valores del cliente
 * \param clienteArray Es el array de clientes
 * \param freePlaceIndex Indica la posicion a setear
 * \param idAux Id del cliente
 * \param nombreAux nombre del cliente
 * \param apellidoAux apellido del cliente
 * \param dniAux Dni del cliente
 * \return -
 *
 */
void setCliente(cliente clienteArray[],int freePlaceIndex,char nombreAux[], char apellidoAux[],int dniAux)
{

    strcpy(clienteArray[freePlaceIndex].apellido,apellidoAux);
    strcpy(clienteArray[freePlaceIndex].nombre,nombreAux);
    clienteArray[freePlaceIndex].dni = dniAux;

    clienteArray[freePlaceIndex].status = 1;
    printf("\n\nEl numero de ID de %s %s es: %d ",clienteArray[freePlaceIndex].nombre,clienteArray[freePlaceIndex].apellido,clienteArray[freePlaceIndex].id);
}


/**
 * \brief Carga los valores del alquiler
 * \param clienteArray Es el array de clientes
 * \param freePlaceIndex Indica la posicion a setear
 * \param idAux Id del cliente
 * \param motivoAux maquinaria que se alquilo
 * \param tiempoAux tiempo aproximado de alquiler
 * \param estadoAlquiler estado del alquiler
 * \return -
 *
 */
void setAlquiler(cliente clienteArray[],int freePlaceIndex,int freePlaceIndexMaquinaria, int motivoAux, int tiempoAux, int operadorAux)
{



   clienteArray[freePlaceIndex].maquinasAlquiladas[freePlaceIndexMaquinaria].motivo = motivoAux;
   clienteArray[freePlaceIndex].maquinasAlquiladas[freePlaceIndexMaquinaria].tiempoEstimado = tiempoAux;
    clienteArray[freePlaceIndex].maquinasAlquiladas[freePlaceIndexMaquinaria].operador=operadorAux;
     clienteArray[freePlaceIndex].maquinasAlquiladas[freePlaceIndexMaquinaria].estadoAlquiler=1;
     clienteArray[freePlaceIndex].cantidadAlquilada=clienteArray[freePlaceIndex].cantidadAlquilada+1;


printf("%d",clienteArray[freePlaceIndex].cantidadAlquilada);



    printf("\n Id de Alquiler: %d\n Cliente: %s %s \n ",clienteArray[freePlaceIndex].maquinasAlquiladas[freePlaceIndexMaquinaria].idAlquiler,clienteArray[freePlaceIndex].nombre,clienteArray[freePlaceIndex].apellido);

}


void unsetAlquiler (cliente clienteArray[],int freePlaceIndex)
{
    printf("Elija que id de alquiler del cliente %s %s finalizo\n \n ",clienteArray[freePlaceIndex].nombre,clienteArray[freePlaceIndex].apellido);
    int j;
    int opcion;
    int tiempo;
    for(j=0;j<20;j++)
    {
        if(clienteArray[freePlaceIndex].maquinasAlquiladas[j].estadoAlquiler ==1)
        {
        printf("ID DEL ALQUILER: %d || MOTIVO: %d (1 AMOLADORA, 2 MEZCLADORA, 3 TALADRO) \n\n",clienteArray[freePlaceIndex].maquinasAlquiladas[j].idAlquiler,clienteArray[freePlaceIndex].maquinasAlquiladas[j].motivo);
        }
    }
        opcion = getValidInt("Ingrese el Id del alquiler: ","Debe ser un numero entre 1 y 20",1,20);
        opcion=opcion-1;

        if(clienteArray[freePlaceIndex].maquinasAlquiladas[opcion].estadoAlquiler==1)
            {
                    tiempo=getValidInt("Ingrese Tiempo total del alquiler en dias: ","Debe ser entre 1 y 1000 dias",1,1000);
                    clienteArray[freePlaceIndex].maquinasAlquiladas[opcion].tiempoReal=tiempo;
                clienteArray[freePlaceIndex].maquinasAlquiladas[opcion].estadoAlquiler=-1;
                clienteArray[freePlaceIndex].cantidadAlquilada=clienteArray[freePlaceIndex].cantidadAlquilada-1;

                printf("ALQUILER FINALIZADO\n");


            }
            else{printf("OPCION NO VALIDA\n");}

        }


        int informarMayorAlquileres(cliente clienteArray[],int arrayLenght)
            {
                int i,j;
                int mayorAlquileres;
                mayorAlquileres=-1;

                        for(i=0;i<arrayLenght; i++)
                            for(j=0;j<20;j++)
                        {



                                {
                                    if(mayorAlquileres < clienteArray[i].cantidadAlquilada && clienteArray[i].maquinasAlquiladas[j].estadoAlquiler == 1)
                                    {
                                        mayorAlquileres = clienteArray[i].cantidadAlquilada;
                                    }
                                }
                        }

                                    return mayorAlquileres;

                        if(mayorAlquileres == -1)
                        {
                            return -1;
                        }

            }

                /** \brief informa equipos mas alquilados
                 *
                 * \param clienteArray[] array de clientes
                 * \param arrayLenght tamaño del array
                 * \return int
                 *
                 */
                int informarEquiposMasAlquilados(cliente clienteArray[], int arrayLenght)
                {
                    int i,j;

                            int contador1=0;
                            int contador2=0;
                            int contador3=0;
                    for(i=0;i<arrayLenght;i++)
                    {
                        for(j=0;j<20;j++)
                        {

                            if(clienteArray[i].maquinasAlquiladas[j].motivo==1&&clienteArray[i].status==1)
                            {
                                contador1=contador1+1;
                            }

                            if(clienteArray[i].maquinasAlquiladas[j].motivo==2&&clienteArray[i].status==1)
                            {
                                contador2=contador2+1;
                            }

                            if(clienteArray[i].maquinasAlquiladas[j].motivo==3&&clienteArray[i].status==1)
                            {
                                contador3=contador3+1;
                            }
                        }
                    }
                    if(contador1>=contador2&&contador1>=contador3)
                    {
                        printf("El equipo mas alquilado es la AMOLADORA con %d unidades alquiladas\n",contador1);

                    }

                            if(contador2>=contador1&&contador2>=contador3)
                                {
                                    printf("El equipo mas alquilado es la MEZCLADORA con %d unidades alquiladas\n",contador2);

                                }

                                    if(contador3>=contador1&&contador3>=contador2)
                                {

                    {
                        printf("El equipo mas alquilado es el TALADRO con %d unidades alquiladas\n",contador3);

                    }




                        }
                    }


/** \brief informa promedio de alquiler
 *
 * \param clienteArray[] cliente
 * \param arrayLenght int
 * \return void
 *
 */
void informarTiempo(cliente clienteArray[],int arrayLenght)
    {
        int i,j;
        int acumulador=0;
        int contador=0;
        float promedio=0;
        for(i=0;i<arrayLenght;i++)
        {
            for(j=0;j<20;j++)
            {
                if(clienteArray[i].maquinasAlquiladas[j].estadoAlquiler==-1&&clienteArray[i].status==1)
                {

                    contador=contador+1;
                    acumulador=acumulador+clienteArray[i].maquinasAlquiladas[j].tiempoReal;
                    promedio=acumulador/contador;
                }
            }
        }
        printf("El promedio de dias de alquiler es: %2.f",promedio);
    }



/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}



/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}



/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }



}






/** \brief
 *menu opciones
 * \param texto[] ingresa las opciones del menu
 * \param auxOpcion[] auxiliar de opciones
 * \return retorna la opcion si esta en el rango
 *
 */
int menuOpciones(char texto[],char auxOpcion[])
        {
            int resultado=0;
            char opcionSoN;

            resultado=getStringNumeros(texto,auxOpcion);


                while(resultado==0)
                {

                    fflush(stdin);
                    opcionSoN = getChar("La opcion no es valida, Desea volver a Ingresar? S/N: ");
                    if(toupper(opcionSoN)!='S')
                    {
                        exit(0);
                    }

                else{ return 0;}
            }

            return atoi(auxOpcion);
        }







