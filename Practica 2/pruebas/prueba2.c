#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Elem.h"
#include "Lista.h"

int main(int argc, char const *argv[]){
    String linea = newString();
    FILE *f = fopen(*(argv+1),"r");
    int cont = 1;
    Lista list = Vacia();
    int conta = 0;

    while (fgets(linea, 100, f) != NULL){
        conta++;
    }
    rewind(f);

    while (fgets(linea,100,f) != NULL){
        list = Cons(linea,list);
        cont++;
    }
    
    printf("\n");
    ImpLista(list);

    return 0;
}