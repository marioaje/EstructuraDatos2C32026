#pragma once

const int MAX_CLAVES = 3;

struct NodeBPplus
{
    int claves[MAX_CLAVES + 1];
    NodeBPplus* hijos[MAX_CLAVES + 2];

    int cantidad;
    bool esHoja;

    NodeBPplus* siguiente;
};

class ArbolPlus
{
private:
    NodeBPplus* root;

    NodeBPplus* crearNodo(bool esHoja);

    void insertEnHoja(NodeBPplus* nodeHoja, int val);

    void dividirEnHoja(NodeBPplus* nodeHoja, int val);

    bool insertarNodo(
        NodeBPplus* node,
        int val,
        int& claveSube,
        NodeBPplus*& derecha
    );

    void dividirNodoInterno(
        NodeBPplus* node,
        int& claveSube,
        NodeBPplus*& derecha
    );

    void liberar(NodeBPplus* node);

public:
    ArbolPlus();
    ~ArbolPlus();

    ArbolPlus(const ArbolPlus&) = delete;
    ArbolPlus& operator=(const ArbolPlus&) = delete;

    void insert(int val);
    void mostrarArbol();
};
