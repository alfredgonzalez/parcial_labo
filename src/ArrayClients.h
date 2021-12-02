/*
 * ArrayClients.h
 *
 *  Created on: 17 oct 2021
 *      Author: alfre
 */

#ifndef ARRAYCLIENTS_H_
#define ARRAYCLIENTS_H_
#include "Localidad.h"

typedef struct
{
	int id;
	char empresa[51];
	char direccion[51];
	int direccionNum;
	char cuit[12];
	int idLocalidad;
	int isEmpty;
}Clients;

/// @fn int IniciarClientes(Clients*, int)
/// @brief recorre el array de lista de clientes dejando todos los espacios vacios
/// @param list
/// @param len
/// @return 0 despues de recorrer el array
int IniciarClientes(Clients* list, int len);
/// @fn int BuscarLibre(Clients*, int)
/// @brief recorre el array de lista de clientes hasta encontrar el primer indice vacio y lo guarda.
/// @param list
/// @param len
/// @return el indice vacio encontrar
int BuscarLibre(Clients* list, int len);
/// @fn int AgregarCliente(Clients*, int*, int)
/// @brief llama a BuscarLibre y guarda el indice vacio encontrado, en ese indice pide y valida los datos personales del usuario
/// @param list
/// @param pId
/// @param len
/// @return retorna 1 si pudo acceder a la lista y 0 si hubo algun error
int AgregarCliente(Clients *list, eLocalidad* localidades, int *pId,int len);
/// @fn int EncontrarClientePorID(Clients*, int, int)
/// @brief pasa un id por parametro y lo compara con todos los id de la lista de clientes, al encontrar el id, guarda el indice.
/// @param list
/// @param len
/// @param id
/// @return retorna el indice del id buscado, o -1 si no pudo encontrarlo
int EncontrarClientePorID(Clients* list, int len,int id);
/// @fn int ModificarCliente(Clients*, int)
/// @brief pide un id al usuario, luego con el id llama a la funcion EncontrarClientePorID para encontrar el indice del cliente, una vez
/// accede a los datos da al cliente la opcion de cambiar la direccion o la localidad.
/// @param list
/// @param len
/// @return retorna 0 si tuvo algun error y 1 si pudo acceder correctamente.
int ModificarCliente(Clients* list, int len, eLocalidad* localidades, int tamLoc);
/// @fn int BajaCliente(Clients*, int, int)
/// @brief recibe un id como parametro, llama a la funcion EncontrarClientePorID y lo guarda en un indice, al acceder al indice da opcion al usuario
/// de eliminarlo o cancelar la baja. Si la baja se realiza, deja la direccion de ese cliente en 0
/// @param list
/// @param len
/// @param id
/// @return retorna -1 si hubo algun error y 0 si pudo acceder correctamente
int BajaCliente(Clients* list, int len, int id);
/// @fn int ContadorClientes(Clients*, int*, int)
/// @brief recibe un puntero de int como parametro, recorre el array de clientes y por cada uno que este cargado suma 1 al contador
/// @param list
/// @param contadorClientes
/// @param len
/// @return -1 si hubo algun error y 0 si pudo acceder correctamente
int ContadorClientes(Clients* list, int *contadorClientes, int len);
/// @fn void MostrarCliente(Clients, eLocalidad*, int)
/// @brief recibe como parametro los clientes, la lista de localidades y el tamaño de la lista de localidades.
/// Llama a CargarDescripcionLocalidad y si no tiene ningun error muestra el cliente junto con la localidad
/// @param x
/// @param localidades
/// @param tamLoc
void MostrarCliente(Clients x, eLocalidad* localidades, int tamLoc);
/// @fn int ImprimirClientes(Clients*, eLocalidad*, int, int)
/// @brief recibe como parametro los clientes, la lista de localidades y el tamaño de la lista de localidades y de clientes. recorre el array de clientes y muestra todos los que esten cargados
/// @param list
/// @param localidades
/// @param tamLoc
/// @param len
/// @return -1 si hubo error y 0 si pudo acceder correctamente
int ImprimirClientes(Clients* list,eLocalidad* localidades, int tamLoc, int len);


#endif /* ARRAYCLIENTS_H_ */
