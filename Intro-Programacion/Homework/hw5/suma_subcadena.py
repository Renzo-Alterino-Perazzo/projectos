

l = [1,2,3,4]
n1 = 1
n2 = 3
pares = True
suma = 0
subcadena = []

for numero in range (n1,n2+1):
    if numero >= n1 and numero <= n2:
        subcadena.append(l[numero])
print(subcadena)

if pares == True:
    for numero in subcadena:
        if numero%2 == 0:
            suma += numero
else:
    for numero in subcadena:
        if numero%2 == 1:
            suma += numero

print (suma)