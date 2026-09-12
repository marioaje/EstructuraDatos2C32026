#pragma once
//los include ---> nos ayuda a incluir librerias y archivos de cabecera

#ifndef  PROFESOR_H//Profesor
#define PROFESOR_H//Profesor

///La estructura es solo para datos....
//agrupar los datos
//por defecto es public los datos
//puede tener metodos
//es para generar la estructura de datos
struct Profesor
{
	int id;
	char nombre[50];
	int edad;
	float salario;
};


//las funciones son para hacer cosas con los datos de la estructura === Protoripos de funciones

void ingresarProfesor(Profesor* profesor);
void mostrarProfesor(Profesor profesor);


#endif // ! PROFESOR_H//Profesor
