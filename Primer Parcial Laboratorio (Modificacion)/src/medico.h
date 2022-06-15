/*
 * medico.h
 *
 *  Created on: 6 may. 2022
 *      Author: Tobias Galvez
 */



#ifndef MEDICO_H_
#define MEDICO_H_


typedef struct
{
	int idMedico;
	char nombre[50];
	int idEspecialidad;
	char calle[50];
	int altura;
	int idClinica;
}eMedico;

/**
 * Funcion que permite listar todos los medicos
 * @param lista
 * @param tam
 * @return 1 si tuvo exito, 0 si no
 */
int listarMedicos(eMedico lista[], int tam);
/**
 * Funcion que permite cargar el nombre de medico
 * @param medicos
 * @param tam
 * @param idMedico
 * @param nombre
 * @return 1 si tuvo exito, 0 si no
 */
int cargarNombreMedico(eMedico medicos[], int tam, int idMedico , char nombre[]);
/**
 * Funcion que permite buscar un medico por id
 * @param lista
 * @param tam
 * @param id
 * @return si encontró el id, el id ingresado, si no -1
 */
int buscarMedicoId(eMedico lista[], int tam, int id);


#endif /* MEDICO_H_ */
