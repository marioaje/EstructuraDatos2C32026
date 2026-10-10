#include <iostream>
#include <algorithm>
#include "arbolplus.h"



ArbolPlus::ArbolPlus() {
	root = nullptr;
}


NodeBPplus* ArbolPlus::crearNodo(bool esHoja) {
	NodeBPplus* nuevo = new NodeBPplus;

	nuevo->cantidad = 0;

	nuevo->esHoja = esHoja;

	nuevo->siguiente = nullptr;



	for (int i = 0; i < MAX_CLAVES; i++)
	{
		nuevo->hijos[i] = nullptr;
	}

	return nuevo;
}

//Un insertar de hojas ordenadamente 

void ArbolPlus::insertEnHoja(NodeBPplus* nodeHoja, int val) {
	int i = nodeHoja->cantidad - 1;
	while (i >= 0 && nodeHoja->claves[i] > val) {
		nodeHoja->claves[i + 1] = nodeHoja->claves[i];

		i--;
	}


	nodeHoja->claves[i + 1] = val;
	nodeHoja->cantidad++;


}




void ArbolPlus::insert(int valor) {
	//Validar si esta vacio

	if (root == nullptr) {

		root = crearNodo(true);

		insertEnHoja(root, valor);

		return;
	}


	if (root->esHoja) {
		//Verificamos si existe espacio en la hoja

		if (root->cantidad < MAX_CLAVES) {
			insertEnHoja(root, valor);
			return;
		}


		//La raiz esta llena, necesitamos dividirla y crear una nueva raiz


		NodeBPplus* izquierda = crearNodo(true);
		NodeBPplus* derecha = crearNodo(true);

		izquierda->claves[0] = root->claves[0];
		izquierda->cantidad = 1;

		derecha->claves[0] = root->claves[1];

		derecha->claves[1] = root->claves[2];

		//izquierda y derecha

		//Interconectar las hojas
		izquierda->siguiente = derecha;

		//Crear una nueva raiz
		NodeBPplus* nuevaRaiz = crearNodo(false);

		nuevaRaiz->claves[0] = derecha->claves[0];
		nuevaRaiz->cantidad = 1;


		nuevaRaiz->hijos[0] = izquierda;
		nuevaRaiz->hijos[1] = derecha;

		delete root;

		root = nuevaRaiz;


		return;

	}

	std::cout << "la siguiente etapa de acceso por splitis" << std::endl;

}

void ArbolPlus::mostrarArbol() {

	if (root == nullptr){
		std::cout << "El árbol está vacío." << std::endl;
		return;
	}


	NodeBPplus* actual = root;


	//Buscar la hoja que este mas a la izquierda
	while (!actual->esHoja) {
		actual = actual->hijos[0];
	}

	std::cout << "Hoja: ";


	while (actual != nullptr) {
		std::cout << "[ ";
		for (int i = 0; i < actual->cantidad; i++)
		{
			std::cout << actual->claves[i];

			if (i < actual->cantidad - 1)
			{
				std::cout << " | ";
			}
		}


		std::cout << " ]";


		actual = actual->siguiente;
		if (actual != nullptr)	 {
			std::cout << " -> ";
		}

		std::cout << std::endl;

		/*actual = actual->hijos[0];*/
	}

	//if (root->esHoja) {
	//	std::cout << "El árbol tiene datos en la raíz." << std::endl;
	//	return;
	//}
	/*else {
		std::cout << "El arbol tiene datos." << std::endl;
		return;
	}*/
	// Implementación para mostrar el árbol
	// Puedes recorrer el árbol y mostrar los valores de las claves
}


/*
int avltree::obteneraltura(node* node) {
	if (node == nullptr) {
		return 0;
	}
	return node->altura;
}*/


