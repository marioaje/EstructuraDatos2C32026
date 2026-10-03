#pragma once
#ifndef AVL_TREE_H
#define AVL_TREE_H

struct Node
{
	int data;
	Node* left;
	Node* right;
	int altura;

	//Node(int val);

};

class AVLTree
{
private:
	Node* root;

	Node* crearNodo(int val);

	Node* insert(Node* node, int val);


	void destroyTree(Node* node);

	Node* rotarDerecha(Node* node);
	Node* rotarIzquierda(Node* node);
	int obtenerAltura(Node* node);
	int obtenerBalance(Node* node);

	//Metodos auxiliares o recursivos de recorrido
	// 
	void preorden(Node* node);
	void inorden(Node* node);
	void postorden(Node* node);




public:
	AVLTree();//Constructor
	~AVLTree();//destructor

	void insert(int val);

	//Metodos auxiliares o recursivos de recorrido
	// 
	void preordenAuxiliar();
	void inordenAuxiliar();
	void postordenAuxiliar();

	//Hijos : Arbol - N->Lista(Analizadora)
//raíz : Arbol - N->entero(Analizadora)

};




//preorden : Arbol - N->nada(Salida pantalla)
//inorden : Arbol - N->nada(Salida pantalla)
//postorden : Arbol - N->nada(Salida pantalla)


#endif