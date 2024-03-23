# IMPORTANTE: No modificar ni borrar ni renombrar este archivo

hw0.so: hw0.c
	gcc -shared -o hw0.so hw0.c

testall: hw0.so
	pytest test_hw0.py
	
testSumarDosNumeros: hw0.so
	pytest test_hw0.py::testSumarDosNumeros

testPositividad: hw0.so
	pytest test_hw0.py::testPositividad

testSumarIntervalo: hw0.so
	pytest test_hw0.py::testSumarIntervalo

clean:
	rm *.so