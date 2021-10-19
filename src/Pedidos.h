/*
 * Pedidos.h
 *
 *  Created on: 19 oct 2021
 *      Author: alfre
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#include "ArrayClients.h"
typedef struct
{
	int id;
	int idPedido;
	int estado;
	int kilos;
	int isEmpty;
	int idLocalidad;
	char estadoDescripcion[40];
}ePedido;

int IniciarPedidos(ePedido *list, int len);
int BuscarLibrePedidos(ePedido *list, int len);
int AgregarPedido(ePedido* list, int id, int len, int *idPedido);
void MostrarPedido(ePedido x);
int ImprimirPedidos(ePedido* list, int len);
int BuscarPedido(ePedido* list, int len, int id);
int BuscarPedidoPorID(ePedido* list, int len, int id);
int CantidadPedidosPorID(ePedido* list, int len, int id);
int ContadorPedidos(ePedido* list, int *contadorPedidos, int len, int id);
int ImprimirClientePendiente(ePedido* lista, Clients* list, int len);
void MostrarPedidoPendiente(Clients* list, ePedido* lista);
int ImprimirPedidosPendientes(ePedido* lista, Clients* list, int len);
#endif /* PEDIDOS_H_ */
