#include <stdio.h>
#include <iostream>
#include "estudiante.h"

using namespace std;

void ingresarEstudiante(struct Estudiante* e) {
	printf("Ingrese el ID del estudiante: ");	
	//scanf("%d", &e->id);
	cin >> e->id;
	printf("Ingrese el nombre del estudiante: ");
	//scanf("%29s", e->nombre);
	cin >> e->nombre;
	printf("Ingrese la edad del estudiante: ");
	//scanf("%d", &e->edad);
	cin >> e->edad;
	printf("Ingrese el promedio del estudiante: ");
	//scanf("%f", &e->promedio);
	cin >> e->promedio;
}

void mostrarEstudiante(struct Estudiante e) {
	printf("Información del estudiante:\n");
	printf("ID: %d\n", e.id);
	printf("Nombre: %s\n", e.nombre);
	printf("Edad: %d\n", e.edad);
	printf("Promedio: %.2f\n", e.promedio);
	printf("-------------------------\n");
}

void actualizarEstudiante(struct Estudiante* e) {
	printf("Actualizar información del estudiante (ID: %d):\n");
	//scanf("%f", &e->promedio);
	printf("Ingrese el promedio del estudiante: ");
	cin >> e->promedio;
}

