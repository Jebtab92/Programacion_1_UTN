/*
 * Publicidad.c
 *
 *  Created on: May 12, 2021
 *      Author: Jonatan Barbuto
 */

#include "Publicidad.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
int Publicidad_idIncremental = 0;

void ePublicidad_Inicializar(ePublicidad array[], int size) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(array != NULL && size > 0)
	{
		//RECORRO TODO EL ARRAY
		for(i = 0; i < size; i++)
		{
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int ePublicidad_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Publicidad_idIncremental += 1;
}

int ePublicidad_ObtenerIndexLibre(ePublicidad array[], int size) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < size; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int ePublicidad_BuscarPorID(ePublicidad array[], int size, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < size; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idPublicidad == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void ePublicidad_MostrarUno(ePublicidad Publicidad) {
	//PRINTF DE UN SOLO Publicidad
	printf("%5d\n", Publicidad.idPublicidad);
}

int ePublicidad_MostrarTodos(ePublicidad array[], int size) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Publicidad");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < size; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Publicidad
				ePublicidad_MostrarUno(array[i]);
				//CONTADOR DE Publicidad
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Publicidad PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int ePublicidad_MostrarDadosDeBaja(ePublicidad array[], int size) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Publicidad\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && size > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < size; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Publicidad
				ePublicidad_MostrarUno(array[i]);
				//CONTADOR DE Publicidad
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Publicidad PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

ePublicidad ePublicidad_CargarDatos(void) {
	ePublicidad auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

ePublicidad ePublicidad_ModificarUno(ePublicidad Publicidad) {
	ePublicidad auxiliar = Publicidad;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int ePublicidad_Alta(ePublicidad array[], int size) {
	int rtn = 0;
	ePublicidad auxPublicidad;

	//BUSCO ESPACIO EN ARRAY
	int index = ePublicidad_ObtenerIndexLibre(array, size);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Publicidad AUXILIAR
		auxPublicidad = ePublicidad_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxPublicidad.idPublicidad = ePublicidad_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxPublicidad.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxPublicidad;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int ePublicidad_Baja(ePublicidad array[], int size) {
	int rtn = 0;
	int idPublicidad;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Publicidad
	if (ePublicidad_MostrarTodos(array, size)) {
		//BANDERA EN 1 SI HAY Publicidad DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Publicidad PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idPublicidad);

		//BUSCO INDEX POR ID EN ARRAY
		while (ePublicidad_BuscarPorID(array, size, idPublicidad) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idPublicidad);
		}

		//OBTENGO INDEX DEL ARRAY DE Publicidad A DAR DE BAJA
		index = ePublicidad_BuscarPorID(array, size, idPublicidad);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECsizeENTE
		rtn = 1;
	}

	return rtn;
}

int ePublicidad_Modificacion(ePublicidad array[], int size) {
	int rtn = 0;
	int idPublicidad;
	int index;
	int flag = 0;
	ePublicidad auxiliar;

	//LISTO TODOS LOS Publicidad
	if (ePublicidad_MostrarTodos(array, size)) {
		//BANDERA EN 1 SI HAY Publicidad DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Publicidad PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idPublicidad);

		//BUSCO INDEX POR ID EN ARRAY
		while (ePublicidad_BuscarPorID(array, size, idPublicidad) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idPublicidad);
		}

		//OBTENGO INDEX DEL ARRAY DE Publicidad A MODIFICAR
		index = ePublicidad_BuscarPorID(array, size, idPublicidad);

		//LLAMO A FUNCION QUE MODIFICA Publicidad
		auxiliar = ePublicidad_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECsizeENTE
		rtn = 1;
	}

	return rtn;
}

int ePublicidad_Sort(ePublicidad array[], int size, int criterio) {
	int rtn = 0;
	int i;
	int j;
	ePublicidad aux;

	/** EJEMPLO DE SORT CON ID DE Publicidad
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
						if (array[i].idPublicidad > array[j].idPublicidad) {
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
						if (array[i].idPublicidad < array[j].idPublicidad) {
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

