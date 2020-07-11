#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Sistema.h"
#include "Elem.h"
#include "ElemString.h"
#include "Lista.h"
#include "matriz.h"
#include "archivo.h"
#include "AFD.h"

void numFilasDeArchivo(FILE * in){
	char a;
	int contador = 0;

	rewind(in);
	while(!feof(in)){
		fscanf(in,"%c",&a);
        if((a == '\n')||(a == '\0'))
			contador++;
	}
	rewind(in);
	printf("Total de filas: %d\n",contador);
}

int main(int argc, char const *argv[]){
	LimpiaPantalla(); 

	char control; // Caracter de control de ciclo de ejecucion del programa
	char pal1[80], *pal2;
	SLista pals = SVacia();
	char * claves[	] = {"diccionario","flotante","refrescos"};

	Lista _estados = Vacia(); // Declaracion de lista para estados
    Lista _alfabeto = Vacia(); // Declaracion de lista para alfabeto
    char _estado_inicial; // Declaracion de estado inicial
    Matriz _tabla_de_transicion; // Declaracion de tabla de transicion de estados
    Lista _estados_de_aceptacion = Vacia(); // Declaracion de lista para estados de aceptacion
    String cadena = newString(); // Declaracion de cadena de entrada
	FILE * tupla = fopen(*(argv+1),"r");
	FILE * in = fopen(*(argv+2),"r");

	SLista cadenas_validas = SVacia();

	printf("\nPractica de laboratorio No.2\n");
    leerTupla(tupla,&_estados,&_alfabeto,&_estado_inicial,&_tabla_de_transicion,&_estados_de_aceptacion);

	if(contienePalabraClave(tupla,claves[0])){ // Ejercicio 1
		cadenas_validas = leerDiccionario(in, &_estados,&_alfabeto,&_estado_inicial,&_tabla_de_transicion,&_estados_de_aceptacion);
		printf("Cadenas validas encontradas: [%d]", SNumElem(cadenas_validas));
		SImpLista(cadenas_validas);
		printf("\n\n");
	}
	else if(contienePalabraClave(tupla,claves[1])){ // Ejercicio 2
		cadenas_validas = leerDiccionario(in, &_estados,&_alfabeto,&_estado_inicial,&_tabla_de_transicion,&_estados_de_aceptacion);
		printf("Cadenas validas encontradas: [%d]", SNumElem(cadenas_validas));
		SImpLista(cadenas_validas);
		printf("\n\n");
	}
	else
		printf("\narchivo no valido\n");

	numFilasDeArchivo();

    return 0;
}

/*
	do{
        LimpiaBuffer();
		printf("\nRealizar otra operacion?(S/N) ");
		scanf("%c",&control);
        usleep(1200000); // pausa de 3.5 segundos

        free(_estados);
        free(_alfabeto);
        free(_tabla_de_transicion);
        free(_estados_de_aceptacion);
        free(cadena);
		fclose(tupla);
        fclose(in);

        if((control != 'S')||(control != 's'))
            printf("\nEnding...\n");
	}while((control == 'S')||(control == 's'));
*/