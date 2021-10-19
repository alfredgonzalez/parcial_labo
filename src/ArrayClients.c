/*
 * ArrayClients.c
 *
 *  Created on: 17 oct 2021
 *      Author: alfre
 */

#include "ArrayClients.h"
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



int IniciarClientes(Clients *list, int len)
{
    int allOk = -1;

    for(int i=0;i<len; i++)
    {
    	list[i].isEmpty = VACIO;
    }
    allOk = 0;

    return allOk;
}


int BuscarLibre(Clients *list, int len)
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


int AgregarCliente(Clients *list,int *pId,int len)
{
    int todoOk = 0 ;
    int indice;
    Clients auxClients;
    if(list != NULL && len > 0)
    {
        indice = BuscarLibre(list,len);
        if(indice == -1)
        {
            printf("Error");
        }
        else
        {
            auxClients.id = *pId;
            (*pId)++;
            ingresarString("Ingresa el nombre de la empresa: ", auxClients.empresa);
            ingresarString("Ingresa la calle:  ", auxClients.direccion);
            auxClients.direccionNum = ingresarEntero("Ingresa la altura de la calle: ");
            ingresarString("Ingresa el cuit ", auxClients.cuit);
            auxClients.localidad = ingresarEntero("Ingresa la localidad.\n 100.Avellaneda.\n101.Bernal.\n102.Quilmes.\n103.Lanus.\n104.Sarandi ");
            auxClients.isEmpty = CARGADO;
            list[indice] = auxClients;
        }
        todoOk = 1;
    }
    return todoOk;
}

int EncontrarClientePorID(Clients* list, int len,int id)
{
    int indice= -1;

    for(int i=0;i<len; i++)
    {
        if(id == list[i].id && list[i].isEmpty == CARGADO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
int ModificarCliente(Clients* list, int len)
{
    int allOk=0;
    int indice;
    int id;
    int option;
    int optionSeguir = 0;

    if(list != NULL && len >0)
    {
        id = ingresarEntero("Ingresa el id del cliente a modificar: ");
        indice = EncontrarClientePorID(list, len, id);
        if(indice==-1)
        {
            printf("Error.. el id (%d) ingresado no corresponde\n", id);
        }
        else
        {

            do
            {
                printf("Direccion: %s %d. \nLocalidad: %d", list[indice].direccion, list[indice].direccionNum, list[indice].localidad);
                option = ingresarEntero("\nSeleccione la informacion a modificar\n 1.Direccion\n 2.Localidad\n");
                while(option!=1&&option!=2)
                {
                    option = ingresarEntero("Error.. selecciona la opcion que corresponda.\nOption\n 1.Direccion\n 2.Localidad\n");
                }
                switch(option)
                {
                case 1:
                	ingresarString("Ingresa la direccion correcta: ",list[indice].direccion);
                	list[indice].direccionNum = ingresarEntero("\nIngresa el numero de direccion correcto: ");
                break;
                case 2:
                	list[indice].localidad = ingresarEntero("Ingresa la localidad.\n 100.Avellaneda.\n101.Bernal.\n102.Quilmes.\n103.Lanus.\n104.Sarandi ");
                break;
                default:
                    printf("Error.. la opcion ingresada no es correcta\n");
                break;
                }
            optionSeguir = ingresarEntero("Queres realizar otro cambio?\n1=si\n0 = no: \n");
            while(optionSeguir!=0 && optionSeguir!=1)
            {
            	optionSeguir = ingresarEntero("Queres realizar otro cambio?\n1=si\n0 = no: \n");
            }
        	}while(optionSeguir!=0);
            allOk=1;
        }
    }

    return allOk;
}

int BajaCliente(Clients* list, int len, int id)
{
    int allOk= -1;
    int indice;
    int remover;

    if(list !=NULL && len > 0)
    {
    	indice = EncontrarClientePorID(list,len,id);
    	if(indice == -1)
    	{
    		printf("Error \n");
    	}
    	else
    	{
    		remover = ingresarEntero("Desea remover el Cliente?\n1=Si.\t0=No");
    		while(remover!=1&&remover!=0)
    		{
    			printf("Error.. selecciona 1 Para remover.\n0 para cancelar.\n");
    		}
    		switch(remover)
    		{
    		case 1:
    			list[indice].isEmpty = VACIO;
    		break;
    		case 2:
    			printf("---------------------\n");
    			printf("La baja fue cancelada\n");
    			printf("---------------------\n");
    		break;
    		}
    		allOk=0;
    	}
    }

    return allOk;
}

int ContadorClientes(Clients* list, int *contadorClientes, int len)
{
	int auxiliarCont=0;
	int allOk=-1;

	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == CARGADO)
			{
				auxiliarCont++;
			}
		}

		allOk=0;
	}
	*contadorClientes = auxiliarCont;
	return allOk;
}


