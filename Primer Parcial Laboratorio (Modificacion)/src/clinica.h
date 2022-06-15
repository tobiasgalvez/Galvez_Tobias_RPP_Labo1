/*
 * clinica.h
 *
 *  Created on: 14 jun. 2022
 *      Author: Tobias Galvez
 */

#ifndef CLINICA_H_
#define CLINICA_H_

typedef struct
{
	int id;
	char descripcion[50];
	char calle[50];
	int altura;
}eClinica;

/**
 * Funcion que permite listar todas las clinicas
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, 0 si no
 */
int listarClinicas(eClinica lista[], int tam);
/**
 * Funcion que permite buscar una clinica por id
 * @param lista
 * @param tam
 * @param id
 * @return si encontró el id, el id ingresado, si no -1
 */
int buscarClinicaId(eClinica lista[], int tam, int id);
#endif /* CLINICA_H_ */
