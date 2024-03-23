
palabra = "algoritmos"
voales = "AEIOUaeiuo"
def consonantes (palabra):
    palabra_auxiliar = ""
#    for i in range(len(palabra)):
#        if palabra[i] != "a" and palabra[i] != "e" and palabra[i] != "i" and palabra[i] != "o" and palabra[i] != "u":
    for i in palabra:
        if i not in voales:
            palabra_auxiliar += i
    print(palabra_auxiliar)
        

consonantes(palabra)