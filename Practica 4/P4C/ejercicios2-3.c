

/*
ejercicio 

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Elem.h"
#include "Pila.h"


// pide una cadena de texto y si esta pertenece a L={0^n 1^n|n>=1}
//devuelve true
int  mismoNumero0y1(){
	char c;
	Stack pilaA=NULL;
	char leidoUnUno=0; //por defecto no se a leido ni un uno
	printf("Escribe una cadena :");
	//lee caracter por caracter  hasta enocntrar salto de linea
	while( (c=getchar())!='\n'){
		if(c =='0'){      //si se le un 0
			if (leidoUnUno){ // si ya se habia leido un 1 			 
			 	return 0;   //no es parte del lenguaje
			 } 
			pilaA= Push(c,pilaA); // de lo contrario agregar a la pila el 0
		}else if (c=='1'){ // si se lee un 1
			leidoUnUno =1;  // marcar como leido un 1
			if (isEmpty(pilaA) ) { // si la pila  esta vacia 
 // no  puede haber mismo numero de 0's q  1's en ese orden
				return 0;    //no es parte del lenguaje
			}else{ 			// de lo contrario
				pilaA= Pop(pilaA);	 //sacar un elemento de la pila
			}

			
		}else{  // si no es  0 o 1  no pertenece al diccionario
			printf("caracter %c no pertenece al diccionario\n",c );
			return 0; // no es parte del lenguaje
		}
	}

	if ( !isEmpty(pilaA) || !leidoUnUno ){   // si la pila no esta vacia 											// o nunca se leyo un 1 (por tanto ningun 0) 
				return 0;  //no es parte del lenguaje
	}else{
		return 1;    //de lo contrario si es parte del lenguaje
	}
}


//invierte el orden de una pila 
//por recursividad
Stack InvPilaRec(Stack anterior,Stack elemento){
	Stack nuevaCab;
	if(elemento->siguiente){  //si exite un elemnto mas abajo de la pila
	 	nuevaCab =InvPilaRec(elemento,elemento->siguiente);	 //	mandarlo a recursividad
	 }else{
	 	nuevaCab = elemento;   // de lo contrario guardar este elemento como nueva cabecera
	 }
	 elemento->siguiente=anterior; // hacer el elemnto siguiente el anterior
	return nuevaCab; // regresar la nueva cabecera
}


int tamPuntero(char * puntArry){

 //leer 
	 int cont =0;
	 while( (puntArry[cont]!='\0' ) ){
	 	cont++;

	 }

	 return cont;

}


//  revisa si una cadena w pertenece al lenguaje
//L = {xy|x, y ∈ {0, 1}^∗ y |x| = |y| pero x 6 = y}
// mismo tamaño pero diferentes substrings
int mismoTamDifSubstr(){
	char c;
	Stack pilaA=NULL;
	Stack pilaB=NULL;
	Stack pilaC=NULL;
	int cont=0; // contar cuantas letras se han incertado
	printf("Escribe una cadena :");
	//lee caracter por caracter  hasta enocntrar salto de linea
	while( (c=getchar())!='\n'){
		if(c!='0' || c!='1') // si el caracter no pertence al diccionario
			return 0;         // no es  parte del diccionario
		pilaA= Push(c,pilaA);  // ingresar cada 
		cont++;//aumentar el contador
	}

	if(cont==0)// si es cadena vacia regresa true
		return 1;

	if( (cont%2)!=0 )// si el tamaño no es multiplo de 2
		return 0;  // no pertenece
	
	//TAMAÑO DE X  E  Y
	int tamX=cont/2;


	for (int i = 0; i < tamX; i++){ //dividir en dos la cadena
		 pilaB =Push( Top(pilaA), pilaB  );
		 pilaA=Pop(pilaA);
	}
 	
 	//voltear contenido en una tercer pila
 	for (int i = 0; i < tamX; ++i)
 	{
 		pilaC=Push( Top(pilaB), pilaC  );
 		 pilaB=Pop(pilaB);
 	}
	for (int i = 0; i <tamX; i++) {
		if( Top(pilaC)!=Top(pilaA) ){
			return 1;   // conque no coencida 1 es falsa
		}
		pilaA=Pop(pilaA); // quitar un elemento a las pilas  
		pilaC=Pop(pilaC);
	}


	return 0;

}




int main(int argc, char const *argv[]){
	//ejercicio 2
	/*int res = mismoNumero0y1();
	if (res)
	{
		printf("Es parte del lenguaje   L={0^n 1^n|n>=1} \n");
	}else{
		printf("No es parte del lenguaje   L={0^n 1^n|n>=1} \n");
	}
	*/
     //ejercicio 4
	int res=mismoTamDifSubstr();
	if (res){
		printf("Es parte del lenguaje  L = {xy|x,y ∈ {0, 1}^∗ y |x| = |y| pero x != y}\n");
	}else{
		printf("NO es parte del lenguaje   L = {xy|x, y ∈ {0, 1}^∗ y |x| = |y| pero x != y} \n");
	}

}