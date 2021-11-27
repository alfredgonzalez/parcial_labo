/*
 * Estado.c
 *
 *  Created on: 2 nov 2021
 *      Author: alfre
 */

#include "Estado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int MostrarEstados(eEstado* estados, int tamEstado)
{
	int allOk=0;

	if (estados != NULL && tamEstado > 0 )
	{
		printf("       Localidades  \n\n");
		printf("  Id         Descripcion\n");
		for(int i=0; i<tamEstado;i++)
		{
			printf("  %d       %-10s\n", estados[i].idEstado, estados[i].descripcion);
		}
		allOk=1;
	}
	return allOk;
}

int CargarDescripcionEstado(eEstado* estados, int tamEstado, int idEstado, char descripcion[])
{
	int allOk=0;
	int flag=1;

	if(estados != NULL && tamEstado>0 && descripcion != NULL)
	{
		allOk = 1;
		for(int i=0; i<tamEstado; i++)
		{
			if(estados[i].idEstado == idEstado)
			{
				strcpy(descripcion, estados[i].descripcion);
				flag =0;
				break;
			}
		}
		if(flag)
		{
			allOk=-1;
		}
	}
	return allOk;
}
