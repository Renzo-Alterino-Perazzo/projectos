
peso_argentino = 1.0
dolar = 102.5
real = 14.1
euro = 104.5
cuenta = float(input("Ingresar total de pesos: "))

total_peso = cuenta
total_dolar = "{:.2f}".format(cuenta/dolar)
total_real = "{:.2f}".format(cuenta/real)
total_euro = "{:.2f}".format(cuenta/euro)

print(f"Usted tiene {total_peso} pesos argentinos, los cuales convierten en:")
print(f"{total_dolar} dolares")
print(f"{total_real} reales")
print(f"{total_euro} euros")
