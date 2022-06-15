/*
 * clinica.c
 *
 *  Created on: 14 jun. 2022
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "clinica.h"



int listarClinicas(eClinica lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {

        printf("\n--------LISTA DE CLINICAS--------\n");
        for(int i=0; i<tam; i++)
        {
            printf("Id: %d\n Clinica: %s\n", lista[i].id, lista[i].descripcion);
            printf("\n----------------------\n");
        }
        todoOk= 1;
    }
    return todoOk;
}


int buscarClinicaId(eClinica lista[], int tam, int id)
{
	int indice = -1;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].id == id)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
