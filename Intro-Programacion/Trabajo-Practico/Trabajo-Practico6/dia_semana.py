
dia = int(input("Ingrese el numero del dia de la semana comenzando el domingo: "))

if dia == 1:
    print("El dia es domingo")
elif dia == 2:
    dia_semana = "El dia es lunes"
elif dia == 3:
    dia_semana = "El dia es martes"
elif dia == 4:
    dia_semana ="El dia es miercoles"
elif dia == 5:
    dia_semana = "El dia es jueves"
elif dia == 6:
    dia_semana = "El dia es viernes"
elif dia == 7:
    dia_semana = "El dia es sabado"
else:
    dia_semana = "Numero invalido"
print(dia_semana)