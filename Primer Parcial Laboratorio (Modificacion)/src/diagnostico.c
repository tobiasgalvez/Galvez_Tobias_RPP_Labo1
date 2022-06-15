/*
 * diagnostico.c
 *
 *  Created on: 7 may. 2022
 *      Author: Tobias Galvez
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "diagnostico.h"

int listarDiagnosticos(eDiagnostico lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {

        printf("\n--------LISTA DE DIAGNOSTICOS--------\n");
        for(int i=0; i<tam; i++)
        {
            printf("Id: %d\n Diagnostico: %s\n ", lista[i].id, lista[i].descripcion);
            printf("\n----------------------\n");
        }
        todoOk= 1;
    }
    return todoOk;
}


int cargarDescripcionDiagnostico(eDiagnostico diagnosticos[], int tam, int idDiagnostico, char descripcion[])
{
	int todoOk = 0;
	if(diagnosticos != NULL && tam > 0 && descripcion != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(diagnosticos[i].id == idDiagnostico)
			{
				strcpy(descripcion, diagnosticos[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
