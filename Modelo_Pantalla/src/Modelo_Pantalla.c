/*
 ============================================================================
 Name        : Modelo_Pantalla.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Pantalla.h"

#define TAM_ESTRUCTURA 5

int main(void) {
	setbuf(stdout, NULL);

	int idPantalla = 0;
	int opc;
	int criterioDeOrdenamiento;

	// Creo array pantalla
	ePantalla Pantalla[TAM_ESTRUCTURA];

	// Creo array tipo y cargo los dos valores
	eTipo Tipo[2];
	hardCodeTipo(Tipo);

	//INICIALIAZO ARRAY DE ESTRUCTURA
	ePantalla_Inicializar(Pantalla, TAM_ESTRUCTURA);


	//BUCLE DE MENU
	do {
		//MENU PRINT
		Menu();
		opc = Get_IntRange("Ingrese Opcion: ", "Error, opcion fuera de rango", 1, 10);

		//MENU SWITCH
		switch(opc)
		{
		case 0:
			/** PREGUNTAR SI DESEA SALIR */
			opc = 0;
			break;
		case 1:
			//ALTA
			if(ePantalla_Alta(Pantalla, &idPantalla, TAM_ESTRUCTURA))
			{
				printf(" * Pantalla DADO DE ALTA EXITOSAMENTE");
			}
			else
			{
				printf(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS Pantalla");
			}
			break;
		case 2:
			//BAJA
			if(ePantalla_Baja(Pantalla, TAM_ESTRUCTURA))
			{
				printf("\n * BAJA DE Pantalla EXITOSA");
				ePantalla_MostrarTodos(Pantalla, TAM_ESTRUCTURA);
			}
			else
			{
				printf("\n * BAJA DE Pantalla CANCELADA");
			}
			break;
		case 3:
			//MODIFICACION
			if (ePantalla_Modificacion(Pantalla, TAM_ESTRUCTURA)) {
				puts("\n * MODIFICACION DE Pantalla EXITOSA\n");
				ePantalla_MostrarTodos(Pantalla, TAM_ESTRUCTURA);
			} else {
				puts("\n * MODIFICACION DE Pantalla CANCELADA");
			}
			break;
		case 4:
			//LISTADO Pantalla
			if(ePantalla_MostrarTodos(Pantalla, TAM_ESTRUCTURA)){
				system("pause");
			}else{
				puts("No hay nada para mostrar pa");
			}

			break;
		case 5:
			//ORDENAR Pantalla
			criterioDeOrdenamiento = -1; //PEDIR CRITERIO DE ORDENAMIENTO
			ePantalla_Sort(Pantalla, TAM_ESTRUCTURA, criterioDeOrdenamiento);
			break;
		}
	} while (opc != 0);

	printf("\n... FIN PROGRAMA");

	return 0;
}
