
from pickle import FALSE


def triangulo (x, y, z):
    if x <= 0:
        return False
    elif y <= 0:
        return False
    elif z <= 0:
        return False
    elif x < (y+z):
        return True
    elif y < (x+z):
        return True
    elif z < (x+y):
        return True
    elif x >= (y+z):
        return False
    elif y >= (x+z):
        return False
    elif z >= (x+y):
        return False

x = int(input("Ingrese longitud del primer lado: "))
y = int(input("Ingrese longitud del segundo lado: "))
z = int(input("Ingrese longitud del tercer lado: "))
resultado = triangulo(x, y, z)

print(resultado)