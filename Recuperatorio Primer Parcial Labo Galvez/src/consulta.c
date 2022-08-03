/*
 * consulta.c
 *
 *  Created on: 6 may. 2022
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "consulta.h"
#include "menus.h"
#define VACIO 0
#define LLENO 1


int inicializarConsulta(eConsulta lista[], int tam)
{
	int todoOk = 0;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			lista[i].estado = VACIO;
		}
		todoOk = 1;
	}
	return todoOk;
}


int buscarLibre(eConsulta lista[], int tam)
{
	int indice = -1;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].estado == VACIO)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}


int buscarConsultaId(eConsulta lista[], int tam, int id)
{
	int indice = -1;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].estado == LLENO && lista[i].idConsulta == id)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}


void mostrarConsulta(eConsulta unaConsulta, eMedico unMedico, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades)
{
	char descNombre[50];
	char descEspecialidad[20];
	char descDiagnostico[20];
	if(unaConsulta.idDiagnostico == 0)
	{
		strcpy(descDiagnostico, "Sin diagnostico");
	}
	else
	{
		cargarDescripcionDiagnostico(diagnosticos, tamDiagnosticos, unaConsulta.idDiagnostico, descDiagnostico);
	}


	cargarNombreMedico(medicos, tamMedicos, unaConsulta.idMedico, descNombre);
	cargarEspecialidad(especialidades, tamEspecialidades, unMedico.idEspecialidad, descEspecialidad);


	printf("  %d %15s  %15d/%d/%d  %16s %20s %22s\n",
			unaConsulta.idConsulta,
			unaConsulta.nombrePaciente,
			unaConsulta.fecha.dia,
			unaConsulta.fecha.mes,
			unaConsulta.fecha.anio,
			descNombre,
			descEspecialidad,
			descDiagnostico);
}

int mostrarConsultas(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades)
{
	int todoOk = 0;
	int flag = 1;
	if(lista != NULL && tam > 0)
	{
		system("cls");
	    printf(" ******************* Listado de consultas ***********************\n");
		printf("   Id  Nombre del paciente \t\tFecha\t\t Medico\t\t Especialidad\t\t Diagnostico\n");
	    printf("--------------------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < tam; i++)
		{
			for(int j=0; j<tamMedicos;j++)
			{
				if(lista[i].estado == LLENO)
				{
					if(lista[i].idMedico == medicos[j].idMedico)
					{
						mostrarConsulta(lista[i], medicos[j], medicos, tamMedicos, diagnosticos, tamDiagnosticos, especialidades, tamEspecialidades);
						flag =0;
						todoOk = 1;
						break;

					}
				}
			}


		}
		if(flag)
		{
			printf("No hay consultas para mostrar\n");
		}
	}
	return todoOk;
}


int altaConsulta(eConsulta lista[], int tam, int* pId, eMedico medicos[], int tamMedicos)
{
	int todoOk = 0;
	int indice;
	eConsulta auxConsulta;

	if(lista != NULL && tam > 0)
	{
		system("cls");
	    printf("******************** Alta consulta ********************\n");
	    printf("-------------------------------------------------------\n");

		indice = buscarLibre(lista, tam);
		if(indice == -1)
		{
			printf("No hay lugar en el sistema\n");
		}
		else
		{
			auxConsulta.idConsulta = *pId;
			(*pId)++;

			utn_getCadena(auxConsulta.nombrePaciente, 50, 3, "Ingrese nombre del paciente: \n", "Error!!! \n");
			printf("Ingrese fecha de atencion:\n");
			utn_getEntero(&auxConsulta.fecha.dia, 3, "Dia: \n", "Error, no es un dia valido\n", 1, 31);
			utn_getEntero(&auxConsulta.fecha.mes, 3, "Mes: \n", "Error, no es un mes valido\n", 1, 12);
			utn_getEntero(&auxConsulta.fecha.anio, 3, "A�o: \n", "Error, no es un a�o valido\n", 1, 2022);

			/*listarDiagnosticos(diagnosticos, tamDiag);
			utn_getEntero(&auxConsulta.idDiagnostico, 3, "Ingrese id de diagnostico: \n", "Error, id invalido", 1, 3);
			*/

			listarMedicos(medicos, tamMedicos);
			utn_getEntero(&auxConsulta.idMedico, 3, "Ingrese id de medico: \n", "Error, id invalido", 1000, 1004);

			auxConsulta.idDiagnostico=0;
			auxConsulta.estado = LLENO;
			lista[indice] = auxConsulta;

		todoOk = 1;
		}
	}
	return todoOk;
}


