
def numero_positivo (numero):
    if numero > 0:
        return True
    else:
        return False

numero = int(input("Ingrese un numero: "))
print(numero_positivo(numero))
