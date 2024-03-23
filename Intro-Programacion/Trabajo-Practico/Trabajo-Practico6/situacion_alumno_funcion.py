def situacion_alumno (parcial1, parcial2):
    promedio = ((parcial1 + parcial2) / 2)
    if (parcial1 >= 4) and (parcial2 >= 4):
        if (promedio >= 8):
            situacion = "Ha promovido"
        else:
            situacion = "Ha quedado regular"
    else:
        situacion = "Ha quedado libre"
    promedio = f"Su promedio es {promedio}"
    return situacion, promedio

parcial1 = int(input("Ingrese la nota del primer parcial: "))
parcial2 = int(input("Ingrese la nota del segundo parcial: "))

situacion, promedio = situacion_alumno(parcial1, parcial2)

print(promedio)
print(situacion)