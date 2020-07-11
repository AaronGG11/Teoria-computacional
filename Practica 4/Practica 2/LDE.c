#include "LDE.h"

void IncertarLDEcola(NODO* cab, TipoDato x)
{
	NODO* aux=(NODO*)malloc(sizeof(NODO));
	aux->dato=x;
	aux->siguiente=NULL;

	NODO *ptr =NULL;
	for(ptr=cab;ptr->siguiente;ptr=ptr->siguiente){}
	aux->anterior =ptr;
	ptr->siguiente=aux;

}


void IncertarLDEpila(NODO **cab, TipoDato X)
{
	NODO* aux=(NODO*)malloc(sizeof(NODO));
	aux->dato=X;
	aux->anterior=NULL;
	aux->siguiente=(*cab);
	if(*cab)
		aux->siguiente->anterior=aux;
	(*cab)=aux;
}

void indNodoCol(NODO**cab,TipoDato x){
NODO* aux=(NODO*)malloc(sizeof(NODO));

	aux->dato=x;
	aux->siguiente=*cab;
	aux->anterior=NULL;
	if(*cab)
	{
		(*cab)->anterior=aux;
		
	}

	(*cab) =aux;



}


//________________________Ingresar datos por la cabecera en LDE________________________
void IngresarCabLDE(NODO**cab,TipoDato x)
{
	NODO* aux=(NODO*)malloc(sizeof(NODO));

	aux->dato=x;
	aux->anterior=*cab;
	aux->siguiente=NULL;
	if(*cab!=NULL)
	{
		(*cab)->siguiente=aux;

	}else
	{
		*cab=aux;
	}
}


//________________________Insertarun nodo que no sea por la cabecera en LDE________________________
void InsertarLDE(NODO *anterior, TipoDato x)
{
	NODO*aux=(NODO*)malloc(sizeof(NODO));
	aux->dato=x;
	aux->siguiente=anterior;
	aux->siguiente=anterior->siguiente;
	anterior->siguiente->anterior=aux;
	anterior->siguiente=aux;
}


//________________________Buscar un elemento LDE________________________
NODO*BuscaLDE(NODO*cab,TipoDato x)
{
	NODO *aux;

	for(aux=cab;aux;aux=aux->siguiente)
	{
		if(aux->dato==x)
		{
			return aux;
		}
	}
	return NULL;
}

//________________________Eliminar un Nodo en un LDE________________________
void EliminarLDE(NODO**cab, TipoDato x)
{
	NODO*aux=*cab;
	int encontrado=0;
	while((aux!=NULL)&&(!encontrado))
	{
		encontrado=(aux->dato==x);
		if(!encontrado)
			aux=aux->siguiente;
	}
	if(aux!=NULL)
	{
		if(aux==*cab)
		{
			*cab=aux->siguiente;
			{
				if(aux->siguiente!=NULL)
				{
					aux->siguiente->anterior=NULL;
				}
				else if(aux->siguiente!=NULL)
				{
					aux->anterior->siguiente=aux->siguiente;
					aux->siguiente->anterior=aux->anterior;
				}
				else
				{
					aux->anterior->siguiente=NULL;
				}
			}
		}
	}
	free(aux);
}

//________________________Eliminar un Nodo en un LDE________________________

void  imprimirLE(NODO * cab){
	for (NODO * ptr1=cab;ptr1->siguiente;ptr1=ptr1->siguiente) {
        printf(" %s-", ptr1->dato );
   }
}