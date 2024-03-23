
lado1 = int(input("Ingrese la longitud del primer lado: "))
lado2 = int(input("Ingrese la longitud del segundo lado: "))
lado3 = int(input("Ingrese la longitud del tercer lado: "))

if (lado1 == lado2) and (lado1 == lado3):
    triangulo = "Es un triangulo equilatero"
elif (lado1 == lado2) and (lado1 != lado3):
    triangulo = "Es un triangulo isoceles"
elif (lado1 == lado3) and (lado1 != lado2):
    triangulo = "Es un triangulo isoceles"
elif lado2 == (lado3 and lado2 != lado1):
    triangulo = "Es un triangulo isoceles"
elif (lado1 != lado2) and (lado1 != lado3) and (lado2 != lado3):
    triangulo = "Es un triangulo escaleno"
else:
    triangulo = "No valido"

print(triangulo)