#include <iostream>
#include "NaryTree.h"


int main() {
	//10, 20, 22, 55, 66, 33, 5
	NaryTree tree(10);
	std::cout << "NaryTree ";


	//Obtenemos el valor de la raiz
	NaryNode* root = tree.getRoot();



	//Insertamos los hijos
	//20335
	tree.addChild(root, 20);
	tree.addChild(root, 33);
	tree.addChild(root, 5);

	//agremos los nuevos hijos, y usamos los nuevos padres.
	// 
	tree.addChild(root->children[0], 22);
	tree.addChild(root->children[0], 55);
	tree.addChild(root->children[0], 66);
//
//└── 10
//    └── 20
//        └── 22
//        └── 55
//        └── 66
//    └── 33
//    └── 5

	std::cout << "Recorrido Preorden ";
	tree.preordenAuxiliar();


	std::cout << "Recorrido Postorden ";
	tree.postordenAuxiliar();

	return 0;
}