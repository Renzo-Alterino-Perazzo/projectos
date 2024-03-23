
def mes_par(x):
    if x == 1:
        return False
    elif x == 2:
        return True
    elif x == 3:
        return False
    elif x == 4:
        return True
    elif x == 5:
        return False
    elif x == 6:
        return True
    elif x == 7:
        return False
    elif x == 8:
        return True
    elif x == 9:
        return False
    elif x == 10:
        return True
    elif x == 11:
        return False
    elif x == 12:
        return True
    else:
        return "No valido"

x = int(input("Ingrese numero del mes: "))
resultado = mes_par(x)

print(resultado)