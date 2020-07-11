# Equipo 
# Garcia Gonzalez Aaron Antonio
# Osornio Zambrano Aciini Alberto 
# Fecha de entrega: Martes 14 de Mayo de 2019.
# Programa principal practic 6

name_file_Gramatica = input("Teclee el nombre del archivo que contiene la gramatica: ")
file_Gramatica = open(name_file_Gramatica,"r")

variables = list(file_Gramatica.readline().replace("{","").replace("}","").replace("=","").replace('\n',"").replace(" ", "").replace(",", ""))
temrinales = list(file_Gramatica.readline().replace("{","").replace("}","").replace("=","").replace('\n',"").replace(" ", "").replace(",", ""))
inicial = list(file_Gramatica.readline().replace("=","").replace('\n',"").replace(" ", ""))

file_Gramatica.readline() # Para saltaar la linea de "producciones"

pos_aux = file_Gramatica.tell() 
no_lineas = len(file_Gramatica.readlines())
file_Gramatica.seek(pos_aux)


print(file_Gramatica.readline().rstrip('\n'))





#fila_auxiliar = file_Gramatica.readline().replace("-","").replace(">",",").replace("|",",").replace(" ","").replace('\n',"").split(',')
#p["a"]=fila_auxiliar