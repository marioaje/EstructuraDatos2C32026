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
#ifndef NARY_TREE_H
#define NARY_TREE_H

#include <vector>
#include <iostream>

struct NaryNode
{
	int data;

	std::vector<NaryNode*> children;//esto es un vector dinamico  para n cantidad de hijos

	NaryNode(int val);

	~NaryNode();

};

class NaryTree
{
private:
	NaryNode* root;
	
	void destroyTree(NaryNode* node);

	//Metodos auxiliares o recursivos de recorrido
	// 
	void preorden(NaryNode* node);
	/*void inorden(Node* node);
	void postorden(Node* node);*/




public:
	NaryTree(int rootVal);//Constructor
	~NaryTree();//destructor

	NaryNode* getRoot();

	bool addChild(NaryNode* parent, int val);

	//Metodos auxiliares o recursivos de recorrido
	// 
	void preordenAuxiliar();
	//void inordenAuxiliar();
	//void postordenAuxiliar();
};



#endif