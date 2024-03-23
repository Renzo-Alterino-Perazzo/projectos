
print("Ingrese 10 numeros")
for numeros in range (1, 10+1):
    numero = int(input("Ingrese un numero: "))
    if numero > 0:
        print("Numero positivo")
    elif numero == 0:
        print("Igual a 0")
    else:
        print("Numero negativo")