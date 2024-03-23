
suma = 0
cantidad = 0
nota = float(input("Ingrese nota (-1 para terminar): "))
while nota != -1:
    suma += nota
    cantidad = (cantidad + 1)
    nota = float(input("Ingrese nota (-1 para terminar): "))

promedio = (suma/cantidad)
print(promedio)