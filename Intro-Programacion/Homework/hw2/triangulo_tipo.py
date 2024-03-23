
def tipo_triangulo (x, y, z):
    if x <= 0 or x >= (y+z):
        return "No es un triangulo"
    elif y <= 0 or y >= (x+z):
        return "No es un triangulo"
    elif z <= 0 or z >= (x+y):
        return "No es un triangulo"
    elif x == y == z:
        return "Equilatero"
    elif x == y != z:
        return "Isosceles"
    elif x == z != y:
        return "Isosceles"
    elif y == z != x:
        return "Isosceles"
    elif x != y != z:
        return "Escaleno"
    else:
        return "No es un triangulo"

x = int(input("Ingrese la longitud del primer lado: "))
y = int(input("Ingrese la longitud del segundo lado: "))
z = int(input("Ingrese la longitud del tercer lado: "))
resultado = tipo_triangulo(x, y, z)

print(resultado)