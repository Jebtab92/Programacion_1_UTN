/*
 ============================================================================
 Name        : Modelo_Orquesta.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Entidades.h"

#define TAM_ESTRUCTURA 5

int main(void) {
	setbuf(stdout, NULL);

	int opc;
	int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	eOrquesta Orquesta[TAM_ESTRUCTURA];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	eOrquesta_Inicializar(Orquesta, TAM_ESTRUCTURA);

	//BUCLE DE MENU
	do {
		//MENU PRINT
		//Menu();
		printf("INGRESE OPCION: ");
		scanf("%d", &opc);

		//MENU SWITCH
		switch(opc)
		{
		case 0:
			/** PREGUNTAR SI DESEA SALIR */
			opc = 0;
			break;
		case 1:
			//ALTA
			if (eOrquesta_Alta(Orquesta, TAM_ESTRUCTURA)) {
				puts(" * Orquesta DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS Orquesta");
			}
			system("pause");
			break;
		case 2:
			//BAJA
			if (eOrquesta_Baja(Orquesta, TAM_ESTRUCTURA)) {
				puts("\n * BAJA DE Orquesta EXITOSA");
				eOrquesta_MostrarTodos(Orquesta, TAM_ESTRUCTURA);
			} else {
				puts("\n * BAJA DE Orquesta CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//MODIFICACION
			if (eOrquesta_Modificacion(Orquesta, TAM_ESTRUCTURA)) {
				puts("\n * MODIFICACION DE Orquesta EXITOSA\n");
				eOrquesta_MostrarTodos(Orquesta, TAM_ESTRUCTURA);
			} else {
				puts("\n * MODIFICACION DE Orquesta CANCELADA");
			}
			system("pause");
			break;
		case 4:
			//LISTADO Orquesta
			if(eOrquesta_MostrarTodos(Orquesta, TAM_ESTRUCTURA)){
				system("pause");
			}else{
				puts("No hay nada para mostrar pa");
			}

			break;
		case 5:
			//ORDENAR Orquesta
			criterioDeOrdenamiento = -1; //PEDIR CRITERIO DE ORDENAMIENTO
			eOrquesta_Sort(Orquesta, TAM_ESTRUCTURA, criterioDeOrdenamiento);
			system("pause");
			break;
		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
