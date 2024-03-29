/*
 * listar.c
 *
 *  Created on: 15 jun. 2022
 *      Author: Tobias Galvez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "medico.h"
#include "diagnostico.h"
#include "consulta.h"


#define VACIO 0
#define LLENO 1

int mostrarConsultasIdMedicoDiagnosticado(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos,eDiagnostico diagnosticos[], int tamDiagnosticos, int idMedico, eEspecialidad especialidades[], int tamEspecialidades)
{
    int todoOk=0;

    if(lista != NULL && tam > 0 && medicos != NULL && tamMedicos > 0 && diagnosticos != NULL && tamDiagnosticos > 0)
    {
        printf("----------------------------------------------------------------------------------------------------\n\n");
        for(int i=0; i<tam;i++)
        {
           if(lista[i].estado == LLENO &&lista[i].idMedico==idMedico && lista[i].idDiagnostico != 0)
				{
					mostrarConsulta(lista[i], medicos[i], medicos, tamMedicos, diagnosticos, tamDiagnosticos, especialidades, tamEspecialidades);
					printf("\n");
				}


        }

        todoOk=1;
    }

    return todoOk;
}



int listaMedicosConsultasDiagnosticadas(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades)
{
	int todoOk=0;
	//int flag=0;
	if(lista != NULL && tam > 0 && medicos != NULL && tamMedicos > 0 && diagnosticos != NULL && tamDiagnosticos > 0)
	{
		printf("  *** Medicos con consultas diagnosticadas ***\n");
		printf("---------------------------------------------------------\n");

			for(int i=0;i<tamMedicos;i++)
			{
				printf("\nConsultas de medico '%s': \n\n",medicos[i].nombre);
				for(int j=0;j<tam;j++)
				{
					if(lista[j].idMedico == medicos[i].idMedico)
					{
						mostrarConsultasIdMedicoDiagnosticado(lista, tam, medicos, tamMedicos, diagnosticos, tamDiagnosticos, lista[j].idMedico, especialidades, tamEspecialidades);
						break;
					}

				}

			}


		todoOk=1;
	}


	return todoOk;
}


int listaConsultasOrdenadasFecha(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades)
{
	int todoOk=0;

	eConsulta auxConsulta;

	if(lista != NULL && tam > 0 && medicos != NULL && tamMedicos > 0 && diagnosticos != NULL && tamDiagnosticos > 0)
	{

		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1;j<tam;j++)
			{
				if(lista[i].fecha.anio < lista[j].fecha.anio
				   ||(lista[i].fecha.anio == lista[j].fecha.anio && lista[i].fecha.mes < lista[j].fecha.mes)
				   ||(lista[i].fecha.anio == lista[j].fecha.anio && lista[i].fecha.mes == lista[j].fecha.mes && lista[i].fecha.dia < lista[j].fecha.dia)
				  )
			    {
					auxConsulta=lista[i];
					lista[i]=lista[j];
					lista[j]=auxConsulta;
				}
			}
		}

		todoOk=1;
	}


		mostrarConsultas(lista, tam, medicos, tamMedicos, diagnosticos, tamDiagnosticos, especialidades, tamEspecialidades);

	return todoOk;
}


int listaConsultasDiagnosticadas(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades)
{
	int todoOk=0;
	int flag=0;

	if(lista != NULL && tam > 0 && medicos != NULL && tamMedicos > 0 && diagnosticos != NULL && tamDiagnosticos > 0)
	{
		for(int i=0;i<tam;i++)
		{
			if(lista[i].estado == LLENO && lista[i].idDiagnostico != 0)
				{
					mostrarConsulta(lista[i], medicos[i], medicos, tam, diagnosticos, tamDiagnosticos, especialidades, tamEspecialidades);
					flag=1;

				}
		}

		todoOk=1;
	}

	if(flag==0)
	{
		printf("No hay consultas diagnosticadas\n");
	}
	else
	{
		printf("Listado de consultas con diagnostico cargado con exito!!!\n");
	}

   return todoOk;
}



int listaConsultasDiagnosticadasCovid19(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades)
{
	int todoOk=0;
	int flag=0;
	int especialidadIngresada;

		if(lista != NULL && tam > 0 && medicos != NULL && tamMedicos > 0 && diagnosticos != NULL && tamDiagnosticos > 0)
		{

			listarEspecialidades(especialidades, tamEspecialidades);
			utn_getEntero(&especialidadIngresada, 3, "Elija id de la especialidad que desea mostrar: \n", "ERROR, id invalido\n", 1000, 1004);

			for(int i=0;i<tam;i++)
			{

				if(lista[i].estado == LLENO && lista[i].idDiagnostico == 2 && (lista[i].fecha.mes >=3 && lista[i].fecha.anio >= 2020))
				{
					mostrarConsulta(lista[i], medicos[i], medicos, tam, diagnosticos, tamDiagnosticos, especialidades, tamEspecialidades);
					flag=1;

				}
			}

			todoOk=1;
		}

		if(flag==0)
		{
			printf("No hay consultas diagnosticadas con covid-19 en pandemia\n");
		}
		else
		{
			printf("Listado de consultas con diagnostico covid-19 en pandemia cargado con exito!!!\n");
		}

	   return todoOk;
}


int listaConsultasPorEspecialidadOrdenadas(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades )
{
	int todoOk=0;

	int indiceMedico1;
	char especialidad1[50];
	int indiceMedico2;
	char especialidad2[50];

	eConsulta auxConsulta;


	if(lista != NULL && tam > 0 && medicos != NULL && tamMedicos > 0 && diagnosticos != NULL && tamDiagnosticos > 0 && especialidades != NULL && tamEspecialidades > 0)
	{

		for(int i=0;i<tam-1;i++)
		{
			indiceMedico1= buscarMedicoId(medicos, tamMedicos, lista[i].idMedico);
			cargarEspecialidad(especialidades, tamEspecialidades, medicos[indiceMedico1].idEspecialidad, especialidad1);

			for(int j=i+1;j<tam;j++)
			{
				indiceMedico2= buscarMedicoId(medicos, tamMedicos, lista[j].idMedico);
				cargarEspecialidad(especialidades, tamEspecialidades, medicos[indiceMedico2].idEspecialidad, especialidad2);
				if(strcmp(especialidad1, especialidad2) > 0)
				{
					auxConsulta = lista[i];
					lista[i]=lista[j];
					lista[j]=auxConsulta;
				}
			}

		}

		todoOk=1;

		mostrarConsultas(lista, tam, medicos, tamMedicos, diagnosticos, tamDiagnosticos, especialidades, tamEspecialidades);
	}

	return todoOk;
}


int mostrarConsultasIdPorEspecialidadAbrilJulio(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos,eDiagnostico diagnosticos[], int tamDiagnosticos, int idEspecialidad, int idMedico, eEspecialidad especialidades[], int tamEspecialidades )
{
    int todoOk=0;

    if(lista != NULL && tam > 0 && medicos != NULL && tamMedicos > 0 && diagnosticos != NULL && tamDiagnosticos > 0)
    {
    	for(int i=0; i<tam;i++)
    	        {

    					if(lista[i].estado == LLENO&& medicos[i].idEspecialidad==idEspecialidad && medicos[i].idMedico == idMedico && (lista[i].fecha.mes >=4 && lista[i].fecha.mes <=7))
						{

							mostrarConsulta(lista[i], medicos[i], medicos, tamMedicos, diagnosticos, tamDiagnosticos, especialidades, tamEspecialidades);
							printf("\n");
							todoOk=1;
							break;
						}

    	        }

    	 }

    	    return todoOk;
}


int listaConsultasPorEspecialidad(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades)
{
    int todoOk= 0;

    if(lista != NULL && tam > 0 && medicos != NULL && tamMedicos > 0 && diagnosticos != NULL && tamDiagnosticos > 0)
    {

        printf("  *** Lista de consultas por especialidad ***\n");
        printf("--------------------------------------------------------------------------------------------------------------------\n");

        for(int i=0;i<tamEspecialidades;i++)
        {
            printf("\nConsultas de especialidad %s: \n", especialidades[i].descripcion);


            for(int j=0;j<tamMedicos;j++)
            {
				if(especialidades[i].id == medicos[j].idEspecialidad)
				{
					mostrarConsultasIdPorEspecialidadAbrilJulio(lista, tam, medicos, tamMedicos, diagnosticos, tamDiagnosticos, medicos[j].idEspecialidad, medicos[j].idMedico, especialidades, tamEspecialidades);
				}
            }
        }
    }


    return todoOk;

}

int porcentajeConsultasDiagnosticadas(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos)
{
	int todoOk=0;
	int contDiagnosticos=0;
	int cont1Diagnosticado=0;
	int cont2Diagnosticado=0;
	int cont3Diagnosticado=0;
	int cont4Diagnosticado=0;
	int cont5Diagnosticado=0;


	float promedio1=0;
	float promedio2=0;
	float promedio3=0;
	float promedio4=0;
	float promedio5=0;

	if(lista != NULL && tam > 0 && medicos != NULL && tamMedicos > 0 && diagnosticos != NULL && tamDiagnosticos > 0)
	{
		for(int i=0;i<tam;i++)
		{
			if(lista[i].estado == LLENO && lista[i].idDiagnostico != 0)
			{
				contDiagnosticos++;

				switch(lista[i].idMedico)
				{
				case 1000:
					cont1Diagnosticado++;
					break;
				case 1001:
					cont2Diagnosticado++;
					break;
				case 1002:
					cont3Diagnosticado++;
					break;
				case 1003:
					cont4Diagnosticado++;
					break;
				case 1004:
					cont5Diagnosticado++;
					break;

				}


				todoOk=1;
			}


		}


	}

	if(contDiagnosticos==0)
	{
		printf("No hay consultas diagnosticadas\n");
	}
	else
	{
		promedio1=(float)cont1Diagnosticado/contDiagnosticos*100;
		promedio2=(float)cont2Diagnosticado/contDiagnosticos*100;
		promedio3=(float)cont3Diagnosticado/contDiagnosticos*100;
		promedio4=(float)cont4Diagnosticado/contDiagnosticos*100;
		promedio5=(float)cont5Diagnosticado/contDiagnosticos*100;

	printf("El Porcentaje de consultas diagnosticadas de %s en funci�n del total de diagn�sticos es de: %.2f\n", medicos[0].nombre, promedio1);
	printf("El Porcentaje de consultas diagnosticadas de %s en funci�n del total de diagn�sticos es de: %.2f\n", medicos[1].nombre, promedio2);
	printf("El Porcentaje de consultas diagnosticadas de %s en funci�n del total de diagn�sticos es de: %.2f\n", medicos[2].nombre, promedio3);
	printf("El Porcentaje de consultas diagnosticadas de %s en funci�n del total de diagn�sticos es de: %.2f\n", medicos[3].nombre, promedio4);
	printf("El Porcentaje de consultas diagnosticadas de %s en funci�n del total de diagn�sticos es de: %.2f\n", medicos[4].nombre, promedio5);
	}



	return todoOk;
}



int especialidadMasEstudiada(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades )
{
	int todoOk=0;
	int contEspecialidad1000 = 0;
	int contEspecialidad1001 = 0;
	int contEspecialidad1002 = 0;
	int contEspecialidad1003 = 0;
	int contEspecialidad1004 = 0;

	int max = 0;

	if(lista != NULL && tam > 0 && medicos != NULL && tamMedicos > 0 && diagnosticos != NULL && tamDiagnosticos > 0 && especialidades != NULL && tamEspecialidades > 0)
	{
		for(int i=0;i<tamMedicos;i++)
		{
			if(medicos[i].idEspecialidad == 1000)
			{
				contEspecialidad1000++;
			}
			else
			{
				if(medicos[i].idEspecialidad == 1001)
				{
					contEspecialidad1001++;
				}
				else
				{
					if(medicos[i].idEspecialidad == 1002)
					{
						contEspecialidad1002++;
					}
					else
					{
						if(medicos[i].idEspecialidad == 1003 )
						{
							contEspecialidad1003++;
						}
						else
						{
							if(medicos[i].idEspecialidad == 1004)
							{
								contEspecialidad1004++;
							}
						}
					}
				}
			}
		}

		if(contEspecialidad1000 > contEspecialidad1001 && contEspecialidad1000 > contEspecialidad1002 && contEspecialidad1000 > contEspecialidad1003 && contEspecialidad1000 > contEspecialidad1004)
		{
			max=contEspecialidad1000;
		}
		else
		{
			if(contEspecialidad1001 >= contEspecialidad1000 && contEspecialidad1001 > contEspecialidad1002 && contEspecialidad1001 > contEspecialidad1003 && contEspecialidad1001 > contEspecialidad1004)
			{
				max=contEspecialidad1001;
			}
			else
			{
				if(contEspecialidad1002 >= contEspecialidad1000 && contEspecialidad1002 >= contEspecialidad1001 && contEspecialidad1002 > contEspecialidad1003 && contEspecialidad1002 > contEspecialidad1004)
				{
					max=contEspecialidad1002;
				}
				else
				{
					if(contEspecialidad1003 >= contEspecialidad1000 && contEspecialidad1003 >= contEspecialidad1001 && contEspecialidad1003 >= contEspecialidad1002 && contEspecialidad1003 > contEspecialidad1004)
					{
						max=contEspecialidad1003;
					}
					else
					{
						max=contEspecialidad1004;
					}
				}
			}
		}


		if(max != 0)
		{

			printf("La especialidad/es mas estudiada/s es/son:\n");
			if(contEspecialidad1000 == max)
			{
				printf("Nefrologo, con un total de %d consultas\n", max);
			}
			if(contEspecialidad1001 == max)
			{
				printf("Oftalmologo, con un total de %d consultas\n", max);
			}
			if(contEspecialidad1002 == max)
			{
				printf("Psiquiatra, con un total de %d consultas\n", max);
			}
			if(contEspecialidad1003 == max)
			{
				printf("Pediatra, con un total de %d consultas\n", max);
			}
			if(contEspecialidad1004==max)
			{
				printf("Cardiologo, con un total de %d consultas\n", max);
			}

			todoOk=1;
		}
		else
		{
			printf("No hay medicos con especialidad seleccionada\n");
		}
	}

	return todoOk;
}





int enfermedadMenosDiagnosticada(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades )
{
	int todoOk=0;
	int contGripe = 0;
	int contCovid = 0;
	int contInfarto = 0;

	int min = 0;

	if(lista != NULL && tam > 0 && medicos != NULL && tamMedicos > 0 && diagnosticos != NULL && tamDiagnosticos > 0 && especialidades != NULL && tamEspecialidades > 0)
	{
		for(int i=0;i<tam;i++)
		{
			if(lista[i].idDiagnostico != 0)
			{
				if(lista[i].idDiagnostico == 1)
				{
					contGripe++;
				}
				else
				{
					if(lista[i].idDiagnostico == 2)
					{
						contCovid++;
					}
					else
					{
						contInfarto++;
					}
				}

				todoOk=1;
			}

		}

		if(contGripe < contCovid && contGripe < contInfarto)
		{
			min=contGripe;
		}
		else
		{
			if(contCovid <= contGripe && contCovid < contInfarto)
			{
				min=contCovid;
			}
			else
			{
				min=contInfarto;
			}
		}
	}


	if(todoOk==0)
	{
		printf("No hay diagnosticos encontrados\n");
	}
	else
	{
		printf("La/s enfermedad/es menos diagnosticada/s es/son:\n");
		if(contGripe == min)
		{
			printf("Gripe A, con %d diagnosticos\n", contGripe);
		}
		if(contCovid == min)
		{
			printf("Covid-19, con %d diagnosticos\n", contCovid);
		}
		if(contInfarto == min)
		{
			printf("Pre Infarto, con %d diagnosticos\n", contInfarto);
		}
	}


	return todoOk;
}

int medicoMasCercanoAClinica(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades, eClinica clinicas[], int tamClinicas )
{
	int todoOk=0;
	int idClinica;
	int indiceClinica;
	int min=-1;
	int flag=0;

	int distancia[5]={0,0,0,0,0};



	if(lista != NULL && tam > 0 && medicos != NULL && tamMedicos > 0 && diagnosticos != NULL && tamDiagnosticos > 0 && especialidades != NULL && tamEspecialidades > 0 && clinicas != NULL && tamClinicas > 0)
	{
		listarClinicas(clinicas, tamClinicas);
		utn_getEntero(&idClinica, 3, "Ingrese id de clinica para consultar medico mas cercano: \n", "ERROR, id invalido\n", 100, 101);
		indiceClinica = buscarClinicaId(clinicas, tamClinicas, idClinica);
			for(int i=0;i<tamMedicos;i++)
			{
				if(medicos[i].idClinica == idClinica)
				{
					if(flag==0|| (((medicos[i].altura-clinicas[indiceClinica].altura)<min) && (medicos[i].altura-clinicas[indiceClinica].altura)>0))
					{
							min=medicos[i].altura-clinicas[indiceClinica].altura;
							//min=clinicas[indiceClinica].altura - medicos[i].altura;
							flag=1;
					}
					else
					{
						if((clinicas[indiceClinica].altura - medicos[i].altura)>0)
						{
							min=clinicas[indiceClinica].altura - medicos[i].altura;
							//min=medicos[i].altura-clinicas[indiceClinica].altura;
						}

					}

					if(distancia[i]==0)
					{
						if(medicos[i].altura > clinicas[indiceClinica].altura)
						{
							distancia[i]=medicos[i].altura-clinicas[indiceClinica].altura;
						}
						else
						{
							distancia[i]=clinicas[indiceClinica].altura - medicos[i].altura;
						}
					}
				}

			}
			todoOk=1;


			printf("De los medicos que trabajan en la clinica %s el/los medico/s:\n", clinicas[indiceClinica].descripcion);
			for(int i=0;i<tamMedicos;i++)
			{
				if(distancia[i]==min)
				{
					printf("%s\n",medicos[i].nombre);
				}
			}
			printf("se encuentra/n mas cerca, con una distancia de %d metros\n", min);

	}

	return todoOk;
}
