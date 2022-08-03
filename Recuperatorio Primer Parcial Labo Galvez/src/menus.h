/*
 * menus.h
 *
 *  Created on: 15 jun. 2022
 *      Author: Tobias Galvez
 */

#ifndef MENUS_H_
#define MENUS_H_

/**
 * Funcion que permite mostrar el men� de consultas
 * @return opcion ingresada
 */
int menu();
/**
 * Funcion que permite mostrar el submenu de consultas, perteneciente al menu de las listas
 * @return opcion ingresada
 */
int subMenu();
/**
 * Funcion que permite acceder al menu de modificacion
 * @return opcion ingresada
 */
int menuModificacion();

#endif /* MENUS_H_ */
