/*
 * Publicidad.h
 *
 *  Created on: May 12, 2021
 *      Author: Jonatan Barbuto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EPublicidad_H_
#define EPublicidad_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 1
#define OCUPADO 0
#define BAJA -1

//*** ESTRUCTURA
typedef struct
{
	int idPublicidad;
	int cuit;
	int dias;
	char video[MAX_CHARS_CADENAS];
	int idPantalla;
	int isEmpty;
} ePublicidad;
//***

/** INICIO CABECERAS DE FUNCION*/
void ePublicidad_Inicializar(ePublicidad array[], int size);
int ePublicidad_ObtenerID(void);
int ePublicidad_ObtenerIndexLibre(ePublicidad array[], int size);
int ePublicidad_BuscarPorID(ePublicidad array[], int size, int ID);
void ePublicidad_MostrarUno(ePublicidad Publicidad);
int ePublicidad_MostrarTodos(ePublicidad array[], int size);
int ePublicidad_MostrarDadosDeBaja(ePublicidad array[], int size);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int ePublicidad_Sort(ePublicidad array[], int size, int criterio);

//ABM
ePublicidad ePublicidad_CargarDatos(void);
ePublicidad ePublicidad_ModificarUno(ePublicidad Publicidad);
int ePublicidad_Alta(ePublicidad array[], int size);
int ePublicidad_Baja(ePublicidad array[], int size);
int ePublicidad_Modificacion(ePublicidad array[], int size);
/** FIN CABECERAS DE FUNCION*/
#endif

