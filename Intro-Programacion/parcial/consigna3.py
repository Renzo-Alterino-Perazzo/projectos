
def tiene_z(palabra):
    if "z" in palabra:
        tiene = True
    else:
        tiene = False
    return tiene

palabra = input("Ingrese una palabra: ")

print(tiene_z(palabra))