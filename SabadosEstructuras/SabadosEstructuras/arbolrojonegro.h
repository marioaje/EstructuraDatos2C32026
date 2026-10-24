#pragma once

struct NodeRN
{
	int valor;
	bool rojo;

	NodeRN* izquierda;
	NodeRN* derecha;
	NodeRN* padre;

};

class ArbolRojoNegro
{
public:
	ArbolRojoNegro();
	~ArbolRojoNegro();

	ArbolRojoNegro(const ArbolRojoNegro&) = delete;
	ArbolRojoNegro& operator=(const ArbolRojoNegro&) = delete;

	void insert(int valor);
	void mostrarArbol();

private:
	NodeRN* root;

	NodeRN* crearNodo(int valor);

	void rotarIzquierda(NodeRN* nodo);
	void rotarDerecha(NodeRN* nodo);

	void corregirNodo(NodeRN* nodo, int valor);

	void mostraNodo(NodeRN* nodo, int nivel);

	void liberar(NodeRN* nodo);


};
