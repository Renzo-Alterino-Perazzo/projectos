
def numero_menor(x, y):
    if x > y:
        return y
    elif x < y:
        return x
    else:
        return "Son iguales!"

x = int(input("Ingrese un numero: "))
y = int(input("Ingrese otro numero: "))
resultado = numero_menor(x, y)

print(resultado)