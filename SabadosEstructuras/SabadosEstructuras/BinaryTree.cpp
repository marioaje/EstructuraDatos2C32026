#include <iostream>
#include "BinaryTree.h"

Node::Node(int val) {
	data = val;
	left = nullptr;
	right = nullptr;
		 
}


BinaryTree::BinaryTree() {
	root = nullptr;
}
//void destroyTree(Node* node);
//BinaryTree::~BinaryTree() {
//	destroyTree(root);
//}

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

void BinaryTree::insert(int val) {
	root = insert(root, val);
}

Node* BinaryTree::insert(Node* node, int val) {
	if (node == nullptr) {
		return new Node(val);
	}

	if (val < node->data) {
		node->left = insert(node->left, val);
	}
	else if (val > node->data) {
		node->right = insert(node->right, val);
	}

	return node;

}


//Recorrido preorden razi, izquiera, derecha

void BinaryTree::preordenAuxiliar() {
	preorden(root);
	std::cout << std::endl;
}


void BinaryTree::preorden(Node* node) {
	if (node != nullptr) {
		std::cout << node->data << " "; //visitar la raiz
		preorden(node->left);//Mostrando la izquierda
		preorden(node->right);//Mostrando la derecha
	}
}


void BinaryTree::inordenAuxiliar() {
	inorden(root);
	std::cout << std::endl;
}




//Recorrido inorden izquierda,raiz, derecha


void BinaryTree::inorden(Node* node) {
	if (node != nullptr) {
		inorden(node->left);//Mostrando la izquierda

		std::cout << node->data << " "; //visitar la raiz
		
		inorden(node->right);//Mostrando la derecha
	}
}

//
////Metodos auxiliares o recursivos de recorrido
//// 
//void preorden(v);
//void inorden(Node* node);
//void postorden(Node* node);
//
//

