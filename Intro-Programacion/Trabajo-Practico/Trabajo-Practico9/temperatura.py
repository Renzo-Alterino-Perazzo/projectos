
#rehacer, probablemente de cero, hacer nueva version
temperatura = input("Ingrese la temperatura en grados Celsius: ")
if temperatura.isdecimal():
    temperatura = int(temperatura)
    if (temperatura < -18) or (temperatura > 50):
        temperatura = "Valor invalido"
    else:
        print("Bien")
else:
    temperatura = "Error"

while temperatura.type(str):
    if temperatura.isdigit() == True:
        temperatura = int(temperatura)
        if (temperatura < -18) or (temperatura > 50):
            temperatura = "Valor invalido"
        else:
            print("Bien")
    else:
        print("Debe ingresar un numero entero")
        temperatura = "Error"
    temperatura = input("Ingrese la temperatura en grados Celsius: ")

print(temperatura)