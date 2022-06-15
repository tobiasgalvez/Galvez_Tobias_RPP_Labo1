/*
 * especialidad.c
 *
 *  Created on: 15 may. 2022
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "especialidad.h"


int listarEspecialidades(eEspecialidad lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {

        printf("\n--------LISTA DE ESPECIALIDADES--------\n");
        for(int i=0; i<tam; i++)
        {
            printf("Id: %d\n Especialidad: %s\n", lista[i].id, lista[i].descripcion);
            printf("\n-----------------------\n");
        }
        todoOk= 1;
    }
    return todoOk;
}

int cargarEspecialidad(eEspecialidad especialidades[], int tam, int idEspecialidad , char especialidad[])
{
	int todoOk = 0;
	if(especialidades != NULL && tam > 0 && especialidad != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(especialidades[i].id == idEspecialidad)
			{
				strcpy(especialidad, especialidades[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

