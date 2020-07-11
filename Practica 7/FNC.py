# -*- coding: utf-8 -*-
# Equipo
# Garcia Gonzalez Aaron Antonio
# Osornio Zambrano Aciini Alberto
# Fecha de entrega: Martes 21 de Mayo de 2019.
# Programa principal practica 7

posiblesVariables={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
                   'S','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n',
                   'o','p','q','r','s','w','x','y','z'}

#devuelve una variable no suada 
def variableDisponible():
    for var in posiblesVariables :
        if ( not(var in terminales ) and not( var in variables) and not( var in producciones) ):
            return var 
        else:
            continue
#devuelve true si es terminal        
def esTerminar(texto):
    return texto in terminales       


#encuentra una produccion terinal si existe  cuya terminal sea el parametro
def extProdTerminal(terminal):
    for  var in producciones :
        if ( len( producciones[var] ) ==1 and   (producciones[var][0] in terminales ) and producciones[var][0]== terminal ):
            return  var
    return False
#encuentra la producciion con la derivacion que necesitamos si exite
#esta produccion tiene que tener una unica dericacion    
def extDerivacion(deriv):
     for  var in producciones :
        if ( len( producciones[var] ) ==1    and producciones[var][0]== deriv ):
            return  var
     return False


f = open("gramatica8.txt")
f.readline() #linea de la descr
#leer datos de la gramatica
variables=f.readline().rstrip("\n").rstrip("}")[5:]
variables=variables.split(",");
terminales=f.readline().rstrip("\n").rstrip("}")[5:]
terminales =terminales.split(",")
inicial=f.readline().rstrip("\n")[4:]
f.readline() # leer cabecera de la las producciones

#cargar las producciones
producciones ={}

#leer linea por linea  cada produccion y pasarla a un array asociativo
for i in range(len(variables)):
    linea =f.readline()
    variable = linea[0]
    linea  = linea[5:].rstrip().split(" | ")
    #print linea
    producciones[variable]=linea 


#mostrar toda la gramtica

print "Variables"
print variables
print "Terminales"
print terminales
print "Inicial"
print inicial
print "Producciones"
print producciones

##cambiar terminales 
#recorrer  cada derivacion  
for var in producciones.keys():
  if( len(producciones[var])>1 ):  ##no hacer esto para las  variables con una derivacion y es terminal
    for derv in range ( len( producciones[var] )):
        for i in range(len(   producciones[var][derv]   )):
            if esTerminar( producciones[var][derv][i]):   #si es terinal   
                varConTer = extProdTerminal(producciones[var][derv][i])    #ver si existe una derivacion con esa  terminal
                if ( not (varConTer)):   #si no existe 
                    newVar = variableDisponible() #buscar una variable sin usar
                    producciones[newVar]=[]  #agregarla 
                    producciones[newVar].append(producciones[var][derv][i])   #la asemos igual a la  terminal
                    #reemplazamos  las terminales por la nueva variable
                    producciones[var][derv] = producciones[var][derv].replace(producciones[var][derv][i],newVar) 
                else:
                    #si ya existe sustituimos la terminal por la variable existente
                    producciones[var][derv] = producciones[var][derv].replace(producciones[var][derv][i],varConTer)                        
       
print "prod con variables que solo derivan un terminal"
print producciones       

#quitar derivaciones de mas de 2 terminos    

for var in producciones.keys():
    for derv in range ( len( producciones[var] )):
        #mientras el tamaño es mas de dos    
        while( len(producciones[var][derv])>2 ):   
          ult2Symb =producciones[var][derv][-2:]          
          varDerv= extDerivacion(ult2Symb)
          if( not(varDerv)):
            newVar = variableDisponible() #buscar una variable sin usar
            producciones[newVar]=[]  #agregarla 
            producciones[newVar].append(ult2Symb)   #la asemos igual a la  terminal
            #reemplazamos  las terminales por la nueva variable
            producciones[var][derv] = producciones[var][derv].replace(ult2Symb,newVar) 
          else:
            #si ya existe sustituimos la terminal por la variable existente
            producciones[var][derv] = producciones[var][derv].replace(ult2Symb,varDerv)                        
print "prod finales"
print producciones   
               