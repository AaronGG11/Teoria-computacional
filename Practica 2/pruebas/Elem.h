

/*
//	Para elementos enteros 

typedef int Elem; //Es par eneteros

void ImpElem(Elem e){ 
	printf("%d ", e);
}


int esMenor(Elem e, Elem f){
	return e < f;
}

int sonIguales(Elem e, Elem f){2
	return e == f;
}
*/

typedef char * String;
String newString(){
	String a = (String)malloc(sizeof(256));
	return a;
}


typedef char*Elem;

void ImpElem(Elem e){
	printf("%s\n", e);
}

int esMenor(Elem x, Elem y){
	return strcmp(x,y)<0; /// Checarla
}

int sonIguales(Elem x, Elem y){
	return strcmp(x,y) == 0;
}