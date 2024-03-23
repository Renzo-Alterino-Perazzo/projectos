
numero = int(input("Ingrese un numero: "))
denominador = int(input("Ingrese un denominador: "))

if denominador != 0:
    division = numero / denominador
    division = round(division, 2)
    resultado = f"El resultado de la division entre {numero} y {denominador} es {division}"
else:
    resultado = "No se puede dividir por cero"
print(resultado)