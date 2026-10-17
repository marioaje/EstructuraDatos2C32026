
#include <iostream>
#include "arbolplus.h"

ArbolPlus::ArbolPlus() {
    root = nullptr;
}

ArbolPlus::~ArbolPlus() {
    liberar(root);
}

NodeBPplus* ArbolPlus::crearNodo(bool esHoja) {
    NodeBPplus* nuevo = new NodeBPplus;

    nuevo->cantidad = 0;
    nuevo->esHoja = esHoja;
    nuevo->siguiente = nullptr;

    for (int i = 0; i < MAX_CLAVES + 2; i++) {
        nuevo->hijos[i] = nullptr;
    }

    return nuevo;
}

// Insertar un valor ordenadamente en una hoja
void ArbolPlus::insertEnHoja(NodeBPplus* nodeHoja, int val) {
    int i = nodeHoja->cantidad - 1;

    while (i >= 0 && nodeHoja->claves[i] > val) {
        nodeHoja->claves[i + 1] = nodeHoja->claves[i];
        i--;
    }

    nodeHoja->claves[i + 1] = val;
    nodeHoja->cantidad++;
}


// Dividir un nodo interno lleno
void ArbolPlus::dividirNodoInterno(
    NodeBPplus* node,
    int& claveSube,
    NodeBPplus*& derecha
) {
    derecha = crearNodo(false);

    int mitad = node->cantidad / 2;
    int total = node->cantidad;

    claveSube = node->claves[mitad];

    // Claves que pasan al nodo derecho
    for (int i = mitad + 1; i < total; i++) {
        derecha->claves[derecha->cantidad] = node->claves[i];
        derecha->cantidad++;
    }

    // Hijos que pasan al nodo derecho
    int j = 0;

    for (int i = mitad + 1; i <= total; i++) {
        derecha->hijos[j] = node->hijos[i];
        node->hijos[i] = nullptr;
        j++;
    }

    node->cantidad = mitad;
}

//Dividir en una hoja llena
void ArbolPlus::dividirEnHoja(NodeBPplus* nodeHoja, int val) {


    std::cout << "dividirEnHoja valor: " << val << " cantidad anterior: " << nodeHoja->cantidad << std::endl;
    //Insertamos temporalemte una hoja en la cuarta clave ultimo elemento
    insertEnHoja(nodeHoja, val);

    NodeBPplus* derecha = crearNodo(true);

    int mitad = nodeHoja->cantidad / 2;
    int total = nodeHoja->cantidad;

    for (int i = mitad; i < total; i++)
    {
        derecha->claves[derecha->cantidad] = nodeHoja->claves[i];
        derecha->cantidad++;

    }

    nodeHoja->cantidad = mitad;

    //Conectamos las hojas
    derecha->siguiente = nodeHoja->siguiente;
    nodeHoja->siguiente = derecha;



}


// Inserción recursiva
bool ArbolPlus::insertarNodo(
    NodeBPplus* node,
    int val,
    int& claveSube,
    NodeBPplus*& derecha
) {
    // Si estamos en una hoja
    if (node->esHoja) {

        if (node->cantidad < MAX_CLAVES) {
            insertEnHoja(node, val);
            return false;
        }

        // La hoja se llenó
        dividirEnHoja(node, val);

        derecha = node->siguiente;
        claveSube = derecha->claves[0];

        return true;
    }

    // Buscar el hijo correspondiente
    int posicion = 0;

    while (posicion < node->cantidad&&
        val >= node->claves[posicion]) {
        posicion++;
    }

    int nuevaClave = 0;
    NodeBPplus* nuevoHijo = nullptr;

    bool dividido = insertarNodo(
        node->hijos[posicion],
        val,
        nuevaClave,
        nuevoHijo
    );

    if (!dividido) {
        return false;
    }

    // Desplazar claves
    for (int i = node->cantidad; i > posicion; i--) {
        node->claves[i] = node->claves[i - 1];
    }

    // Desplazar hijos
    for (int i = node->cantidad + 1; i > posicion + 1; i--) {
        node->hijos[i] = node->hijos[i - 1];
    }

    node->claves[posicion] = nuevaClave;
    node->hijos[posicion + 1] = nuevoHijo;
    node->cantidad++;

    if (node->cantidad <= MAX_CLAVES) {
        return false;
    }

    // Dividir nodo interno
    dividirNodoInterno(node, claveSube, derecha);
    return true;
}

void ArbolPlus::insert(int valor) {
    // Árbol vacío
    if (root == nullptr) {
        root = crearNodo(true);
        insertEnHoja(root, valor);
        return;
    }

    // Verificar duplicados
    NodeBPplus* actual = root;

    while (!actual->esHoja) {
        int i = 0;

        while (i < actual->cantidad &&
            valor >= actual->claves[i]) {
            i++;
        }

        actual = actual->hijos[i];
    }

    for (int i = 0; i < actual->cantidad; i++) {
        if (actual->claves[i] == valor) {
            std::cout << "El valor " << valor
                << " ya existe.\n";
            return;
        }
    }

    int claveSube = 0;
    NodeBPplus* derecha = nullptr;

    bool dividido = insertarNodo(
        root, valor, claveSube, derecha
    );

    // Crear una nueva raíz si la anterior se dividió
    if (dividido) {
        NodeBPplus* nuevaRaiz = crearNodo(false);

        nuevaRaiz->claves[0] = claveSube;
        nuevaRaiz->cantidad = 1;

        nuevaRaiz->hijos[0] = root;
        nuevaRaiz->hijos[1] = derecha;

        root = nuevaRaiz;
    }
}

void ArbolPlus::mostrarArbol() {
    if (root == nullptr) {
        std::cout << "El arbol esta vacio.\n";
        return;
    }

    NodeBPplus* actual = root;

    // Buscar la hoja más a la izquierda
    while (!actual->esHoja) {
        actual = actual->hijos[0];
    }

    std::cout << "Hoja: ";

    while (actual != nullptr) {
        std::cout << "[ ";

        for (int i = 0; i < actual->cantidad; i++) {
            std::cout << actual->claves[i];

            if (i < actual->cantidad - 1) {
                std::cout << " | ";
            }
        }

        std::cout << " ]";

        actual = actual->siguiente;

        if (actual != nullptr) {
            std::cout << " -> ";
        }
    }

    std::cout << std::endl;
}

void ArbolPlus::liberar(NodeBPplus* node) {
    if (node == nullptr) {
        return;
    }

    if (!node->esHoja) {
        for (int i = 0; i <= node->cantidad; i++) {
            liberar(node->hijos[i]);
        }
    }

    delete node;
}
