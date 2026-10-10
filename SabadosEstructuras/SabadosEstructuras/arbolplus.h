const int MAX_CLAVES = 3; // Maximum number of nodes in the tree


struct NodeBPplus
{
	int claves[MAX_CLAVES + 1]; 

	NodeBPplus* hijos[MAX_CLAVES + 2];


	int cantidad;

	bool esHoja; //balanceo si existe algo nuevo

	//Enlace entre las hojas

	NodeBPplus* siguiente;

};

class ArbolPlus
{

private:
	NodeBPplus* root;


	NodeBPplus* crearNodo(bool esHoja);

	void insertEnHoja(NodeBPplus* nodeHoja, int val);


	void dividirEnHoja(NodeBPplus* nodeHoja, int val);

public:
	ArbolPlus();//Constructor

	void insert(int val);

	void mostrarArbol();
};

//
//class BinaryTree
//{
//private:
//	Node* root;
//
//	Node* insert(Node* node, int val);
//	void destroyTree(Node* node);
//
//	//Metodos auxiliares o recursivos de recorrido
//	// 
//	void preorden(Node* node);
//	void inorden(Node* node);
//	void postorden(Node* node);
//
//
//
//
//public:
//	BinaryTree();//Constructor
//	~BinaryTree();//destructor
//
//	void insert(int val);
//
//	//Metodos auxiliares o recursivos de recorrido
//	// 
//	void preordenAuxiliar();
//	void inordenAuxiliar();
//	void postordenAuxiliar();
//
//	//Hijos : Arbol - N->Lista(Analizadora)
////raíz : Arbol - N->entero(Analizadora)
//
//};
//
//

//
//
//class AVLTree
//{
//private:
//	Node* root;
//
//	Node* crearNodo(int val);
//
//	Node* insert(Node* node, int val);
//
//
//	void destroyTree(Node* node);
//
//	Node* rotarDerecha(Node* node);
//	Node* rotarIzquierda(Node* node);
//	int obtenerAltura(Node* node);
//	int obtenerBalance(Node* node);
//
//	//Metodos auxiliares o recursivos de recorrido
//	// 
//	void preorden(Node* node);
//	void inorden(Node* node);
//	void postorden(Node* node);
//
//
//
//
//public:
//	AVLTree();//Constructor
//	~AVLTree();//destructor
//
//	void insert(int val);
//
//	//Metodos auxiliares o recursivos de recorrido
//	// 
//	void preordenAuxiliar();
//	void inordenAuxiliar();
//	void postordenAuxiliar();
//
//	//Hijos : Arbol - N->Lista(Analizadora)
////raíz : Arbol - N->entero(Analizadora)
//
//};
