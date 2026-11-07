//#include <iostream>
//#include <cstdlib> //Es la administración de memoria dinámica
//
////Ejemplo de memoria dinámica en C++ ( Malloc y Free)
//using namespace std;	
//
//int main() {
//
//
//	cout << "Ejemplo de memoria dinamica en C++ ( Malloc y Free)" << endl;
//	int cantidades;
//	int* datos;
//
//	//Reservar la memoria
//	cantidades = 10;
//	datos = (int*)malloc(cantidades * sizeof(int));
//	//Mostrar tamano de memoria reservada o solicitada
//	cout << "Tamano de memoria reservada o solicitada: " << cantidades * sizeof(int) << endl;
//
//
//	//Mostrar la direccion
//	cout << "Direccion de memoria reservada: " << datos << endl;
//
//
//	//Mostrar memoria tamano en bytes
//	cout << "Tamano de memoria reservada: " << sizeof(int) << "bytes" << endl;
//
//	for (int i = 0; i < cantidades; i++)
//	{
//		cout << "datos [" << i << "] valor: " << datos[i] << " direccion: " << &datos << endl;
//	}
//
//
//	if (datos == nullptr) {
//		cout << "Error al reservar memoria" << endl;
//		return 1;
//	}
//
//	cout << "Seccion de free: " << datos << endl;
//	free(datos); //Liberar la memoria)
//	datos = nullptr;
//
//	cout << "Direccion de memoria reservada despues del free: " << datos << endl;
//	cout << "Tamano de memoria reservada o solicitada despues del free: " << cantidades * sizeof(int) << endl;
//	cout << "Tamano de memoria reservada : " << sizeof(int) << "bytes" << endl;
//
//	if (datos == nullptr) {
//		cout << "Error al reservar memoria, luego de free" << endl;
//		return 1;
//	}
//	cout << "Direccion de memoria reservada: " << datos << endl;
//
//	return 0;
//
//}