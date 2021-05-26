/*
 * Biblioteca.c
 *
 *  Created on: May 11, 2021
 *      Author: Jonatan Barbuto
 */

#include "Biblioteca.h"

// Validaciones

int Validate_OnlyNumberInt(char pData[])
{
	int rtn = 1;

	if(strlen(pData) > 0)
	{
		for(int i = 0; i < strlen(pData); i++)
		{
			if(isdigit(pData[i]) == 0)
			{
				if(i == 0)
				{
					if(pData[0] != '-')
					{
						rtn = 0;
						break;
					}
				}
				else
				{
					rtn = 0;
					break;
				}
			}
		}
	}
	else
	{
		rtn = 0;
	}

	return rtn;
} // Fin Validate_OnlyNumberInt


int Validate_OnlyNumberFloat(char pData[])
{
	int countSigno = 0;
	int rtn = 1;

	if(strlen(pData) > 0)
	{
		for(int i = 0; i < strlen(pData); i++)
		{

			if(pData[i] == '.' || pData[i] == ',')
			{
				countSigno++;
			}
			else
			{
				if(isdigit(pData[i]) == 0)
				{
					if(i == 0)
					{
						if(pData[0] != '-')
						{
							rtn = 0;
							break;
						}
					}
					else
					{
						rtn = 0;
						break;
					}
				}
			}
		}

		if(countSigno > 1)
		{
			rtn = 0;
		}
	}
	else
	{
		rtn = 0;
	}

	return rtn;
} // Fin Validate_OnlyNumberFloat


int Validate_OnlyAlphabet(char pData[])
{
	int rtn = 1;

	if(strlen(pData) > 0)
	{
		for(int i = 0; i < strlen(pData); i++)
		{
			if(isalpha(pData[i]) == 0)
			{
				rtn = 0;
				break;
			}
		}
	}
	else
	{
		rtn = 0;
	}

	return rtn;
} // Fin Validate_OnlyAlphabet

int Validate_OnlyAlphabetWithSpaces(char pData[])
{
	int rtn = 1;

	if(strlen(pData) > 0)
	{
		for(int i = 0; i < strlen(pData); i++)
		{
			if(isalpha(pData[i]) == 0)
			{
				if(isspace(pData[i]) == 0)
				{
					rtn = 0;
					break;
				}
			}
		}
	}
	else
	{
		rtn = 0;
	}

	return rtn;
} // Fin Validate_OnlyAlphabetWithSpaces

int Validate_Exit_SN(char MSJ[], char ERROR_MSJ[], int REINTENTOS)
{
	int rtn = 0;
	char c;

	c = Get_Char(MSJ, ERROR_MSJ, REINTENTOS);
	c = toupper(c);

	while(c != 'S' && c != 'N')
	{
		printf("Error, opcion no valida");
		c = Get_Char(MSJ, ERROR_MSJ, REINTENTOS);
		c = toupper(c);
	}

	if(c == 'S')
	{
		rtn = 1;
	}

	return rtn;
} // Fin Validate_Exit_SN

int Validate_Cuit(char pData[])
{
	int rtn = 1;
	int i;
	int contadorDigito=0;
	int contadorGuion=0;

	if(pData!=NULL)
	{
		for(i=0; i < strlen(pData);i++)
		{
			if(isdigit(pData[i]) != 0)
			{
				contadorDigito++;
			}
			if(pData[i] == '-')
			{
				contadorGuion++;
			}
		}
		if(contadorDigito >= 10 && contadorGuion == 2)
		{
			rtn = 1;
		}
		else
		{
			rtn = 0;
		}
	}
	return rtn;
} // Fin Validate_Cuit

// Get Funciones

int Get_Int(char MSJ[], char ERROR_MSJ[])
{
	int rtn;
	char buffer[SIZE_BUFFER];

	fflush(stdin);
	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(Validate_OnlyNumberInt(buffer) == 0)
	{
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	rtn = atoi(buffer);
	return rtn;
} // Fin Get_Int

int Get_IntRange(char MSJ[], char ERROR_MSJ[], int MIN, int MAX, int REINTENTOS)
{
	int rtn = Get_Int(MSJ, ERROR_MSJ);

	while(rtn < MIN || rtn > MAX)
	{
		printf("ERROR, Fuera de rango -> [MIN]=%d [MAX]=%d.\n", MIN, MAX);
		rtn = Get_Int(MSJ, ERROR_MSJ);
		REINTENTOS--;
		if(REINTENTOS == 1)
		{
			printf("Intentos Agotados\n");
			system("pause");
			break;
		}
	}
	return rtn;
} // Fin Get_IntRange

int Get_IntPositive(char MSJ[], char ERROR_MSJ[], int REINTENTOS)
{
	int rtn = Get_Int(MSJ, ERROR_MSJ);
	while(rtn < 0)
	{
		printf("ERROR, Solo numeros positivos\n");
		rtn = Get_Int(MSJ, ERROR_MSJ);
		REINTENTOS--;
		if(REINTENTOS == 1)
		{
			printf("Intentos Agotados\n");
			system("pause");
			break;
		}
	}
	return rtn;
} // Fin Get_IntPositive

int Get_IntNegative(char MSJ[], char ERROR_MSJ[], int REINTENTOS)
{
	int rtn = Get_Int(MSJ, ERROR_MSJ);
	while(rtn > 0)
	{
		printf("ERROR, Solo numeros negativos\n");
		rtn = Get_Int(MSJ, ERROR_MSJ);
		REINTENTOS--;
		if(REINTENTOS == 1)
		{
			printf("Intentos Agotados\n");
			system("pause");
			break;
		}
	}
	return rtn;
} // Fin Get_IntNegative

float Get_Float(char MSJ[], char ERROR_MSJ[], int REINTENTOS)
{
	int rtn;
	char buffer[SIZE_BUFFER];
	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(Validate_OnlyNumberFloat(buffer) == 0)
	{
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
		REINTENTOS--;
		if(REINTENTOS == 1)
		{
			printf("Intentos Agotados\n");
			system("pause");
			break;
		}
	}
	rtn = atof(buffer);
	return rtn;

} // Fin Get_Float

float Get_FloatRange(char MSJ[], char ERROR_MSJ[], float MIN, float MAX, int REINTENTOS)
{
	float rtn = Get_Float(MSJ, ERROR_MSJ, REINTENTOS);

	while(rtn < MIN || rtn > MAX)
	{
		printf("ERROR, Fuera de rango -> [MIN]=%.2f [MAX]=%.2f.\n", MIN, MAX);
		rtn = Get_Float(MSJ, ERROR_MSJ, REINTENTOS);
		REINTENTOS--;
		if(REINTENTOS == 1)
		{
			printf("Intentos Agotados\n");
			system("pause");
			break;
		}
	}
	return rtn;
} // Fin Get_FloatRange

char Get_Char(char MSJ[], char ERROR_MSJ[], int REINTENTOS)
{
	char rtn;
	char buffer[SIZE_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer) > 1 || Validate_OnlyAlphabet(buffer) == 0)
	{
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
		REINTENTOS--;
		if(REINTENTOS == 1)
		{
			printf("Intentos Agotados\n");
			system("pause");
			break;
		}
	}

	rtn = buffer[0];

	return rtn;
} // Fin Get_Char

