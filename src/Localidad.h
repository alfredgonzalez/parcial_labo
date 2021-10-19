/*
 * Localidad.h
 *
 *  Created on: 19 oct 2021
 *      Author: alfre
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#include "Pedidos.h"
#include "ArrayClients.h"
typedef struct
{
    int id;
    char descripcion[50];
}eLocalidad;

int mostrarLocalidades(eLocalidad* localidades, int tam);
int PedidosPorLocalidad(ePedido* lista, eLocalidad* list, int tam, int len, int id);
void MostrarCliente(Clients x, eLocalidad* localidades, int tamLoc);
int ImprimirClientes(Clients* list,eLocalidad* localidades, int tamLoc, int len);
#endif /* LOCALIDAD_H_ */
