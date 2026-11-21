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

	//Insertar elemenots
	void insertar(int clave) {

		int indice = funsionHashing(clave);


		//Evitar la duplicidad
		for (int valor: tabla[indice])
		{
			if (valor == clave) {
				cout << "*** El valor esta duplicado: " << clave << endl;
				return;
			}
		}


		tabla[indice].push_back(clave);

		cantidad++;

		cout << "*** El valor esta insertado: " << clave << " ,inidice: " << indice << endl;

		cout << "*** El valor de carga: " << factorCarga()*100 << "%" << endl;

		if (factorCarga() > FACTORMAXIMOCARGA) {
			rehash();
		}

	}

	void mostrar() {
		cout << "*** Mostrar Hashing dinamico: " << endl;
		for (int i = 0; i < capacidad; i++)
		{
			cout << "[" << i << "], ->";
			for (int clave : tabla[i]) {
				cout << clave << " ->";
			}
			cout << "Vacio\n";

		}


		cout << "Capaciadad de elementos: " << cantidad << endl;
		cout << "Capaciadad: " << cantidad << endl;
		cout << "*** El valor de carga: " << factorCarga() * 100 << "%" << endl;

		/*for (int i = 0; i < capacidadanterior; i++)
		{
			for (int clave : tablaAnterior[i]) {
				insertarSinRehash(clave);
			}
		}*/
	}

	bool buscar(int clave) {
		int indice = funsionHashing(clave);

		for (int valor : tabla[indice]) {
			if (valor == clave) {
				return true;
			}
		}

		return false;
	}

};

int main() {
	TablaDinamica hash(5);
	cout << "*** Hashing dinamico: " << endl;
	hash.insertar(10);
	hash.insertar(21);
	hash.insertar(32);
	hash.mostrar();
	if (hash.buscar(10)) 
		cout << "*** Valor encontrado: 10" << endl;	
	else
		cout << "*** Valor encontrado: 10" << endl;


	return 0;
}