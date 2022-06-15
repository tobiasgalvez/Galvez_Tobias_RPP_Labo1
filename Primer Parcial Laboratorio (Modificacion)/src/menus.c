/*
 * menus.c
 *
 *  Created on: 15 jun. 2022
 *      Author: Tobias Galvez
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"



int menu()
{
	int opcion;

	    system("cls");
	    printf("            *** ABM Consultas ***              \n");
	    printf("---------------------------------------------\n");
	    printf("1- Alta consulta\n");
	    printf("2- Modificar consulta\n");
	    printf("3- Baja consulta\n");
	    printf("4- Diagnosticar\n");
	    printf("5- Listar\n");
	    printf("6- Salir\n");


	    printf("\nIngresar opcion: ");
	    scanf("%d", &opcion);

	    return opcion;
}

int subMenu()
{
	char opcion;

		    system("cls");
		    printf("********************* Listas *********************\n");
		    printf("--------------------------------------------------\n");
		    printf("a- Todos los medicos\n");
		    printf("b- Todas las consultas\n");
		    printf("c- Todos los medicos con consultas diagnosticadas\n");
		    printf("d- Listado de consultas ordenadas por fecha, desde la m�s reciente hasta la m�s antigua\n");
		    printf("e- Listado de consultas que ya fueron diagnosticadas\n");
		    printf("f- Listado de las consultas diagnosticadas con covid-19 desde el inicio de la pandemia hasta la actualidad\n");
		    printf("g- Listado de consultas ordenadas por especialidad alfab�ticamente\n");
		    printf("h- Listado de todas las consultas entre el mes de abril y julio para una especialidad determinada \n");
		    printf("i- Porcentaje de consultas diagnosticadas que atiende cada m�dico en funcion del total de diagnosticos\n");
		    printf("j- La especialidad más estudiada por los médicos\n");
		    printf("k- La enfermedad menos diagnosticada\n");
		    printf("l- Mostrar de una clinica determinada, el medico que viva mas cerca\n");


		    printf("\nIngresar opcion: ");
		    fflush(stdin);
		    scanf("%c", &opcion);

		    return opcion;
}

int menuModificacion()
{
    int opcion;

    printf("------MENU MODIFICACION-------\n\n");

    printf("1- Nombre del paciente\n");
    printf("2- Fecha de consulta\n");
    printf("3- Medico\n");

    printf("\nIngresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
