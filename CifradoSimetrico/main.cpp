#include "SistemaCifrado.h"

int main() {
    SistemaCifrado sistema;
    int opcion;
    string emisor, receptor;
    int llave;

    do {
        cout << "\n--- Menu ---\n";
        cout << "[1] Agregar Emisor\n";
        cout << "[2] Eliminar Emisor\n";
        cout << "[3] Agregar Receptor\n";
        cout << "[4] Eliminar Receptor\n";
        cout << "[5] Agregar Llave\n";
        cout << "[6] Eliminar Llave\n";
        cout << "[7] Crear Conexion\n";
        cout << "[8] Mostrar Conexiones\n";
        cout << "[9] Mostrar Conjuntos\n";
        cout << "[10] Calculadora de Conjuntos\n";
        cout << "[0] Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese Emisor: ";
                cin >> emisor; sistema.agregarEmisor(emisor);
                break;
            case 2:
                cout << "Ingrese Emisor a eliminar: ";
                cin >> emisor; sistema.eliminarEmisor(emisor);
                break;
            case 3:
                cout << "Ingrese Receptor: ";
                cin >> receptor; sistema.agregarReceptor(receptor);
                break;
            case 4:
                cout << "Ingrese Receptor a eliminar: ";
                cin >> receptor; sistema.eliminarReceptor(receptor);
                break;
            case 5:
                cout << "Ingrese Llave: ";
                cin >> llave; sistema.agregarLlave(llave);
                break;
            case 6:
                cout << "Ingrese Llave a eliminar: ";
                cin >> llave; sistema.eliminarLlave(llave);
                break;
            case 7:
                cout << "Ingrese Emisor: "; cin >> emisor;
                cout << "Ingrese Llave: "; cin >> llave;
                cout << "Ingrese Receptor: "; cin >> receptor;
                sistema.crearConexion(emisor, llave, receptor);
                break;
            case 8:
                sistema.mostrarConexiones();
                break;
            case 9:
                sistema.mostrarEmisores();
                sistema.mostrarReceptores();
                sistema.mostrarLlaves();
                break;
            case 10: sistema.calculadoraConjuntos(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
