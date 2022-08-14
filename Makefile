#/*****************************************************
#Fecha: 06 de Agosto de 2022
#Autor: Juan Camilo De Los Ríos
#Materia: Parallel and Distributed Computing
#Tema: Primer taller introducción a C
#*******************************************************/

GCC = gcc
FLAGS = -ansi -pedantic -Wall -std=gnu11
MATHFLAGS = -lm

PROGRS = taller_main
 
all: $(PROGRS) 

taller_main:
	$(GCC) $(FLAGS) -c $@.c
	$(GCC) $(FLAGS) -c taller_lib.c
	$(GCC) $(FLAGS) -o $@ $@.o taller_lib.o $(MATHFLAGS)

clean: 
	$(RM) *.o $(PROGRS)