
def cargar (l):
    numero = input("Ingrese un numero: ")
    while numero != "Salir":
        l.append(int(numero))
        numero = input("Ingrese un numero: ")
    return l

l = []
l = cargar(l)
print(l)
print(len(l))
l_indice = l[int(input("Ingrese lugar en el indice: "))-1]
print(l_indice)