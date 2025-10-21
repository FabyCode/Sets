#ifndef SISTEMACIFRADO_H
#define SISTEMACIFRADO_H

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;

class SistemaCifrado {
private:
    vector<string> emisores;
    vector<string> receptores;
    vector<int> llaves;
    vector<tuple<string, int, string>> conexiones; // (Emisor, Llave, Receptor)

public:
    // Emisores
    void agregarEmisor(const string& e);
    void eliminarEmisor(const string& e);

    // Receptores
    void agregarReceptor(const string& r);
    void eliminarReceptor(const string& r);

    // Llaves
    void agregarLlave(int llave);
    void eliminarLlave(int llave);

    // Conexiones
    void crearConexion(const string& emisor, int llave, const string& receptor);
    void mostrarConexiones() const;

    // Conjuntos
    void mostrarEmisores() const;
    void mostrarReceptores() const;
    void mostrarLlaves() const;
    void calculadoraConjuntos() const;

    // Funciones
    void verificarPropiedadesFuncion() const;
    bool esFuncion() const;
    bool esInyectiva() const;
    bool esSobreyectiva() const;

    // Relaciones
    void verificarPropiedadesRelacion() const;
    bool esReflexiva() const;
    bool esSimetrica() const;
    bool esTransitiva() const;

    // Conjuntos
    vector<string> unionConjuntos(const vector<string>& A, const vector<string>& B) const;
    vector<string> interseccionConjuntos(const vector<string>& A, const vector<string>& B) const;
    vector<string> diferenciaConjuntos(const vector<string>& A, const vector<string>& B) const;
    vector<string> diferenciaSimetrica(const vector<string>& A, const vector<string>& B) const;
};

#endif
