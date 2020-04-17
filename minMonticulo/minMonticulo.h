#include <stdbool.h>

typedef int tipoElementoMinMonticulo;

typedef struct tMM{
	tipoElementoMinMonticulo *array; //se le pasan los valores al minMonticulo
	int pos; //contiene las posiciones del array de elementos
	int numEl; //num. de elementos en minMonticulo
}tipoMinMonticulo;
//tipoMinMonticulo es un struct con dos enteros..
//*array es un array dinamico 


void nuevoMinMonticulo(tipoMinMonticulo*, int);//

void errorMinMonticulo(char s[]);//

void insertarMinMonticulo(tipoMinMonticulo *, tipoElementoMinMonticulo);

void eliminarElemento(tipoMinMonticulo *, tipoElementoMinMonticulo);

tipoElementoMinMonticulo devolverRaiz(tipoMinMonticulo);

void mostrarAnchura(tipoMinMonticulo); //

bool esVacio(tipoMinMonticulo); // 

bool estaLleno(tipoMinMonticulo);
