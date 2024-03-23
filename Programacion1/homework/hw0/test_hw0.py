# test_hw0.py
# IMPORTANTE: No modificar ni borrar ni renombrar este archivo

from ctypes import CDLL

libfact = CDLL("./hw0.so")

def testSumarDosNumeros():
    print('Testeando sumar_dos_numeros()... ')
    assert libfact.sumar_dos_numeros(1, 3) == 4 
    assert libfact.sumar_dos_numeros(1, 0) == 1
    assert libfact.sumar_dos_numeros(-4, 5) == 1
    print('Paso!')

def testPositividad():
    print('Testeando positividad()... ')
    assert libfact.positividad(1) == 1 
    assert libfact.positividad(-4) == 0
    assert libfact.positividad(0) == 1
    print('Paso!')

def testSumarIntervalo():
    print('Testeando sumar_intervalo()... ')
    assert libfact.sumar_intervalo(1, 3) == 6 
    assert libfact.sumar_intervalo(5, 6) == 11
    assert libfact.sumar_intervalo(3, 7) == 25
    print('Paso!')