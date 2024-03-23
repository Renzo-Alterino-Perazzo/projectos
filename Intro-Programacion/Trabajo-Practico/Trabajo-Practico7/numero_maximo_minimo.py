
numero1 = int(input("Ingrese un numero: "))
posicion_mayor = 1
posicion_menor = 1
mayor = numero1
menor = numero1
for numero in range(10-1):
    n = int(input("Ingrese un numero: "))
    if (n > mayor):
        mayor = n
        posicion_mayor = numero + 2
    elif (n < menor):
        menor = n
        posicion_menor = numero + 2
    

print(f"El numero mayor es {mayor} en la posicion {posicion_mayor}")
print(f"El numero menor es {menor} en la posicion {posicion_menor}")
