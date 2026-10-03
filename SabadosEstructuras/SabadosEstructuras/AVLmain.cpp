#include <iostream>
#include "avl.h"


int main() {
	AVLTree tree;
	std::cout << "AVLTree" << std::endl;

	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	tree.insert(40);
	tree.insert(50);
	


	std::cout << "Preorden: ";
	tree.preordenAuxiliar();


	std::cout << "Inorden: ";
	tree.inordenAuxiliar();


	std::cout << "Postoorden: ";
	tree.postordenAuxiliar();

	//

	std::cout << "avlTree";

	return 0;
}
