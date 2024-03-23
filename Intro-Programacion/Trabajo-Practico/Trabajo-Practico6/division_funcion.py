
def division(numero, denominador):
    if denominador != 0:
        division = numero / denominador
        division = round(division, 2)
        resultado = division
    else:
        resultado = "No se puede dividir por cero"
    return resultado

numero = int(input("Ingrese un numero: "))
denominador = int(input("Ingrese un denominador: "))

resultado = division(numero, denominador)
print(resultado)