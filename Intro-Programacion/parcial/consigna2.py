
def usuario_facebook():
    mayor_amigos = 0
    total_amigos = 0
    cantidad = 0
    maradona = False
    while cantidad <= 200:
        usuario_nombre = input("Ingrese nombre del usuario: ")
        usuario_amigos = int(input("Ingrese cantidad de amigos: "))
        total_amigos += usuario_amigos
        if usuario_nombre == "Diego Maradona":
            maradona = True
        if usuario_amigos > mayor_amigos:
            mayor_usuario = usuario_nombre
            mayor_usuario = usuario_amigos
        cantidad += 1
    promedio = total_amigos/cantidad
    print(f"El promedio de amigos por usuario es {promedio} amigos")
    if maradona == True:
        print("Al menos un usuario se llama Diego Maradona")
    print(f"El usuario con mas amigos es {mayor_usuario} con un total de {mayor_amigos} amigos")
    return None