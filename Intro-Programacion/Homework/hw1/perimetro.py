
from unittest import result


def perimetro(base, altura):
    perimetro = 2 * (base + altura)
    resultado = perimetro
    return resultado

base = 2
altura = 1
resultado = perimetro(base, altura)

print(resultado)