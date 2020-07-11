#include<stdio.h>
#include<stdlib.h>

void LimpiaBuffer(){ 
	int ch; 
	while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
} 

int main(int argc, char const *argv[]){
	printf("a.Ingresar 1 peso\n");
	printf("b.Ingresar 5 pesos\n");
	printf("c.Comprar refresco\n");
	printf("d.Devolucion de dinero\n");




//(c - '0')

	return 0;
}
