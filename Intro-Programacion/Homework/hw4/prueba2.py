
s = "Hola"
n = int(input("Ingrese un numero: "))
m = int(input("Ingrese un numero: "))
acumulador = ""

for numero in range(n, m+1):
    if (numero < n or numero > m):
        acumulador = acumulador + s[numero]

print(acumulador)