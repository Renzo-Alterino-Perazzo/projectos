
def situacion_alumno(p1, p2):
    promedio = (p1 + p2)/2
    if promedio >= 8:
        return "Promovido"
    elif promedio >= 4:
        return "Regular"
    else:
        return "Libre"

p1 = int(input("Ingrese nota del primer parcial: "))
p2 = int(input("Ingrese nota del segundo parcial: "))
promedio = situacion_alumno(p1, p2)

print(promedio)