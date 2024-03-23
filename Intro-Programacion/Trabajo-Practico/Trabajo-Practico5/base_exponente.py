
def exponencial(base, exponente):
    resultado = base ** exponente
    return resultado

base = float(input("Ingrese un numero: "))
exponente = float(input("Ingrese un exponente: "))
resultado = exponencial(base, exponente)

print(f"El resultado de {base} a la {exponente} es {resultado}")