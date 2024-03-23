
numero = "1234567890"

def puntuacion (numero):
    contador = 0
    numero_auxiliar = ""
    for i in range (len(numero)-1, -1 , -1):
        numero_auxiliar = numero_auxiliar + numero[i]
        contador += 1
        if (contador == 3):
            contador = 0
            numero_auxiliar = numero_auxiliar + "."
    numero = ""
    for i in range (len(numero_auxiliar)-1, -1 , -1):
        numero = numero + numero_auxiliar[i]
    print(numero)

puntuacion(numero)

print(numero[::-1])