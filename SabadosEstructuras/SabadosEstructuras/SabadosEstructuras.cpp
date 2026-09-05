// SabadosEstructuras.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
//📘 Ejercicio Práctico — Repaso de C : Structs y Punteros
//📌 Tema
//
//Repaso del lenguaje C :
//
//Tipos de datos básicos
//
//Uso de struct
//
//Arreglos
//
//Punteros
//
//Paso de estructuras a funciones
//
//🎯 Objetivo del ejercicio
//
//El objetivo de este ejercicio es que el estudiante :
//
//Comprenda cómo definir y utilizar estructuras(struct) en C.
//
//Maneje arreglos de estructuras para almacenar múltiples registros.
//
//Utilice punteros para acceder y modificar datos dentro de una estructura.
//
//Refuerce el uso de funciones para organizar el código.
//
//📝 Enunciado
//
//Una universidad desea desarrollar un programa sencillo en lenguaje C para gestionar información básica de estudiantes.
//Cada estudiante debe almacenar :
//
//Un ID(entero)
//
//Un nombre(cadena de caracteres)
//
//Una edad(entero)
//
//Un promedio(decimal)
//
//El programa deberá permitir registrar varios estudiantes y mostrar su información utilizando punteros y funciones.
//📋 Requisitos
//
//El programa debe cumplir con lo siguiente :
//
//Definir una estructura llamada Estudiante que contenga :
//
//int id
//
//char nombre[30]
//
//int edad
//
//float promedio
//
//Crear un arreglo para almacenar hasta 3 estudiantes.
//
//Implementar las siguientes funciones :
//
//void ingresarEstudiante(struct Estudiante* e);
//
//void mostrarEstudiante(struct Estudiante e);
//
//En la función main :
//
//Solicitar al usuario los datos de cada estudiante.
//
//Almacenar la información en el arreglo.
//
//Actualizar la información en el arreglo.
//
//Mostrar la información completa de todos los estudiantes registrados.
//
//El acceso a los campos de la estructura debe realizarse usando punteros en al menos una función.


#include <iostream>
#include "estudiante.h"

int main()
{
    std::cout << "Programa!\n";

    //Seccion de arreglos
	struct Estudiante estudiantes[3];


	//Ingresar datos de los estudiantes
	for (size_t i = 0; i < 3; i++)
	{
		printf("-------------------------\n");
		printf("Estudiante %d:\n");
		printf("-------------------------\n");

		ingresarEstudiante(&estudiantes[i]);

	}

	//Mostrar datos de los estudiantes
	for (size_t i = 0; i < 3; i++)
	{
		mostrarEstudiante(estudiantes[i]);
	}


	//Actualizar datos de los estudiantes
	actualizarEstudiante(&estudiantes[0]);
	printf("-------------------------\n");
	printf("Estudiante actualizado:\n");
	printf("-------------------------\n");

	//Mostrar datos de los estudiantes
	for (size_t i = 0; i < 3; i++)
	{
		mostrarEstudiante(estudiantes[i]);
	}

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
