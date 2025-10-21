#include "SistemaCifrado.h"


// GESTION DE USUARIOS (EMISOR, RECEPTOR Y LLAVES)
void SistemaCifrado::agregarEmisor(const string& e) {
    if (find(emisores.begin(), emisores.end(), e) == emisores.end()) {
        emisores.push_back(e);
        cout << "Emisor agregado correctamente.\n";
    } else {
        cout << "El emisor ya existe.\n";
    }
}

void SistemaCifrado::eliminarEmisor(const string& e) {
    auto it = find(emisores.begin(), emisores.end(), e);
    if (it != emisores.end()) {
        emisores.erase(it);
        cout << "Emisor eliminado correctamente.\n";
    } else {
        cout << "Emisor no encontrado.\n";
    }
}

void SistemaCifrado::agregarReceptor(const string& r) {
    if (find(receptores.begin(), receptores.end(), r) == receptores.end()) {
        receptores.push_back(r);
        cout << "Receptor agregado correctamente.\n";
    } else {
        cout << "El receptor ya existe.\n";
    }
}

void SistemaCifrado::eliminarReceptor(const string& r) {
    auto it = find(receptores.begin(), receptores.end(), r);
    if (it != receptores.end()) {
        receptores.erase(it);
        cout << "Receptor eliminado correctamente.\n";
    } else {
        cout << "Receptor no encontrado.\n";
    }
}

void SistemaCifrado::agregarLlave(int llave) {
    if (find(llaves.begin(), llaves.end(), llave) == llaves.end()) {
        llaves.push_back(llave);
        cout << "Llave agregada correctamente.\n";
    } else {
        cout << "La llave ya existe.\n";
    }
}

void SistemaCifrado::eliminarLlave(int llave) {
    auto it = find(llaves.begin(), llaves.end(), llave);
    if (it != llaves.end()) {
        llaves.erase(it);
        cout << "Llave eliminada correctamente.\n";
    } else {
        cout << "Llave no encontrada.\n";
    }
}


// CONEXIONES Y VERIFICACIONES
void SistemaCifrado::crearConexion(const string& emisor, int llave, const string& receptor) {
    if (find(emisores.begin(), emisores.end(), emisor) == emisores.end()) {
        cout << "Error: El emisor no existe.\n";
        return;
    }
    if (find(receptores.begin(), receptores.end(), receptor) == receptores.end()) {
        cout << "Error: El receptor no existe.\n";
        return;
    }
    if (find(llaves.begin(), llaves.end(), llave) == llaves.end()) {
        cout << "Error: La llave no existe.\n";
        return;
    }

    tuple<string, int, string> nuevaConexion = make_tuple(emisor, llave, receptor);

    if (find(conexiones.begin(), conexiones.end(), nuevaConexion) == conexiones.end()) {
        conexiones.push_back(nuevaConexion);
        cout << "Conexion agregada: (" << emisor << ", " << llave << ", " << receptor << ")\n";

        verificarPropiedadesFuncion();
        verificarPropiedadesRelacion();
    } else {
        cout << "Error: La conexion ya existe.\n";
    }
}

void SistemaCifrado::mostrarConexiones() const {
    if (conexiones.empty()) {
        cout << "No hay conexiones registradas.\n";
        return;
    }

    cout << "\nConexiones existentes:\n";
    for (const auto& c : conexiones)
        cout << "(" << get<0>(c) << ", " << get<1>(c) << ", " << get<2>(c) << ")\n";
}

void SistemaCifrado::mostrarEmisores() const {
    cout << "\nEmisores: { ";
    for (const auto& e : emisores) cout << e << " ";
    cout << "}\n";
}

void SistemaCifrado::mostrarReceptores() const {
    cout << "Receptores: { ";
    for (const auto& r : receptores) cout << r << " ";
    cout << "}\n";
}

void SistemaCifrado::mostrarLlaves() const {
    cout << "Llaves: { ";
    for (const auto& l : llaves) cout << l << " ";
    cout << "}\n";
}

// PROPIEDADES DE FUNCION (punto 1.2.4)
void SistemaCifrado::verificarPropiedadesFuncion() const {
    cout << "\n--- Verificacion de Propiedades de Funcion ---\n";
    bool funcion = esFuncion();
    bool inyectiva = false, sobreyectiva = false, biyectiva = false;

    if (funcion) {
        inyectiva = esInyectiva();
        sobreyectiva = esSobreyectiva();
        biyectiva = (inyectiva && sobreyectiva);
    }

    cout << "Es funcion: " << (funcion ? "Si" : "No") << endl;
    cout << "Inyectiva: " << (inyectiva ? "Si" : "No") << endl;
    cout << "Sobreyectiva: " << (sobreyectiva ? "Si" : "No") << endl;
    cout << "Biyectiva: " << (biyectiva ? "Si" : "No") << endl;
}

