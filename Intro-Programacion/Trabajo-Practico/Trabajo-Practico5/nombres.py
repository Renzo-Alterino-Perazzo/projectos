
def mayor(nombre1, nombre2):
    if len(nombre1) > len(nombre2):
        valor = True
    elif len(nombre1) < len(nombre2):
        valor = False
    else:
        valor = "Iguales"
    return valor 

nombre1 = input("Ingrese un nombre: ")
nombre2 = input("Ingrese otro nombre: ")
resultado = mayor(nombre1, nombre2)

print(resultado)
