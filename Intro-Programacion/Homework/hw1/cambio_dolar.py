
def cambioDolar(pesos):
    dolar = pesos / 90
    resultado = f"Si me das {pesos} pesos, te doy {dolar} dolares"
    return resultado

pesos = 180
resultado = cambioDolar(pesos)

print(resultado)