bool SistemaCifrado::esFuncion() const {
    set<string> emisoresUnicos;
    for (const auto& c : conexiones) {
        string e = get<0>(c);
        if (emisoresUnicos.count(e)) return false;
        emisoresUnicos.insert(e);
    }
    return true;
}

bool SistemaCifrado::esInyectiva() const {
    set<string> receptoresUnicos;
    for (const auto& c : conexiones) {
        string r = get<2>(c);
        if (receptoresUnicos.count(r)) return false;
        receptoresUnicos.insert(r);
    }
    return true;
}

bool SistemaCifrado::esSobreyectiva() const {
    set<string> receptoresConConexion;
    for (const auto& c : conexiones)
        receptoresConConexion.insert(get<2>(c));

    for (const auto& r : receptores)
        if (receptoresConConexion.count(r) == 0)
            return false;
    return true;
}

// PROPIEDADES DE RELACION
void SistemaCifrado::verificarPropiedadesRelacion() const {
    cout << "\n--- Verificacion de Propiedades de Relacion ---\n";
    cout << "Reflexiva: " << (esReflexiva() ? "Si" : "No") << endl;
    cout << "Simetrica: " << (esSimetrica() ? "Si" : "No") << endl;
    cout << "Transitiva: " << (esTransitiva() ? "Si" : "No") << endl;
}

bool SistemaCifrado::esReflexiva() const {
    for (const auto& c : conexiones)
        if (get<0>(c) == get<2>(c))
            return true;
    return false;
}

bool SistemaCifrado::esSimetrica() const {
    for (const auto& c : conexiones) {
        string a = get<0>(c);
        string b = get<2>(c);
        bool existeSimetrica = false;
        for (const auto& d : conexiones)
            if (get<0>(d) == b && get<2>(d) == a)
                existeSimetrica = true;
        if (!existeSimetrica)
            return false;
    }
    return true;
}

bool SistemaCifrado::esTransitiva() const {
    for (const auto& x : conexiones) {
        string a = get<0>(x);
        string b = get<2>(x);
        for (const auto& y : conexiones) {
            if (get<0>(y) == b) {
                string c = get<2>(y);
                bool existe = false;
                for (const auto& z : conexiones)
                    if (get<0>(z) == a && get<2>(z) == c)
                        existe = true;
                if (!existe)
                    return false;
            }
        }
    }
    return true;
}


// CALCULADORA DE CONJUNTOS
void SistemaCifrado::calculadoraConjuntos() const {
    cout << "\n--- Calculadora de Conjuntos (Emisores y Receptores) ---\n";

    vector<string> uni = unionConjuntos(emisores, receptores);
    vector<string> inter = interseccionConjuntos(emisores, receptores);
    vector<string> dif = diferenciaConjuntos(emisores, receptores);
    vector<string> difSim = diferenciaSimetrica(emisores, receptores);

    auto mostrar = [](const vector<string>& v, const string& nombre) {
        cout << nombre << ": { ";
        for (const auto& x : v) cout << x << " ";
        cout << "}\n";
    };

    mostrar(uni, "Union (A ∪ B)");
    mostrar(inter, "Interseccion (A ∩ B)");
    mostrar(dif, "Diferencia (A - B)");
    mostrar(difSim, "Diferencia Simetrica (A Δ B)");
}

vector<string> SistemaCifrado::unionConjuntos(const vector<string>& A, const vector<string>& B) const {
    vector<string> resultado = A;
    for (const auto& b : B)
        if (find(resultado.begin(), resultado.end(), b) == resultado.end())
            resultado.push_back(b);
    return resultado;
}

vector<string> SistemaCifrado::interseccionConjuntos(const vector<string>& A, const vector<string>& B) const {
    vector<string> resultado;
    for (const auto& a : A)
        if (find(B.begin(), B.end(), a) != B.end())
            resultado.push_back(a);
    return resultado;
}

vector<string> SistemaCifrado::diferenciaConjuntos(const vector<string>& A, const vector<string>& B) const {
    vector<string> resultado;
    for (const auto& a : A)
        if (find(B.begin(), B.end(), a) == B.end())
            resultado.push_back(a);
    return resultado;
}

vector<string> SistemaCifrado::diferenciaSimetrica(const vector<string>& A, const vector<string>& B) const {
    vector<string> resultado;
    for (const auto& a : A)
        if (find(B.begin(), B.end(), a) == B.end())
            resultado.push_back(a);
    for (const auto& b : B)
        if (find(A.begin(), A.end(), b) == A.end())
            resultado.push_back(b);
    return resultado;
}
