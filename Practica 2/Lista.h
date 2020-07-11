// Equipo: García González Aarón Antonio && Osornio Zambrano Alberto Aacini
// Teoria de la computación
// Reporte de primera practica de laboratorio 
// Fecha de entrega: 12-Febrero-2019

// Definiciones y funciones con el TDA Lista

typedef struct NodoL{
	Elem dato;
	struct NodoL * siguiente;
} * Lista;

Lista Vacia(){
	return NULL;
}

// Construye un nodo 
Lista Cons(Elem e, Lista l){ 
	Lista auxiliar = (Lista)malloc(sizeof(struct NodoL));
	auxiliar -> dato = e;
	auxiliar -> siguiente = l;
	return auxiliar;
}

// Verifica si esta vacia la lista
int esVacia(Lista l){
	return l == Vacia(); // 0 si es falso, 1 distinto de 0
}

// Obtiene la cabeza de la lista
Elem Cabeza(Lista l){
	return l -> dato;
}

// Obtiene el resto de la lista
Lista Resto(Lista l){
	return l -> siguiente;	
}

// Cuenta el numero de nodos/elementos de la lista
int NumElem(Lista l){
	if(esVacia(l)){
		return 0;
	}
	else{
		return 1 + NumElem(Resto(l));
	}
}

// imprime la lista
void ImpLista(Lista l){
	if(!esVacia(l)){
		ImpElem(Cabeza(l));
		ImpLista(Resto(l));
	}
}

// Une dos listas
Lista PegaListas(Lista x, Lista y){
	if(esVacia(x)){
		return y;
	}
	else{
		return Cons(Cabeza(x),PegaListas(Resto(x),y));
	}
}

// Invierte una lista
Lista InvierteLista(Lista l){
	if(esVacia(l)){
		return l;
	}
	else{
		return PegaListas(InvierteLista(Resto(l)),Cons(Cabeza(l),Vacia()));
	}
}


/* Funcion que reciba como argumento un elemto y una lista
	y devuelve verdadero si el elemento esta en la lista o falso en caso contrario*/
int estaEn(Elem e, Lista l){
	if(esVacia(l)){
		return 0;
	}
	else if(sonIguales(e,Cabeza(l))){
		return 1;
	}
	else{
		return estaEn(e,Resto(l));
	}
}


////////////// Lista String ///////////////////

typedef struct SNodoL{
	ElemString dato;
	struct SNodoL * siguiente;
} * SLista;

SLista SVacia(){
	return NULL;
}

// Construye un nodo 
SLista SCons(ElemString e, SLista l){ 
	SLista auxiliar = (SLista)malloc(sizeof(struct NodoL));
	auxiliar -> dato = e;
	auxiliar -> siguiente = l;
	return auxiliar;
}

// Verifica si esta vacia la lista
int SesVacia(SLista l){
	return l == SVacia(); // 0 si es falso, 1 distinto de 0
}

// Obtiene la cabeza de la lista
ElemString SCabeza(SLista l){
	return l -> dato;
}

// Obtiene el resto de la lista
SLista SResto(SLista l){
	return l -> siguiente;	
}

// Cuenta el numero de nodos/elementos de la lista
int SNumElem(SLista l){
	if(SesVacia(l)){
		return 0;
	}
	else{
		return 1 + SNumElem(SResto(l));
	}
}

// imprime la lista
void SImpLista(SLista l){
	if(!SesVacia(l)){
		SImpElem(SCabeza(l));
		SImpLista(SResto(l));
	}
}

// Une dos listas
SLista SPegaListas(SLista x, SLista y){
	if(SesVacia(x)){
		return y;
	}
	else{
		return SCons(SCabeza(x),SPegaListas(SResto(x),y));
	}
}

// Invierte una lista
SLista SInvierteLista(SLista l){
	if(SesVacia(l)){
		return l;
	}
	else{
		return SPegaListas(SInvierteLista(SResto(l)),SCons(SCabeza(l),SVacia()));
	}
}


/* Funcion que reciba como argumento un elemto y una lista
	y devuelve verdadero si el elemento esta en la lista o falso en caso contrario*/
int SestaEn(ElemString e, SLista l){
	if(SesVacia(l)){
		return 0;
	}
	else if(SsonIguales(e,SCabeza(l))){
		return 1;
	}
	else{
		return SestaEn(e,SResto(l));
	}
}


///////// Lista de enteros ///////////////

typedef struct INodoL{
	ElemInt dato;
	struct INodoL * siguiente;
} * ILista;


ILista IVacia(){
	return NULL;
}

// Construye un nodo 
ILista ICons(ElemInt e, ILista l){ 
	ILista auxiliar = (ILista)malloc(sizeof(struct INodoL));
	auxiliar -> dato = e;
	auxiliar -> siguiente = l;
	return auxiliar;
}


// Verifica si esta vacia la lista
int IesVacia(ILista l){
	return l == IVacia(); // 0 si es falso, 1 distinto de 0
}

// Obtiene la cabeza de la lista
Elem ICabeza(ILista l){
	return l -> dato;
}

// Obtiene el resto de la lista
ILista IResto(ILista l){
	return l -> siguiente;	
}

// Cuenta el numero de nodos/elementos de la lista
int INumElem(ILista l){
	if(IesVacia(l)){
		return 0;
	}
	else{
		return 1 + INumElem(IResto(l));
	}
}

// imprime la lista
void IImpLista(ILista l){
	if(!IesVacia(l)){
		IImpElem(ICabeza(l));
		IImpLista(IResto(l));
	}
}

// Une dos listas
ILista IPegaListas(ILista x, ILista y){
	if(IesVacia(x)){
		return y;
	}
	else{
		return ICons(ICabeza(x),IPegaListas(IResto(x),y));
	}
}

// Invierte una lista
ILista IInvierteLista(ILista l){
	if(IesVacia(l)){
		return l;
	}
	else{
		return IPegaListas(IInvierteLista(IResto(l)),ICons(ICabeza(l),IVacia()));
	}
}


/* Funcion que reciba como argumento un elemto y una lista
	y devuelve verdadero si el elemento esta en la lista o falso en caso contrario*/
int IestaEn(ElemInt e, ILista l){
	if(IesVacia(l)){
		return 0;
	}
	else if(IsonIguales(e,ICabeza(l))){
		return 1;
	}
	else{
		return IestaEn(e,IResto(l));
	}
}











