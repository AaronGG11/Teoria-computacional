
#include "LDE.c"
//leerArchivoIns();

NODO * leerArchivoIns(FILE * archivo){
NODO* cab =NULL;

  char * buffer = NULL;
  int i, c;
  c = fgetc(archivo);

  while(!feof(archivo)){
      buffer = (char*)realloc(NULL, sizeof(char));
        i = 0;
      while( c != '\n'){
          buffer[i] = c;
          i++;
          buffer = (char*)realloc(buffer,(i+1)*sizeof(char));
          c = fgetc(archivo);
      }

      buffer = (char*)realloc(buffer,(i+2)*sizeof(char));
      buffer[i] = c;
      buffer[i+1] = 0;
      /*Trabajar con el buffer*/
      indNodoCol(&cab,buffer);
      c = fgetc(archivo);
  }
  free(buffer);
  fclose(archivo);

	return cab;
}
