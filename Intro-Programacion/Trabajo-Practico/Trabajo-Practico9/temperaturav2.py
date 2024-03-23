
temperatura = input("Ingrese la temperatura en grados Celsius: ")
while temperatura.isalpha() or temperatura=="":
    print("Error")
    temperatura = input("Ingrese la temperatura en grados Celsius: ")
temperatura = int(temperatura)

while (temperatura < -18) or (temperatura > 50):
    print("Valor no valido")
    temperatura = input("Ingrese la temperatura en grados Celsius: ")
    while temperatura.isalpha() or temperatura=="":
        print("Error")
        temperatura = input("Ingrese la temperatura en grados Celsius: ")
    temperatura = int(temperatura)

print(f"La temperatura es {temperatura} grados Celsius")