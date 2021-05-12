/*
 * biblioteca_estructuras.h
 *
 *  Created on: Apr 28, 2021
 *      Author: jonat
 */

#ifndef BIBLIOTECA_ESTRUCTURAS_H_
#define BIBLIOTECA_ESTRUCTURAS_H_

typedef struct
{
	int legajo;
	char sexo;
	int edad;
	int idCarrera;
	float nota1;
	float nota2;
	float promedio;
	char apellido[20];
	int isEmpty;
}alumno;

typedef struct
{
	int idCarrera;
	char descripcionCarrera[50];
	int isEmpty;
}Carrera;


int mostrarMenu(int* opcion);
int inicializarIsEmpty(alumno alumnos[], int size);
int buscarLibre(alumno array[], int size);
int ingresarAlumno(alumno array[], int size);
int listarAlumno(int legajo, char sexo, int edad, float nota1, float nota2, char* apellido);
int listarAlumnos(alumno array[], int size);
int bajaAlumno(alumno array[], int size);
int modificarAlumno();
int ordenarAlumno();

#endif /* BIBLIOTECA_ESTRUCTURAS_H_ */
