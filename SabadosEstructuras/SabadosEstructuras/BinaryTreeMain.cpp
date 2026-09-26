#include <iostream>
#include "BinaryTree.h"


int main() {
	BinaryTree tree;
	std::cout << "BinaryTree";

	tree.insert(23);
	tree.insert(12);
	tree.insert(32);
	tree.insert(8);
	tree.insert(7);
	tree.insert(15);


	std::cout << "Preorden: ";
	tree.preordenAuxiliar();


	std::cout << "BinaryTree";

	return 0;
}
