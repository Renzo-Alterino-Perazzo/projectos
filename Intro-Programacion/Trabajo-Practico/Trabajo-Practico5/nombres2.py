def nombre_mayor(nombre1, nombre2):
    resultado = len(nombre1) > len(nombre2)
    return resultado

nombre1 = input("Ingrese un nombre: ")
nombre2 = input("Ingrese otro nombre: ")
resultado = nombre_mayor(nombre1, nombre2)

print(resultado)