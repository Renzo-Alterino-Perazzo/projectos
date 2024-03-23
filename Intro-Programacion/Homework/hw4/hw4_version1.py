################################################################################################
# Nombre de archivo: hw4.py (No cambiar el nombre de este archivo)
# El repositorio donde esta tu HW4 es: github.com/unlu-edu-ar/homework-4-TuNombreDeUsuarioGithub
#
# Completa con tu nombre, apellido y DNI
# Nombre y Apellido: Renzo Alterino Perazzo
# DNI: 42.302.260
################################################################################################


#################################################
# Funciones que tenés que programar
#################################################

# Cree una función que recibe un string s de longitud > 0, y dos números enteros 
# naturales n y m, donde 0<=n<=m<len(s), y retorna un nuevo string t que 
# es el string s sin la subcadena s[n1..n2].
# Ejemplo: s="Hola", n=1, m=2, retorna "Ha"
# Ejemplo: s="Hola", n=1, m=1, retorna "Hla" 
# Ejemplo: s="Hola", n=3, m=3, retorna "Hol"
# Ejemplo: s="Hola", n=0, m=3, retorna ""
# string, que es el resultado 
def borrarSubcadena(s,n,m):
    pass

# Cree una función que recibe un string s, y retorna dos enteros n y m, siendo
# n la cantidad de vocales minúsculas, y m la cantidad de vocales mayúsculas,
# que tiene el string s.
def contadorVocales(s):
    n = 0
    m = 0
    vocales_mayusculas = "AEIOU"
    vocales_minusculas = "aeiou"
    for numero in range(len(s)):
        if (s[numero] in vocales_minusculas):
            n += 1
        elif (s[numero] in vocales_mayusculas):
            m += 1
    return n, m
    

#################################################
# Funciones de Test (no modificar)
#################################################

def testBorrarSubcadena():
    print('Testeando borrarSubcadena()... ', end='')
    assert borrarSubcadena("Hola", 1, 2) == "Ha"
    assert borrarSubcadena("Hola", 1, 1) == "Hla"
    assert borrarSubcadena("Hola", 3, 3) == "Hol"
    assert borrarSubcadena("Hola", 0, 3) == ""
    print('Pasó!')

def testContadorVocales():
    print('Testeando contadorVocales()... ', end='')
    assert contadorVocales("Argentina") == (3,1)
    assert contadorVocales("hola") == (2,0)
    assert contadorVocales("mmm") == (0,0)
    assert contadorVocales("B") == (0,0)
    assert contadorVocales("e") == (1,0)
    assert contadorVocales("U") == (0,1)
    print('Pasó!')

#################################################
# testearTodo y main
#################################################

def testearTodo():
    # comentá los tests que no querés correr!
    #testBorrarSubcadena()
    testContadorVocales()

def main():
    testearTodo()

if __name__ == '__main__':
    main()