int modificarConsulta(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades)
{
	int todoOk = 0;
	int id;
	int indice;
	//int idMedico;
	int indiceMedico;
	char confirma;
	eConsulta auxConsulta;


	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf(" ************** Modificar consulta *****************\n");
		printf("----------------------------------------------------\n");

		mostrarConsultas(lista, tam,medicos, tamMedicos, diagnosticos, tamDiagnosticos, especialidades, tamEspecialidades);

		utn_getEntero(&id, 3, "Ingrese id: \n", "ERROR, reintente nuevamente\n", 1000, 1009);
		indice = buscarConsultaId(lista, tam, id);
		indiceMedico = buscarMedicoId(medicos, tamMedicos, lista[indice].idMedico);


		if(indice == -1)
		{
			printf("No existe una consulta con id: %d\n", id);
		}
		else
		{
			mostrarConsulta(lista[indice], medicos[indiceMedico], medicos, tamMedicos, diagnosticos, tamDiagnosticos, especialidades, tamEspecialidades);

			utn_getCaracter(&confirma, 3, "Confirma modificacion? ('s' para confirmar)\n", "ERROR, reintente nuevamente\n");

			confirma = tolower(confirma);

			if(confirma == 's')
			{
				switch(menuModificacion())
				{
				case 1:
					utn_getCadena(auxConsulta.nombrePaciente, 50, 3, "Ingrese nuevo nombre del paciente: \n", "Error!!! \n");
					strcpy(lista[indice].nombrePaciente, auxConsulta.nombrePaciente);

					printf("Nombre modificado exitosamente\n");
					break;
				case 2:
					printf("\nIngrese nueva fecha de consulta: \n");
					utn_getEntero(&auxConsulta.fecha.dia, 3, "Dia: \n", "Error, no es un dia valido\n", 1, 31);
					utn_getEntero(&auxConsulta.fecha.mes, 3, "Mes: \n", "Error, no es un mes valido\n", 1, 12);
					utn_getEntero(&auxConsulta.fecha.anio, 3, "A�o: \n", "Error, no es un a�o valido\n", 1, 2022);
					lista[indice].fecha = auxConsulta.fecha;
					printf("Fecha de consulta modificada exitosamente\n");
					break;
				case 3:
					listarMedicos(medicos, tamMedicos);
					utn_getEntero(&auxConsulta.idMedico, 3, "Ingrese nuevo id de medico: \n", "Error, id invalido", 1000, 1004);
					lista[indice].idMedico = auxConsulta.idMedico;
					printf("medico modificado exitosamente\n");
				}
				todoOk = 1;
			}
			else
			{
				printf("Se ha cancelado la modificacion \n");
			}
		}
	}
	return todoOk;
}


int bajaConsulta(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades)
{
	int todoOk = 0;
	int id;
	int indice;
	//int idMedico;
	int indiceMedico;
	char confirma;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("       *** Baja Consulta ***      \n");
		printf("----------------------------------\n");

		mostrarConsultas(lista, tam,medicos, tamMedicos, diagnosticos, tamDiagnosticos, especialidades, tamEspecialidades);

		utn_getEntero(&id, 3, "Ingrese id: \n", "ERROR, reintente nuevamente\n", 1000, 1009);

		indice = buscarConsultaId(lista, tam, id);
		indiceMedico = buscarMedicoId(medicos, tamMedicos, lista[indice].idMedico);

		if(indice == -1)
		{
			printf("No existe una persona con id: %d\n", id);
		}
		else
		{
			mostrarConsulta(lista[indice], medicos[indiceMedico],medicos, tamMedicos, diagnosticos, tamDiagnosticos, especialidades, tamEspecialidades);
			utn_getCaracter(&confirma, 3, "Confirma baja? ('s' para confirmar)\n", "ERROR, reintente nuevamente\n");

			if(confirma == 's')
			{
				lista[indice].estado = VACIO;
				todoOk = 1;
			}
			else
			{
				printf("Se ha cancelado la baja \n");
			}
		}
	}
	return todoOk;
}

int diagnosticarConsulta(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades)
{
	int todoOk=0;

	int indice;
	char confirma;

	int idMedico;
	int idConsulta;
	int auxIdDiagnostico;

	int flag=0;

	if(lista != NULL && medicos != NULL && diagnosticos != NULL)
	{

	system("cls");
	printf(" ************** Diagnosticar consulta *****************\n");
	printf("-------------------------------------------------------\n");



	listarMedicos(medicos, tamMedicos);
	utn_getEntero(&idMedico, 3, "Ingrese id de medico para listar consultas: \n", "Error, id invalido\n", 1000, 1004);

	for(int i=0;i<tam;i++)
	{

		if(lista[i].estado == LLENO && lista[i].idMedico == idMedico && lista[i].idDiagnostico == 0)
			{
				mostrarConsulta(lista[i], medicos[i], medicos, tamMedicos, diagnosticos, tamDiagnosticos, especialidades, tamEspecialidades);
				flag=1;
			}
	}


	if(flag == 0)
	{
		printf("\nError\n");
	}
	else
	{

		printf("Ingrese id de consulta para cargar diagnostico: \n");
		scanf("%d", &idConsulta);

		indice = buscarConsultaId(lista, tam, idConsulta);

			if(indice == -1)
			{
				printf("No existe una consulta con id: %d\n", idConsulta);
			}
			else
			{

				printf("Confirma cargar diagnostico para esta consulta?(s/n): \n");
				fflush(stdin);
				scanf("%c", &confirma);

				if(confirma == 's')
				{
					listarDiagnosticos(diagnosticos, tamDiagnosticos);
					utn_getEntero(&auxIdDiagnostico, 3, "Ingrese id de diagnostico a cargar en consulta: \n", "Error, id invalido", 1, 3);
					lista[indice].idDiagnostico = auxIdDiagnostico;
					todoOk = 1;
				}
				else
				{
					printf("Se ha cancelado el diagnostico de la consulta");
				}
			}
	}
	}




	return todoOk;
}
