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

/// @fn int IniciarTipos(eTipo*, int)
/// @brief recorre el array de tipo dejando todos los espacios vacios
/// @param lista
/// @param len
/// @return -1 si error y 0 si pudo funcionar correctamente
int IniciarTipos(eTipo *lista, int len);
/// @fn int BuscarLibreTipo(eTipo*, int)
/// @brief recorre el array de tipo hasta encontrar indice vacio y lo guarda
/// @param lista
/// @param len
/// @return el indice encontrado previamente
int BuscarLibreTipo(eTipo* lista, int len);
/// @fn int PedirTipos(ePedido*, int, int, eTipo*, int*, int*)
/// @brief recibe como parametro la lista de pedidos y 2 punteros de int, uno de acumulador y otro de contador de clientes.
/// Busca el indice deseado por medio de un ID, al encontrar el indice lo compara con el del estado del pedido y
/// si hay match pide al usuario los tipos de plasticos para su pedido
/// @param list
/// @param len
/// @param id
/// @param lista
/// @param pAcum
/// @param pClientes
/// @return 0 si hubo error y 1 si pudo funcionar correctamente
int PedirTipos(ePedido* list, int len, int id, eTipo* lista,int *pAcum, int *pClientes);
/// @fn int ImprimirPedidosCompletados(ePedido*, Clients*, int, eTipo*)
/// @brief recorre el array de pedidos y de tipos. Compara el estado del pedido, los ids del pedido y verifica que ambas listas esten cargadas,
/// por ultimo imprime los pedidos completados con los datos del cliente junto con los tipos de plasticos del pedido
/// @param lista
/// @param list
/// @param len
/// @param listaT
/// @return -1 si hubo error y 0 si pudo funcionar correctamente
int ImprimirPedidosCompletados(ePedido* lista, Clients* list, int len, eTipo* listaT);
/// @fn void calcularPromedio(ePedido*, int, int*, int*)
/// @brief calcula el promedio de PP que fue entregado en el transcurso del programa y lo printea
/// @param lista
/// @param len
/// @param pAcum
/// @param pContador
void calcularPromedio(ePedido* lista, int len, int *pAcum, int* pContador);


#endif /* TIPO_H_ */
