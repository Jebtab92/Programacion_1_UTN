/*
 * Ejercicio_8.h
 *
 *  Created on: Apr 22, 2021
 *      Author: jonat
 */

#ifndef EJERCICIO_8_H_
#define EJERCICIO_8_H_

int inicializarInt(int legajo[], int size);
int inicializarFloat(float array[], int size);
int inicializarChar(char array[], int size);
int inicializarMatriz(char array[][20], int size);
int cargarLegajo(int legajo[], int size);
int cargarEdad(int edad[], int size);
int cargarSexo(char array[], int size);
int cargarNotaUno(float nota[],int size);
int cargarNotaDos(float nota[],int size);
int cargarPromedio(float promedio[], float nota1, float nota2, int size);
int cargarApellido(char array[][20], int size);
int ordenarLegajo(int legajo[],char sexo[], float nota1[], float nota2[], float promedio[], char apellido[][20], int size);
int ordenarApellido(int legajo[],char sexo[], float nota1[], float nota2[], float promedio[], char apellido[][20], int size);
int ordenarPromedioLegajo(int legajo[],char sexo[], float nota1[], float nota2[], float promedio[], char apellido[][20], int size);
int mostrarEstudiante(int legajo, char sexo, int edad, float nota1, float nota2, float promedio, char apellido[][20]);
int mostrarEstudiantes(int legajo[], char sexo[], int edad[], float nota1[], float nota2[], float promedio[], char apellido[][20], int size);

#endif /* EJERCICIO_8_H_ */
