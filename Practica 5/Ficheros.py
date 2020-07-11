# Equipo 
# Garcia Gonzalez Aaron Antonio
# Osornio Zambrano Aciini Alberto
# Fecha de entrega: Martes 7 de Mayo de 2019.
# Modulo con las funciones necesarias para imprimir las tuplas (AFD y gramatica) en un archivo.

# --------------- Funcion que recibe como parametros; el archivo donde se almcenara la tupla y 
#                   la tupla del AFD que se escribira en el archivo.
def imprimirEnArchivo_AFD(file_Gramatica,estados_AFD,alfabeto_AFD,simbolo_inicial_ADF,finales_AFD,tabla_AFD,enunciado_AFD):

    file_Gramatica.write("Convercion de tuplas: AFD a Gramatica" + '\n\n')
    file_Gramatica.write(enunciado_AFD +'\n')
    file_Gramatica.write("Tupla AFD (Q,Σ,q,δ,F)"+'\n')
    file_Gramatica.write("Q = {" + ','.join(estados_AFD) + '}' + '\n')
    file_Gramatica.write("Σ = {" + ','.join(alfabeto_AFD) + '}' + '\n')
    file_Gramatica.write("q = "+ simbolo_inicial_ADF + '\n')
    file_Gramatica.write("F = {" + ','.join(finales_AFD) + '}' + '\n\n')

    for i in tabla_AFD:
        file_Gramatica.write(''.join(i) + '\n')
    return

# --------------- Funcion que recibe como parametros; el archivo donde se almcenara la tupla y 
#                   la tupla de la gramatica que se escribira en el archivo.
def imprimirEnArchivo_Gramatica(file_Gramatica,variables_G,terminales_G,simbolo_inicial_G,producciones_G):
    file_Gramatica.write('\n' +     "Tupla Gramatica (V,T,P,S)"+'\n')
    file_Gramatica.write("V = {" + ','.join(variables_G) + '}' + '\n')
    file_Gramatica.write("T = {" + ','.join(terminales_G) + '}' + '\n')
    file_Gramatica.write("S = " + simbolo_inicial_G + '\n')
    file_Gramatica.write("Producciones" + '\n')

    for i in producciones_G:
        aux = ''.join(i)[0] + " -> " + ''.join(i)[1:len(''.join(i))]
        file_Gramatica.write(aux + '\n')
    return