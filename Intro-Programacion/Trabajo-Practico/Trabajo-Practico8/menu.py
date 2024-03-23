
from menu_funciones import menu_opciones, eleccion_opciones

opcion = 0

while (opcion != 4):
    menu_opciones()
    opcion = int(input("Eliga una opcion: "))
    resultado = eleccion_opciones(opcion)
    print(resultado)
    
