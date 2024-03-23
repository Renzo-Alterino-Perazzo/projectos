
def consonantes (s):
    vocales = "aeiou"
    resultado = ""
    for i in range (len(s)):
        if not (s[i] in vocales):
            resultado += s[i]
    return resultado

s = input("Ingrese una palabra: ")
resultado = consonantes(s)
print(resultado)