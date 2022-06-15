/*
 * medico.c
 *
 *  Created on: 6 may. 2022
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "medico.h"



int listarMedicos(eMedico lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {

        printf("\n--------LISTA DE MEDICOS--------\n");
        for(int i=0; i<tam; i++)
        {
            printf("Id: %d\n Medico: %s\n", lista[i].idMedico, lista[i].nombre);
            printf("\n----------------------\n");
        }
        todoOk= 1;
    }
    return todoOk;
}

int cargarNombreMedico(eMedico medicos[], int tam, int idMedico , char nombre[])
{
	int todoOk = 0;
	if(medicos != NULL && tam > 0 && nombre != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(medicos[i].idMedico == idMedico)
			{
				strcpy(nombre, medicos[i].nombre);
				break;
			todoOk = 1;
			}
		}
	}
	return todoOk;
}

int buscarMedicoId(eMedico lista[], int tam, int id)
{
	int indice = -1;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].idMedico == id)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
