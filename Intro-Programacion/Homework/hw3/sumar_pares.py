
n1 = 10
n2 = 11
pares = False
suma = 0
if (pares == True):
    if (n1%2 == 0):
        for numero in range (n1, n2+1, 2):
            suma += numero
    else:
        for numero in range (n1+1, n2, 2):
            suma += numero
else:
    if (n1%2 == 1):
        for numero in range (n1, n2+1, 2):
            suma += numero
    else:
        for numero in range(n1+1, n2+1, 2):
            suma += numero

print(suma)