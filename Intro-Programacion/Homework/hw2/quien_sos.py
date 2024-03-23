
def quien_sos (x):
    if x == "Maria":
        return "Sos Maria"
    elif x == "Pedro":
        return "Sos Pedro"
    else:
        return "No sos Maria ni Pedro. Quien sos?"

x = input("Ingrese su nombre: ")
print(quien_sos(x))