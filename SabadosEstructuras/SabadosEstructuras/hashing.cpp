#include <iostream>
#include <vector>
#include <list>

using namespace std;

class TablaDinamica {
private :

	vector<list<int>> tabla;

	int capacidad;
	int cantidad;

	//Factor de carga o almancenimento
	const double FACTORMAXIMOCARGA = 0.75;


	//Funcion
	int funsionHashing(int clave) {
		return (clave % capacidad + capacidad) % capacidad;
	}

	//calaculara el FACTORMAXIMOCARGA
	double factorCarga() {
		return(double)cantidad / capacidad;
	}

	//Insercion de datos sin 	//calaculara el FACTORMAXIMOCARGA
	void insertarSinRehash(int clave) {
		int indice = funsionHashing(clave);
		tabla[indice].push_back(clave);

		cantidad++;
	}

	//redimensionar la tabla
	void rehash() {
		int capacidadanterior = capacidad;


		vector<list<int>> tablaAnterior = tabla;

		capacidad = capacidad * 2;
		tabla.clear();
		tabla.resize(capacidad);

		cantidad = 0;


		cout << "Rehashing automatico\n";

		cout << "Capaciadad Anterior: " << capacidadanterior << endl;
		cout << "Capaciadad nueva: " << cantidad << endl;

		for (int i = 0; i < capacidadanterior; i++)
		{
			for (int clave : tablaAnterior[i]) {
				insertarSinRehash(clave);
			}
		}

	}



public:
	//Constructor
	TablaDinamica(int capacidadInicial = 5) {
		capacidad = capacidad > 0 ? capacidad : 5;

		cantidad = 0;

		tabla.resize(capacidad);
	}

};