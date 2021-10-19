/*
 * Pedidos.c
 *
 *  Created on: 19 oct 2021
 *      Author: alfre
 */

#include "Pedidos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblio.h"
#include "Tipo.h"
#define TAM 100
#define PEDIDOS 100
#define VACIO 1
#define CARGADO 0
#define COMPLETADO 2
#define INICIALIZADO -1
#define NOASIGNADO 1
#define PENDIENTE 0

int IniciarPedidos(ePedido *list, int len)
{
    int allOk = -1;

    for(int i=0;i<len; i++)
    {
    	list[i].isEmpty = VACIO;
    }
    allOk = 0;

    return allOk;
}

int BuscarLibrePedidos(ePedido *list, int len)
{
    int indice = -1;

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty == VACIO)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int AgregarPedido(ePedido* list, int id, int len, int *idPedido)
{
	int allOk=-1;
    int indice;
    ePedido auxPedido;

    if(list != NULL && len > 0)
    {
        indice = BuscarLibrePedidos(list, len);
        if(indice == -1)
        {
            printf("Error.....");
        }
        else
        {
        	auxPedido.id = id;
        	auxPedido.idPedido = *idPedido;
        	(*idPedido)++;
            auxPedido.kilos = ingresarEntero("Ingrese la cantidad de kilos del pedido: ");
            auxPedido.estado = PENDIENTE;
            auxPedido.isEmpty = CARGADO;
            auxPedido.idLocalidad = ingresarEntero("Ingresa la localidad.\n 100.Avellaneda.\n101.Bernal.\n102.Quilmes.\n103.Lanus.\n104.Sarandi ");
            list[indice] = auxPedido;
            MostrarPedido(list[indice]);
        }
      allOk=0;
    }
	return allOk;
}

void MostrarPedido(ePedido x)
{
	if(x.estado==PENDIENTE)
	{
		strcpy(x.estadoDescripcion, "Pendiente");
		printf("Lista de pedidos:                                                    \n");
		printf("------------------------------------------------------------------\n");
		printf("ID Cliente       KILOS          ID PEDIDO       ESTADO  \n");
		printf("------------------------------------------------------------------\n");
		printf("%-5d %15d %15d %20s\n", x.id, x.kilos,x.idPedido, x.estadoDescripcion);
	}
	else
	{
		strcpy(x.estadoDescripcion, "Completado");
		printf("Lista de pedidos:                                                    \n");
		printf("------------------------------------------------------------------\n");
		printf("ID Cliente       KILOS          ID PEDIDO       ESTADO  \n");
		printf("------------------------------------------------------------------\n");
		printf("%-5d %15d %15d %20s\n", x.id, x.kilos,x.idPedido, x.estadoDescripcion);
	}
}

int ImprimirPedidos(ePedido* list, int len)
{
	int allOk=-1;

	if(list != NULL && len > 0)
	{
		for(int i=0;i<len; i++)
		{
			if(list[i].isEmpty==CARGADO)
			{
				MostrarPedido(list[i]);
			}
		}
		allOk=0;
	}

	return allOk;
}

int BuscarPedido(ePedido* list, int len, int id)
{
	int indice=-1;
	if(list != NULL && len > 0)
	{
		for(int i=0; i<len;i++)
		{
			if(list[i].id==id && list[i].isEmpty == CARGADO)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
int BuscarPedidoPorID(ePedido* list, int len, int id)
{
	int indice=-1;
	if(list != NULL && len > 0)
	{
		for(int i=0; i<len;i++)
		{
			if(list[i].idPedido==id && list[i].isEmpty == CARGADO)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int CantidadPedidosPorID(ePedido* list, int len, int id)
{
	int pedidos=-1;
	int indice;
	int contadorPedidos=0;
	if(list != NULL && len > 0)
	{
		indice = BuscarPedido(list,len, id);
		if(indice==-1)
		{
			printf("Error.. el id ingresado no existe");
		}
		else
		{
			for(int i=0; i<len; i++)
			{
				if(list[i].id == id && list[i].isEmpty == CARGADO && list[i].estado == PENDIENTE)
				{
					contadorPedidos++;
				}
			}
			pedidos= contadorPedidos;
		}
	}
	return pedidos;
}

int ContadorPedidos(ePedido* list, int *contadorPedidos, int len, int id)
{
	int auxiliarCont=0;
	int allOk=-1;

	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == CARGADO && list[i].estado == PENDIENTE &&list[i].id == id)
			{
				auxiliarCont++;
			}
		}

		allOk=0;
	}
	*contadorPedidos = auxiliarCont;
	return allOk;
}


int ImprimirClientePendiente(ePedido* lista, Clients* list, int len)
{
	int allOk=-1;

	printf("Lista de clientes pendientes:                                        \n");
	printf("---------------------------------------------------------------------\n");
	printf(" Id    EMPRESA     DIRECCION          KILOS          \n");
	printf("---------------------------------------------------------------------\n");
	for(int i=0;i<len; i++)
	{
		for(int j=0;j<len;j++)
		{
			if(list[i].id == lista[j].id && lista[i].estado == PENDIENTE && list[i].isEmpty == CARGADO && lista[j].isEmpty == CARGADO)
			{
				printf("%-5d  %-10s %-10s %-10d %-15d\n", list[i].id, list[i].empresa, list[i].direccion, list[i].direccionNum, lista[j].kilos);
			}
		}

	}

	return allOk;
}
int ImprimirPedidosPendientes(ePedido* lista, Clients* list, int len)
{
	int allOk=-1;

	printf("Lista de pedidos pendientes:                                        \n");
	printf("---------------------------------------------------------------------\n");
	printf(" CUIT          DIRECCION             KILOS          \n");
	printf("---------------------------------------------------------------------\n");
	for(int i=0;i<len; i++)
	{
		for(int j=0;j<len;j++)
		{
			if(list[i].id == lista[j].id && lista[i].estado == PENDIENTE && list[i].isEmpty == CARGADO && lista[j].isEmpty == CARGADO)
			{
				printf("%-5s   %-11s%-10d    %-13d\n", list[i].cuit, list[i].direccion, list[i].direccionNum, lista[j].kilos);
			}
		}
	}
	return allOk;
}

