
s = input("Ingrese una palabra: ")
n = 0
m = 0
vocales_mayusculas = "AEIOU"
vocales_minusculas = "aeiou"

for numero in range(len(s)):
    if (s[numero] in vocales_minusculas):
        n += 1
    elif (s[numero] in vocales_mayusculas):
        m += 1

print(n)
print(m)
    