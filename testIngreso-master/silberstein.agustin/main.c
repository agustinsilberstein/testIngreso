#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"



int main()
{
    // arrays de clientes
    cliente clienteArray[MAX_QTY];

    //________________________________________________


    // variables auxiliares
    char nombreAux[200];

    char apellidoAux[60];
    int dniAux;
    int motivoAux;
    int tiempoAux;
    int estadoAux;
    int idAux;
    int idAlquilerAux;
    int operadorAux;
    int auxInt;
    //________________________________________________

    int freePlaceIndex;
    int foundIndex;
    int foundIndexMaquinaria;
    int option = 0;
    char opcionBuffer[400];

     setMaquinariaid(clienteArray, MAX_QTY);
    setStatus(clienteArray,MAX_QTY,0);
    setid(clienteArray,MAX_QTY);
setAlquilerStatus( clienteArray,10,0 );







    //________________________________________________

    while(option != 7)
    {
         option = menuOpciones("\n\n\n1 - ALTA \n2 - MODIFICACION \n3 - BAJA\n4 - NUEVO ALQUILER\n5 - FIN DEL ALQUILER\n6 - INFORMAR\n\n\n",opcionBuffer);
         switch(option)
         {
            case 1: // ALTA DE CLIENTE

                freePlaceIndex = findEmptyPlace(clienteArray,MAX_QTY);
                if(freePlaceIndex == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    break;
                }



                 dniAux = getValidInt("Ingrese el DNI: ","El DNI debe ser numerico\n", 10000000, 99999999);
                 fflush(stdin);
                getValidString("Ingrese el Nombre del cliente: ","El nombre debe estar compuesto solo por letras\n", nombreAux);
                fflush(stdin);
                getValidString("Ingrese el Apellido del cliente: ","El Apellido debe ser solo por letras\n", apellidoAux);

                setCliente(clienteArray,freePlaceIndex,nombreAux,apellidoAux,dniAux);




                break;

            case 2: // MODIFICAR


                idAux = getValidInt("Ingrese el Id del cliente a modificar: ","El Id debe ser numerico\n", 1, 15000);
                foundIndex = findclienteById(clienteArray,MAX_QTY,idAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID\n");
                    break;
                }


                getValidString("Ingrese el Apellido del cliente: ","El apellido debe estar compuesto  solo por letras\n", apellidoAux);
                fflush(stdin);
                getValidString("Ingrese el Nombre del cliente:  ","El nombre debe estar compuesto solo por letras\n", nombreAux);

                setCliente(clienteArray,foundIndex,nombreAux,apellidoAux,dniAux);

                break;



            case 3: // BAJA



                 idAux = getValidInt("Ingrese el Id a dar de baja: ","El Id debe ser numerico\n", 1, 15000);
                foundIndex = findclienteById(clienteArray,MAX_QTY,idAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID\n");
                    break;
                }
                clienteArray[foundIndex].status = -1;
                printf("El cliente %s %s ha sido dado de baja",clienteArray[foundIndex].nombre,clienteArray[foundIndex].apellido);
                break;





            case 4: // NUEVO ALQUILER

            idAux = getValidInt("Ingrese el Id del cliente: ","El Id debe ser numerico\n", 1, 15000);


                foundIndex = findclienteById(clienteArray,MAX_QTY,idAux);

                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID\n");
                    break;
                }

                 freePlaceIndex = findEmptyPlaceMaquinaria(clienteArray,idAux,MAX_QTY);
                if(freePlaceIndex == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    break;
                }



               motivoAux= getValidInt("Ingrese el equipo alquilado:\n 1-AMOLADORA\n2-MEZCLADORA\n3-TALADRO\n","Debe ser una opcion entre 1 Y 3\n",1,3);
               fflush(stdin);
               tiempoAux=getValidInt("Ingrese el tiempo aproximado del alquiler en dias: ","Debe estar entre 1 y 10000\n",1,10000);
               fflush(stdin);
               operadorAux=getValidInt("Ingrese el numero de operador: ","Debe estar entre 1 y 1000\n",1,1000);
               setAlquiler(clienteArray,foundIndex,freePlaceIndex,motivoAux,tiempoAux,operadorAux);

               break;



            case 5:  //FIN ALQUILER


                idAux = getValidInt("Ingrese el Id del cliente: ","El Id debe ser numerico\n", 1, 15000);

                foundIndex = findclienteById(clienteArray,MAX_QTY,idAux);

                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID\n");
                    break;
                }

                unsetAlquiler(clienteArray,foundIndex);
                break;

            case 6://INFORMAR

               auxInt=informarMayorAlquileres(clienteArray,MAX_QTY);
               int i;
               if(auxInt!=-1)
                {
                for(i=0;i<MAX_QTY;i++)
                    {
                        if(clienteArray[i].status==1&&clienteArray[i].cantidadAlquilada>0)
                        {
                        printf("El cliente con mas alquileres actuales es: %s %s con %d alquileres\n",clienteArray[i].nombre,clienteArray[i].apellido,clienteArray[i].cantidadAlquilada);
                        }
               }
               }


            informarEquiposMasAlquilados(clienteArray,MAX_QTY);
            informarTiempo(clienteArray,MAX_QTY);









    //INFORMAR














         }
    }


    return 0;
}
