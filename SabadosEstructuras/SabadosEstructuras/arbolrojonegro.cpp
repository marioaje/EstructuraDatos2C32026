
#include <iostream>
#include "arbolrojonegro.h"

ArbolRojoNegro::ArbolRojoNegro() {
    root = nullptr;
}

ArbolRojoNegro::~ArbolRojoNegro() {
    liberar(root);
}


void ArbolRojoNegro::liberar(NodeRN* node) {
    if (node == nullptr) {
        return;
    }

    liberar(node->derecha);
    liberar(node->izquierda);

    delete node;
}


NodeRN* ArbolRojoNegro::crearNodo(int valor) {
    NodeRN* nuevo = new NodeRN;
    nuevo->valor = valor;
    nuevo->rojo = true;

    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;
    nuevo->padre = nullptr;

    return nuevo;

}
//	void rotarIzquierda(NodeRN* nodo);

void ArbolRojoNegro::rotarIzquierda(NodeRN* nodo) {


    NodeRN* derecho = nodo->derecha;

    nodo->derecha = derecho->izquierda;

    if (derecho->izquierda != nullptr)
    {
        derecho->izquierda->padre = nodo;
    }


    derecho->padre = nodo->padre;

    if (nodo->padre == nullptr) {
        root = derecho;
    }

    else if (nodo == nodo->padre->izquierda) {
        nodo->padre->izquierda = derecho;
    }
    else {
        nodo->padre->derecha = derecho;
    }

    derecho->izquierda = nodo;
    nodo->padre = derecho;
}


void ArbolRojoNegro::rotarDerecha(NodeRN* nodo) {


    NodeRN* izquierdo = nodo->izquierda;

    nodo->izquierda = izquierdo->derecha;

    if (izquierdo->derecha != nullptr)
    {
        izquierdo->derecha->padre = nodo;
    }


    izquierdo->padre = nodo->padre;

    if (nodo->padre == nullptr) {
        root = izquierdo;
    }

    else if (nodo == nodo->padre->izquierda) {
        nodo->padre->izquierda = izquierdo;
    }
    else {
        nodo->padre->derecha = izquierdo;
    }

    izquierdo->derecha = nodo;
    nodo->padre = izquierdo;
}


void ArbolRojoNegro::insert(int valor) {
    NodeRN* nuevo = crearNodo(valor);

    NodeRN* actual = root;

    NodeRN* padre = nullptr;

    //Buscar
    while (actual != nullptr) {
        padre = actual;

        if (valor < actual -> valor)
        {
            actual = actual->izquierda;
        }

        else if (valor > actual->valor)
        {
            actual = actual->derecha;
        }
        else{
            std::cout << "Valor duplicado:" << valor << std::endl;
            delete nuevo;
                return;
        }

    }

    nuevo-> padre = padre;

    if (padre == nullptr) {
        root = nuevo;

    }

    if (valor < padre->valor)
    {
        padre->izquierda = nuevo;
    }

    else if (valor > actual->valor)
    {
        padre->derecha = nuevo;
    }




}
