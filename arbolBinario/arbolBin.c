/*Programa realizado por Alejandro Meza
 * Fecha: 1/10/2019
 * El programa se encarga de la implementacion de un arBin
 */
 
 #include "arbolBin.h"
 #include <stdio.h>
 #include <stdlib.h>
 
 void nuevoArbolBin(tipoArbolBin *a){
	 *a = NULL;
} 

void errorArbolBin(char s[]){
	printf("\n\n Error en arbol binario: %s \n", s);
}

tipoArbolBin construir(tipoElementoArbolBin elemento, tipoArbolBin i, tipoArbolBin d){
	tipoArbolBin nuevo;
	nuevo = (celdaArbolBin*)malloc(sizeof(celdaArbolBin)); 
	nuevo->elem = elemento; 
	nuevo->izda = i; //puntero izquierda de nuevo apunta a lo mismo que apunta i, 
	//puntero a celda arbol bin
	nuevo->dcha = d; //puntero derecha de nuevo a paunta a lo mismo que apunta d, 
	//puntero a celda de arbol bin
	return (nuevo); 
}

tipoElementoArbolBin devolverRaiz(tipoArbolBin a){
	if (esVacio(a)){
		errorArbolBin("El arbol es vacio"); 
	}
	return (a->elem); 
}	 
 
 void preorden(tipoArbolBin a){
	 //tipoElementoArbolBin elem; 
	 if (!esVacio(a)){
		 printf("%d", a->elem);
		 preorden(a->izda);
		 preorden(a->dcha);
	}
} 

void inorden(tipoArbolBin a){
	 //tipoElementoArbolBin elem; 
	 if (!esVacio(a)){
		 inorden(a->izda);
		 printf("%d", a->elem);
		 inorden(a->dcha);
	}
} 

void postorden(tipoArbolBin a ){
	//tipoElementoArbolBin elem; 
	 if (!esVacio(a)){
		 postorden(a->izda);
		 postorden(a->dcha);
		 printf("%d", a->elem);
	}
} 

bool esVacio(tipoArbolBin a){
	return a == NULL; 
}
	

		 
