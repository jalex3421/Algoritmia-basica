/*Programa realizado por Alejandro Meza
 * 25/09/2019
 * Se trabaja la implementacion de una cola doble
 */
 
#include <stdio.h>
#include <stdlib.h> //se incluye malloc.. Para conocer exit y malloc
#include "colaDobleCaracteres.h"
#include <stdbool.h>

void errorColaDeEnteros(char s[]) {
	printf("\n\n\nERROR en el modulo colas:  %s\n", s);
	while (true)
		exit(-1);
}

void nuevaColaDoble(tipoColaDoble *c) {
	c->ini = NULL; //primer elem. es nulo
	c->fin = NULL; //último elem. es nulo
//luego al ser nulo cabeza y cola, esta vacia
}

void encolarUltimo(tipoColaDoble *c, tipoElementoColaDoble x) {
	celdaColaDoble * q;
	q = (celdaColaDoble*)malloc(sizeof(celdaColaDoble));
	//caso que malloc encuentre problema de que no haya mem. disponible
	q->elem = x; //condiciones iniciales
	q->sig = NULL;
	q->ant = c->fin;
	if (c->fin == NULL){ //caso de que cola este vacía
		c->ini = q;
	} else { //si no está vacía
		c->fin->sig = q; //siguiente del final sera nuestro elemento.
	}
	c->fin = q;
}

void encolarPrimero(tipoColaDoble *c, tipoElementoColaDoble x){
	celdaColaDoble * q;
	q = (celdaColaDoble*)malloc(sizeof(celdaColaDoble));
	//caso que malloc encuentre problema de que no haya mem. disponible
	q->elem = x; //condiciones iniciales
	q->sig = c->ini;
	q->ant = NULL;
	if (c->fin == NULL){ //caso de que cola este vacía
		c->fin = q;
		//otro caso luego
	} //else { //si no está vacía
		//c->fin->sig = q; //siguiente del final sera nuestro elemento.
	//}
	else{
		c->ini->ant = q;
	}
	c->ini= q;
}


bool esNulaColaDoble(tipoColaDoble c) { //true o falso
	//si dev true se netra en el if
	return (c.ini == NULL); //retorna el elemento inicial de la cola si
	//lo retorna si es nulo..
	//luego si es nulo, la cola doble es por ende nula
}

void desencolarPrimero(tipoColaDoble *c) { 
	
	if (esNulaColaDoble(*c)) {
		errorColaDeEnteros("desencolando cola nula");
	}
	else{
		celdaColaDoble *q;
		q = c->ini;
		c->ini = c->ini->sig;
		free(q);
		if (c->ini == NULL) { //DUDOSO
			c->fin = NULL;
		}
		else{
			c->ini->ant = NULL;
		}
  }
}

void desencolarUltimo(tipoColaDoble *c) { 
	celdaColaDoble *q;
	if (esNulaColaDoble(*c)) {
		errorColaDeEnteros("desencolando en cola nula");
	}
	q = c->fin;
	c->fin = c->fin->ant;
	free(q);
	if (c->fin == NULL) {
		c->ini == NULL;
	}
	else{
		c->fin->sig = NULL;
	}
	
}
//copia en elemento, el mas antiguo de la cola: en x para nuestro caso
//particular
tipoElementoColaDoble elemPrimero(tipoColaDoble c) {
	if (esNulaColaDoble(c)) {
		errorColaDeEnteros("primero en cola nula");
	}
	return (c.ini->elem); //se le copia el elemento x 
	//cuidado con tipo tElem
}

tipoElementoColaDoble elemUltimo(tipoColaDoble c) {
	if (esNulaColaDoble(c)) {
		errorColaDeEnteros("primero en cola nula");
	}
	return (c.fin->elem); //se le copia el elemento x 
	//cuidado con tipo tElem
}
