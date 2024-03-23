
s = "Hola"
acumulador = ""
n = int(input("Ingrese un numero: "))
m = int(input("Ingrese otro numero: "))
for numero in range(len(s)):
    if (numero < n or numero > m):
        acumulador = acumulador + s[numero]

print(acumulador)