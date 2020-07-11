// Equipo: García González Aarón Antonio && Osornio Zambrano Alberto Aacini
// Teoria de la computación
// Reporte de primera practica de laboratorio 
// Fecha de entrega: 12-Febrero-2019

// Funciones de sistema

// Funcion para limpiar el buffer del teclado 
void LimpiaBuffer(){ 
	int ch; 
	while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
} 

// Funcion para limpiar pantalla visible
void LimpiaPantalla(){
	system("clear");
}

// Funcion para generar una pausa de programa 
void PausaPrograma(){
	getchar();
}