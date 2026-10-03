#include <iostream>
#include <algorithm>
#include "avl.h"




AVLTree::AVLTree() {
	root = nullptr;
}
//void destroyTree(Node* node);
AVLTree::~AVLTree() {
	destroyTree(root);
}

void AVLTree::destroyTree(Node* node) {
	if (node != nullptr) {
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}
}

//Node* insert(Node* node, int val);

//
//struct Node
//{
//	int data;
//	Node* left;
//	Node* right;
//	Node(int val);
//
//};

int AVLTree::obtenerAltura(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	return node->altura;
}



int AVLTree::obtenerBalance(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	return obtenerAltura(node->left) - obtenerAltura(node->right);
}

Node* AVLTree::rotarDerecha(Node* nodeIzquierdo) {

	Node* nodeDerecho = nodeIzquierdo->left;
	Node* nodeTemporal = nodeDerecho->right;

	//La rotación derecha
	nodeDerecho->right = nodeIzquierdo;
	nodeDerecho->left = nodeTemporal;

	//Actualizar alturas
	nodeIzquierdo->altura = 1 + std::max(obtenerAltura(nodeIzquierdo->left), obtenerAltura(nodeIzquierdo->right));

	nodeDerecho->altura = 1 + std::max(obtenerAltura(nodeDerecho->left), obtenerAltura(nodeDerecho->right));

	return nodeDerecho;

}


Node* AVLTree::rotarIzquierda(Node* nodeDerecho) {

	Node* nodeIzquierdo = nodeDerecho->right;
	Node* nodeTemporal = nodeIzquierdo->left;

	//La rotación Izquierda
	nodeIzquierdo->left = nodeDerecho;
	nodeDerecho->right = nodeTemporal;
	
	//Actualizar alturas
	nodeDerecho->altura = 1 + std::max(obtenerAltura(nodeDerecho->left), obtenerAltura(nodeDerecho->right));

	nodeIzquierdo->altura = 1 + std::max(obtenerAltura(nodeIzquierdo->left), obtenerAltura(nodeIzquierdo->right));

	return nodeIzquierdo;

}

Node* AVLTree::crearNodo(int val) {

	Node* newNode = new Node;

    newNode->data = val;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->altura = 1; // Inicialmente, la altura de un nuevo nodo es 1

	return newNode;

}


void AVLTree::insert(int val) {
	root = insert(root, val);
}

Node* AVLTree::insert(Node* node, int val) {
	if (node == nullptr) {
		return crearNodo(val);
	}

	if (val < node->data) {
		node->left = insert(node->left, val);
	}
	else if (val > node->data) {
		node->right = insert(node->right, val);
	}
	else {
		std::cout << "Valor duplicado: " << val << std::endl;
		return node;
	}


	//actualizar la altura del nodo actual
	node->altura = 1 + std::max(obtenerAltura(node->left), obtenerAltura(node->right));

	//Calcular el factor de balance
	int balance = obtenerBalance(node);


	//Caso 1 izquierda - izquierda
	// 
	if (balance > 1 && val < node->left->data) {
		return rotarDerecha(node);
	}


	//Caso 2 derecha - derecha
	// 
	if (balance < -1 && val > node->right->data) {
		return rotarIzquierda(node);
	}



	//Caso 3 izquierda - derecha
	// 
	if (balance > 1 && val > node->left->data) {

		node->left = rotarIzquierda(node->left);


		return rotarDerecha(node);
	}


	//Caso 4 derecha - izquierda
	if (balance < -1 && val < node->right->data) {
		node->right = rotarDerecha(node->right);


		return rotarIzquierda(node);


	}


	return node;

}


//Recorrido preorden razi, izquiera, derecha

void AVLTree::preordenAuxiliar() {
	preorden(root);
	std::cout << std::endl;
}


void AVLTree::preorden(Node* node) {
	if (node != nullptr) {
		std::cout << node->data << " "; //visitar la raiz
		preorden(node->left);//Mostrando la izquierda
		preorden(node->right);//Mostrando la derecha
	}
}


void AVLTree::inordenAuxiliar() {
	inorden(root);
	std::cout << std::endl;
}

//Recorrido inorden izquierda,raiz, derecha


void AVLTree::inorden(Node* node) {
	if (node != nullptr) {
		inorden(node->left);//Mostrando la izquierda

		std::cout << node->data << " "; //visitar la raiz

		inorden(node->right);//Mostrando la derecha
	}
}



//Recorrido postorden izquierda, derecha, raiz
void AVLTree::postordenAuxiliar() {
	postorden(root);
	std::cout << std::endl;
}



void AVLTree::postorden(Node* node) {
	if (node != nullptr) {
		postorden(node->left);//Mostrando la izquierda		

		postorden(node->right);//Mostrando la derecha

		std::cout << node->data << " "; //visitar la raiz
	}
}