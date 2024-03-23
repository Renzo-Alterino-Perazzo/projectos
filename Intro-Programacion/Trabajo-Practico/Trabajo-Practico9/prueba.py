
numero = int(input("Ingrese un numero entre 0 y 10: "))

while (numero < 0 or numero > 10):
    print("Error")
    numero = int(input("Ingrese un numero entre 0 y 10: "))

print("Fin")