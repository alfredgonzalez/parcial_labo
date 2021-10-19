/*
 * Biblio.h
 *
 *  Created on: 17 oct 2021
 *      Author: alfre
 */

#ifndef BIBLIO_H_
#define BIBLIO_H_



int ingresarString(char mensaje[], char dato[]);
int ingresarEntero(char mensaje[]);
float ingresarFlotante(char mensaje[]);
int validarRangoEntero(int valor, int limiteInferior, int limiteSuperior);
int stringPrimeroLetraMayuscula(char string[]);
int pedirOpcion(void);

#endif /* BIBLIO_H_ */
