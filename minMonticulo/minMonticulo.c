/*Programaza realizado por Alejandro Meza Tudela
 *FECHA: 09/10/2019
 *Proposito: el programa trabaja con minmonticulos
 */
#include <stdio.h>
#include <stdlib.h>
#include "minMonticulo.h"

void errorMinMonticulo(char s[]){
	printf("%s",s);
}

void swap(tipoElementoMinMonticulo *m, tipoElementoMinMonticulo posA, tipoElementoMinMonticulo posB){
  tipoElementoMinMonticulo aux;
  aux = m[posA];
  m[posA] = m[posB];
  m[posB] = aux;

}	

void orderInsertion(tipoMinMonticulo *m, tipoElementoMinMonticulo elem, tipoElementoMinMonticulo posToOrden){
	if (posToOrden >0){
		if(elem < m->array[(posToOrden-1)/2]){
			swap(m->array, posToOrden, (posToOrden-1)/2);
			posToOrden = (m->pos-1)/2;
			orderInsertion(m, elem, posToOrden);
		}
	}
}

//correcto
int buscarElemento(tipoMinMonticulo m, tipoElementoMinMonticulo elem){
	int i = 0;
	while (i<=m.pos  && m.array[i] != elem){
		i++;
	}
	if (m.array[i] == elem){
		return i;
	}
	else{
		return -1;
	}
}


int buscaHijoMenor (tipoMinMonticulo m , int p){
	int l,r;
	l = p*2 +1;
	r = p*2 +2;
	if(l<m.pos){
		if(r<m.pos){
			if(m.array[l]<m.array[r]){
				return l;
			}
			else{
				return r;
			}
		}
		else{
			return l;
		}
	}
	else{
		return m.pos;
	}
}


void insertarMinMonticulo(tipoMinMonticulo *m, tipoElementoMinMonticulo elem){
	int index;
	if(estaLleno(*m)){
		errorMinMonticulo("El minMonticulo esta lleno, no se pueden insertar elementos ya \n"); 
	}
	else{
		m->pos = m->pos+1;
		index = m->pos;
		m->array[index] = elem;
		orderInsertion(m, elem, m->pos); //
    } 
}

void eliminarElemento(tipoMinMonticulo *m, tipoElementoMinMonticulo elem){
	//caso de que minMonticulo este vacio
	if(esVacio(*m)){
		errorMinMonticulo("MinMontiuclo vacio");
	}
	else{
		int p,h,aux;
		int posDelete = buscarElemento(*m, elem);
		if (posDelete == -1){
			printf("Elemento %d no se encuentra en minMonticulo\n",elem);
		}
		else{
			int lastElement = m->array[(m->pos)];
			m->array[posDelete] = lastElement;
			m->pos = (m->pos)-1;
			p = posDelete;
			h = buscaHijoMenor(*m, p);
			while( (h<m->pos) && (m->array[p] > m->array[h]) ){
				aux= m->array[p];
				m->array[p] = m->array[h];
				m->array[h] = aux;
				p = h;
				h= buscaHijoMenor(*m, p);
			}
		//m->pos : representa cuan lleno esta el array
		//posDelete: pos de elem que ha sido borrado
		}
	}
}

tipoElementoMinMonticulo devolverRaiz(tipoMinMonticulo m){
	//se tiene en cuenta que se insertan elems desde un array
	if(esVacio(m)){
		errorMinMonticulo("El monticulo esta vacio, no se devuelven elementos\n");
	}
	else{
		return (m.array[0]);
     }
}

void nuevoMinMonticulo(tipoMinMonticulo *new, int elem){
	
	new->array= (tipoElementoMinMonticulo* )malloc(sizeof(tipoElementoMinMonticulo)*elem);
	//con calloc restrinjo aun mas la memoria, asignandole los elementos introducidos
	new->pos = -1; //para que cuando se introduzca un elem, comience en la pos 0
	new->numEl = elem;
}

bool esVacio(tipoMinMonticulo m){
	return (m.pos == 0);
}

void mostrarAnchura(tipoMinMonticulo m ){
	int i; 
	for (i = 0; i<=m.pos; i++){
		printf("%d", m.array[i]);
	}
	printf("\n");
}

bool estaLleno(tipoMinMonticulo m){
	return (m.pos == m.numEl -1);
	//las posiciones comienzan en 0, por eso se le debe restar uno a nElem.
}
