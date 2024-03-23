
lista = []
for i in range(10):
    lista.append(i)
print(lista[4])

lista_factorial = []

for numero in lista:
    factorial = 1
    for i in range(1,lista[numero]+1):
        factorial = factorial * i
    lista_factorial.append(factorial)

print(factorial)
print(lista_factorial)