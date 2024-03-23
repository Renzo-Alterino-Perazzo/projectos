
def pares_impares(L):
    pares = 0
    impares = 0
    for numero in L:
        if numero%2==0:
            pares += 1
        else:
            impares += 1
    return pares, impares

L = [5,4,-2,3,8,11]
pares, impares = pares_impares(L)
print(pares)
print(impares)