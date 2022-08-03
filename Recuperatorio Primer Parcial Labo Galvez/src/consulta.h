/*
 * consulta.h
 *
 *  Created on: 6 may. 2022
 *      Author: Tobias Galvez
 */



#ifndef CONSULTA_H_
#define CONSULTA_H_

#include "fecha.h"
#include "especialidad.h"
#include "clinica.h"
#include "medico.h"
#include "diagnostico.h"




typedef struct
{
	int idConsulta;
	char nombrePaciente[50];
	eFecha fecha;
	int idDiagnostico;
	int idMedico;
	int estado;
}eConsulta;



/**
 * Funcion que inicializa todos los estados de consultas en "VACIO"
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, y 0 si no.
 */
int inicializarConsulta(eConsulta lista[], int tam);
/**
 * Funcion que permite buscar si hay espacio libre para dar de alta una consulta
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, y 0 si no.
 */
int buscarLibre(eConsulta lista[], int tam);
/**
 * Funcion que permite buscar una consulta por id
 * @param lista
 * @param tam
 * @param id
 * @return 1 si tuvo exito, y 0 si no.
 */
int buscarConsultaId(eConsulta lista[], int tam, int id);
/**
 * Funcion que permite mostrar una consulta
 * @param unaConsulta
 * @param medicos
 * @param tamMedicos
 * @param diagnosticos
 * @param tamDiagnosticos
 * @param especialidades
 * @param tamEspecialidades
 */
void mostrarConsulta(eConsulta unaConsulta, eMedico unMedico, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades);
/**
 * Funcion que permite mostrar una lista de consultas
 * @param lista
 * @param tam
 * @param medicos
 * @param tamMedicos
 * @param diagnosticos
 * @param tamDiagnosticos
 * @param especialidades
 * @param tamEspecialidades
 * @return 1 si tuvo exito, 0 si no
 */
int mostrarConsultas(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades);

/**
 * Funcion que permite dar de alta una consulta
 * @param lista
 * @param tam
 * @param pId
 * @param medicos
 * @param tamMedicos
 * @return 1 si tuvo exito, 0 si no
 */
int altaConsulta(eConsulta lista[], int tam, int* pId, eMedico medicos[], int tamMedicos);

/**
 * Funcion que permite modificar datos de consulta
 * @param lista
 * @param tam
 * @param medicos
 * @param tamMedicos
 * @param diagnosticos
 * @param tamDiagnosticos
 * @param especialidades
 * @param tamEspecialidades
 * @return 1 si tuvo exito, 0 si no
 */
int modificarConsulta(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades);

/**
 * Funcion que permite dar de baja una consulta
 * @param lista
 * @param tam
 * @param medicos
 * @param tamMedicos
 * @param diagnosticos
 * @param tamDiagnosticos
 * @param especialidades
 * @param tamEspecialidades
 * @return 1 si tuvo exito, 0 si no
 */
int bajaConsulta(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades);
/**
 * Funcion que permite diagnosticar la consulta de un paciente
 * @param lista
 * @param tam
 * @param medicos
 * @param tamMedicos
 * @param diagnosticos
 * @param tamDiagnosticos
 * @param especialidades
 * @param tamEspecialidades
 * @return 1 si tuvo exito, 0 si no
 */
int diagnosticarConsulta(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades);

#endif /* CONSULTA_H_ */
