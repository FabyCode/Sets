#ifndef SISTEMACIFRADO_H
#define SISTEMACIFRADO_H

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;

// -------------------------------------------------------------
// SISTEMA DE CIFRADO SIMÉTRICO - PUNTOS 1.2.5 Y 1.2.6
// -------------------------------------------------------------
//
// Objetivo:
// Implementar la verificación de propiedades de relación
// (reflexiva, simétrica, transitiva) y una calculadora de conjuntos
// aplicada a Emisores y Receptores.
//
// -------------------------------------------------------------

class SistemaCifrado {
private:
    vector<string> emisores;
    vector<string> receptores;
    vector<int> llaves;
    vector<tuple<string, int, string>> conexiones; // (Emisor, Llave, Receptor)

public:
    // ---- Gestión de Emisores ----
    void agregarEmisor(const string& e);
    void eliminarEmisor(const string& e);

    // ---- Gestión de Receptores ----
    void agregarReceptor(const string& r);
    void eliminarReceptor(const string& r);

    // ---- Gestión de Llaves ----
    void agregarLlave(int llave);
    void eliminarLlave(int llave);

    // ---- Conexiones ----
    void crearConexion(const string& emisor, int llave, const string& receptor);
    void mostrarConexiones() const;

    // ---- Mostrar conjuntos ----
    void mostrarEmisores() const;
    void mostrarReceptores() const;
    void mostrarLlaves() const;

    // ---- Operaciones de Conjuntos ----
    void calculadoraConjuntos() const;

private:
    // ---- Propiedades de Función ----
    void verificarPropiedadesFuncion() const;
    bool esFuncion() const;
    bool esInyectiva() const;
    bool esSobreyectiva() const;

    // ---- Propiedades de Relación ----
    void verificarPropiedadesRelacion() const;
    bool esReflexiva() const;
    bool esSimetrica() const;
    bool esTransitiva() const;

    // ---- Operaciones de Conjuntos ----
    vector<string> unionConjuntos(const vector<string>& A, const vector<string>& B) const;
    vector<string> interseccionConjuntos(const vector<string>& A, const vector<string>& B) const;
    vector<string> diferenciaConjuntos(const vector<string>& A, const vector<string>& B) const;
    vector<string> diferenciaSimetrica(const vector<string>& A, const vector<string>& B) const;
};

#endif
