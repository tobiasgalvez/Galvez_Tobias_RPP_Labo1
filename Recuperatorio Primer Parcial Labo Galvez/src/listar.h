/*
 * listar.h
 *
 *  Created on: 15 jun. 2022
 *      Author: Tobias Galvez
 */

#ifndef LISTAR_H_
#define LISTAR_H_

/**
 * Funcion que permite mostrar consultas diagnosticadas por id de medico
 * @param lista
 * @param tam
 * @param medicos
 * @param tamMedicos
 * @param diagnosticos
 * @param tamDiagnosticos
 * @param idMedico
 * @param especialidades
 * @param tamEspecialidades
 * @return 1 si tuvo exito, 0 si no
 */
int mostrarConsultasIdMedicoDiagnosticado(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos,eDiagnostico diagnosticos[], int tamDiagnosticos, int idMedico, eEspecialidad especialidades[], int tamEspecialidades);

/**
 * Funcion que permite listar todos los m�dicos con consultas diagnosticadas
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
int listaMedicosConsultasDiagnosticadas(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades);
/**
 * Funcion que permite un listado de consultas ordenadas por fecha, desde la m�s reciente
 * hasta la m�s antigua
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
int listaConsultasOrdenadasFecha(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades);
/**
 * Funcion que permite un listado de consultas que ya fueron diagnosticadas.
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
int listaConsultasDiagnosticadas(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades);
/**
 * Funcion que permite un Listado de las consultas diagnosticadas con covid-19 desde el
 * inicio de la pandemia hasta la actualidad
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
int listaConsultasDiagnosticadasCovid19(eConsulta lista[], int tam, eMedico medicos[], int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades);

/**
 * Funcion que permite mostrar un listado de consultas ordenadas por especialidad alfabéticamente
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
int listaConsultasPorEspecialidadOrdenadas(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades );



/**
 * Funcion que permite mostrar consultar por id de medico con consultas entre abril y julio
 * @param lista
 * @param tam
 * @param medicos
 * @param tamMedicos
 * @param diagnosticos
 * @param tamDiagnosticos
 * @param idMedico
 * @param especialidades
 * @param tamEspecialidades
 * @return 1 si tuvo exito, 0 si no
 */
int mostrarConsultasIdPorEspecialidadAbrilJulio(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos,eDiagnostico diagnosticos[], int tamDiagnosticos, int idEspecialidad, int idMedico, eEspecialidad especialidades[], int tamEspecialidades);



/**
 * Funcion que permite Listado de todas las consultas entre el mes de abril y julio para una especialidad determinada.
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
int listaConsultasPorEspecialidad(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades);


/**
 * Funcion que permite calcular el porcentaje de consultas
 * diagnosticadas que atiende cada m�dico en funci�n del total de diagn�sticos
 * @param lista
 * @param tam
 * @param medicos
 * @param tamMedicos
 * @param diagnosticos
 * @param tamDiagnosticos
 * @return 1 si tuvo exito, 0 si no
 */
int porcentajeConsultasDiagnosticadas(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos);

/**
 * Funcion que permite mostrar la/las especialidad/es mas estudiada/s
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
int especialidadMasEstudiada(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades );

/**
 * Funcion que permite mostrar la/las enfermedad/es menos diagnosticada/s
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
int enfermedadMenosDiagnosticada(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades );


/**
 * Funcion que permite averiguar el medico mas cercano de una clinica determinada
 * @param lista
 * @param tam
 * @param medicos
 * @param tamMedicos
 * @param diagnosticos
 * @param tamDiagnosticos
 * @param especialidades
 * @param tamEspecialidades
 * @param clinicas
 * @param tamClinicas
 * @return 1 si tuvo exito, 0 si no
 */
int medicoMasCercanoAClinica(eConsulta lista[],int tam,eMedico medicos[],int tamMedicos, eDiagnostico diagnosticos[], int tamDiagnosticos, eEspecialidad especialidades[], int tamEspecialidades, eClinica clinicas[], int tamClinicas );
#endif /* LISTAR_H_ */
