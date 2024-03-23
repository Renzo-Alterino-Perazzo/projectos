
k = 10
lista = []
for numero in range(20):
    lista.append(numero)

def numero_k(lista, k):
    menor = []
    mayor = []
    igual = []
    multiplo = []
    for i in lista:
        if i < k:
            menor.append(i)
        elif i > k:
            mayor.append(i)
        else:
            igual.append(i)
        if (i%k == 0) and (i != 0):
            multiplo.append(i)
    return menor, mayor, igual, multiplo

menor, mayor, igual, multiplo = numero_k(lista, k)
print(menor)
print(mayor)
print(igual)
print(multiplo)
#for i in lista:
#    print(i)