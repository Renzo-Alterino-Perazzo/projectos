
parcial1 = int(input("Ingrese la nota del primer parcial: "))
parcial2 = int(input("Ingrese la nota del segundo parcial: "))
promedio = (parcial1 + parcial2) / 2

print(f"Su nota promedio es {promedio}")
if (parcial1 >= 4) and (parcial2 >= 4):
    if (promedio >= 8):
        situacion = "Usted a promovido Introduccion a la Programacion"
    else:
        situacion = "Usted a quedado regular en Introduccion a la Programacion"
else:
    situacion = "Usted a quedado libre en Introduccion a la Programacion"
print(situacion)