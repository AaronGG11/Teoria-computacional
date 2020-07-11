// Equipo: García González Aarón Antonio && Osornio Zambrano Alberto Aacini
// Teoria de la computación
// Reporte de primera practica de laboratorio 
// Fecha de entrega: 12-Febrero-2019

// Funciones para operar archivos

// Funcion para leer una tupla completa de un AFD {Q,Σ,s,δ,F} a partir de un archivo 
// Q,Σ,F -> Serán almacenada como listas individuales
// s -> Será almacenado como un caracter
// δ -> Será almacenado como una matriz

void readFile(FILE * in, Lista * b, Lista * c, char * d, Matriz * m, Lista * e){
    char a;
    int cont = 0; // Para contar el numero de saltos de linea
    int cont2 = 0; 
    int cont3 = 0;

    while(!feof(in)){
        fscanf(in,"%c",&a);
        if((a == '\n')||(a == '\0')){
            cont++;
            cont3++;
        }
        if((a != '\n')&&(cont == 0)){ // Primera linea se refiere al conjunto de estados
            printf("%c",a);
        }
        if((a != '\n')&&(cont == 1)){ // Primera linea se refiere al conjunto de estados
            *b = Cons(a,*b);
        }
        if((a != '\n')&&(cont == 2)){ // Segunda linea se refiere al conjunto alfabeto
            *c = Cons(a,*c);
        }
        if((a != '\n')&&(cont == 3)){ // Tercera linea se refiere al estado inicial 
            *d = a;
        }
    }

    *b = InvierteLista(*b);
    *c = InvierteLista(*c);

    rewind(in); // Redirecciona el puntero del file a la primera poscion del mismo
    *m = generaMatriz(*m,NumElem(*b),NumElem(*c)+1);
    cont = 0;
    
    while(!feof(in)){
        fscanf(in,"%c",&a);

        if((a == '\n')||(a == '\0')){
            cont++;
        }
        if((a != '\n')&&(cont > 3)&&(cont < cont3)){ // De la linea 3 al 9 se refiere a la tabla de estados
            aux[cont2] = a;
            cont2++;
        }
        if((a != '\n')&&(cont == cont3)&&(a != '\0')&&(a != EOF)){ // La ultima linea se refiere al conjunto de estados de aceptacion
            *e = Cons(a,*e);
        }
    }
    *e = Resto(*e);  
    *e = InvierteLista(*e);
    llena(*m,NumElem(*b),NumElem(*c)+1,aux);
    printf("\nEstados: ");
    ImpLista(*b);
    printf("\nAlfabeto: ");
    ImpLista(*c);
    printf("\nEdo inicial: %c",*d);
    printf("\nTabla:\n");
    Imprime_Matriz(*m,NumElem(*b),NumElem(*c)+1);
    printf("\nEstados finales: ");
    ImpLista(*e);
}