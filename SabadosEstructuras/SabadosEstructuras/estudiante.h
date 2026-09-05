#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
//
//Un ID(entero)
//
//Un nombre(cadena de caracteres)
//
//Una edad(entero)
//
//Un promedio(decimal)

struct Estudiante
{
	int id;
	char nombre[30];
	int edad;
	float promedio;
};

//Funciones
void ingresarEstudiante(struct Estudiante* e);
void mostrarEstudiante(struct Estudiante e);
void actualizarEstudiante(struct Estudiante* e);

#endif