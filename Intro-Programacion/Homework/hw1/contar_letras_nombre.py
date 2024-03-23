
def contarLetrasNombre(nombre):
    letras = len(nombre)
    resultado = f"El nombre {nombre} tiene {letras} letras"
    return resultado

nombre = "Renzo"
resultado = contarLetrasNombre(nombre)
print(resultado)