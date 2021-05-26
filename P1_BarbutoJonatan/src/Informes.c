/*
 * Informes.c
 *
 *  Created on: May 18, 2021
 *      Author: Jonatan Barbuto
 */

#include "Informes.h"
#define LIBRE 1
#define OCUPADO 0



eRecaudacion cargarDatosRecaudacion(eContribuyente arrayC[], int sizeC)
{
	eRecaudacion auxiliar;
	int auxId, auxTipo, auxEstado;
	int indexC;
	int reintentos = 3;

	do
	{
		mostrarContribuyentes(arrayC, sizeC);
		auxId = Get_IntRange("\nIngrese id del contribuyente para la nueva recaudacion --> ", "\nError, reingrese", 1000, 1100, reintentos);
		indexC = buscarIdContribuyente(arrayC, sizeC, auxId);
		if(indexC == -1)
		{
			printf("\nContribuyente no encontrado\n");
			reintentos--;
		}
		if(reintentos == 1)
		{
			break;
		}
	}while(indexC == -1);

	if(indexC != -1)
	{
		auxiliar.idContribuyente = arrayC[indexC].idContribuyente;
		auxiliar.mes = Get_IntRange("\nIngrese mes --> ", "\nError, reingrese --> ", 1, 12, 3);
		auxTipo = Get_IntRange("\nIngrese tipo de recaudacion \n"
					"1) ARBA\n"
					"2) IIBB\n"
					"3) GANANCIAS\n"
					"Ingrese opcion --> ", "\nError, reingrese --> ", 1, 3, 3);
		switch(auxTipo)
		{
			case 1:
			{
				strcpy(auxiliar.tipo,"ARBA");
				break;
			}
			case 2:
			{
				strcpy(auxiliar.tipo,"IIBB");
				break;
			}
			case 3:
			{
				strcpy(auxiliar.tipo,"GANANCIAS");
				break;
			}
		}
		auxEstado = Get_IntRange("\nIngrese estado de recaudacion\n"
						"1) ADEUDADO\n"
						"2) REFINANCIADO\n"
						"3) SALDADO\n"
						"Ingrese opcion --> ", "\nError, reingrese --> ", 1, 3, 3);
		switch(auxEstado)
		{
			case 1:
			{
				strcpy(auxiliar.estado,"ADEUDADO");
				break;
			}
			case 2:
			{
				strcpy(auxiliar.estado,"REFINANCIADO");
				break;
			}
			case 3:
			{
				strcpy(auxiliar.estado,"SALDADO");
				break;
			}
		}

		auxiliar.importe = Get_Float("\nIngrese importe --> ", "\nError, reingrese --> ", 3);
	}
	return auxiliar;
} // Fin cargarDatosRecaudacion

int altaRecaudacion(eRecaudacion arrayR[],int *idRecaudacion, int sizeR, eContribuyente arrayC[], int sizeC)
{
	int rtn = 0;
	int index;
	eRecaudacion auxRecaudacion;
	auxRecaudacion.importe = 0;

	index = buscarLibreRecaudacion(arrayR, sizeR);

	if(index != -1)
	{
		auxRecaudacion = cargarDatosRecaudacion(arrayC, sizeC);

		if(auxRecaudacion.importe != 0)
		{
			if(Validate_Exit_SN("Desea continuar Si[s] - No[n] --> ", "Error, reingrese --> ", 3) == 1)
			{
				auxRecaudacion.idRecaudacion = eRecaudacion_ObtenerID(&*idRecaudacion);
				auxRecaudacion.isEmpty = OCUPADO;
				arrayR[index] = auxRecaudacion;
				rtn = 1;
				mostrarTituloRecaudacion();
				mostrarRecaudacion(arrayR, index);
				system("pause");
			}
			else
			{
				printf("Alta Cancelada");
			}
		}
	}
		return rtn;
} // Fin altaRecaudacion

