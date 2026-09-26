#include "NaryTree.h"

//La creacion del arbol
NaryNode::NaryNode(int val) {
	data = val;
}


//El debe revsar y liberar los nodos automatiamente hacia abajo o como una cascada
NaryNode::~NaryNode() {
	for (NaryNode* child : children) {
		delete child;
	}
}


//Implementacion del arbol
//Padre o base ---> hijo(padre) o base ---> hijo(padre) o base ---> hijo(padre) o base ---> hijo(padre)
NaryTree::NaryTree(int rootVal) {
	root = new NaryNode(rootVal);
}


NaryTree::~NaryTree() {
	delete root;
}

NaryNode* NaryTree::getRoot() {
	return root;
}

bool NaryTree::addChild(NaryNode* parent, int val) {
	if (parent == nullptr) {
		return false;
	}
	NaryNode* newNode = new NaryNode(val);

	parent->children.push_back(newNode);

	return true;


}


//Recorrido preorden razi, izquiera, derecha

void NaryTree::preordenAuxiliar() {
	preorden(root);
	std::cout << std::endl;
}


void NaryTree::preorden(NaryNode* node) {
	if (node != nullptr) {
		std::cout << node->data << " "; //visitar la raiz

		for (NaryNode* child : node->children) {
			preorden(child);
		}

	}
}