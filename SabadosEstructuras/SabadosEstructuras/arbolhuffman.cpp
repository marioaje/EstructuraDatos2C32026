
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// Estructura del nodo del arbol
struct Nodo
{
    char caracter;
    int frecuencia;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(char c, int f)
    {
        caracter = c;
        frecuencia = f;
        izquierda = nullptr;
        derecha = nullptr;
    }

    Nodo(Nodo* izq, Nodo* der)
    {
        caracter = '\0';
        frecuencia = izq->frecuencia + der->frecuencia;
        izquierda = izq;
        derecha = der;
    }

    bool esHoja()
    {
        return izquierda == nullptr &&
            derecha == nullptr;
    }
};

// Comparador para la cola de prioridad
struct Comparador
{
    bool operator()(Nodo* a, Nodo* b)
    {
        return a->frecuencia > b->frecuencia;
    }
};

// Construir el arbol Huffman
Nodo* construirArbol(map<char, int>& frecuencias)
{
    priority_queue<
        Nodo*,
        vector<Nodo*>,
        Comparador
    > cola;

    for (auto par : frecuencias)
    {
        cola.push(
            new Nodo(par.first, par.second)
        );
    }

    if (cola.empty())
        return nullptr;

    while (cola.size() > 1)
    {
        Nodo* izquierda = cola.top();
        cola.pop();

        Nodo* derecha = cola.top();
        cola.pop();

        Nodo* padre = new Nodo(
            izquierda, derecha
        );

        cola.push(padre);
    }

    return cola.top();
}

// Generar codigos binarios
void generarCodigos(
    Nodo* raiz,
    string codigo,
    map<char, string>& codigos
)
{
    if (raiz == nullptr)
        return;

    if (raiz->esHoja())
    {
        codigos[raiz->caracter] =
            codigo.empty() ? "0" : codigo;
        return;
    }

    generarCodigos(
        raiz->izquierda,
        codigo + "0",
        codigos
    );

    generarCodigos(
        raiz->derecha,
        codigo + "1",
        codigos
    );
}

// Comprimir el texto
string comprimir(
    string texto,
    map<char, string>& codigos
)
{
    string resultado = "";

    for (char c : texto)
    {
        resultado += codigos[c];
    }

    return resultado;
}

// Descomprimir el texto
string descomprimir(
    string binario,
    Nodo* raiz
)
{
    string resultado = "";

    if (raiz == nullptr)
        return resultado;

    // Caso especial: un solo caracter
    if (raiz->esHoja())
    {
        return string(
            binario.size(),
            raiz->caracter
        );
    }

    Nodo* actual = raiz;

    for (char bit : binario)
    {
        if (bit == '0')
            actual = actual->izquierda;
        else
            actual = actual->derecha;

        if (actual->esHoja())
        {
            resultado += actual->caracter;
            actual = raiz;
        }
    }

    return resultado;
}

// Liberar memoria dinamica
void liberarArbol(Nodo* raiz)
{
    if (raiz == nullptr)
        return;

    liberarArbol(raiz->izquierda);
    liberarArbol(raiz->derecha);

    delete raiz;
}

int main()
{
    string texto = "profemario";

    //cout << "================================\n";
    //cout << " COMPRESION HUFFMAN EN C++\n";
    //cout << "================================\n";

    //cout << "\nIngrese el texto: ";
    //getline(cin, texto);

    //if (texto.empty())
    //{
    //    cout << "El texto esta vacio.\n";
    //    return 0;
    //}

    // 1. Calcular frecuencias
    map<char, int> frecuencias;

    for (char c : texto)
    {
        frecuencias[c]++;
    }

    cout << "\nTABLA DE FRECUENCIAS\n";

    for (auto par : frecuencias)
    {
        cout << par.first
            << " : "
            << par.second
            << endl;
    }

    // 2. Construir arbol
    Nodo* raiz = construirArbol(frecuencias);

    // 3. Generar codigos
    map<char, string> codigos;

    generarCodigos(raiz, "", codigos);

    cout << "\nCODIGOS HUFFMAN\n";

    for (auto par : codigos)
    {
        cout << par.first
            << " : "
            << par.second
            << endl;
    }

    // 4. Comprimir
    string comprimido =
        comprimir(texto, codigos);

    cout << "\nTEXTO ORIGINAL:\n";
    cout << texto << endl;

    cout << "\nTEXTO COMPRIMIDO:\n";
    cout << comprimido << endl;

    // 5. Descomprimir
    string recuperado =
        descomprimir(comprimido, raiz);

    cout << "\nTEXTO DESCOMPRIMIDO:\n";
    cout << recuperado << endl;

    // 6. Estadisticas
    int bitsOriginales = texto.size() * 8;
    int bitsComprimidos = comprimido.size();

    double ahorro = 100.0 * (
        1.0 -
        (double)bitsComprimidos / bitsOriginales
        );

    cout << "\nESTADISTICAS\n";

    cout << "Bits originales: "
        << bitsOriginales << endl;

    cout << "Bits Huffman: "
        << bitsComprimidos << endl;

    cout << fixed << setprecision(2);

    cout << "Ahorro teorico: "
        << ahorro << "%" << endl;

    cout << "\nVerificacion: "
        << (texto == recuperado
            ? "CORRECTA"
            : "ERROR")
        << endl;

    liberarArbol(raiz);

    return 0;
}
