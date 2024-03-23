

def mayor_ (L):
    mayor = L[0]
    pos = 0
    for i in range(1, len(L)):
        if L[i] > mayor:
            mayor = L[i]
            pos = i
    print(mayor)
    print(pos)
    return None

L = []
for i in range(10):
    L.append(i)

mayor_(L)