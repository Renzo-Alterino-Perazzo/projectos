
def mayuscula(palabra):
    resultado = palabra.upper()
    return resultado

def minuscula(palabra):
    resultado = palabra.lower()
    return resultado


def mixta(palabra):
    resultado1 = mayuscula(palabra)
    resultado2 = minuscula(palabra)
    return resultado1, resultado2

palabra = input("Ingrese una palabra: ")
resultado1, resultado2 = mixta(palabra)
print(resultado1)
print(resultado2)