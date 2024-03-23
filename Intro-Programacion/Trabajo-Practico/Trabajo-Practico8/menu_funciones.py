
def menu_opciones():
    print("********* MI PROGRAMA *********")
    print("1. Saludar.")
    print("2. Informar temperatura.")
    print("3. Mostrar nombre de materia.")
    print("4. Salir.")
    return None

def eleccion_opciones(opcion):
    if (opcion == 1):
        mensaje = "Hola, bienvenido a mi programa interactivo!"
    elif (opcion == 2):
        mensaje = "Hay una sensación térmica de 20 grados Celsius"
    elif (opcion == 3):
        mensaje = "Estás en la materia Introducción a la Programación!"
    elif (opcion == 4):
        mensaje = "Hasta la próxima!"
    else:
        mensaje = "Opción inválida"
    return mensaje