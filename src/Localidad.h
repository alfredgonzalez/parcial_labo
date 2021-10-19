/*
 * Localidad.h
 *
 *  Created on: 19 oct 2021
 *      Author: alfre
 */
#include "Pedidos.h"
#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_


typedef struct
{
    int id;
    char descripcion[50];
}eLocalidad;

int mostrarLocalidades(eLocalidad* localidades, int tam);
int PedidosPorLocalidad(ePedido* lista, eLocalidad* list, int tam, int len, int id);
#endif /* LOCALIDAD_H_ */
