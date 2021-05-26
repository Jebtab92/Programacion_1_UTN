/*
 * Pantalla.c
 *
 *  Created on: May 12, 2021
 *      Author: Jonatan Barbuto
 */

#include "Pantalla.h"
#include "Biblioteca.h"


void hardCodeTipo(eTipo array[])
{
	if(array != NULL)
	{
		array[0].idTipo = 1;
		strcpy(array[0].nombreTipo,"LCD");

		array[1].idTipo = 2;
		strcpy(array[1].nombreTipo,"LED");
	}
}
//ID AUTOINCREMENTAL
int Pantalla_idIncremental = 0;

void ePantalla_Inicializar(ePantalla array[], int size) {
	int i;
	if(array != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			array[i].isEmpty = LIBRE;
		}
	}
}

int ePantalla_ObtenerID(int *Pantalla_idIncremental)
{
	int rtn;
	rtn = *Pantalla_idIncremental +=1;
	return rtn;
}

int ePantalla_ObtenerIndexLibre(ePantalla array[], int size) {
	int rtn = -1;
	int i;
	if (array != NULL && size > 0) {
		for (i = 0; i < size; i++) {
			if (array[i].isEmpty == LIBRE) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int ePantalla_BuscarPorID(ePantalla array[], int size, int ID)
{
	int rtn = -1;
	int i;
	if (array != NULL && size > 0) {
		for (i = 0; i < size; i++) {
			if (array[i].idPantalla == ID && array[i].isEmpty == OCUPADO) {

				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void ePantalla_MostrarUno(ePantalla Pantalla) {
	//PRINTF DE UN SOLO Pantalla
	printf("%5d\n", Pantalla.idPantalla);
}

int ePantalla_MostrarTodos(ePantalla array[], int size) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	//puts("\n\t> LISTADO Pantalla");
	//printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < size; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Pantalla
				ePantalla_MostrarUno(array[i]);
				//CONTADOR DE Pantalla
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Pantalla PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int ePantalla_MostrarDadosDeBaja(ePantalla array[], int size) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Pantalla\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < size; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Pantalla
				ePantalla_MostrarUno(array[i]);
				//CONTADOR DE Pantalla
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Pantalla PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

ePantalla ePantalla_CargarDatos(void) {
	ePantalla auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/

	Get_Cuil("Ingrese Cuil: ", "Error, reingrese: ", auxiliar.cuil, MAX_CHARS_CADENAS);


	Get_DNI("Ingrese DNI (sin puntos): ", "Error, reingrese: ", auxiliar.dni, MAX_CHARS_CADENAS);
	auxiliar.direccion.altura = Get_Int("Ingrese altura: ", "Error, reingrese");
	auxiliar.idPantalla = 0;
	auxiliar.idTipo = Get_IntRange("Ingrese tipo\n\t1-LCD\n\t2-LED", "Error, reingrese:", 1, 2);
	auxiliar.precio = Get_Float("Ingrese precio: ", "Error, reingrese: ");
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

ePantalla ePantalla_ModificarUno(ePantalla Pantalla) {
	ePantalla auxiliar = Pantalla;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int ePantalla_Alta(ePantalla array[],int *idPantalla, int size)
{
	int rtn = 0;
	ePantalla auxPantalla;

	//BUSCO ESPACIO EN ARRAY
	int index = ePantalla_ObtenerIndexLibre(array, size);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
			//PIDO DATOS - CARGO Pantalla AUXILIAR
			auxPantalla = ePantalla_CargarDatos();

			//CAMBIO SU ESTADO A "OCUPADO"
			auxPantalla.isEmpty = OCUPADO;

			ePantalla_MostrarUno(auxPantalla);
			//mostrar antes de guardar
			if(Validate_Exit_SN("Desea continuar Si[s] - No[n]: ", "Error, Reingrese: "))
			{
				//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
				auxPantalla.idPantalla = ePantalla_ObtenerID(&*idPantalla);

				//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
				array[index] = auxPantalla;

				//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
				rtn = 1;
			}
			else
			{
				printf("Alta Cancelada");
			}

		}

		return rtn;
}

int ePantalla_Baja(ePantalla array[], int size) {
	int rtn = 0;
	int idPantalla;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Pantalla
	if(ePantalla_MostrarTodos(array, size)) {
		//BANDERA EN 1 SI HAY Pantalla DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Pantalla PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idPantalla);

		//BUSCO INDEX POR ID EN ARRAY
		while (ePantalla_BuscarPorID(array, size, idPantalla) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idPantalla);
		}

		//OBTENGO INDEX DEL ARRAY DE Pantalla A DAR DE BAJA
		index = ePantalla_BuscarPorID(array, size, idPantalla);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECsizeENTE
		rtn = 1;
	}

	return rtn;
}

int ePantalla_Modificacion(ePantalla array[], int size) {
	int rtn = 0;
	int idPantalla;
	int index;
	int flag = 0;
	ePantalla auxiliar;

	//LISTO TODOS LOS Pantalla
	if (ePantalla_MostrarTodos(array, size)) {
		//BANDERA EN 1 SI HAY Pantalla DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Pantalla PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idPantalla);

		//BUSCO INDEX POR ID EN ARRAY
		while (ePantalla_BuscarPorID(array, size, idPantalla) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idPantalla);
		}

		//OBTENGO INDEX DEL ARRAY DE Pantalla A MODIFICAR
		index = ePantalla_BuscarPorID(array, size, idPantalla);

		//LLAMO A FUNCION QUE MODIFICA Pantalla
		auxiliar = ePantalla_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECsizeENTE
		rtn = 1;
	}

	return rtn;
}

int ePantalla_Sort(ePantalla array[], int size, int criterio) {
	int rtn = 0;
	int i;
	int j;
	ePantalla aux;

	/** EJEMPLO DE SORT CON ID DE Pantalla
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)

	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < size - 1; i++) {
				for (j = i + 1; j < size; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idPantalla > array[j].idPantalla) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < size - 1; i++) {
				for (j = i + 1; j < size; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idPantalla < array[j].idPantalla) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}
