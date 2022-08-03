/*
 * hardcodeo.c
 *
 *  Created on: 1 ago. 2022
 *      Author: Tobias Galvez
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hardcodeo.h"


char nombres[5][20] = {
		"Juan",
		"Pedro",
		"Sofia",
		"Miguel",
		"Valentina",
};


int fecha[5][3] = {{10, 10, 2009} ,{14, 7, 2021}, {29, 5, 2015}, {5,4,2022}, {23, 1, 2001}};

int idDiagnostico[5] = {0,0,0,0,0};

int idMedico[5] = {1001, 1000, 1001, 1004, 1003};

int hardcodearConsultas(eConsulta* lista, int tam, int cant, int* pId)
{
	int contador = -1;
	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
	{
		contador = 0;
		for(int i = 0; i < cant; i++)
		{
			lista[i].idConsulta = *pId;
			(*pId)++;
			strcpy(lista[i].nombrePaciente, nombres[i]);
			lista[i].fecha.dia = fecha[i][0];
			lista[i].fecha.mes = fecha[i][1];
			lista[i].fecha.anio = fecha[i][2];
			lista[i].idDiagnostico = idDiagnostico[i];
			lista[i].idMedico = idMedico[i];
			lista[i].estado = 1;
			contador++;
		}
	}
	return contador;
}
