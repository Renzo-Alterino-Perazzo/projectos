
nota = 0
cantidad = 0
suma = 0

while (nota != 99):
    nota = float(input("Ingrese un numero entre 1 y 10: "))
    while (nota < 1 or nota > 10) and (nota != 99):
        print("Error")
        nota = float(input("Ingrese un numero entre 1 y 10: "))
    if nota != 99:
        cantidad += 1
        suma += nota

promedio = suma/cantidad
promedio = round(promedio, 2)

print(f"La nota promedio es {promedio}")