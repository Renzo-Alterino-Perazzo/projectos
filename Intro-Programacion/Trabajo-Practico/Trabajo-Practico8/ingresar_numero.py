
print("Ingrese 10 numeros")
n = 1
while (n <= 10):
    numero = int(input("Ingrese un numero: "))
    if numero > 0:
        print("Numero positivo")
    elif numero == 0:
        print("Igual a 0")
    else:
        print("Numero negativo")
    n += 1