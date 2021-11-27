/*
 * Localidad.h
 *
 *  Created on: 19 oct 2021
 *      Author: alfre
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

typedef struct
{
    int id;
    char descripcion[50];
}eLocalidad;

/// @fn int mostrarLocalidades(eLocalidad*, int)
/// @brief recibe como parametro las localidades y el tamaño de la lista. Recorre la lista de localidades y muestra el id de las localidades junto con la descripcion
/// @param localidades
/// @param tam
/// @return 0 si hubo error y 1 si pudo acceder correctamente
int mostrarLocalidades(eLocalidad* localidades, int tam);
/// @fn int cargarDescripcionLocalidad(eLocalidad*, int, int, char[])
/// @brief recibe el idLocalidad como parametro y recorre el array de localidades mientras compara el id ingresado con el de la estructura.
/// Al matchear copia la descripcion de la estructura con la descripcion recibida por parametro
/// @param localidades
/// @param tam
/// @param idLocalidad
/// @param descripcion
/// @return -1 si hubo error y 0 si pudo acceder correctamente
int cargarDescripcionLocalidad(eLocalidad* localidades, int tam,int idLocalidad, char descripcion[]);

#endif /* LOCALIDAD_H_ */
