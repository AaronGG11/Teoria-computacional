# TDA Pila 

class Pila: # Creamos la clase Stack
    def __init__(self):
        self.items = []
    
    def isVacia(self): # Metodo para verificar si la pila esta vacia
        return self.items == []
    
    def apilar(self, item): # Metodo para insertar elementos a la pila
        self.items.append(item)
    
    def desapilar(self): # Metodo para eliminar el ultimo elemento apilado
        return self.items.pop()
    
    def impPila(self): # Metodo para mostrar los elementos de la pila
        print(self.items)

    def tope(self): # 
        return self.items[len(self.items)-1]

    def tamPila(self):
         return len(self.items)