void Get_String(char MSJ[], char ERROR_MSJ[], char pString[], int size, int REINTENTOS)
{
	char buffer[SIZE_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer) > size || strlen(buffer) == 0)
	{
		printf("Error, Fuera de rango -> Caracteres [MIN] = 1 [MAX] = %d \n", size);
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
		REINTENTOS--;
		if(REINTENTOS == 1)
		{
			printf("Intentos Agotados\n");
			system("pause");
			break;
		}
	}
	strcpy(pString, buffer);
} // Fin Get_String

void Get_OnlyAlphabetString(char MSJ[], char ERROR_MSJ[], char pString[], int size, int REINTENTOS)
{
	char buffer[SIZE_BUFFER];
	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer) > size || strlen(buffer) == 0 || Validate_OnlyAlphabet(buffer) == 0)
	{
		if(strlen(buffer) > size || strlen(buffer) == 0)
		{
			printf("Error, fuera de rango -> Caracteres [MIN] = 1 [MAX] = %d \n", size);
		}
		else
		{
			printf("\n");
		}

		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
		REINTENTOS--;
		if(REINTENTOS == 1)
		{
			printf("Intentos Agotados\n");
			system("pause");
			break;
		}
	}

	strcpy(pString, buffer);
} // Fin Get_OnlyAlphabetString

void Get_OnlyAlphabetStringWithSpaces(char MSJ[], char ERROR_MSJ[], char pString[], int size, int REINTENTOS)
{
	char buffer[SIZE_BUFFER];
	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer) > size || strlen(buffer) == 0 || Validate_OnlyAlphabetWithSpaces(buffer) == 0)
	{
		if(strlen(buffer) > size || strlen(buffer) == 0)
		{
			printf("Error, fuera de rango -> Caracteres [MIN] = 1 [MAX] = %d \n", size);
		}
		else
		{
			printf("Error, solo caracteres alfabeticos validos \n");
		}

		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
		REINTENTOS--;
		if(REINTENTOS == 1)
		{
			printf("Intentos Agotados\n");
			system("pause");
			break;
		}
	}

	strcpy(pString, buffer);
} // Fin Get_OnlyAlphabetStringWithSpaces

void Get_Cuil(char MSJ[], char ERROR_MSJ[], char pString[], int size, int REINTENTOS)
{
	char buffer[SIZE_BUFFER];
	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer) > size || strlen(buffer) == 0 || Validate_Cuit(buffer) == 0)
	{
		if(strlen(buffer) > size || strlen(buffer) == 0)
		{
			printf("Error, fuera de rango -> Caracteres [MIN] = 1 [MAX] = %d \n", size);
		}
		else
		{
			printf("Error, solo formato [XX-XXXXXXXX-X] \n");
		}

		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
		REINTENTOS--;
		if(REINTENTOS == 1)
		{
			printf("Intentos Agotados\n");
			system("pause");
			break;
		}
	}

	strcpy(pString, buffer);

} // Fin Get_Cuil

void Get_DNI(char MSJ[], char ERROR_MSJ[], char pString[], int size, int REINTENTOS)
{
	char buffer[SIZE_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer) > 8 || strlen(buffer) < 7 || Validate_OnlyNumberInt(buffer) == 0)
	{
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
		REINTENTOS--;
		if(REINTENTOS == 1)
		{
			printf("Intentos Agotados\n");
			system("pause");
			break;
		}
	}

	strcpy(pString, buffer);
} // Fin Get_DNI

void Menu(void)
{
	printf("\n--Menu Principal--\n"
			"1) Alta de contribuyente\n"
			"2) Modificar datos del contribuyente\n"
			"3) Baja de contribuyente\n"
			"4) Recaudacion\n"
			"5) Refinanciar recaudacion\n"
			"6) Saldar recaudacion\n"
			"7) Imprimir contribuyentes\n"
			"8) Imprimir recaudacion\n"
			"9) Salir\n");
} // Fin Menu
