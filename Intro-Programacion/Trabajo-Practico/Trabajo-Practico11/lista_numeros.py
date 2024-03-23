
def lista_numeros (lista):
    lista_primos = []
    numeros_primos = [2,3,5,7,11,13,17,19,23,29]
    contador = 0
    while contador < len(lista):
        if lista[contador] in numeros_primos:
            lista_primos.append(lista[contador])
        contador += 1
    suma = 0
    for numero in range(len(lista)):
        suma += lista[numero]
    suma = suma/len(lista)
    lista_factorial = []
    for numero in lista:
        factorial = 1
        for i in range(1,lista[numero]+1):
            factorial = factorial * i
        lista_factorial.append(factorial)
    return lista_primos, suma, lista_factorial

lista = []
for i in range(10):
    lista.append(i)
print(lista)

lista_primos, suma, lista_factorial = lista_numeros(lista)
print(lista_primos)
print(suma)
print(lista_factorial)