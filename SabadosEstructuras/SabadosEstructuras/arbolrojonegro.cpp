
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

    //Buscar donde insertar
    while (actual != nullptr) {
        padre = actual;

        if (valor < actual->valor)
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

    nuevo->padre = padre;

    if (padre == nullptr) {
        root = nuevo;

    }

    else if (valor < padre->valor)
    {
        padre->izquierda = nuevo;
    }

    else 
    {
        padre->derecha = nuevo;
    }


    corregirInsert(nuevo);

}

//Corrige colores y rota desp
void ArbolRojoNegro::corregirInsert(NodeRN* nodo) {

    while (nodo != root && nodo->padre != nullptr && nodo->padre->rojo) {

        NodeRN* padre = nodo->padre;
        NodeRN* abuelo = padre->padre;

        if (abuelo == nullptr) {
            break;
        }

        //El padre se encuentra en datos del abuelo
        if (padre == abuelo->izquierda) {
            NodeRN* tio = abuelo->derecha;

            //Caso cuando el tio se rojo
            if (tio != nullptr && tio->rojo) {
                padre->rojo = false;
                tio->rojo = false;
                abuelo->rojo = true;
                nodo = abuelo;
            }
            else {
                //Caso de izquierda a derecha
                if (nodo == padre->derecha) {
                    nodo = padre;
                    rotarIzquierda(nodo);
                }

                // izquierda izquierda
                // 
                nodo->padre->rojo = false;
                nodo->padre->padre->rojo = true;
                rotarDerecha(nodo->padre->padre);
            }
        }
        else {
            //caso donde son iguales el padre al lado derecho

            NodeRN* tio = abuelo->izquierda;

            if (tio != nullptr && tio->rojo) {
                padre->rojo = false;
                tio->rojo = false;
                abuelo->rojo = true;
                nodo = abuelo;
            }

            else {
                //Caso de derecha a izquierda
                if (nodo == padre->izquierda) {
                    nodo = padre;
                    rotarDerecha(nodo);
                }

                // derecha derecha
                // 
                nodo->padre->rojo = false;
                nodo->padre->padre->rojo = true;
                rotarIzquierda(nodo->padre->padre);
            }

        }


    }

    root->rojo = false;


 }


void ArbolRojoNegro::mostraNodo(NodeRN* nodo, int nivel) {

    if (nodo == nullptr) {
        return;
    }

    for (int i = 0; i < nivel; i++)
    {
        std::cout << "    ";
    }

    std::cout << nodo->valor << (nodo->rojo ? "(R)" : "(N)") << std::endl;
    mostraNodo(nodo->izquierda, nivel + 1);
    mostraNodo(nodo->derecha, nivel + 1);
}

void ArbolRojoNegro::mostrarArbol() {
    if (root == nullptr) {
        std::cout << "Arbol esta sin datos\n";
        return;
    }
    mostraNodo(root, 0);
}