
nota = int(input("Ingrese un numero entre 1 y 10: "))
cantidad = 1
suma_nota = nota
parar = False
if nota == 99:
    parar = True

while parar == False:
    while (nota < 1 or nota > 10):
        print("Error")
        nota = int(input("Ingrese un numero entre 1 y 10: "))
    cantidad += 1
    suma_nota += nota
    if nota == 99:
        parar = True
        

promedio = suma_nota/cantidad


