/*
 ============================================================================
 Name        : Ejercicio_2-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



int main(void) {




	return 0;
}
int get_Cliente(char* continuar)
{
	do
	{
		// Numero de cliente
		printf("Ingrese numero de cliente\n");
		scanf("%d", &cliente);

		// Estado civil
		do
		{
			printf("Ingrese estado civil\n");
			printf("s - Soltero\n");
			printf("c - Casado\n");
			printf("v - Viudo\n");
			__fpurge(stdin);
			scanf("%c", &estado);
		}while(estado != 's' && estado != 'c' && estado != 'v');

		// Edad
		do
		{
			printf("Ingrese su edad\n");
			scanf("%d", &edad);
		}while(edad <= 17);

		// Temperatura
		do
		{
			printf("Ingrese su temperatura corporal\n");
			scanf("%f", &temperatura);
		}while(temperatura < 25 && temperatura > 45);

		// Sexo
		do
		{
			printf("Ingrese Sexo\n");
			printf("f - Femenino\n");
			printf("m - Masculino\n");
			printf("o - No binario\n");
			__fpurge(stdin);
			scanf("%c", &sexo);
		}while(sexo != 'f' && sexo != 'm' && sexo != 'o');

		// Viudo mayor
		if(estado == 'v' && edad > 60)
		{
			viudoMayor += 1;
		}

		// Soltera mas joven
		if(sexo == 'f' && estado == 's' && edad < edadJoven)
		{
			clienteJoven = cliente;
			edadJoven = edad;
			flagJoven = 1;
		}

		// Acumulador Mayores
		if(edad > 60)
		{
			cantDesc +=1;
		}

		// Acumulador total
		totalViaje += 600;
		cantViaje += 1;
		// Continuar
		printf("Ingrese 's' para agregar un nuevo pasajero\n");
		fflush(stdin);
		scanf("%c", &continuar);
	}while(continuar == 's');
}
