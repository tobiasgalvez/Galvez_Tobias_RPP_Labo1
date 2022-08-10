/*
 1. ALTA CONSULTA: Se ingresan los datos de una consulta. El id deberÃ¡ ser autoincremental. No se deberÃ¡
diagnosticar al momento de crear la consulta.
2. MODIFICAR CONSULTA: Se ingresarÃ¡ el id de la consulta, permitiendo en un
submenÃº modificar:
â—� Nombre del paciente
â—� Fecha de consulta
â—� MÃ©dico

3. CANCELAR CONSULTA: Se ingresarÃ¡ el id de la consulta y se realizarÃ¡ una baja lÃ³gica de la misma.
4. DIAGNOSTICAR: dado el ingreso del id de un mÃ©dico, listar las consultas QUE NO ESTÃ‰N
DIAGNOSTICADAS. Se deberÃ¡ ingresar el id de la consulta y elegir el diagnÃ³stico indicado.
5. LISTAR:
a. Todos los mÃ©dicos.
b. Todas las consultas.
c. Todos los mÃ©dicos con consultas diagnosticadas.
d. Listado de consultas ordenadas por fecha, desde la mÃ¡s reciente hasta la mÃ¡s antigua.
e. Listado de consultas que ya fueron diagnosticadas.
f. Listado de las consultas diagnosticadas con covid-19 desde el inicio de la pandemia hasta la actualidad.
g. Listado de consultas ordenadas por especialidad alfabÃ©ticamente
h. Listado de todas las consultas entre el mes de abril y julio para una especialidad determinada.
i. Porcentaje de consultas diagnosticadas que atiende cada mÃ©dico en funciÃ³n del total de diagnÃ³sticos.
j. La especialidad mÃ¡s estudiada por los mÃ©dicos.
k. La enfermedad menos diagnosticada.
l. Mostrar de una clinica determinada, el medico que viva mas cerca
m. Listado de medicos que pertenecen a una clinica determinada


GALVEZ TOBIAS 1C

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "medico.h"
#include "diagnostico.h"
#include "consulta.h"
#include "especialidad.h"
#include "clinica.h"
#include "listar.h"
#include "menus.h"
#include "hardcodeo.h"
#define VACIO 0
#define LLENO 1
#define TAM 10
#define TAMDIAGNOSTICOS 3
#define TAMMEDICOS 5
#define TAMESPECIALIDADES 5
#define TAMCLINICAS 2

int main(void) {

	setbuf(stdout, NULL);
	int nextId= 1000;
	char seguir = 's';
	int flagAlta = 0;

	eConsulta lista[TAM];
	/*eConsulta lista[TAM] = {{1000, "tobias", {10, 10, 2009}, 0, 1001, 1},
							{1001, "daniel" , {14, 7, 2021}, 0, 1000, 1},
							{1002, "fernando", {29, 5, 2015}, 0, 1001, 1},
							{1003, "antonella", {5,4,2022},0, 1004, 1},
							{1004, "sofia", {23, 1, 2001}, 0, 1003, 1},
						   };*/
	eDiagnostico listaDiagnosticos[TAMDIAGNOSTICOS]= {{1, "Gripe A"},{2, "Covid-19"},{3, "Pre infarto"}};
	eMedico listaMedicos[TAMMEDICOS] =
	{{1000, "Juan Paz", 1000, "Avenida Lamadrid", 900, 100},
	 {1001, "Carlos Morguen", 1003, "Gral Manuel Belgrano", 1850, 101},
	 {1002, "Federico Regueira", 1000, "Gral Manuel Belgrano", 2300, 101},
	 {1003, "Andres Mendez", 1003, "Avenida Lamadrid", 750, 100},
	 {1004, "Franco Gonzalez", 1004, "Avenida Lamadrid", 750, 100}
	 };

	eEspecialidad listaEspecialidades[TAM]={{1000, "Nefrologo"}, {1001, "Oftalmologo"}, {1002, "Psiquiatra"}, {1003, "Pediatra"}, {1004, "Cardiologo"}};
	eClinica listaClinicas[TAMCLINICAS]={{100, "Clinica del ninio y la familia", "Avenida Lamadrid", 444},{101, "Clinica privada Ranelagh", "Gral Manuel Belgrano", 4786}};


	if(!inicializarConsulta(lista, TAM))
	    {
	    	printf("Ocurrio un problema al inicializar consultas\n");
	    }

	if(hardcodearConsultas(lista, TAM, 5, &nextId) != -1)
	{
		flagAlta=1;
	}
	    do
	    {
	        switch(menu())
	        {
	            case 1:
	                if(altaConsulta(lista, TAM, &nextId, listaMedicos, TAMMEDICOS))
	                {
	                	printf("Alta exitosa\n");
	                	flagAlta=1;
	                }
	                else
	                {
	                	printf("Hubo un problema al dar de alta\n");
	                }
	                break;
	            case 2:
	            	if(flagAlta == 0)
	            	{
	            		printf("Primero se debe realizar un alta, elija opcion 1!!!!");
	            	}
	            	else
	            	{

	            	   if(modificarConsulta(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES))
	            	   {
	            		   printf("Modificacion exitosa\n");
	            	   }
	            	   else
	            	   {
	            		   printf("Hubo un problema al modificar los datos\n");
	            	  }
	            	}
	            	   break;
	            case 3:
	            	if(flagAlta == 0)
	            	{
	            		printf("Se debe realizar por lo menos un alta antes de ingresar esta opcion!!!!");
	            	}
	            	else
	            	{

						if(bajaConsulta(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES))
						{
							printf("Baja exitosa\n");
						}
						else
						{
							printf("Hubo un problema al hacer la baja\n");
						}
	            	}
	                break;

	            case 4:
	            	if(flagAlta == 0)
	            	{
	            		printf("Se debe realizar por lo menos un alta antes de ingresar esta opcion!!!!");
	            	}
	            	else
	            	{

						if(diagnosticarConsulta(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES))
						{
							printf("Diagnostico exitoso\n");
						}
						else
						{
							printf("Hubo un problema al diagnosticar\n");
						}
	            	}
	            	break;
	            case 5:
	            	if(flagAlta==0)
	            	{
	            		printf("Se debe realizar por lo menos un alta antes de ingresar esta opcion!!!!");
	            	}
	            	else
	            	{

						switch(subMenu())
						{
						case 'a':
							listarMedicos(listaMedicos, TAMMEDICOS);
							break;
						case 'b':
							mostrarConsultas(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES);
							break;
						case 'c':
							listaMedicosConsultasDiagnosticadas(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES);
							break;
						case 'd':
							listaConsultasOrdenadasFecha(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES);
							break;
						case 'e':
							listaConsultasDiagnosticadas(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES);
							break;
						case 'f':
							listaConsultasDiagnosticadasCovid19(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES);
							break;
						case 'g':
							listaConsultasPorEspecialidadOrdenadas(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES);
							break;
						case 'h':
							listaConsultasPorEspecialidad(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES);
							break;
						case 'i':
							porcentajeConsultasDiagnosticadas(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS);
							break;
						case 'j':
							especialidadMasEstudiada(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES);
							break;
						case 'k':
							enfermedadMenosDiagnosticada(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES);
							break;
						case 'l':
							medicoMasCercanoAClinica(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES, listaClinicas, TAMCLINICAS);
							break;
						case 'm':
							medicosEnClinica(lista, TAM, listaMedicos, TAMMEDICOS, listaDiagnosticos, TAMDIAGNOSTICOS, listaEspecialidades, TAMESPECIALIDADES, listaClinicas, TAMCLINICAS);
						}
	            	}
	            	break;
	            case 6:
	                seguir = 'n';
	                break;

	            default:
	                printf("Opcion invalida\n");
	            }
	         printf("\nPresione cualquier tecla para continuar...\n");
	         fflush(stdin);
	         getchar();
	       }while(seguir == 's');




	return 0;
}
