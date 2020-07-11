
# ------------------------------------ Bibliotecas -------------------------------------
from Stack import * 
from Palindromo import *
import os

# ------------------------------ Declaracion de variables ------------------------------

original = Pila()
inversa = Pila()

# ------------------------------------- Ejecutable --------------------------------------

os.system("clear")
string = input("Teclea una cadena binaria: ").lower()


inversa = pilaInversa(string,inversa)
inversa.impPila()

original = pilaOriginal(string,original)
original.impPila()
