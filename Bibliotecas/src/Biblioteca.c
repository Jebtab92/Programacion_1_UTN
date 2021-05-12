/*
 * Biblioteca.c
 *
 *  Created on: May 9, 2021
 *      Author: Jonatan Barbuto
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblioteca.h"

/*
 *\brief
 *\param
 *\return
 */
int Validate_OnlyNumberInt(char *pData)
{
	int rtn = 1;

	if(strlen(pData) > 0)
	{
		for (int i = 0; i < strlen(pData); i++)
		{
			if (isdigit(pData[i]) == 0)
			{
				if (i == 0)
				{
					if (pData[0] != '-')
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
}

/*
 *\brief
 *\param
 *\return
 */
int Validate_OnlyNumberFloat(char *pData)
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
}

/*
 *\brief
 *\param
 *\return
 */
int Validate_OnlyAlphabet(char *pData)
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
}

/*
 *\brief
 *\param
 *\return
 */
int Validate_OnlyAlphabetWithSpaces(char *pData)
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
}

/*
 *\brief
 *\param
 *\return
 */
void Format_NameLastname(char *pName, char *pLastname, char *pFormatName)
{

	strcpy(pFormatName, pLastname);
	strcat(pFormatName, ", ");
	strcat(pFormatName, pName);

	strlwr(pFormatName);

	if(strlen(pName) > 0 && strlen(pLastname) > 0)
	{
		for(int i = 0; i < strlen(pFormatName); i++)
		{
			if(i == 0 && isspace(pFormatName[i]) == 0)
			{
				pFormatName[0] = toupper(pFormatName[0]);

			}
			else
			{
				if(isspace(pFormatName[i]) && i < strlen(pFormatName) - 1)
				{
					pFormatName[i + 1] = toupper(pFormatName[i + 1]);
				}
			}
		}
	}
}
