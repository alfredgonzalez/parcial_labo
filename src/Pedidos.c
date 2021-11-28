/*
 * Pedidos.c
 *
 *  Created on: 19 oct 2021
 *      Author: alfre
 */

#include "Pedidos.h"
#include "ArrayClients.h"
#include "Estado.h"
#include "Localidad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblio.h"
#include "Tipo.h"
#define TAM 100
#define PEDIDOS 100
#define COMPLETADO 2
#define VACIO 1
#define CARGADO 0
#define INICIALIZADO -1


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

int AgregarPedido(ePedido* list, eEstado* estados, Clients* lista, eTransporte* listaTransporte, int tamTransporte, int tamEstado, int id, int len, int *idPedido)
{
	int allOk=-1;
    int indice;
    ePedido auxPedido;
    int indiceCliente;
    eTransporte auxTransporte;


    if(list != NULL && len > 0)
    {
        indice = BuscarLibrePedidos(list, len);
        indiceCliente = EncontrarClientePorID(lista, TAM, id);
        if(indice == -1)
        {
            printf("Error.....");
        }
        else
        {
        	if(lista[indiceCliente].id != id)
        	{
        		printf("Error....");
        	}
        	else
        	{
        	auxPedido.idCliente = id;
        	auxPedido.idPedido = *idPedido;
        	(*idPedido)++;
            auxPedido.kilos = ingresarEntero("Ingrese la cantidad de kilos del pedido: ");
            auxPedido.estado = 0;
            auxPedido.isEmpty = CARGADO;
            auxPedido.idLocalidad = lista[indiceCliente].idLocalidad;
            mostrarTransportes(listaTransporte, tamTransporte);
            auxTransporte.idTransporte = ingresarEntero("Ingrese el id del transporte deseado: ");
            while(auxPedido.kilos > 50 && auxTransporte.idTransporte == 1)
            {
            	printf("Error, el transporte elegido no puede soportar esa cantidad de kilos\n");
            	auxTransporte.idTransporte = ingresarEntero("Ingrese el id del transporte deseado nuevamente: ");
            }
            while(auxPedido.kilos > 100 && auxTransporte.idTransporte == 2)
            {
            	printf("Error, el transporte elegido no puede soportar esa cantidad de kilos\n");
            	auxTransporte.idTransporte = ingresarEntero("Ingrese el id del transporte deseado nuevamente: ");
            }
            while(auxPedido.kilos > 200 && auxTransporte.idTransporte == 3)
            {
                printf("Error, el transporte elegido no puede soportar esa cantidad de kilos\n");
                auxTransporte.idTransporte = ingresarEntero("Ingrese el id del transporte deseado nuevamente: ");
            }
        	}
        	auxPedido.idTransporte = auxTransporte.idTransporte;
            list[indice] = auxPedido;
            MostrarPedido(list[indice], estados, listaTransporte, tamEstado, tamTransporte);
        }
      allOk=0;
    }
	return allOk;
}

void MostrarPedido(ePedido x, eEstado* estados, eTransporte* listaTransporte, int tamEstado, int tamTransporte)
{
	char estadoDescripcion[50];
	char transporteDescripcion[50];
	if(CargarDescripcionEstado(estados, tamEstado, x.estado, estadoDescripcion)==1 && cargarDescripcionTransporte(listaTransporte, tamTransporte, x.idTransporte, transporteDescripcion)==1)
	{
		if(x.estado==0)
		{
			printf("Lista de pedidos:                                                    \n");
			printf("--------------------------------------------------------------------------\n");
			printf("ID Cliente       KILOS          ID PEDIDO       ESTADO        VEHICULO\n");
			printf("--------------------------------------------------------------------------\n");
			printf("%-5d %15d %15d %20s %10s\n", x.idCliente, x.kilos,x.idPedido, estadoDescripcion, transporteDescripcion);
		}
		else
		{
			printf("Lista de pedidos:                                                    \n");
			printf("-------------------------------------------------------------------------\n");
			printf("ID Cliente       KILOS          ID PEDIDO       ESTADO        VEHICULO\n");
			printf("-------------------------------------------------------------------------\n");
			printf("%-5d %15d %15d %20s %10s\n", x.idCliente, x.kilos,x.idPedido, estadoDescripcion, transporteDescripcion);
		}
	}
}

int ImprimirPedidos(ePedido* list, eEstado* estados, eTransporte* listaTransporte, int tamEstado, int tamTransporte, int len)
{
	int allOk=-1;

	if(list != NULL && len > 0)
	{
		for(int i=0;i<len; i++)
		{
			if(list[i].isEmpty==CARGADO)
			{
				MostrarPedido(list[i], estados, listaTransporte, tamEstado, tamTransporte);
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
			if(list[i].idCliente==id && list[i].isEmpty == CARGADO)
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
				if(list[i].idCliente == id && list[i].isEmpty == CARGADO && list[i].estado == 0)
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
			if(list[i].isEmpty == CARGADO && list[i].estado == 0 &&list[i].idCliente == id)
			{
				auxiliarCont++;
			}
		}

		allOk=0;
	}
	*contadorPedidos = auxiliarCont;
	return allOk;
}
int PedidosPorLocalidad(ePedido* lista, eLocalidad* list, int tam,int len, int id)
{
	int pedidos=0;

	for(int i=0;i<tam;i++)
	{

			if(id==lista[i].idLocalidad && lista[i].estado == 0)
			{
				pedidos++;
			}
	}
	return pedidos;
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
			if(list[i].id == lista[j].idCliente && lista[j].estado == 0 && list[i].isEmpty == CARGADO && lista[j].isEmpty == CARGADO)
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
			if(list[i].id == lista[j].idCliente && lista[j].estado == 0 && list[i].isEmpty == CARGADO && lista[j].isEmpty == CARGADO)
			{
				printf("%-5s   %-11s%-10d    %-13d\n", list[i].cuit, list[i].direccion, list[i].direccionNum, lista[j].kilos);
			}
		}
	}
	return allOk;
}

