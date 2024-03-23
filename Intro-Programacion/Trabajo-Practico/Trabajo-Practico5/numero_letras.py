
def numero_letras(nombre):
    letras = len(nombre)
    return letras

nombre = input("Ingrese un nombre: ")
letras = numero_letras(nombre)

print(f"El nombre {nombre} tiene {letras} letras")
