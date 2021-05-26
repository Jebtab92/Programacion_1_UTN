/*
 * Recaudacion.c
 *
 *  Created on: May 15, 2021
 *      Author: Jonatan Barbuto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Recaudacion.h"

#define LIBRE 1
#define OCUPADO 0

void inicializarRecaudacion(eRecaudacion array[], int size)
{
	int i;

	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			array[i].isEmpty = LIBRE;
		}
	}
} // Fin inicializarRecaudacion

int arrayVacioRecaudacion(eRecaudacion array[], int size)
{
	int rtn = 0;
	int i;

	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				rtn ++;
			}
		}
	}
	return rtn;
} // Fin arrayVacioRecaudacion

int buscarLibreRecaudacion(eRecaudacion array[], int size)
{
	int i;
	int rtn = -1;

	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			if(array[i].isEmpty == LIBRE)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
} // Fin buscarLibreRecaudacion

void mostrarTituloRecaudacion(void)
{
	printf("+-------------------------------------------------------------------------------------+\n");
	printf("|%10s  %10s  %10s  %15s  %15s  %15s| \n", "ID REC", "ID CON", "MES", "TIPO", "ESTADO", "IMPORTE");
	printf("+-------------------------------------------------------------------------------------+\n");
} // Fin mostrarTituloRecaudacion

void mostrarRecaudacion(eRecaudacion array[], int index)
{
	printf("|%10d| %10d| %10d| %15s| %15s| %15.2f| \n",array[index].idRecaudacion, array[index].idContribuyente,
			array[index].mes, array[index].tipo, array[index].estado, array[index].importe);
} // Fin mostrarRecaudacion

void mostrarRecaudaciones(eRecaudacion array[], int size)
{
	int i;

	if(array != NULL && size > 0)
	{
		mostrarTituloRecaudacion();
		for(i = 0; i < size; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				mostrarRecaudacion(array, i);
			}
		}
	}
} // Fin mostrarRecaudacion

int eRecaudacion_ObtenerID(int *idRecaudacion)
{
	int rtn;
	rtn = *idRecaudacion +=1;
	return rtn;
}

int buscarIdRecaudacion(eRecaudacion array[], int size, int ID)
{
	int rtn = -1;
	int i;
	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			if(array[i].idRecaudacion == ID && array[i].isEmpty == OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
} // Fin buscarIdRecaudacion


int imprimirListaRecaudacion(eRecaudacion array[], int size, int ID)
{
	int rtn = -1;
	int i;
	if(array != NULL && size > 0)
	{
		mostrarTituloRecaudacion();
		for(i = 0; i < size; i++)
		{
			if(array[i].idContribuyente == ID && array[i].isEmpty == OCUPADO)
			{
				mostrarRecaudacion(array, i);
			}
		}
	}
	return rtn;
} // Fin imprimirListaRecaudacion

int bajaRecaudacion(eRecaudacion array[], int size, int ID)
{
	int rtn = -1;
	int i;
	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			if(array[i].idContribuyente == ID)
			{
				array[i].isEmpty = LIBRE;
			}
		}
	}
	return rtn;
} // Fin bajaRecaudacion
