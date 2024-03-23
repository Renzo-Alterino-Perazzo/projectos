
menor = 9999
for numero in range(10):
    n = int(input("Ingrese un numero: "))
    if (n < menor):
        menor = n
        posicion = numero + 1

print(f"El numero menor es {menor} en la posicion {posicion}")