/*
 * Transporte.c
 *
 *  Created on: 25 nov 2021
 *      Author: alfre
 */
#include "Transporte.h"

int mostrarTransportes(eTransporte* listaTransporte, int tamTransporte)
{
	int allOk = 0;
	if (listaTransporte != NULL && tamTransporte > 0 )
	{
	    printf("       VEHICULOS  \n\n");
	    printf("  Id      Vehiculo         Kilos Soportados\n");
	    for (int i = 0; i < tamTransporte; i++)
	    {
	         printf("  %d       %-10s       %-10d\n", listaTransporte[i].idTransporte, listaTransporte[i].vehiculo, listaTransporte[i].kilosSoportados);
	    }
	    allOk = 1;
	}
	return allOk;

}

int cargarDescripcionTransporte(eTransporte* listaTransporte, int tamTransporte,int idVehiculo, char descripcion[])
{
	 int allOk = 0;
	 int flag = 1;
	 if (listaTransporte != NULL && tamTransporte > 0 && descripcion != NULL)
	 {
	     allOk = 1;
	        for (int i = 0; i < tamTransporte; i++)
	        {
	            if (listaTransporte[i].idTransporte == idVehiculo)
	            {
	                strcpy(descripcion, listaTransporte[i].vehiculo);
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

