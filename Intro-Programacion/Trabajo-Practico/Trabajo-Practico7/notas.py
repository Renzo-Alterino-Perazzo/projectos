
suma = 0
for i in range(3):
    nota = float(input(f"Nota estudiante {i}: "))
    suma += nota

promedio = (suma/3)
promedio = round(promedio, 2)
print(f"El promedio es {promedio}")