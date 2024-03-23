
numero = int(input("Ingrese un numero: "))
posicion_mayor = 1
posicion_menor = 1
mayor = numero
menor = numero
n = 0

while (n < 10):
    n += 1
    if (numero > mayor):
        mayor = numero
        posicion_mayor = n
    elif (numero < menor):
        menor = numero
        posicion_menor = n
    if (n < 10):
        numero = int(input("Ingrese un numero: "))

print(f"El numero mayor es {mayor} en la posicion {posicion_mayor}")
print(f"El numero menor es {menor} en la posicion {posicion_menor}")