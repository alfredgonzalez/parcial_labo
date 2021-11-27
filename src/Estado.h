/*
 * Estado.h
 *
 *  Created on: 2 nov 2021
 *      Author: alfre
 */

#ifndef ESTADO_H_
#define ESTADO_H_

typedef struct
{
	int idEstado;
	char descripcion[50];
}eEstado;

/// @fn int MostrarEstados(eEstado*, int)
/// @brief recibe como parametro la lista de estado junto con el tamaño de la lista, recorre la lista y muestra el id del estado junto con la descripcion
/// @param estados
/// @param tamEstado
/// @return 0 si hubo error y 1 si pudo funcionar correctamente
int MostrarEstados(eEstado* estados, int tamEstado);
/// @fn int CargarDescripcionEstado(eEstado*, int, int, char[])
/// @brief recibe como parametro la lista de estado junto con el tamaño de la lista,
/// recorre la lista y compara el idEstado que recibe como parametro con el idEstado de la estructura, al matchear copia la descripcion de ese id en una variable
/// @param estados
/// @param tamEstado
/// @param idEstado
/// @param descripcion
/// @return -1 si hubo error y 0 si pudo funcionar correctamente
int CargarDescripcionEstado(eEstado* estados, int tamEstado, int idEstado, char descripcion[]);


#endif /* ESTADO_H_ */
