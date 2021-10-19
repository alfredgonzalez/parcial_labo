/*
 * Biblio.c
 *
 *  Created on: 17 oct 2021
 *      Author: alfre
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblio.h"

int ingresarString(char mensaje[], char dato[])
{
	int allOk = 0;

	    if(mensaje != NULL && dato !=NULL)
	    {
	        printf("%s", mensaje);
	        fflush(stdin);
	        gets(dato);

	        allOk = 1;
	    }

	    return allOk;
}
int ingresarEntero(char mensaje[])
{
    int numeroIngresado;
    printf("%s",mensaje);

    scanf("%d",&numeroIngresado);

    return numeroIngresado;

}
float ingresarFlotante(char mensaje[])
{
    float numeroIngresado;
    printf("%s",mensaje);

    scanf("%f",&numeroIngresado);

    return numeroIngresado;

}
int validarRangoEntero(int valor, int limiteInferior, int limiteSuperior)
{
    int allOk = 0;
    if(valor >= limiteInferior && valor <= limiteSuperior )
    {
        allOk = 1;
    }
    return allOk;
}
int stringPrimeroLetraMayuscula(char string[])
{
    int allOk = -1;
    int i = 0;

    if(string != NULL)
    {
        strlwr(string);
        string[0] = toupper(string[0]);
        while(string[i] != '\0')
        {
            if(string[i] == ' ')
            {
                string[i+1] = toupper(string[i+1]);
            }

            i++;
        }
        allOk = 0;
    }
    return allOk;
}
int pedirOpcion(void)
{
	int opcion;
	system("cls");
	printf("1.ALTA CLIENTE\n");
	printf("2.MODIFICACION CLIENTE\n");
	printf("3.BAJA CLIENTE\n");
	printf("4.IMPRIMIR CLIENTES/CREAR PEDIDO DE RECOLECCION\n");
	printf("5.PROCESAR RESIDUOS \n");
	printf("6.IMPRIMIR CLIENTES CON PEDIDOS PENDIENTES\n");
	printf("7.IMPRIMIR PEDIDOS PENDIENTES\n");
	printf("8.IMPRIMIR PEDIDOS PROCESADOS\n");
	printf("9.INDICAR PEDIDOS PENDIENTES POR LOCALIDAD\n");
	printf("10.CANTIDAD DE KILOS DE POLIPROPILENO RECICLADO PROMEDIO\n");
	printf("11.SALIR\n");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
