/*
 * diagnostico.h
 *
 *  Created on: 7 may. 2022
 *      Author: Tobias Galvez
 */

#ifndef DIAGNOSTICO_H_
#define DIAGNOSTICO_H_

typedef struct
{
	int id;
	char descripcion[20];
}eDiagnostico;

/**
 * Funcion que permite listar todos los diagnosticos
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, 0 si no
 */
int listarDiagnosticos(eDiagnostico lista[], int tam);
/**
 * Funcion que permite cargar la descripcion del diagnostico
 * @param diagnosticos
 * @param tam
 * @param idDiagnostico
 * @param descripcion
 * @return 1 si tuvo exito, 0 si no
 */
int cargarDescripcionDiagnostico(eDiagnostico diagnosticos[], int tam, int idDiagnostico, char descripcion[]);

#endif /* DIAGNOSTICO_H_ */
