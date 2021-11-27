/*
 * Transporte.h
 *
 *  Created on: 25 nov 2021
 *      Author: alfre
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#ifndef TRANSPORTE_H_

typedef struct
{
	int idTransporte;
	char vehiculo[30];
	int kilosSoportados;
}eTransporte;

#define TRANSPORTE_H_

/// @fn int mostrarTransportes(eTransporte*, int)
/// @brief Muestra la lista de transportes y los kilos correspondientes que soporta cada uno
/// @param listaTransporte
/// @param tamTransporte
/// @return 0 si da error y 1 si funciona correctamente
int mostrarTransportes(eTransporte* listaTransporte, int tamTransporte);
/// @fn int cargarDescripcionTransporte(eTransporte*, int, int, char[])
/// @brief recibe el id de un vehiculo como parametro y busca matchear con el id de la estructura. Al matchear, copa la descripcion de dicho vehiculo en una variable
/// @param listaTransporte
/// @param tamTransporte
/// @param idVehiculo
/// @param descripcion
/// @return 0 si da error y 1 si funciona correctamente
int cargarDescripcionTransporte(eTransporte* listaTransporte, int tamTransporte,int idVehiculo, char descripcion[]);

#endif /* TRANSPORTE_H_ */
