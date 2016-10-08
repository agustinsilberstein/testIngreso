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
    char nombreAux[51];

    char apellidoAux[80];
    int idAux;
    int dniAux;
    int motivoAux;
    int tiempoAux;
    int estadoAux;

    //________________________________________________

    int freePlaceIndex;
    int foundIndex;
    int option = 0;
    char opcionBuffer[400];

    setStatus(clienteArray,MAX_QTY,0);
    setStatusAlquiler(clienteArray,MAX_QTY,-1);




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

                idAux = getValidInt("Ingrese el Id del cliente: ","El Id debe ser numerico\n", 1, 15000);
                if(findclienteByCode(clienteArray,MAX_QTY,idAux) != -1)
                {
                    printf("\n\nEL ID YA EXISTE!!!\n");
                    break;
                }

                 dniAux = getValidInt("Ingrese el DNI: ","El DNI debe ser numerico\n", 10000000, 99999999);






                getValidString("Ingrese el Nombre del cliente: ","El nombre debe estar compuesto solo por letras\n", nombreAux);
                getValidString("Ingrese el Apellido del cliente: ","El Apellido debe ser solo por letras\n", apellidoAux);



                setCliente(clienteArray,freePlaceIndex,idAux,nombreAux,apellidoAux,dniAux);



                break;

            case 2: // MODIFICAR


                idAux = getValidInt("Ingrese el Id del cliente a modificar: ","El Id debe ser numerico\n", 1, 15000);
                foundIndex = findclienteByCode(clienteArray,MAX_QTY,idAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID\n");
                    break;
                }


                getValidString("Ingrese el Apellido del cliente: ","El apellido debe estar compuesto  solo por letras\n", apellidoAux);

                getValidString("Ingrese el Nombre del cliente:  ","El nombre debe estar compuesto solo por letras\n", nombreAux);

                setCliente(clienteArray,foundIndex,idAux,nombreAux,apellidoAux,dniAux);

                break;



            case 3: // BAJA



                 idAux = getValidInt("Ingrese el Id a dar de baja: ","El Id debe ser numerico\n", 1, 15000);
                foundIndex = findclienteByCode(clienteArray,MAX_QTY,idAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID\n");
                    break;
                }
                clienteArray[foundIndex].status = 0;
                break;





            case 4: // NUEVO ALQUILER
                 idAux = getValidInt("Ingrese el Id del cliente para registrar nuevo alquiler: ","El Id debe ser numerico\n", 1, 15000);
                foundIndex = findclienteByCode(clienteArray,MAX_QTY,idAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID\n");
                    break;
                }

               motivoAux= getValidInt("Ingrese el equipo alquilado:\n 1-AMOLADORA\n2-MEZCLADORA\n3-TALADRO\n","Debe ser una opcion entre 1 Y 3\n",1,3);
               tiempoAux=getValidInt("Ingrese el tiempo aproximado del alquiler en dias: ","Debe estar entre 1 y 500",1,500);
               setAlquiler(clienteArray,foundIndex,idAux,motivoAux,tiempoAux);
               break;






                break;

            case 5: // FIN DEL ALQUILER
               idAux = getValidInt("Ingrese el Id que finalizo el alquiler: ","El Id debe ser numerico\n", 1, 15000);
                foundIndex = findclienteByCode(clienteArray,MAX_QTY,idAux);
                if(foundIndex == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE ID\n");
                    break;
                }
                clienteArray[foundIndex].estadoAlquiler = 0;
                break;











         }
    }


    return 0;
}
