
def buscar_nombre ():
    nombres = ["Juan", "Pedro", "Francisco", "Javier"]
    buscar = ""
    nombre_encontrado = []
    while buscar != "Parar":
        buscar = input("Ingrese un nombre: ")
        if buscar in nombres:
            nombre_encontrado.append(buscar)
    print(nombre_encontrado)
    return None

buscar_nombre()