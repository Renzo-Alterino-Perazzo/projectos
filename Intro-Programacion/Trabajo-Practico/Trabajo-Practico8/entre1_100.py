
numero = int(input("Ingrese un numero entre 1 y 100: "))
while (numero < 1) or (numero > 100):
    print("El numero ingresado esta fuera del rango permitido")
    numero = int(input("Ingrese un numero entre 1 y 100: "))

print(f"{numero} es valido. Gracias!")