/*
 * ArrayClients.c
 *
 *  Created on: 17 oct 2021
 *      Author: alfre
 */

#include "ArrayClients.h"
#include "Localidad.h"
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
#define TAM_LOC 5



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


int AgregarCliente(Clients *list, eLocalidad* localidades, int *pId,int len)
{
    int todoOk = 0 ;
    int indice;

    Clients auxClients;
    eLocalidad auxLocalidad;
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
            while(verificarSiContieneNumero(auxClients.empresa) == 1 || validarLargoString (auxClients.empresa,3, 20))
            {
            	ingresarString("Error(Ingresa solo caracteres),Minimo 3 letras Maximo 20.\n Ingresa el nombre de la empresa: ", auxClients.empresa);
            }
            ingresarString("Ingresa la calle:  ", auxClients.direccion);
            while(verificarSiContieneNumero(auxClients.direccion) == 1)
            {
                ingresarString("Error(Ingresa solo caracteres).\n Ingresa la direccion: ", auxClients.direccion);
            }
            auxClients.direccionNum = ingresarEntero("Ingresa la altura de la calle: ");
            ingresarString("Ingresa el cuit(sin guiones ni puntos): ", auxClients.cuit);

            while(verificarSiContieneNumero(auxClients.cuit) == 0 || strlen(auxClients.cuit) != 11)
            {
            	ingresarString("Error(Ingresa solo numeros), el cuit debe tener 11 numeros en total(sin guiones ni puntos).\n Ingresa el cuit de la empresa: ", auxClients.cuit);
            }
            mostrarLocalidades(localidades, TAM_LOC);
            auxLocalidad.id = ingresarEntero("Ingresa la localidad del cliente: ");
            while(auxLocalidad.id != 100 && auxLocalidad.id != 101 && auxLocalidad.id != 102 && auxLocalidad.id != 103 && auxLocalidad.id != 104)
            {
            	mostrarLocalidades(localidades, TAM_LOC);
            	printf("Error.. la localidad ingresada no se encuentra en la base de datos\n");
            	auxLocalidad.id = ingresarEntero("Ingresa la localidad del cliente. ");
            }
            auxClients.idLocalidad = auxLocalidad.id;
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
int ModificarCliente(Clients* list, int len, eLocalidad* localidades,int tamLoc)
{
    int allOk=0;
    int indice;
    int id;
    int option;
    int optionSeguir = 0;
    char descripcion[50];

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
            	cargarDescripcionLocalidad( localidades, tamLoc, list[indice].idLocalidad, descripcion);
                printf("Direccion: %s %d. \nLocalidad: %s", list[indice].direccion, list[indice].direccionNum, descripcion);
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
                	mostrarLocalidades(localidades, TAM_LOC);
                	list[indice].idLocalidad = ingresarEntero("Ingresa la localidad.\n ");
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
    		printf("Error el id no pertenece a ningun cliente\n");
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

void MostrarCliente(Clients x, eLocalidad* localidades, int tamLoc)
{
	char descLocalidad[20];

		if ( cargarDescripcionLocalidad( localidades, tamLoc, x.idLocalidad, descLocalidad) == 1)
		{

			printf("\n %-5d %-11s %-10s %-10d %-15s %-25s\n",x.id,x.empresa,x.direccion,x.direccionNum,x.cuit, descLocalidad);
		}

}

int ImprimirClientes(Clients* list,eLocalidad* localidades, int tamLoc, int len)
{
	int allOk=-1;

	if(list != NULL && len > 0)
	{

		printf("Lista de clientes:                                                     \n");
		printf("---------------------------------------------------------------------\n");
		printf(" Id    EMPRESA     DIRECCION             CUIT            Localidad \n");
		printf("---------------------------------------------------------------------\n");
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == CARGADO)
			{
				MostrarCliente(list[i], localidades, tamLoc);
			}
		}
		allOk=0;
	}
	return allOk;
}


