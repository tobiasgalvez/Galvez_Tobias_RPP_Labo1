/*
 * especialidad.h
 *
 *  Created on: 15 may. 2022
 *      Author: Tobias Galvez
 */

#ifndef ESPECIALIDAD_H_
#define ESPECIALIDAD_H_

typedef struct
{
	int id;
	char descripcion[20];
}eEspecialidad;


/**
 * Funcion que permite listar todas las especialidades
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, 0 si no
 */
int listarEspecialidades(eEspecialidad lista[], int tam);
/**
 * Funcion que permite cargar el nombre de especialidad
 * @param especialidades
 * @param tam
 * @param idEspecialidad
 * @param especialidad
 * @return 1 si tuvo exito, 0 si no
 */
int cargarEspecialidad(eEspecialidad especialidades[], int tam, int idEspecialidad , char especialidad[]);

#endif /* ESPECIALIDAD_H_ */
