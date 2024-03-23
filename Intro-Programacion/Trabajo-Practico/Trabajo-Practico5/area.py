def area(base, altura):
    resultado = base * altura
    return resultado

base = float(input("Ingrese base: "))
altura = float(input("Ingrese altura: "))

resultado = area(base, altura)
print(f"El area del rectangulo es {resultado}")