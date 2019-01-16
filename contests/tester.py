"""
Importante! Borrar freopen del cpp, aunque tenga ifdef.

Modo de uso:
Poner el tester.py y el a.exe en la carpeta del problema
(es decir, una carpeta que tiene como subdirectorios 
a /input y /output), e invocar al tester desde Python.
"""

import os
from subprocess import check_output
import time

correct = 0
total = 0
tiempoTotal = 0

for testName in os.listdir('./input'):
	input = open('./input/' + testName)
	output = open('./output/' + testName)

	start = time.time()
	runOutput = check_output('a.exe', stdin=input) 
	end = time.time()
	tiempoTotal += end-start

	a = output.read().splitlines(keepends=False) 
	b = runOutput.decode().splitlines(keepends=False)

	print(a)
	print(b)

	correct += (a == b)
	total += 1

	print("%s is " % (testName) + (" correct." if a == b else " incorrect."))

print("Accepted" if correct == total else "Wrong Answer.")
print("Tiempo aproximado: %s" % (tiempoTotal))
print("%i de %i" % (correct, total))
