/*Programa realizado por Alejandro Meza
 * Fecha de realizacion: 1/10/2019
 * El programa se encarga de simular el funcionamiento
 * .... de un arbol binario de busqueda. 
 */
	
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "arbolBinarioBusqueda.h" 

void nuevoArbolBB(tipoArbolBB *a){
	*a = NULL;  //si *a == NULL ->segmentation fault 
} 

void errorArbolBB(char s[]){
	printf("\n\n Error en arbol binario de busqueda: %s \n", s);
}

void insertar(tipoArbolBB *a, tipoElementoArbolBusqueda e){
	if (esVacio(*a)){ //caso base
		celdaArbolBusqueda *new;
		new = (celdaArbolBusqueda*)malloc(sizeof(celdaArbolBusqueda));
		new ->elem = e;
		new ->izda = NULL;
		new ->dcha = NULL;
		*a = new;
	}
	else{
		 if (((*a)->elem == e)){
			 printf("Elemento ya existente en el arbol\n");
			}
			else{
				//nos quedan dos casos posibles
				if(e < (*a)->elem){
					insertar(&((*a)->izda), e);
					//llamada recursiva para ir al caso base
				}
				else if (e> (*a)->elem){
					insertar(&((*a)->dcha), e);
				 }
			 }
		}
}

void borrar(tipoArbolBB *a, tipoElementoArbolBusqueda e){
	if (esVacio(*a)){
		errorArbolBB("El arbol es vacio, no se pueden borrar elementos\n");
	}
	else{
		if ((*a)->elem > e){
			borrar(&((*a)->izda), e); 
		}
		else if ((*a)->elem <e){
			borrar(&((*a)->dcha), e);
	    }
	    //hemos encontrado el elemento
	    else if ((*a)->elem == e){
			//caso que no tenga hijos
			if(((*a)->izda == NULL) && ((*a)->dcha == NULL)){
				tipoArbolBB aux;
				aux = *a;
				*a = NULL; 
				free(aux);
			}
			//con hijo derecho
			else if(((*a)->izda == NULL) && ((*a)->dcha != NULL)){
				tipoArbolBB aux;
				aux = (*a);
				*a= (*a)->dcha;
				free(aux);
			}
			//con hijo izquierd
			else if (((*a)->izda != NULL) && ((*a)->dcha == NULL)){
				tipoArbolBB aux;
				aux = (*a);
				(*a) = (*a)-> izda;
				free(aux);
		    }//sendos hijos-->caso ultimo!!
		    else if (((*a)->izda != NULL) && ((*a)->dcha != NULL)){
				tipoArbolBB aux;
				aux = (*a)->dcha;
				while ( aux->izda != NULL){
					aux = aux->izda; 
				}
				(*a)->elem = (aux)->elem;
				//aprovecho llamada a funcion para borrar elemento
				
				borrar(&(*a)->dcha,aux->elem);	
	 	    }
	}
	}
}
 
void mostrarPreorden(tipoArbolBB a ){
	if (!esVacio(a)){
       printf("%d", a->elem);
       mostrarPreorden(a->izda);
       mostrarPreorden(a->dcha); 
     }
} 
 
void mostrarInorden(tipoArbolBB a ){
	if (!esVacio(a)){
       mostrarInorden(a->izda);
       printf("%d", a->elem);
       mostrarInorden(a->dcha); 
     }
}

void mostrarPostorden(tipoArbolBB a ){
	if (!esVacio(a)){
       mostrarPostorden(a->izda);
       mostrarPostorden(a->dcha); 
       printf("%d", a->elem); 
     }
}
       
bool esVacio(tipoArbolBB a ){
	return (a == NULL);
}
