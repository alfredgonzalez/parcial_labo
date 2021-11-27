/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Localidad.h"
#include "Tipo.h"
#include "Pedidos.h"
#include "Transporte.h"
#include "Estado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblio.h"
#include "ArrayClients.h"
#define TAM 100
#define PEDIDOS 1000
#define TAM_TRANSPORTE 3
#define TAM_LOC 5
#define VACIO 1
#define CARGADO 0
#define INICIALIZADO -1



int main(void)
{
	setbuf(stdout, NULL);
	int idClient = 1000;
	Clients lista[TAM];
	eTipo listaTipo[PEDIDOS];
	ePedido listaPedido[PEDIDOS];
	int opcion=1;
	int contadorClientes=0;
	int idBaja;
	int idPedido = 1000;
	int idUsuario;
	int contadorPedidos=0;
	int idTipo;
	int pedidosLocalidad;
	int idLocalidad;
	int acumTipo=0;
	int contadorTipo=0;
	eLocalidad localidades[TAM_LOC] =
	    {
	        { 100, "Avellaneda" },
	        { 101, "Bernal" },
	        { 102, "Quilmes" },
	        { 103, "Lanus" },
	        { 104, "Sarandi" }
	    };
	eEstado estadoPedido[3] =
	{
			{0, "Pendiente"},
			{1, "No asignado"},
			{2, "Completado"},
	};
	eTransporte listaVehiculo[3] =
	{
			{1, "Moto", 50},
			{2, "Auto", 100},
			{3, "Camion", 200}
	};


	if((IniciarClientes(lista,TAM) == -1) || (IniciarPedidos(listaPedido, PEDIDOS) == -1) || IniciarTipos(listaTipo, PEDIDOS) == -1)
	{
	    printf("Error....\n");
	}

	do
	{
		switch(pedirOpcion())
		{
		case 1:
			printf("NUEVO CLIENTE\n");
			if(BuscarLibre(lista, TAM)==-1)
			{
				printf("Error.. no se encontro un lugar libre\n");
			}
			else
			{
				BuscarLibre(lista, TAM);
				AgregarCliente(lista, localidades, &idClient, TAM);
				printf("------------------------\n");
				printf("Alta realizada con exito\n");
				printf("------------------------\n");
				contadorClientes++;
			}
			break;
		case 2:
			if(contadorClientes==0)
			{
				printf("Error, no hay clientes en la base de datos\n");
			}
			else
			{
				ImprimirClientes(lista, localidades, TAM_LOC, TAM);
				if(!ModificarCliente(lista, TAM, localidades))
				{
					printf("No se pudo modificar el cliente\n");
				}
				else
				{
					printf("--------------------------------\n");
					printf("Modificacion realizada con exito\n");
					printf("--------------------------------\n");
				}
			}
			break;
		case 3:
			if(contadorClientes==0)
			{
				printf("Error, no hay clientes en la base de datos\n");
			}
			else
			{
				ImprimirClientes(lista, localidades, TAM_LOC, TAM);
				idBaja = ingresarEntero("Ingresa el id a dar de baja\n");
				if(BajaCliente(lista, TAM, idBaja)==-1)
				{
					printf("No fue posible realizar la baja\n");
				}
				else
				{
					printf("------------------------\n");
					printf("Baja realizada con exito\n");
					printf("------------------------\n");
					contadorClientes--;
				}
			}
			break;
		case 4:
			ContadorClientes(lista, &contadorClientes, TAM);
			if(contadorClientes==0)
			{
				printf("Error, no hay clientes en la base de datos\n");
			}
			else
			{
				ImprimirClientes(lista, localidades, TAM_LOC, TAM);
				if(BuscarLibrePedidos(listaPedido, PEDIDOS) == -1)
				{
					printf("Error\n");
				}
				else
				{
					idUsuario = ingresarEntero("Ingresar ID del cliente para el pedido: ");
					if(EncontrarClientePorID(lista, TAM, idUsuario)==-1)
					{
						printf("Error, no se encontro el cliente en la base de datos\n");
					}
					else
					{

						AgregarPedido( listaPedido, estadoPedido, lista, listaVehiculo, TAM_TRANSPORTE, 3, idUsuario, PEDIDOS, &idPedido);
						printf("Pedido cargado con exito\n");
						contadorPedidos++;
					}
				}
			}
			break;
		case 5:
			if(contadorPedidos==0)
			{
				printf("Error.. no hay pedidos cargados\n");
			}
			else
			{
				ImprimirPedidos(listaPedido, estadoPedido, listaVehiculo, 3, TAM_TRANSPORTE, PEDIDOS);
				idTipo= ingresarEntero("Ingresa el id del pedido pendiente: ");
				if(PedirTipos(listaPedido, PEDIDOS, idTipo, listaTipo, &acumTipo, &contadorTipo)==0)
				{
					printf("Error.. el id del pedido ingresado no es correcto\n");
				}
				else
				{
					printf("Tipos cargados correctamente\n");
				}
			}
			break;
		case 6:
			if(contadorPedidos==0)
			{
				printf("Error. no hay pedidos ingresados\n");
			}
			else
			{
				ImprimirClientePendiente(listaPedido, lista, TAM);
			}
			break;
		case 7:
			if(contadorPedidos==0)
			{
				printf("Error. no hay pedidos ingresados\n");
			}
			else
			{
				ImprimirPedidosPendientes(listaPedido, lista, TAM);
			}
			break;
		case 8:
			if(contadorPedidos==0)
			{
				printf("Error. no hay pedidos ingresados\n");
			}
			else
			{
				ImprimirPedidosCompletados(listaPedido, lista, TAM, listaTipo);
			}
			break;
		case 9:
			if(contadorPedidos==0)
			{
				printf("Error. no hay pedidos ingresados\n");
			}
			else
			{

				mostrarLocalidades(localidades, TAM_LOC);
				idLocalidad = ingresarEntero("Ingresa el numero segun la localidad (100.Avellaneda.\n101.Bernal.\n102.Quilmes.\n103.Lanus.\n104.Sarandi)\n: ");
				pedidosLocalidad = PedidosPorLocalidad(listaPedido, localidades, PEDIDOS, TAM, idLocalidad);
				printf("La cantidad de pedidos de esa localidad son (%d)\n", pedidosLocalidad);
			}

			break;
		case 10:
			if(contadorPedidos==0)
			{
				printf("Error. no hay pedidos ingresados\n");
			}
			else
			{
				calcularPromedio(listaPedido, PEDIDOS, &acumTipo, &contadorTipo);
			}
			break;
		case 11:
			if(contadorPedidos ==0)
			{
				printf("Error.. no se encontraron pedidos");
			}
			else
			{
				if(!ClienteMasPendientes(listaPedido,lista,TAM,PEDIDOS))
				{
					printf("No fue posible encontrar los clientes con mas pedidos en pendiente \n");
				}
			}

			break;
		case 12:
			if(contadorPedidos==0)
			{
				printf("Error.. no se encontraron pedidos");
			}
			else
			{
				if(!ClienteMasCompletados(listaPedido, lista, TAM, PEDIDOS))
				{
					printf("No fue posible encontrar los clientes con mas pedidos completados \n");
				}
			}
			break;
		case 13:
			if((contadorPedidos)==0)
			{
				printf("Error.. no se encontraron pedidos\n");
			}
			else
			{
				if(!vehiculoMasKilosEnviados(listaPedido, PEDIDOS))
						{
							printf("No fue posible encontrar el vehiculo con mas kilos enviados \n");
						}
			}
			break;
		case 14:
			if((contadorPedidos)==0)
			{
				printf("Error.. no se encontraron pedidos\n");
			}
			else
			{
				if(!primerClienteMoto(listaPedido, lista, listaVehiculo, TAM, PEDIDOS, TAM_TRANSPORTE))
				{
					printf("No fue posible encontrar el primer cliente con envio en moto\n");
				}
			}
			break;
		case 15:
			printf("Gracias por elegirnos");
			opcion = 0;
			break;
		}

	}while(opcion==1);
}



