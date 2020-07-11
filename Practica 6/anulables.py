# -*- coding: utf-8 -*-

# ve si la cadena enviada contiene producciones anulables
def contieneTerminales(texto):
    for terminal in terminales:  # recorre los terminales
        try:
            texto.index(terminal)  #comprueba si esta contenido algun terminal en el texto
            return True 
        except:
            continue
    return False  # si termino de recorrer y no encontro alguno   , false


#verifica si el texto enviado contien algun anulable
def contieneAnulable(texto):
    for letra in texto:
        if (letra in VarAnulables):
            return True
    return False


f = open("G3.txt")
f.readline() #linea de la descr
#leer datos de la gramatica
variables=f.readline().rstrip("\n").rstrip("}")[5:]
variables=variables.split(",");
terminales=f.readline().rstrip("\n").rstrip("}")[5:]
terminales =terminales.split(",")
inicial=f.readline().rstrip("\n")[4:]
f.readline() # leer cabecera de la las producciones
# rstrip("c")

producciones ={}

for i in range(len(variables)):
    linea =f.readline()
    variable = linea[0]
    linea  = linea[5:].rstrip().split(" | ")
    #print linea
    producciones[variable]=linea 


print ("Variables")
print (variables)
print ("Terminales")
print (terminales)
print ("Inicial")
print (inicial)
print ("Producciones")
print (producciones)


print ("recorrer producciones")

VarAnulables ={}

for i in range(len(variables)): # repetir tantas variables exista    
    for var in producciones:  #recorer cada variable  en produccion
        for prod in range(len(  producciones[var])): # recorer cada produccion  que tenga cada variable
            producActual =producciones[var][prod] 
            # ver si tiene produccion vacia  or  (no tenga terminales y tenga alguna anulable)     
            if(producActual =='e' )  or ( not contieneTerminales(producActual) and contieneAnulable(producActual)    ):           
                if ( not  var in  VarAnulables ): # si no existe la variable en las varAnulables
                    VarAnulables[var]=[producActual] ##agregarla como una nueva con la produccion que da su anulabilidad
                else:  # de lo contrrio  si no  se ha agregado esa produccion 
                    if (not (producActual in VarAnulables[var]) ):  
                        VarAnulables[var].append(producActual)  # agregarla a la lista

print("Variables anulables")
print(VarAnulables)


   


        