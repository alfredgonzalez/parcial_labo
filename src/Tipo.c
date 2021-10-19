/*
 * Tipo.c
 *
 *  Created on: 19 oct 2021
 *      Author: alfre
 */

#include "Tipo.h"
#include "Pedidos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblio.h"
#define TAM 100
#define PEDIDOS 1000
#define VACIO 1
#define CARGADO 0
#define COMPLETADO 2
#define INICIALIZADO -1
#define NOASIGNADO 1
#define PENDIENTE 0

int IniciarTipos(eTipo *list, int len)
{
    int allOk = -1;

    for(int i=0;i<len; i++)
    {
    	list[i].isEmpty = VACIO;
    }
    allOk = 0;

    return allOk;
}

int BuscarLibreTipo(eTipo* lista, int len)
{
    int indice = -1;

    for(int i=0;i<len;i++)
    {
        if(lista[i].isEmpty == VACIO)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int PedirTipos(ePedido* list, int len, int id, eTipo* lista, int *pAcum, int *pClientes)
{
	int allOk=0;
	int indice;
	eTipo auxTipo;
	int acumulador=0;
	int indiceTipo;

	if(list != NULL && len > 0)
	{
		indice = BuscarPedidoPorID(list, len, id);
		indiceTipo = BuscarLibreTipo(lista, len);
		if(indice==-1 || list[indice].estado == COMPLETADO)
		{
			printf("Error..\n");
		}
		else
		{
			auxTipo.HDPE = ingresarEntero("Ingresa la cantidad de HDPE: ");
			auxTipo.LDPE = ingresarEntero("Ingresa la cantidad de LDPE: ");
			auxTipo.PP = ingresarEntero("Ingresa la cantidad de PP: ");
			acumulador = auxTipo.HDPE + auxTipo.LDPE + auxTipo.PP;
			*pAcum = auxTipo.PP + *pAcum ;
			(*pClientes)++;

			while(validarRangoEntero(acumulador, 0, list[indice].kilos)==0)
			{
				printf("Error...Superaste los kilos o ingresaste un numero negativo \n");
				auxTipo.HDPE = ingresarEntero("Ingresa la cantidad de HDPE: ");
				auxTipo.LDPE = ingresarEntero("Ingresa la cantidad de LDPE: ");
				auxTipo.PP = ingresarEntero("Ingresa la cantidad de PP: ");
				acumulador = auxTipo.HDPE + auxTipo.LDPE + auxTipo.PP;
			}

			auxTipo.idPedido = id;
			lista[indiceTipo] = auxTipo;
			list[indice].estado = COMPLETADO;
			allOk= 1;
		}

	}
	return allOk;
}
int ImprimirPedidosCompletados(ePedido* lista, Clients* list, int len, eTipo* listaT)
{
	int allOk=-1;
	printf("-------------------------------------------------\n");
	printf("  CUIT         DIRECCION          HDPE  LDPE  PP\n");
	printf("-------------------------------------------------\n");
	for(int i=0;i<len; i++)
	{
		for(int j=0;j<len;j++)
		{
			for(int k=0;k<len;k++)
			{
				if(lista[i].estado == COMPLETADO && list[i].isEmpty == CARGADO && lista[j].isEmpty == CARGADO &&
						listaT[k].idPedido == lista[j].idPedido)
				{
					printf("%-10s %-11s %-10d %-5d %-5d %-5d\n", list[i].cuit, list[i].direccion, list[i].direccionNum, listaT[k].HDPE, listaT[k].LDPE, listaT[k].PP);
				}
			}
		}
	}
	return allOk;
}
