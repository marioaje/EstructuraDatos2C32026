#include <iostream>
#include "profesor.h"

using namespace std;

void ingresarProfesor(Profesor* profesor)
{
	cout << "Ingresar Informacion\n\n ";
	//Obtiene y modifica el valor de la variable atravez del puntero profesor
	cout << "Ingrese el ID del profesor: ";
	cin >> profesor->id;

	cout << "Ingrese el nombre del profesor: ";
	cin >> profesor->nombre;

	cout << "Ingrese el salario del profesor: ";
	cin >> profesor->salario;


	cout << "\n\n ";
}
void mostrarProfesor(Profesor profesor)
{
	cout << "Mostrar Informacion\n\n ";
	cout << "ID: " << profesor.id << endl;
	cout << "Nombre: " << profesor.nombre << endl;
	cout << "Salario: " << profesor.salario << endl;
	cout << "\n\n ";
}