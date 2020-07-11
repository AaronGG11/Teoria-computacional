// Equipo: García González Aarón Antonio && Osornio Zambrano Alberto Aacini
// Teoria de la computación
// Reporte de primera practica de laboratorio 
// Fecha de entrega: 12-Febrero-2019

// Definiciones de tipos de dato a utilizar
typedef char Elem;
typedef char * String;

// Funcion para imprimir caracteres
void ImpElem(Elem e){
	printf("%c", e);
}
String newString(){
	String a = (String)malloc(sizeof(256));
	return a;
}

// Funcion que funcione como peficado e indique si dos elementos son iguales
int sonIguales(Elem x, Elem y){
	return x == y;
}
