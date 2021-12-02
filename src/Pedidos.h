/*
 * Pedidos.h
 *
 *  Created on: 19 oct 2021
 *      Author: alfre
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#include "ArrayClients.h"
#include "Estado.h"
#include "Localidad.h"
#include "Transporte.h"
typedef struct
{
	int idCliente;
	int idPedido;
	int estado;
	int kilos;
	int isEmpty;
	int idLocalidad;
	int idTransporte;
}ePedido;


/// @fn int IniciarPedidos(ePedido*, int)
/// @brief inicializa la lista de pedidos y las deja todas en vacio
/// @param list
/// @param len
/// @return -1 si hubo error y 0 si pudo funcionar correctamente
int IniciarPedidos(ePedido *list, int len);
/// @fn int BuscarLibrePedidos(ePedido*, int)
/// @brief recorre el array y guarda la primera direccion vacio en un indice
/// @param list
/// @param len
/// @return -1 si hubo error y el indice si pudo acceder correctamente
int BuscarLibrePedidos(ePedido *list, int len);
/// @fn int AgregarPedido(ePedido*, eEstado*, int, int, int, int*)
/// @brief busca el indice libre, pide y valida los datos personales del usuario, por ultimo cambia el estado del pedido a pendiente
/// @param list
/// @param estados
/// @param tamEstado
/// @param id
/// @param len
/// @param idPedido
/// @return -1 si hubo error y 0 si funciona correctamente
int AgregarPedido(ePedido* list, eEstado* estados, Clients* lista, eTransporte* listaTransporte, int tamTransporte, int tamEstado, int id, int len, int *idPedido);
/// @fn void MostrarPedido(ePedido, eEstado*, int)
/// @brief Muestra los pedidos tanto en pendiente como en completado junto con los datos de un cliente
/// @param x
/// @param estados
/// @param tamEstado
void MostrarPedido(ePedido x, eEstado* estados, eTransporte* listaTransporte, int tamEstado, int tamTransporte);
/// @fn int ImprimirPedidos(ePedido*, eEstado*, int, int)
/// @brief llama a mostrar pedidos e imprime todos los pedidos junto con el id de los clientes
/// @param list
/// @param estados
/// @param tamEstado
/// @param len
/// @return -1 si hubo error y 0 si pudo funcionar correctamente
int ImprimirPedidos(ePedido* list, eEstado* estados, eTransporte* listaTransporte, int tamEstado, int tamTransporte, int len);
int BuscarPedido(ePedido* list, int len, int id);
/// @fn int BuscarPedidoPorID(ePedido*, int, int)
/// @brief recibe un id como parametro y recorre el array en busca del pedido de ese id, cuando lo encuentra guarad el indice
/// @param list
/// @param len
/// @param id
/// @return -1 si hubo error y el indice si funciono correctamente
int BuscarPedidoPorID(ePedido* list, int len, int id);
/// @fn int CantidadPedidosPorID(ePedido*, int, int)
/// @brief busca por un id en la lista de pedidos el indice, al matchear agrega 1 al contador de pedidos
/// @param list
/// @param len
/// @param id
/// @return -1 si hubo error y los pedidos encontrados si funciono correctamente
int CantidadPedidosPorID(ePedido* list, int len, int id);
/// @fn int ContadorPedidos(ePedido*, int*, int, int)
/// @brief recorre el array de pedidos, al encontrar matchs con los ids y cuando las listas estan cargadas y pendientes, agrega 1 al contador de pedidos
/// @param list
/// @param contadorPedidos
/// @param len
/// @param id
/// @return -1 si hubo error y 0 si pudo funcionar
int ContadorPedidos(ePedido* list, int *contadorPedidos, int len, int id);
/// @fn int PedidosPorLocalidad(ePedido*, eLocalidad*, int, int, int)
/// @brief compara el id que pasa por parametro junto con el id de localidad y el estado del pedidos, al hacer match carga 1 al contador de pedidos
/// @param lista
/// @param list
/// @param tam
/// @param len
/// @param id
/// @return -1 si hubo error y el contador de pedidos si funciono correctamente
int PedidosPorLocalidad(ePedido* lista, eLocalidad* list, int tam, int len, int id);
/// @fn int ImprimirClientePendiente(ePedido*, Clients*, int)
/// @brief recorre la listas de pedidos y la lista de clientes, compara los ids de la lista y valida que el estado del pedido sea en pendiente, luego imprime los datos del cliente pendiente
/// @param lista
/// @param list
/// @param len
/// @return -1 si hubo error y 0 si pudo funcionar correctamente
int ImprimirClientePendiente(ePedido* lista, Clients* list, int len, int tam);
/// @fn void MostrarPedidoPendiente(Clients*, ePedido*)
/// @brief compara los id del pedido junto con lo del cliente y muestra los datos del cliente al hacer match
/// @param list
/// @param lista
void MostrarPedidoPendiente(Clients* list, ePedido* lista);
/// @fn int ImprimirPedidosPendientes(ePedido*, Clients*, int)
/// @brief  recorre los array de cliente y de pedidos, verifica que el estado del pedido sea pendiente y por ultimo imprime todos los pedidos en pendiente junto con info del cliente
/// @param lista
/// @param list
/// @param len
/// @return -1 si da error y 0 si funciono correctamente
int ImprimirPedidosPendientes(ePedido* lista, Clients* list, int len, int tam);
/// @fn int ClienteMasPendientes(ePedido*, Clients*, int, int)
/// @brief recorre ambos arrays, compara el pedido con el id del cliente, valida que el pedido esta en pendiente y si todo matchea corrrectamente agrega 1 al contador en el indice i. con el contador compara el cliente para verificar que sea/sean el/los cliente con mas pedidos pendientes
/// @param lista
/// @param list
/// @param len
/// @param tam
/// @return 0 si da error y 1 si funciona correctamente
int ClienteMasPendientes(ePedido* lista, Clients* list, int len, int tam);
/// @fn int ClienteMasCompletados(ePedido*, Clients*, int, int)
/// @brief recorre ambos arrays, compara el pedido con el id del cliente, valida que el pedido esta en completados y si todo matchea corrrectamente agrega 1 al contador en el indice i. con el contador compara el cliente para verificar que sea/sean el/los cliente con mas pedidos pendientes y lo/los imprime
/// @param lista
/// @param list
/// @param len
/// @param tam
/// @return 0 si da error y 1 si funciona correctamente
int ClienteMasCompletados(ePedido* lista, Clients* list, int len, int tam);
/// @fn int vehiculoMasKilosEnviados(ePedido*, int)
/// @brief Recorre el array en busca del vehiculo que mas cantidad de kilos envio en el transcurso del programa y lo printea
/// @param lista
/// @param len
/// @return 0 si da error y 1 si funciona correctamente
int vehiculoMasKilosEnviados(ePedido* lista, int len);
/// @fn int primerClienteMoto(ePedido*, Clients*, eTransporte*, int, int, int)
/// @brief recorre los array de las 3 listas en busca del primer envio completado que haya sido realizado en moto y printea el nombre y el cuil de la persona
/// @param lista
/// @param list
/// @param listaTransporte
/// @param len
/// @param tam
/// @param tamTransporte
/// @return 0 si da error y 1 si funciona correctamente
int primerClienteMoto(ePedido* lista, Clients* list, eTransporte* listaTransporte, int len, int tam, int tamTransporte);
#endif /* PEDIDOS_H_ */
