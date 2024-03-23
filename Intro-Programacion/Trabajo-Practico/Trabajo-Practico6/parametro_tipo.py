
parametro = input("Escriba una palabra: ")

if parametro.isdigit():
    valor = "La palabra es numerica"
elif parametro.isalpha():
    valor ="La palabra es alfabetica"
elif parametro.isalnum():
    valor = "La palabra es alfanumerica"
print(valor)