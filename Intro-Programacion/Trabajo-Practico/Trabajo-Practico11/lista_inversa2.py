
lista = ["Di", "buen", "dia", "a", "papa"]
lista_auxiliar = []

for i in range (len(lista)-1, -1, -1):
    lista_auxiliar.append(lista[i])

lista = []
for i in lista_auxiliar:
    lista.append(i)

print(lista)