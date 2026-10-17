#include <iostream>
#include "arbolplus.h"


int main() {
	ArbolPlus tree;
	std::cout << "ArbolPlus" << std::endl;

	tree.insert(10);
	tree.insert(20);
	tree.insert(30);


	tree.insert(40);
	tree.insert(50);
	//tree.insert(60);

	//tree.insert( 70);
	//tree.insert(80);
	//tree.insert(90);
	//tree.insert(100);
	//tree.insert(110);
	//tree.insert(120);

	tree.mostrarArbol();

	


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
