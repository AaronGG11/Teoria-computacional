// Integrante 1: Garcia Gonzalez Aaron Antonio
// Integrante 2: Osornio Zambrano Alberto Aacini
// Entrega de practica 4: Martes 02 de Abril de 2019
// Especificacion del TDA Pila (Stack)


// ---------- Declaracion del TDA Pila: estructura autoreferenciada 
typedef struct Nodo{ 
	Elem dato;
	struct Nodo * siguiente;
} * Stack;

// ---------- Funcion que devuelve una pila vacia 
Stack empty(){
	return NULL;
}

// ---------- Funcion apilar un nuevo elemento a la pila 
Stack Push(Elem e, Stack p){
	Stack auxiliar = (Stack)malloc(sizeof(struct Nodo));
	auxiliar -> dato = e;
	auxiliar -> siguiente = p;
	return auxiliar;
}

// ---------- Funcion para comprobar si una pila esta vacia
int isEmpty(Stack p){
	return p == empty();
}


// ---------- Funcion para mostrar el tope de la pila
Elem Top(Stack p){
	return p -> dato;
}

// ---------- Funcion para sacar el tope de la pila
Stack Pop(Stack p){
	return p -> siguiente;
}


// ---------- Funcion para calcular el tamaño de la pila
int numElem(Stack p){
	Stack auxiliar = p;
	int contador = 0;

	while(!isEmpty(auxiliar)){
		auxiliar = Pop(auxiliar);
		contador++;
	}
	return contador;
}

// ---------- Funcion para mostrar una pila sin sacar
void printStack(Stack p){
	Stack auxiliar = p;
	if(isEmpty(auxiliar))
		printf("\n");
	else{
		printElem(Top(auxiliar));
		printStack(Pop(auxiliar));
	}
}



