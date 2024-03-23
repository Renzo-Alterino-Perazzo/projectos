
def numero_mayor(numero1, numero2):
    if (numero1 > numero2):
        mayor = f"{numero1} es mayor que {numero2}"
    elif (numero1 < numero2):
        mayor = f"{numero2} es mayor que {numero1}"
    else:
        mayor = "Ambos numeros son iguales"
    return mayor

numero1 = int(input("Ingrese un numero: "))
numero2 = int(input("Ingrese otro numero: "))

print(numero_mayor(numero1, numero2))