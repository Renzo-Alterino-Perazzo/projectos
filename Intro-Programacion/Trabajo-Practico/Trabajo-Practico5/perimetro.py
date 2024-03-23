
def perimetro(base, altura):
    resultado = (base * 2) + (altura * 2)
    return resultado

base = float(input("Ingrese la base: "))
altura = float(input("Ingrese la altura: "))
resultado = perimetro(base, altura)

print(f"El perimetro del rectangulo con base {base} y altura {altura} es {resultado}")