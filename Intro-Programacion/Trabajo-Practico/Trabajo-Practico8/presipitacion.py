
mayor = -9999
total = 0
n = 0
while (n < 7):
    presipitacion = int(input("Ingrese precipitacion en milimetros: "))
    total += presipitacion
    if (presipitacion > mayor):
        mayor = presipitacion
        semana = n + 1
    n += 1

promedio = total/7
promedio = round(promedio, 2)
if semana == 1:
    dia = "Domingo"
elif semana == 2:
    dia = "Lunes"
elif semana == 3:
    dia = "Martes"
elif semana == 4:
    dia = "Miercoles"
elif semana == 5:
    dia = "Jueves"
elif semana == 6:
    dia = "Viernes"
elif semana == 7:
    dia = "Sabado"

print(f"El promedio de precipitaciones fue {promedio} mls. diarios")
print(f"El dia de mas prescipitacion fue el {dia}")