#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Elem.h"
#include "ElemInteger.h"
#include "ElemString.h"
#include "Lista.h"


void esLineaValida(String linea){
	int contador = 0;
	char pal1[80], *pal2;
	SLista pals = SVacia();

	FILE * archivo = fopen("ejemplo1.txt","wt");
	fputs(linea,archivo);
	fclose(archivo);

	FILE * in = fopen("ejemplo1.txt","r");

	while(fscanf(in,"%s",pal1)!=EOF){
		pal2 = (char*)malloc(80);
		strcpy(pal2,pal1);
		pals = SCons(pal2,pals);
	}

	free(pal2);
	fclose(in);

	// lista con palabras de la linea determinada del archivo original
}

int main(int argc, char const *argv[]){

	return 0;
}


