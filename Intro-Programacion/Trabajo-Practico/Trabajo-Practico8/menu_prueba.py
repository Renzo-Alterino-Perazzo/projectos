
from menu_funciones import menu_opciones, eleccion_opciones

menu_opciones()

opcion = int(input("Elegir una opcion: "))
mensaje = eleccion_opciones(opcion)
print(mensaje)