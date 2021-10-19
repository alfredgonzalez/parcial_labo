/*
 * Tipo.h
 *
 *  Created on: 19 oct 2021
 *      Author: alfre
 */

#ifndef TIPO_H_
#define TIPO_H_

#include "Pedidos.h"
#include "ArrayClients.h"

typedef struct
{
	int HDPE;
	int LDPE;
	int PP;
	int idPedido;
	int isEmpty;
}eTipo;


int BuscarLibreTipo(eTipo* lista, int len);
int IniciarTipos(eTipo *lista, int len);
int PedirTipos(ePedido* list, int len, int id, eTipo* lista);
int ImprimirPedidosCompletados(ePedido* lista, Clients* list, int len, eTipo* listaT);


#endif /* TIPO_H_ */