//
//AVLTree::AVLTree() {
//	root = nullptr;
//}
////void destroyTree(Node* node);
//AVLTree::~AVLTree() {
//	destroyTree(root);
//}
//
//void AVLTree::destroyTree(Node* node) {
//	if (node != nullptr) {
//		destroyTree(node->left);
//		destroyTree(node->right);
//		delete node;
//	}
//}
//
////Node* insert(Node* node, int val);
//
////
////struct Node
////{
////	int data;
////	Node* left;
////	Node* right;
////	Node(int val);
////
////};
//
//int AVLTree::obtenerAltura(Node* node) {
//	if (node == nullptr) {
//		return 0;
//	}
//	return node->altura;
//}
//
//
//
//int AVLTree::obtenerBalance(Node* node) {
//	if (node == nullptr) {
//		return 0;
//	}
//	return obtenerAltura(node->left) - obtenerAltura(node->right);
//}
//
//Node* AVLTree::rotarDerecha(Node* nodeIzquierdo) {
//
//	Node* nodeDerecho = nodeIzquierdo->left;
//	Node* nodeTemporal = nodeDerecho->right;
//
//	//La rotación derecha
//	nodeDerecho->right = nodeIzquierdo;
//	nodeDerecho->left = nodeTemporal;
//
//	//Actualizar alturas
//	nodeIzquierdo->altura = 1 + std::max(obtenerAltura(nodeIzquierdo->left), obtenerAltura(nodeIzquierdo->right));
//
//	nodeDerecho->altura = 1 + std::max(obtenerAltura(nodeDerecho->left), obtenerAltura(nodeDerecho->right));
//
//	return nodeDerecho;
//
//}
//
//
//Node* AVLTree::rotarIzquierda(Node* nodeDerecho) {
//
//	Node* nodeIzquierdo = nodeDerecho->right;
//	Node* nodeTemporal = nodeIzquierdo->left;
//
//	//La rotación Izquierda
//	nodeIzquierdo->left = nodeDerecho;
//	nodeDerecho->right = nodeTemporal;
//
//	//Actualizar alturas
//	nodeDerecho->altura = 1 + std::max(obtenerAltura(nodeDerecho->left), obtenerAltura(nodeDerecho->right));
//
//	nodeIzquierdo->altura = 1 + std::max(obtenerAltura(nodeIzquierdo->left), obtenerAltura(nodeIzquierdo->right));
//
//	return nodeIzquierdo;
//
//}
//
//Node* AVLTree::crearNodo(int val) {
//
//	Node* newNode = new Node;
//
//	newNode->data = val;
//	newNode->left = nullptr;
//	newNode->right = nullptr;
//	newNode->altura = 1; // Inicialmente, la altura de un nuevo nodo es 1
//
//	return newNode;
//
//}
//
//
//void AVLTree::insert(int val) {
//	root = insert(root, val);
//}
//
//Node* AVLTree::insert(Node* node, int val) {
//	if (node == nullptr) {
//		return crearNodo(val);
//	}
//
//	if (val < node->data) {
//		node->left = insert(node->left, val);
//	}
//	else if (val > node->data) {
//		node->right = insert(node->right, val);
//	}
//	else {
//		std::cout << "Valor duplicado: " << val << std::endl;
//		return node;
//	}
//
//
//	//actualizar la altura del nodo actual
//	node->altura = 1 + std::max(obtenerAltura(node->left), obtenerAltura(node->right));
//
//	//Calcular el factor de balance
//	int balance = obtenerBalance(node);
//
//
//	//Caso 1 izquierda - izquierda
//	// 
//	if (balance > 1 && val < node->left->data) {
//		return rotarDerecha(node);
//	}
//
//
//	//Caso 2 derecha - derecha
//	// 
//	if (balance < -1 && val > node->right->data) {
//		return rotarIzquierda(node);
//	}
//
//
//
//	//Caso 3 izquierda - derecha
//	// 
//	if (balance > 1 && val > node->left->data) {
//
//		node->left = rotarIzquierda(node->left);
//
//
//		return rotarDerecha(node);
//	}
//
//
//	//Caso 4 derecha - izquierda
//	if (balance < -1 && val < node->right->data) {
//		node->right = rotarDerecha(node->right);
//
//
//		return rotarIzquierda(node);
//
//
//	}
//
//
//	return node;
//
//}
//
//
////Recorrido preorden razi, izquiera, derecha
//
//void AVLTree::preordenAuxiliar() {
//	preorden(root);
//	std::cout << std::endl;
//}
//
//
//void AVLTree::preorden(Node* node) {
//	if (node != nullptr) {
//		std::cout << node->data << " "; //visitar la raiz
//		preorden(node->left);//Mostrando la izquierda
//		preorden(node->right);//Mostrando la derecha
//	}
//}
//
//
//void AVLTree::inordenAuxiliar() {
//	inorden(root);
//	std::cout << std::endl;
//}
//
////Recorrido inorden izquierda,raiz, derecha
//
//
//void AVLTree::inorden(Node* node) {
//	if (node != nullptr) {
//		inorden(node->left);//Mostrando la izquierda
//
//		std::cout << node->data << " "; //visitar la raiz
//
//		inorden(node->right);//Mostrando la derecha
//	}
//}
//
//
//
////Recorrido postorden izquierda, derecha, raiz
//void AVLTree::postordenAuxiliar() {
//	postorden(root);
//	std::cout << std::endl;
//}
//
//
//
//void AVLTree::postorden(Node* node) {
//	if (node != nullptr) {
//		postorden(node->left);//Mostrando la izquierda		
//
//		postorden(node->right);//Mostrando la derecha
//
//		std::cout << node->data << " "; //visitar la raiz
//	}
//}