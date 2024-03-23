
palabra = "Hola"

def imprimir_caracteres (palabra):    
    print(palabra[0:2])

def imprimir_ultimos (palabra):
#    for i in range (len(palabra) - 3, len(palabra)):
#        print(palabra[i])
#    print(palabra[1:4])
    print(palabra[len(palabra)-3:len(palabra)])

def imprimir_alreves (palabra):
    for i in range (len(palabra)):
        v = len(palabra) - i -1
        print(palabra[v], end="")
    print("")

imprimir_caracteres (palabra)
imprimir_ultimos (palabra)
imprimir_alreves (palabra)