
def area(base, altura):
    #calcula el area del rectangulo
    resultado = base * altura
    return resultado

def exponencial(base, exponente):
    #calcula el resultado de elevar un numero
    resultado = base ** exponente
    return resultado

def numero_letras(nombre):
    #calcula cuantos caracteres tiene el nombre
    letras = len(nombre)
    return letras

def suma(numero1, numero2):
    #suma dos numeros
    resultado = numero1 + numero2
    return resultado

def mayuscula(palabra):
    #convierte todas las letras a mayuscula
    resultado = palabra.upper()
    return resultado

def minuscula(palabra):
    #convierte todas las letras a minusculas
    resultado = palabra.lower()
    return resultado

def perimetro(base, altura):
    #calcula el perimetro del rectangulo
    resultado = (base * 2) + (altura * 2)
    return resultado

def mayor(nombre1, nombre2):
    #calcula cual nombre es mas largo
    if len(nombre1) > len(nombre2):
        valor = True
    elif len(nombre1) < len(nombre2):
        valor = False
    else:
        valor = "Iguales"
    return valor 

def leer_cadena():
    palabra = input("Ingrese una palabra: ")
    return palabra

def numero_mayor(numero1, numero2):
    #calcula cual numero es mayor
    if (numero1 > numero2):
        mayor = f"{numero1} es mayor que {numero2}"
    elif (numero1 < numero2):
        mayor = f"{numero2} es mayor que {numero1}"
    else:
        mayor = "Ambos numeros son iguales"
    return mayor

def situacion_alumno (parcial1, parcial2):
    #recibe notas, calcula el promedio y devuelve el promedio y situacion del alumno
    promedio = ((parcial1 + parcial2) / 2)
    if (parcial1 >= 4) and (parcial2 >= 4):
        if (promedio >= 8):
            situacion = "Ha promovido"
        else:
            situacion = "Ha quedado regular"
    else:
        situacion = "Ha quedado libre"
    promedio = f"Su promedio es {promedio}"
    return situacion, promedio

def division(numero, denominador):
    #divide asegurandose que no rompa reglas
    if denominador != 0:
        division = numero / denominador
        division = round(division, 2)
        resultado = division
    else:
        resultado = "No se puede dividir por cero"
    return resultado
