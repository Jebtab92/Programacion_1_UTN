/*
 * Biblioteca.h
 *
 *  Created on: May 9, 2021
 *      Author: Jonatan Barbuto
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int Validate_OnlyNumberInt(char *pData);
int Validate_OnlyNumberFloat(char *pData);
int Validate_OnlyAlphabet(char *pData);
int Validate_OnlyAlphabetWithSpaces(char *pData);
void Format_NameLastname(char *pName, char *pLastname, char *pFormatName);

#endif /* BIBLIOTECA_H_ */
