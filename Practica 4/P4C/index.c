// Integrante 1: Garcia Gonzalez Aaron Antonio
// Integrante 2: Osornio Zambrano Alberto Aacini
// Entrega de practica 4: Martes 02 de Abril de 2019
// Programa principal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sistema.h"
#include "Elem.h"
#include "Pila.h"
#include "utilidades.h"

int main(int argc, char const *argv[]){
	String cad = newString();
	char control;
	int seleccion;
	
	do{
		cleanDisplay();
		printf("Teclee una cadena: ");
		scanf("%[^\n]",cad);
		cleanDisplay();
		printf("Cadena tecleada: %s\n",cad);
		CleanBuffer();

		printf("\t\t\tMenu\n");
		printf("[1]. Programa para saber si una cadena binaria es un palindromo.\n");
		printf("[2]. Programa para saber si una cadena pertenece al lenguaje L = {0^n^1n|n ≥ 1}\n");
		printf("[3]. Programa para saber si una cadena pertenece al lenguaje L = {ww^r|w ∈ {a, b}\n");
		printf("[4]. Programa para saber si una cadena pertenece al lenguaje L = {xy|x, y ∈ {0, 1}* y |x| = |y| pero x /= y}.\n");
		printf("     Selecciona una opcion: ");
		scanf("%d",&seleccion);

		printf("\n");
		switch(seleccion){
			case 1:
				if(hasBinaryAlphabet(cad) && isPalindrome(cad))
					printf("La cadena: %s, es una palindromo binario\n",cad);
				else
					printf("La cadena: %s, NO es una palindromo binario.\n",cad);
				break;
			case 2: 
				break;
			case 3:
				if(isPalindromeAndLenPair(cad))
					printf("La cadena: %s, pertenece al lenguaje L = {ww^r|w ∈ {a, b}\n",cad);
				else
					printf("La cadena: %s, NO pertenece al lenguaje L = {ww^r|w ∈ {a, b}\n",cad);
				break;
			case 4:
				break;
			default:
				printf("Opcion no valida\n");
		}


		printf("\n\nVolver a elegir[S/N]: ");
		CleanBuffer();
		scanf("%c",&control);
		CleanBuffer();
	}while((control == 's')||(control == 'S'));

	free(cad);

	return 0;
}


/*
	// ---------- Ejercicio 3 ------------------------------------
	if(isPalindromeAndPair(cad))
		printf("La cadena: %s, ES Valida para 3\n",cadena);
	else
		printf("La cadena: %s, NO ES Valida para 3\n",cadena);
*/