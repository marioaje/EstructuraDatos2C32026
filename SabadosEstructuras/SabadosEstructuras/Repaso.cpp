

#include <iostream>
#include <cstring>
#include "profesor.h"
#include "listas.h"
using namespace std;
int main()
{
	std::cout << "Repaso arreglos!\n";

	///Arreglos
	int edadesArreglo[6];

	//edadesArreglo = { 18, 19, 20 };
	edadesArreglo[0] = 1;
	edadesArreglo[1] = 1;
	edadesArreglo[2] = 1;
	edadesArreglo[3] = 1;
	edadesArreglo[4] = 1;
	edadesArreglo[5] = 1;
	/*94... sin hacer nada*/

	std::cout << "Edad del primer estudiante: " << edadesArreglo[0] << std::endl;


	//Arreglos de estructuras
	Profesor profesorEstructurasArreglo[3];

	//Los punteros nos ayudan a acceder a la memoria de los datos, y a modificar los datos de las estructuras
	//Direccion de memoria de la Computadora


	int numeroDeProfesores = 3;//donde esta???
	std::cout << "En donde estoy el numero de profesores: " << numeroDeProfesores << std::endl;
	//Obtener direccion de memoria de la variable numeroDeProfesores  &numeroDeProfesores : 0x7ffee3b8c9ac 
	std::cout << "En donde estoy el numero de profesores DIRECCION MEMORIA: " << &numeroDeProfesores << std::endl; 

	//Se puede declarar un puntero
	int* numeroDeProfesoresPuntero = &numeroDeProfesores;//profesores DIRECCION MEMORIA

	std::cout << "En donde estoy el numero de profesores PUNTERO: " << *numeroDeProfesoresPuntero << std::endl;

	//Obtiene y modifica el valor de la variable numeroDeProfesores a traves del puntero numeroDeProfesoresPuntero
	*numeroDeProfesoresPuntero = 30;
	std::cout << "En donde estoy el numero de profesores yo era un 3: " << numeroDeProfesores << std::endl;
	std::cout << "En donde estoy el numero de profesores DIRECCION MEMORIA: " << &numeroDeProfesores << std::endl;
	numeroDeProfesores = 300;//donde esta???

	std::cout << "En donde estoy el numero de profesores yo era un 30: " << numeroDeProfesores << std::endl;
	std::cout << "En donde estoy el numero de profesores DIRECCION MEMORIA: " << &numeroDeProfesores << std::endl;

	cout << "\n\n ";
	Profesor profesorEstructura;
	profesorEstructura.edad = 30;
	profesorEstructura.id = 1;
	//profesorEstructura.nombre = "Profe";
	strcpy_s(profesorEstructura.nombre, "Profe");
	profesorEstructura.salario = 1000.0f;
	//ingresarProfesor(&profesorEstructura);
	//mostrarProfesor(profesorEstructura);

	///Arreglo estatico de estructuras
	/*int edadesArreglo[6];*/
	//Memoria dinamica de estructuras
	listaNodo* nodo1 = new listaNodo();
	nodo1->dato = 10;
	nodo1->siguiente = nullptr;//---

	return 0;

}