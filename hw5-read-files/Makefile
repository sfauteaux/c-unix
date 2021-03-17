#Makefile for file, fileTest

main:file.c fileTest.c fileTest.h
	gcc -o main file.c fileTest.c

file.o:file.c fileTest.h
	gcc -c file.c
fileTest.o:fileTest.c fileTest.h
	gcc -c fileTest.c