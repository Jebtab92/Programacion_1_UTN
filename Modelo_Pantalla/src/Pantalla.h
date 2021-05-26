/*
 * Pantalla.h
 *
 *  Created on: May 12, 2021
 *      Author: Jonatan Barbuto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

#ifndef EPantalla_H_
#define EPantalla_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 1
#define OCUPADO 0
#define BAJA -1
#define LED 2
#define LCD 1

//*** ESTRUCTURA
typedef struct
{
	int idTipo;
	char nombreTipo[3];
} eTipo;

typedef struct
{
	char calle[MAX_CHARS_CADENAS];
	int altura;
	char localidad[MAX_CHARS_CADENAS];
	int codigo_postal;
} eDireccion;

typedef struct
{
	int idPantalla;
	char cuil[MAX_CHARS_CADENAS];
	char dni[MAX_CHARS_CADENAS];
	int idTipo;
	char nombre[MAX_CHARS_CADENAS];
	eDireccion direccion;
	float precio;
	int isEmpty;
} ePantalla;
//***
void hardCodeTipo(eTipo array[]);
/** INICIO CABECERAS DE FUNCION*/
void ePantalla_Inicializar(ePantalla array[], int size);
int ePantalla_ObtenerID(int *Pantalla_idIncremental);
int ePantalla_ObtenerIndexLibre(ePantalla array[], int size);
int ePantalla_BuscarPorID(ePantalla array[], int size, int ID);
void ePantalla_MostrarUno(ePantalla Pantalla);
int ePantalla_MostrarTodos(ePantalla array[], int size);
int ePantalla_MostrarDadosDeBaja(ePantalla array[], int size);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int ePantalla_Sort(ePantalla array[], int size, int criterio);

//ABM
ePantalla ePantalla_CargarDatos(void);
ePantalla ePantalla_ModificarUno(ePantalla Pantalla);
int ePantalla_Alta(ePantalla array[],int *idPantalla, int size);
int ePantalla_Baja(ePantalla array[], int size);
int ePantalla_Modificacion(ePantalla array[], int size);
/** FIN CABECERAS DE FUNCION*/
#endif
