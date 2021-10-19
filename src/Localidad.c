/*
 * Localidad.c
 *
 *  Created on: 19 oct 2021
 *      Author: alfre
 */

#include "Localidad.h"
#include "Pedidos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define PENDIENTE 0


int mostrarLocalidades(eLocalidad* localidades, int tam )
{
    int allOk = 0;
    if (localidades != NULL && tam > 0 )
    {
        printf("       Localidades  \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n", localidades[i].id, localidades[i].descripcion);
        }
        //printf("\n");
        allOk = 1;
    }

    return allOk;
}

int PedidosPorLocalidad(ePedido* lista, eLocalidad* list, int tam,int len, int id)
{
	int pedidos=0;

	for(int i=0;i<tam;i++)
	{
		for(int j=0;i<len;i++)
		{
			if(id == list[j].id && lista[i].estado == PENDIENTE)
			{
				pedidos++;
			}
		}
	}
	return pedidos;
}

int cargarDescripcionLocalidad(eLocalidad* localidades, int tam,int idLocalidad, char descripcion[])
{
    int allOk = 0;
    int flag = 1;
    if (localidades != NULL && tam > 0 && descripcion != NULL)
    {
        allOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (localidades[i].id == idLocalidad)
            {
                strcpy(descripcion, localidades[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            allOk = -1; // no habia localidad con el id que le pasaron
        }
    }
    return allOk;
}


