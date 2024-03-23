
from pickle import FALSE


def triangulo (x, y, z):
    if x <= 0 or x >= (y+z):
        return False
    elif y <= 0 or y >= (x+z):
        return False
    elif z <= 0 or z >= (x+y):
        return False
    elif x < (y+z):
        return True
    elif y < (x+z):
        return True
    elif z < (x+y):
        return True

x = int(input("Ingrese longitud del primer lado: "))
y = int(input("Ingrese longitud del segundo lado: "))
z = int(input("Ingrese longitud del tercer lado: "))
resultado = triangulo(x, y, z)

print(resultado)