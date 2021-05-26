/*
 ============================================================================
 Name        : P1_BarbutoJonatan.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Contribuyente.h"
#include "Biblioteca.h"
#include "Recaudacion.h"
#include "Informes.h"

#define SIZE 50

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int idContribuyente = 999;
	int idRecaudacion = 99;

	eContribuyente arrayContribuyente[SIZE];
	inicializarContribuyente(arrayContribuyente, SIZE);

	eRecaudacion arrayRecaudacion[SIZE];
	inicializarRecaudacion(arrayRecaudacion, SIZE);

	do
	{
		Menu();
		switch(opcion = Get_IntRange("\nIngrese opcion --> ", "Opcion fuera de rango\n", 1, 9, 3))
		{
			case 1:
			{ // Alta
				if((altaContribuyente(arrayContribuyente, &idContribuyente, SIZE)) == 1)
				{
					printf("\n--Alta Exitosa--\n");
					system("pause");
				}
				else
				{
					printf("\n--Alta anulada--\n");
					system("pause");
				}
				break;
			}
			case 2:
			{ // Modificar
				if(arrayVacioContribuyente(arrayContribuyente, SIZE) == 0)
				{
					printf("\n::::.No hay contribuyentes a modificar.::::\n");
					system("pause");
				}
				else
				{
					// Aca va funcion modificar
					if((modificarContribuyente(arrayContribuyente, SIZE)) == 0)
					{
						printf("\n--Modificacion fue exitosa--");
						system("pause");
					}
					else
					{
						printf("\n--Modificacion Anulada--");
						system("pause");
					}
				}
				break;
			}
			case 3:
			{
				if(arrayVacioContribuyente(arrayContribuyente, SIZE) == 0)
				{
					printf("\n::::.No hay contribuyentes a eliminar.::::\n");
					system("pause");
				}
				else
				{
					if(bajaContribuyente(arrayContribuyente, SIZE, arrayRecaudacion, SIZE) == 0)
					{
						printf("\n::::.Baja del contribuyente exitosa.::::");
					}
					else
					{
						printf("\n::::.No se pudo realizar la baja.::::");
						system("pause");
					}
				}
				break;
			}
			case 4:
			{ // Recaudacion Alta
				if(arrayVacioContribuyente(arrayContribuyente, SIZE) == 0)
				{
					printf("\n::::.No hay contribuyentes para asignar recaudacion.::::\n");
					system("pause");
				}
				else
				{
					if(altaRecaudacion(arrayRecaudacion, &idRecaudacion, SIZE, arrayContribuyente, SIZE) == 1)
					{
						printf("\n--Alta de recaudacion exitosa--\n");
						system("pause");
					}
					else
					{
						printf("\n--Alta anulada--\n");
						system("pause");
					}
				}
				break;
			}
			case 5:
			{
				if(arrayVacioRecaudacion(arrayRecaudacion, SIZE) == 0)
				{
					printf("\n--No hay recaudaciones para refinanciar--");
					system("pause");
				}
				else
				{
					refinanciarRecaudacion(arrayRecaudacion, SIZE, arrayContribuyente, SIZE);
					system("pause");
				}
				break;
			}
			case 6:
			{
				if(arrayVacioRecaudacion(arrayRecaudacion, SIZE) == 0)
				{
					printf("\n--No hay recaudaciones para saldar--");
					system("pause");
				}
				else
				{
					saldarRecaudacion(arrayRecaudacion, SIZE, arrayContribuyente, SIZE);
					system("pause");
				}
				break;
			}
			case 7:
			{
				if(arrayVacioContribuyente(arrayContribuyente, SIZE) == 0)
				{
					mostrarContribuyentes(arrayContribuyente, SIZE);
				}
				else
				{
					imprimirContribuyentes(arrayRecaudacion, SIZE, arrayContribuyente, SIZE);
					system("pause");
				}
				break;
			}
			case 8:
			{
				if(arrayVacioRecaudacion(arrayRecaudacion, SIZE) == 0)
				{
					printf("\n--No hay recaudaciones para mostrar\n--");
					system("pause");
				}
				else
				{
					if(imprimirSaldadas(arrayContribuyente, SIZE, arrayRecaudacion, SIZE) != 0)
					{
						printf("\n--No hay recaudaciones saldadas--\n");
						system("pause");
					}
					system("pause");
				}
				break;
			}
			case 9:
			{
				printf("::::.Adios.::::");
				break;
			}
		}
	}while(opcion != 9);
	return 0;
}
