/*
 * ArrayClients.h
 *
 *  Created on: 17 oct 2021
 *      Author: alfre
 */

#ifndef ARRAYCLIENTS_H_
#define ARRAYCLIENTS_H_

typedef struct
{
	int id;
	char empresa[51];
	char direccion[51];
	int direccionNum;
	char cuit[12];
	int localidad;
	int isEmpty;
}Clients;


int IniciarClientes(Clients* list, int len);
int BuscarLibre(Clients* list, int len);
int AgregarCliente(Clients* list,int *pId,int len);
int EncontrarClientePorID(Clients* list, int len,int id);
int ModificarCliente(Clients* list, int len);
int BajaCliente(Clients* list, int len, int id);
int ContadorClientes(Clients* list, int *contadorClientes, int len);
void MostrarClientes(Clients x);



#endif /* ARRAYCLIENTS_H_ */
