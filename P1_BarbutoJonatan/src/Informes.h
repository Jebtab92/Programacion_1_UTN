/*
 * Informes.h
 *
 *  Created on: May 18, 2021
 *      Author: jonat
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Recaudacion.h"
#include "Contribuyente.h"
#include "Biblioteca.h"


/*
 * \brief recibe una estructura eContribuyente, una eRecaudacion, sus tamanios y id Recaudacion
 * \param confirma, crea nuevo id y carga los valores a la estructura final
 * \return int 1 si es correcto 0 si hubo un error
 */
int altaRecaudacion(eRecaudacion arrayR[],int *idRecaudacion, int sizeR, eContribuyente arrayC[], int sizeC);

/*
 * \brief recibe una estructura eContribuyente y su tamanio
 * \param pide, valida y carga los datos de la estructura
 * \param dentro de una variable auxiliar
 * \return eRecaudacion auxiliar
 */
eRecaudacion cargarDatosRecaudacion(eContribuyente arrayC[], int sizeC);

/*
 * \brief recibe una estructura eContribuyente, una eRecaudacion y sus tamanio
 * \param pide ID recaudacion y cambia el estado a refinanciado
 * \return 1 si se cambio o 0 si hubo un error
 */
int refinanciarRecaudacion(eRecaudacion arrayR[], int sizeR, eContribuyente arrayC[], int sizeC);

/*
 * \brief recibe una estructura eContribuyente, una eRecaudacion y sus tamanio
 * \param pide ID recaudacion y cambia el estado a saldado
 * \return 1 si se cambio o 0 si hubo un error
 */
int saldarRecaudacion(eRecaudacion arrayR[], int sizeR, eContribuyente arrayC[], int sizeC);

/*
 * \brief recibe una estructura eContribuyente, una eRecaudacion y sus tamanio
 * \param imprime por pantalla contribuyentes y sus recaudaciones
 * \return void
 */
void imprimirContribuyentes(eRecaudacion arrayR[], int sizeR, eContribuyente arrayC[], int sizeC);

/*
 * \brief recibe una estructura eContribuyente, una eRecaudacion y sus tamanio
 * \param imprime por pantalla las recaudaciones saldadas y sus contribuyentes
 * \return void
 */
int imprimirSaldadas(eContribuyente arrayC[], int sizeC, eRecaudacion arrayR[], int sizeR);

#endif /* INFORMES_H_ */
