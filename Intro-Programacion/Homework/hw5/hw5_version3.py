################################################################################################
# Nombre de archivo: hw5.py (No cambiar el nombre de este archivo)
# El repositorio donde esta tu HW5 es: github.com/unlu-edu-ar/homework-5-TuNombreDeUsuarioGithub
#
# Completa con tu nombre, apellido y DNI
# Nombre y Apellido: Renzo Alterino Perazzo
# DNI: 42.302.260
################################################################################################


#################################################
# Funciones que tenés que programar
#################################################

# Cree una función que recibe una lista l de números enteros y retorna una lista
# de los números pares de la lista l, conservando el orden que tenían dichos
# números pares en la lista l. Si no hay ningún número par en la lista l, deberá
# retornar una lista vacía.
# Ejemplo, si l=[1,0,-4,-5,2,0] deberá retornar la lista [0,-4,2,0]
def extraePares(l):
    pares = []
    for numero in l:
        if numero%2 == 0:
            pares.append(numero)
    return pares

# Cree una función que recibe una lista no vacía l de números enteros y retorna 
# un entero m con la multiplicación de todos los números de la lista, y un número 
# entero s con la sumatoria de los elementos de la lista l.
# Ejemplo: l=[-1,2,3] debe retornar (-6,4)
# Ejemplo: l=[-1,0,3] debe retornar (0,2)
def productoriaYSumatoria(l):
    m = 1
    s = 0
    for numero in l:
        m = m * numero
        s += numero
    return m, s

# Cree una función que recibe como parámetros una lista l no vacía de números 
# enteros, dos números enteros naturales n1 y n2, donde 0<=n1<=n2<len(l), y 
# un booleano. Si el booleano fuese True, la función retorna 
# el resultado de sumar los números enteros pares contenidos en el intervalo 
# l[n1...n2] (si no hay ningún número par en el intervalo retorna 0). Si el 
# booleano fuese False, la función retorna el resultado de sumar los números 
# enteros impares contenidos en el intervalo l[n1...n2] (si no hay ningún número 
# impar en el intervalo retorna 0).
def sumaSubcadena(l, n1, n2, pares):
    suma = 0
    subcadena = []
    for numero in range (n1,n2+1):
        if numero >= n1 and numero <= n2:
            subcadena.append(l[numero])
    if pares == True:
        for numero in subcadena:
            if numero%2 == 0:
                suma += numero
    else:
        for numero in subcadena:
            if numero%2 == 1:
                suma += numero
    return suma

#################################################
# Funciones de Test (no modificar)
#################################################

def testExtraePares():
    print('Testeando extraePares()... ', end='')
    assert extraePares([1,0,-4,-5,2,0])==[0,-4,2,0]
    assert extraePares([])==[]
    assert extraePares([0])==[0]
    assert extraePares([3,1])==[]
    assert extraePares([2,4,2])==[2,4,2]
    print('Pasó!')

def testProductoriaYSumatoria():
    print('Testeando productoriaYSumatoria()... ', end='')
    assert productoriaYSumatoria([-1,2,3])==(-6,4)
    assert productoriaYSumatoria([-1,0,3])==(0,2)
    assert productoriaYSumatoria([0])==(0,0) 
    assert productoriaYSumatoria([2])==(2,2)   
    print('Pasó!')

def testSumaSubcadena():
    print('Testeando sumaSubcadena()... ', end='')
    assert sumaSubcadena([1,2,3],0,1,True)==2
    assert sumaSubcadena([1,2,3],2,2,False)==3  
    assert sumaSubcadena([1,2,2],2,2,False)==0  
    assert sumaSubcadena([0],0,0,True)==0   
    assert sumaSubcadena([1],0,0,False)==1 
    assert sumaSubcadena([1,2,3,4],1,3,True)==6
    print('Pasó!')

#################################################
# testearTodo y main
#################################################

def testearTodo():
    # comentá los tests que no querés correr!
    testExtraePares()
    testProductoriaYSumatoria()
    testSumaSubcadena()

def main():
    testearTodo()

if __name__ == '__main__':
    main()