int ClienteMasPendientes(ePedido* lista, Clients* list, int len, int tam)
{
	int contador[len];
	int flag =1;
	int mayorPendientes=0;
	int flagEstado=1;
	int allOk=0;
	for(int i=0;i<len;i++)
	{
		contador[i]=0;
	}
	if(lista != NULL && tam > 0 && list != NULL && len > 0)
	{
		printf("---------Cliente con mas pendientes---------\n");
		for(int i=0; i<len;i++)
		{
			for(int j=0; j<tam;j++)
			{
				if(lista[j].idCliente == list[i].id  && lista[j].isEmpty == CARGADO && lista[j].estado == 0)
				{
					flagEstado = 0;
					contador[i]++;
				}
			}
		}
		for(int i=0;i<len;i++)
		{
			if(contador[i] > mayorPendientes || flag == 1)
			{
				mayorPendientes = contador[i];
				flag = 0;
			}
		}
		for(int i=0;i<len;i++)
		{
			if(contador[i]==mayorPendientes && flagEstado == 0)
			{
				printf("El cliente con mas pedidos pendientes es: %s \n", list[i].empresa);
				break;
			}

		}
		if(flagEstado == 1)
		{
			printf("Error... no se encontraron pedidos pendientesn\n");
		}
		allOk=1;
	}
	return allOk;

}
int ClienteMasCompletados(ePedido* lista, Clients* list, int len, int tam)
{
	int contador[len];
	int flag =1;
	int mayorCompletados;
	int allOk=0;
	int flagEstado=1;
	for(int i=0;i<len;i++)
	{
		contador[i]=0;
	}
	if(lista != NULL && tam > 0 && list != NULL && len > 0)
	{

		for(int i=0; i<len;i++)
		{
			for(int j=0; j<tam;j++)
			{
				if(lista[j].idCliente == list[i].id  && lista[j].isEmpty == CARGADO && lista[j].estado == 2)
				{
					flagEstado = 0;
					contador[i]++;
				}
			}
		}
		for(int i=0;i<len;i++)
		{
			if(contador[i] > mayorCompletados || flag == 1)
			{
				mayorCompletados = contador[i];
				flag = 0;
			}
		}
		for(int i=0;i<len;i++)
		{
			if(contador[i]==mayorCompletados && flagEstado == 0)
			{
				printf("------------Cliente con mas pedidos completados-------------\n");
				printf("El cliente con mas pedidos completados  es: %s \n", list[i].empresa);
				break;
			}

		}
		if(flagEstado == 1)
		{
			printf("No se encontraron pedidos completados\n");
		}
		allOk=1;
	}
	return allOk;
}
int vehiculoMasKilosEnviados(ePedido* lista, int len)
{
	int allOk= 0;
	int acumMoto=0;
	int acumAuto=0;
	int acumCamion=0;
	if(lista != NULL && len >0)
	{
		for(int i=0; i<len; i++)
		{

			if(lista[i].isEmpty == CARGADO && lista[i].estado == COMPLETADO)
			{
				switch(lista[i].idTransporte)
				{
					case 1:
						acumMoto = lista[i].kilos + acumMoto;
					break;
					case 2:
						acumAuto = lista[i].kilos +acumAuto;
					break;
					case 3:
						acumCamion = lista[i].kilos + acumCamion;
					break;
				}
			}
		}
		allOk = 1;
		printf("---------Vehiculo con mas kilos enviados---------\n");
		if(acumMoto > acumAuto && acumMoto > acumCamion)
		{
			printf("El vehiculo con mas kilos enviados fue moto con un total de: [%d]\n", acumMoto);
		}
		else
		{
			if(acumAuto > acumMoto && acumAuto > acumCamion)
			{
				printf("El vehiculo con mas kilos enviados fue auto con un total de: [%d]\n", acumAuto);
			}
			else
			{
				if(acumCamion > acumAuto && acumCamion > acumMoto)
				{
					printf("El vehiculo con mas kilos enviados fue camion con un total de: [%d]\n", acumCamion);
				}
				else
				{
					printf("No se pudo encontrar el vehiculo con mas envios cargados\n");
				}
			}
		}
	}

	return allOk;
}

int primerClienteMoto(ePedido* lista, Clients* list, eTransporte* listaTransporte, int len, int tam, int tamTransporte)
{
	int allOk=0;
	int flag =1;
	char primerClienteMoto[50];
	char cuitPrimerMoto[20];

	if(lista != NULL && list != NULL && listaTransporte != NULL && len > 0 && tam > 0 && tamTransporte > 0)
	{
		for(int i=0; i<len;i++)
		{
			for(int j=0; j<tam;j++)
			{
				for(int k=0; k<tamTransporte;k++)
				{
					if(lista[j].idCliente == list[i].id && lista[j].isEmpty == CARGADO && lista[j].estado == 2
							&& listaTransporte[k].idTransporte == 1 && lista[j].idTransporte == 1 && flag == 1)
					{
						strcpy(primerClienteMoto, list[i].empresa);
						strcpy(cuitPrimerMoto, list[i].cuit);
						printf("El primer cliente con envio entregado en moto es: \nNOMBRE:%s\nCUIT:%s\n", primerClienteMoto, cuitPrimerMoto);
						flag = 0;
						break;
					}

				}
			}
		}
		allOk = 1;
		if(flag == 1)
		{
			printf("Error.. no hay pedidos entregados\n");
		}
	}
	return allOk;
}
