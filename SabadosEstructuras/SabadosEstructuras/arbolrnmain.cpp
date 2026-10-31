#include <iostream>
#include "arbolrojonegro.h"


int main() {
	ArbolRojoNegro tree;
	std::cout << "arbol rojo negro" << std::endl;
	//Ejemplo cargado : 10, 20, 30, 15, 25, 5.
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);


	tree.insert(15);
	tree.insert(25);
	tree.insert(5);

	//tree.insert( 70);
	//tree.insert(80);
	//tree.insert(90);
	//tree.insert(100);
	//tree.insert(110);
	//tree.insert(120);

	//tree.mostrarArbol();

	


	//std::cout << "Preorden: ";
	//tree.preordenAuxiliar();


	//std::cout << "Inorden: ";
	//tree.inordenAuxiliar();


	//std::cout << "Postoorden: ";
	//tree.postordenAuxiliar();

	////

	//std::cout << "avlTree";

	return 0;
}
