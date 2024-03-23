
from ast import Return


def decime_mes (x):
    if x == 1:
        return "Enero"
    elif x == 2:
        return "Febrero"
    elif x == 3:
        return "Marzo"
    elif x == 4:
        return "Abril"
    elif x == 5:
        return "Mayo"
    elif x == 6:
        return "Junio"
    elif x == 7:
        return "Julio"
    elif x == 8:
        return "Agosto"
    elif x == 9:
        return "Septiembre"
    elif x == 10:
        return "Octubre"
    elif x == 11:
        return "Noviembre"
    elif x == 12:
        return "Diciembre"
    else:
        return "No valido"

x = int(input("Ingrese numero del mes: "))
mes = decime_mes(x)

print(mes)