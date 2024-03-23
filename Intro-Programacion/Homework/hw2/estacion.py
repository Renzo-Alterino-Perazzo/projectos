
def estacion(x):
    if x == 1:
        return "Verano"
    elif x == 2:
        return "Verano"
    elif x == 3:
        return "Verano"
    elif x == 4:
        return "Otoño"
    elif x == 5:
        return "Otoño"
    elif x == 6:
        return "Otoño"
    elif x == 7:
        return "Invierno"
    elif x == 8:
        return "Invierno"
    elif x == 9:
        return "Invierno"
    elif x == 10:
        return "Primavera"
    elif x == 11:
        return "Primavera"
    elif x == 12:
        return "Primavera"
    else:
        return "No valido"

x = int(input("Ingrese el numero del mes: "))
est = estacion(x)

print(est)