#define MAX_QTY 100
#define AMOLADORA 1
#define MEZCLADORA 2
#define TALADRO 3




typedef struct{

int idAlquiler;
int motivo;/**< (1) AMOLADORA, (2) MEZCLADORA, (3) TALADRO */
int tiempoEstimado;
int operador;
 int estadoAlquiler; /**< alquilado (1 )  no utilizado (0) finalizado(-1) */
int tiempoReal;


}maquinaria;



typedef struct{
    char nombre[51];
    int dni;
    char apellido[51];
    int cantidadAlquilada;
    int id;
    int status;/**< activo (1), inactivo(0), baja (-1) */
    maquinaria maquinasAlquiladas[20];


}cliente;

int menuOpciones(char texto[],char auxOpcion[]);



void setMaquinariaid(cliente clienteArray[],int arrayLenght);

void setid(cliente clienteArray[],int arrayLenght);
void setStatus(cliente clienteArray[],int arrayLenght,int value);
void setAlquilerStatus(cliente clienteArray[],int arrayLenght,int value);
void setAlquiler(cliente clienteArray[],int freePlaceIndex,int freePlaceIndexMaquinaria, int motivoAux, int tiempoAux, int operadorAux);
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

int findclienteById(cliente clienteArray[],int arrayLenght,int id);
int findEmptyPlaceMaquinaria(cliente clienteArray[],int i,int arrayLenght);
int findEmptyPlace(cliente clienteArray[],int arrayLenght);
void orderArrayByTitle(cliente clienteArray[],int arrayLenght);
void unsetAlquiler (cliente clienteArray[],int freePlaceIndex);


void setCliente(cliente clienteArray[],int freePlaceIndex,char nombreAux[], char apellidoAux[],int stockAux);
void showArray(cliente clienteArray[],int arrayLenght);
int informarMayorAlquileres(cliente clienteArray[],int arrayLenght);
int informarEquiposMasAlquilados(cliente clienteArray[], int arrayLenght);


void informarTiempo(cliente clienteArray[],int arrayLenght);
