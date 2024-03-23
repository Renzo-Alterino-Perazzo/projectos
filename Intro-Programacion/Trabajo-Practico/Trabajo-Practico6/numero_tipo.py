
numero = int(input("Ingrese un numero: "))

if (numero > 0):
    tipo_numero = f"{numero} es positivo"
elif (numero < 0):
    tipo_numero = f"{numero} es negativo"
elif (numero == 0):
    tipo_numero = f"{numero} es igual a 0"
else:
    tipo_numero = "No valido"

print(tipo_numero)