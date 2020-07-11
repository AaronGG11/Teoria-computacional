def esPalindroma(a,b):
    cont = 0
    for i in range(0,a.tamPila()):
        if(a.tope() == b.tope()):
            cont += 0
        else:
            cont += 1
        a.desapilar()
        b.desapilar()

    if(cont == 0):
        return 0
    else:
        return 1


def pilaInversa(cadena,pila):
    for i in range(0,len(cadena)):
        if(cadena[i] != " "):
            pila.apilar(cadena[i])

    return pila

def pilaOriginal(cadena,pila):
    for i in range(0,len(cadena)):
        if(i<len(cadena)):
            if(cadena[len(cadena)-1-i] != " "):
                pila.apilar(cadena[len(cadena)-1-i])

    return pila