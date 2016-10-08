#define MAX_QTY 200

typedef struct{
    char title[51];
    int code;
    int dni;
    int apellido;
    int status; /**< Activo (1) o Inactivo (0)  */
    int motivo;
    int tiempo;
    int estadoAlquiler; /**< alquilado (1) o finalizado (0) no utilizado(-1) */

}cliente;

int menuOpciones(char texto[],char auxOpcion[]);


void setStatus(cliente clienteArray[],int arrayLenght,int value);
void setStatusAlquiler(cliente clienteArray[],int arrayLenght,int value);

int findEmptyPlace(cliente clienteArray[],int arrayLenght);
void orderArrayByTitle(cliente clienteArray[],int arrayLenght);


void setCliente(cliente clienteArray[],int freePlaceIndex, int idAux,char nombreAux[], char apellidoAux[],int stockAux);
void setAlquiler(cliente clienteArray[],int freePlaceIndex, int idAux,int motivoAux, int tiempoAux);
void showArray(cliente clienteArray[],int arrayLenght);

