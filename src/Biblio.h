/*
 * Biblio.h
 *
 *  Created on: 17 oct 2021
 *      Author: alfre
 */

#ifndef BIBLIO_H_
#define BIBLIO_H_

/// @fn int esNumero(char[])
/// @brief verifica que el numero ingresado sea solo numero
/// @param str
/// @return 0 si hubo error y 1 si pudo funcionar correctamente
int esNumero(char str[]);
/// @fn int ingresarString(char[], char[])
/// @brief pide al usuario un string y lo guarda
/// @param mensaje
/// @param dato
/// @return0 si hubo error y 1 si pudo funcionar correctamente
int ingresarString(char mensaje[], char dato[]);
/// @fn int ingresarEntero(char[])
/// @brief pide al usuario un entero y lo guarda
/// @param mensaje
/// @return 0 si hubo error y 1 si pudo funcionar correctamente
int ingresarEntero(char mensaje[]);
/// @fn float ingresarFlotante(char[])
/// @brief pide al usuario un flotante y lo guarda
/// @param mensaje
/// @return 0 si hubo error y 1 si pudo funcionar correctamente
float ingresarFlotante(char mensaje[]);
/// @fn int validarRangoEntero(int, int, int)
/// @brief valida que el entero que ingresa el cliente se encuentren entre los dos rangos minimo y maximo que se pasan como parametro
/// @param valor
/// @param limiteInferior
/// @param limiteSuperior
/// @return 0 si hubo error y 1 si pudo funcionar correctamente
int validarRangoEntero(int valor, int limiteInferior, int limiteSuperior);
/// @fn int stringPrimeroLetraMayuscula(char[])
/// @brief convierte la primera letra del array en mayuscula
/// @param string
/// @return 0 si hubo error y 1 si pudo funcionar correctamente
int stringPrimeroLetraMayuscula(char string[]);
/// @fn int verificarSiContieneNumero(char[])
/// @brief recorre el array y verifica que este no contenga numero
/// @param list
/// @return 0 si hubo error y 1 si pudo funcioanr correctamente
int verificarSiContieneNumero(char list[]);
/// @fn int validarLargoString(char[], int, int)
/// @brief valida que el string del cliente se encuentre entre los dos rangos minimo y maximo que se pasan como parametro
/// @param string
/// @param min
/// @param max
/// @return 0 si hubo error y 1 si pudo funcionar correctamente
int validarLargoString(char string[], int min , int max);
/// @fn int pedirOpcion(void)
/// @brief muestra al cliente las opciones del menu
/// @return la opcion elegida por el usuario
int pedirOpcion(void);

#endif /* BIBLIO_H_ */
