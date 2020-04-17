/*
 *  Programa realizado por Alejandro Meza
 *  un 10 de septiembre
 *  Se procede a implementar una pila dinamica
 */ 
 #include <stdio.h>
 #include <stdlib.h>
 #include "pilaEnterosDinamica.h"
 
void nuevaPila(tipoPila *); 

void apilar(tipoPila *, tipoElementoPila);

void desapilar(tipoPila *);

tipoElementoPila cima(tipoPila);

bool esNulaPila(tipoPila);
////////////////////////////////////////////FUNCIONES////////////////////////////////////
void nuevaPila(tipoPila *p)
{
	*p =NULL;
}

void apilar(tipoPila *p, tipoElementoPila elemento)
{
	celdaPila *nuevo; 
	nuevo=(celdaPila*)malloc(sizeof(celdaPila)); //se crea espacio en memoria para celdapila nuevo 
	nuevo->elem=elemento;
	nuevo->sig=*p;
	*p=nuevo; //p apunta al elem de la "cima"; luego ahora pasa a ser nuestro elemento nuevo..
}

void desapilar(tipoPila *p)
{
	if (esNulaPila(*p))
	{
		printf("Se ha producido un error, pues la pila esta vacia \n");
	}
	else{
		celdaPila *aux; //conceptualmente..
		 aux = *p; //aux
		*p = (*p)->sig;
		free(aux);
	}
}

tipoElementoPila cima (tipoPila p) //*P?????
{
	//no es *p, porque tipoPila es de por si un puntero
	if (esNulaPila(p))
	{
		printf("No se ha podido encontrar el primer elem, pues la pila esta vacia");
	}
	else {
	return p->elem; }
}

bool esNulaPila (tipoPila p)
{
	return p == NULL;
}
	




 
