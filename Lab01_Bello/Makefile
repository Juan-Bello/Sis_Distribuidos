/*#######################################################################################
 #* Fecha: 15 de agosto de 2025
 #* Autor: Juan Esteban Bello Durango
 #* Tema:
 #* 	- Programa Multiplicación de Matrices algoritmo clásico
 #* 	- Paralelismo con OpenMP
######################################################################################*/
# Compilador a utilizar
GCC = gcc

# Flags generales
CFLAGS = -lm

# Flags específicos para OpenMP
FOPENMP = -fopenmp -O3

# Flags para hilos POSIX
POSIX = -lpthread

# Módulo adicional (no utilizado)
modulo = inter.c

# Lista de programas a compilar
PROGRAMAS = mmClasicaOpenMP 

# Compila todos los programas
ALL: $(PROGRAMAS)

# Regla para compilar mmClasicaOpenMP
mmClasicaOpenMP:
    # Compila el programa con $(GCC): compilador gcc, $(CLFAGS): flags generales,- $@.c: toma el nombre del target y añade .c , -o $@: genera el ejecutable con el nombre del target, $(FOPENMP): flags para OpenMP
	$(GCC) $(CLFAGS) $@.c -o $@ $(FOPENMP)

# Elimina todos los ejecutables compilados
clean:
	$(RM) $(PROGRAMAS)
