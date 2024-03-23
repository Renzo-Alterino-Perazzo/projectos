

lado1 = int(input("Ingrese la longitud del primer lado: "))
lado2 = int(input("Ingrese la longitud del segundo lado: "))
lado3 = int(input("Ingrese la longitud del tercer lado: "))

if (lado1 == lado2) and (lado1 == lado3):
    triangulo = "Es un triangulo equilatero"
elif (lado1 != lado2) and (lado1 != lado3) and (lado2 != lado3):
    triangulo = "Es un triangulo escaleno"
else:
    triangulo = "Es un triangulo isoceles"

print(triangulo)