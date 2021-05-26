/*
 * Contribuyente.c
 *
 *  Created on: May 15, 2021
 *      Author: Jonatan Barbuto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Contribuyente.h"
#include "Biblioteca.h"
#include "Recaudacion.h"

#define LIBRE 1
#define OCUPADO 0


void inicializarContribuyente(eContribuyente array[], int size)
{
	int i;

	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			array[i].isEmpty = LIBRE;
		}
	}
} // Fin inicializarContribuyente

int arrayVacioContribuyente(eContribuyente array[], int size)
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
} // Fin arrayVacioContribuyente

int buscarLibreContribuyente(eContribuyente array[], int size)
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
} // Fin buscarLibreContribuyente

int bajaContribuyente(eContribuyente arrayC[], int sizeC, eRecaudacion arrayR[], int sizeR)
{
	int i;
	int auxId;
	int rtn = -1;

	if(arrayC != NULL && sizeC > 0)
	{
		auxId = Get_IntRange("\nIngrese ID a dar de baja --> ", "ID no encontrado\n", 1000, 1500, 3);

		for(i = 0; i < sizeR; i++)
		{
			if(arrayC[i].idContribuyente == auxId)
			{
				mostrarTituloContribuyente();
				mostrarContribuyente(arrayC, i);
				imprimirListaRecaudacion(arrayR, sizeR, auxId);
				if(Validate_Exit_SN("Desea continuar con la baja? Si[s] - No[n]: ", "Error, Reingrese: ", 3) == 1)
				{
					arrayC[i].isEmpty = LIBRE;
					bajaRecaudacion(arrayR, sizeR, auxId);
					rtn = 0;
					system("pause");
				}
			}
		}
	}

	return rtn;
} // Fin bajaContribuyente
void mostrarTituloContribuyente(void)
{
	printf("+----------------------------------------------------------------------------+\n");
	printf("|%10s  %20s  %20s  %20s| \n","ID","NOMBRE","APELLIDO","CUIL");
	printf("+----------------------------------------------------------------------------+\n");
} // Fin mostrarTituloContribuyente

void mostrarContribuyente(eContribuyente array[], int index)
{
	if(array != NULL && index >= 0)
	{
		printf("|%10d| %20s| %20s| %20s| \n",array[index].idContribuyente, array[index].nombre, array[index].apellido, array[index].cuil);
	}
} // Fin mostrarContribuyente

void mostrarContribuyentes(eContribuyente array[], int size)
{
	int i;

	if(array != NULL && size > 0)
	{
		mostrarTituloContribuyente();
		for(i = 0; i < size; i++)
		{
			if(array[i].isEmpty == OCUPADO)
			{
				mostrarContribuyente(array, i);
			}
		}
	}
} // Fin mostrarContribuyentes

eContribuyente cargarDatosContribuyente(void)
{
	eContribuyente auxiliar;

	Get_OnlyAlphabetString("\nIngrese nombre --> ", "\nError, reingrese --> ", auxiliar.nombre, MAX_CHAR, 3);
	auxiliar.nombre[0] = toupper(auxiliar.nombre[0]);
	Get_OnlyAlphabetString("\nIngrese apellido --> ", "\nError, reingrese --> ", auxiliar.apellido, MAX_CHAR, 3);
	auxiliar.apellido[0] = toupper(auxiliar.apellido[0]);
	Get_Cuil("\nIngrese cuil --> ", "\nError, reingrese --> ", auxiliar.cuil, MAX_CHAR, 3);

	// El id se cambia en la siguiente funcion
	return auxiliar;
} // Fin cargarDatosContribuyente

int obtenerIdContribuyente(int *idContribuyente)
{
	int rtn;
	rtn = *idContribuyente +=1;
	return rtn;
} // Fin obtenerIdContribuyente

int altaContribuyente(eContribuyente array[],int *idContribuyente, int size)
{
	int rtn = 0;
	int index;
	eContribuyente auxContribuyente;

	if(array != NULL && size > 0)
	{
		index = buscarLibreContribuyente(array, size);

		if(index != -1)
		{
			auxContribuyente = cargarDatosContribuyente();
			if(Validate_Exit_SN("Desea continuar Si[s] - No[n]: ", "Error, Reingrese: ", 3) == 1)
			{
				auxContribuyente.idContribuyente = obtenerIdContribuyente(&*idContribuyente);
				auxContribuyente.isEmpty = OCUPADO;
				array[index] = auxContribuyente;
				rtn = 1;
				mostrarTituloContribuyente();
				mostrarContribuyente(array, index);
				system("pause");
			}
			else
			{
				printf("Alta Cancelada");
			}

		}
	}
	return rtn;
} // Fin AltaContribuyente

int buscarIdContribuyente(eContribuyente array[], int size, int ID)
{
	int rtn = -1;
	int i;
	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			if(array[i].idContribuyente == ID && array[i].isEmpty == OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
} // Fin buscarIdContribuyente

int modificarContribuyente(eContribuyente array[], int size)
{
	int auxID;
	int index;
	int opcion;
	int rtn = 1;

	if(array != NULL && size > 0)
	{
		do
		{
			auxID = Get_IntRange("\nIngrese id a modificar --> ", "\nError, reingrese --> ", 1000, 1100, 3);
			index = buscarIdContribuyente(array, size, auxID);
		}while(index == -1);

		printf("\n--Menu de modificacion--\n"
				"1) Modificar nombre\n"
				"2) Modificar apellido\n"
				"3) Modificar cuil\n"
				"4) Volver al menu principal\n");
		opcion = Get_IntRange("\nIngrese la opcion a modificar --> ", "\nError, reingrese --> ", 1, 4, 3);

		switch(opcion)
		{
			case 1:
			{
				Get_OnlyAlphabetString("\nIngrese nuevo nombre --> ", "\nError, reingrese --> ", array[index].nombre, MAX_CHAR, 3);
				rtn = 0;
				break;
			}
			case 2:
			{
				Get_OnlyAlphabetString("\nIngrese nuevo apellido --> ", "\nError, reingrese --> ", array[index].apellido, MAX_CHAR, 3);
				rtn = 0;
				break;
			}
			case 3:
			{
				Get_Cuil("\nIngrese nuevo cuil --> ", "\nError, reingrese --> ", array[index].cuil, MAX_CHAR, 3);
				rtn = 0;
				break;
			}
			case 4:
			{
				system("pause");
				break;
			}
		}
	}
	return rtn;
} // Fin modificarContribuyente