int refinanciarRecaudacion(eRecaudacion arrayR[], int sizeR, eContribuyente arrayC[], int sizeC)
{
	int rtn = 0;
	int auxIdRec;
	int indexRec;
	int auxIdCon;
	int indexCon;
	int reintentos = 3;

	//pedir id
	do
	{
		auxIdRec = Get_IntRange("\nIngrese id de la recaudacion --> ", "\Error, reingrese --> ", 100, 200, 3);
		indexRec = buscarIdRecaudacion(arrayR, sizeR, auxIdRec);
		if(indexRec == -1)
		{
			printf("\nRecaudacion no encontrado\n");
			reintentos--;
		}
		if(reintentos == 1)
		{
			break;
		}

	}while(indexRec == -1);

	do
	{
		auxIdCon = arrayR[indexRec].idContribuyente;
		indexCon = buscarIdContribuyente(arrayC, sizeC, auxIdCon);
		if(indexCon == -1)
		{
			printf("\nContribuyente no encontrado\n");
			reintentos--;
		}
		if(reintentos == 1)
		{
			break;
		}
	}while(indexCon == -1);

	if(indexRec != -1 && indexCon != -1)
	{
		mostrarTituloContribuyente();
		mostrarContribuyente(arrayC, indexCon);

		if(strcmp(arrayR[indexRec].estado, "REFINANCIADO") != 0)
		{
			if(Validate_Exit_SN("Desea cambiar estado a refinanciado? Si[s] - No[n] --> ", "Error, reingrese --> ", 3) == 1)
			{
				strcpy(arrayR[indexRec].estado, "REFINANCIADO");
				rtn = 1;
				printf("\n--Refinanciado exitosamente--\n");
				system("pause");
			}
		}
		else
		{
			printf("\n--Esta recaudacion ya se encuentra refinanciada--\n");
			system("pause");
		}
	}
	return rtn;
} // Fin refinanciarRecaudacion

int saldarRecaudacion(eRecaudacion arrayR[], int sizeR, eContribuyente arrayC[], int sizeC)
{
	int rtn = 0;
	int auxIdRec;
	int indexRec = -1;
	int auxIdCon;
	int indexCon = -1;

	if(arrayR != NULL && arrayC != NULL && sizeR > 0 && sizeC > 0)
	{
		auxIdRec = Get_IntRange("\nIngrese id de la recaudacion --> ", "\Error, reingrese --> ", 100, 200, 3);
		indexRec = buscarIdRecaudacion(arrayR, sizeR, auxIdRec);
		auxIdCon = arrayR[indexRec].idContribuyente;
		indexCon = buscarIdContribuyente(arrayC, sizeC, auxIdCon);

		if(indexRec != -1 && indexCon != -1)
		{
			mostrarTituloContribuyente();
			mostrarContribuyente(arrayC, indexCon);

			if(strcmp(arrayR[indexRec].estado, "SALDADO") != 0)
			{
				if(Validate_Exit_SN("Desea cambiar estado a Saldado? Si[s] - No[n] --> ", "Error, reingrese --> ", 3) == 1)
				{
					strcpy(arrayR[indexRec].estado, "SALDADO");
					rtn = 1;
					printf("\n--Saldado exitosamente exitosamente--\n");
					system("pause");
				}
			}
			else
			{
				printf("\n--Esta recaudacion ya se encuentra saldada--\n");
				system("pause");
			}
		}
		else
		{
			printf("\n--Saldar recaudacion anulada (Verifique ids ingresados)--\n");
			system("pause");
		}
	}
	return rtn;
} // Fin saldarRecaudacion

void imprimirContribuyentes(eRecaudacion arrayR[], int sizeR, eContribuyente arrayC[], int sizeC)
{
	int i, j;

	if(arrayR != NULL && arrayC != NULL && sizeR > 0 && sizeC > 0)
	{
		for(i = 0; i < sizeC;i++)
		{
			if(arrayC[i].isEmpty == OCUPADO)
			{
				mostrarTituloContribuyente();
				mostrarContribuyente(arrayC, i);
				for(j = 0; j < sizeR; i++)
				{
					if(arrayC[i].idContribuyente == arrayR[j].idContribuyente)
					{
						mostrarRecaudacion(arrayR, j);
					}
				}
			}
		}
	}
} // Fin imprimirContribuyetes

int imprimirSaldadas(eContribuyente arrayC[], int sizeC, eRecaudacion arrayR[], int sizeR)
{
	int i;
	int indexC;
	int rtn = -1;

	if(arrayR != NULL && arrayC != NULL && sizeR > 0 && sizeC > 0)
	{
		printf("+---------------------------------------------------------------------------------------------------------"
				"------------------------+\n");
		printf("|%10s  %20s  %20s  %10s  %10s  %15s  %15s  %15s| \n", "ID CON"
				,"CUIL", "NOMBRE","ID REC", "MES", "TIPO", "ESTADO", "IMPORTE");
		printf("+---------------------------------------------------------------------------------------------------------"
				"------------------------+\n");

		for(i=0;i<sizeR;i++)
		{
			if(strcmp(arrayR[i].estado,"SALDADO") == 0)
			{
				indexC = buscarIdContribuyente(arrayC, sizeC, arrayR[i].idContribuyente);
				printf("|%10d| %20s| %20s| %10d| %10d| %15s| %15s| %15.2f| \n",arrayC[indexC].idContribuyente,
						arrayC[indexC].cuil, arrayC[indexC].nombre, arrayR[i].idRecaudacion,
						arrayR[i].mes, arrayR[i].tipo, arrayR[i].estado, arrayR[i].importe);
				rtn = 0;
			}
		}
	}
	return rtn;
} // Fin imprimirSaldadas
