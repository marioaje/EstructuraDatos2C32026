//Arbol - N: nada->Arbol - N(Constructora)
//Hijos : Arbol - N->Lista(Analizadora)
//raíz : Arbol - N->entero(Analizadora)
//HijoPos : Arbol - N, entero->entero(Analizadora)
//esVacio : Arbol - N -> bool(Analizadora)
//peso : Arbol - N->entero(Analizadora)
//altura : Arbol - N->entero(Analizadora)
//preorden : Arbol - N->nada(Salida pantalla)
//inorden : Arbol - N->nada(Salida pantalla)
//postorden : Arbol - N->nada(Salida pantalla)
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int val);

};

class BinaryTree
{
	private:
		Node* root;

		Node* insert(Node* node, int val);
	//	void destroyTree(Node* node);
		
		//Metodos auxiliares o recursivos de recorrido
		// 
		void preorden(Node* node);
		void inorden(Node* node);
		void postorden(Node* node);


		

	public:
		BinaryTree();//Constructor
		//~BinaryTree();//destructor
		
		void insert(int val);

		//Metodos auxiliares o recursivos de recorrido
		// 
		void preordenAuxiliar();
		void inorden();
		void postorden();

	//Hijos : Arbol - N->Lista(Analizadora)
//raíz : Arbol - N->entero(Analizadora)

};




//preorden : Arbol - N->nada(Salida pantalla)
//inorden : Arbol - N->nada(Salida pantalla)
//postorden : Arbol - N->nada(Salida pantalla)


#endif