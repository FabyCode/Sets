#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Sets.h"

using namespace std;

void showSetTypeMenu();
void showOperationMenu();

int main() {
    srand(time(nullptr));

    cout << "=== SET OPERATIONS PROGRAM ===\n";
    showSetTypeMenu();
    int typeChoice;
    cout << "Select type: ";
    cin >> typeChoice;
    cin.ignore();

    int n;
    cout << "Enter number of sets to create: ";
    cin >> n;
    cin.ignore();

    // ---------------------------------------------------------
    // TIPO ENTERO
    // ---------------------------------------------------------
    if (typeChoice == 1) {
        vector<shared_ptr<Sets<int>>> sets;

        cout << "\nDo you want to fill sets automatically?: ";
        int autoFill;
        cin >> autoFill;
        cin.ignore();

        for (int i = 0; i < n; i++) {
            cout << "\nEnter name for set #" << i + 1 << ": ";
            string name;
            getline(cin, name);

            auto s = make_shared<Sets<int>>(name);

            int elementsCount;
            cout << "How many elements? ";
            cin >> elementsCount;
            cin.ignore();

            if (autoFill == 1) {
                // Generar elementos aleatorios únicos
                while ((int)s->getElements().size() < elementsCount) {
                    int value = rand() % 100 + 1; // Rango 1–100
                    s->addElement(value);
                }
            } else {
                for (int j = 0; j < elementsCount; j++) {
                    int value;
                    cout << "Element " << j + 1 << ": ";
                    cin >> value;
                    cin.ignore();
                    s->addElement(value);
                }
            }

            s->show();
            sets.push_back(s);
        }

        // Crear universo (unión de todos)
        Sets<int> universe("Universe");
        for (auto& s : sets)
            universe = universe.unionSet(*s);

        // --- Menú de operaciones ---
        int op;
        do {
            showOperationMenu();
            cout << "Select operation: ";
            cin >> op;
            cin.ignore();

            if (op == 0) break;

            int a, b;
            Sets<int> result("Result");

            if (op >= 1 && op <= 4) {
                cout << "Select first set (1-" << n << "): ";
                cin >> a;
                cout << "Select second set (1-" << n << "): ";
                cin >> b;
                cin.ignore();

                if (a < 1 || b < 1 || a > n || b > n) {
                    cout << "Invalid indices.\n";
                    continue;
                }

                auto& A = *sets[a - 1];
                auto& B = *sets[b - 1];

                switch (op) {
                    case 1: result = A.unionSet(B); break;
                    case 2: result = A.intersectionSet(B); break;
                    case 3: result = A.differenceSet(B); break;
                    case 4: result = A.symmetricDifferenceSet(B); break;
                }

                result.show();
            }
            else if (op == 5) {
                cout << "Select a set (1-" << n << "): ";
                cin >> a;
                cin.ignore();

                if (a < 1 || a > n) {
                    cout << "Invalid index.\n";
                    continue;
                }

                auto& A = *sets[a - 1];
                auto result = A.complementSet(universe);
                result.show();
            }
            else if (op == 6) {
                cout << "\n=== Validations Menu ===\n";
                cout << "1. Check if A ⊆ B\n";
                cout << "2. Check if A ⊂ B\n";
                cout << "3. Check if A ≠̸ B\n";
                cout << "Select validation: ";
                int valOp;
                cin >> valOp;
                cin.ignore();

                cout << "Select first set (A) (1-" << n << "): ";
                cin >> a;
                cout << "Select second set (B) (1-" << n << "): ";
                cin >> b;
                cin.ignore();

                if (a < 1 || b < 1 || a > n || b > n) {
                    cout << "Invalid indices.\n";
                    continue;
                }

                auto& A = *sets[a - 1];
                auto& B = *sets[b - 1];

                switch (valOp) {
                    case 1:
                        cout << A.getName() << " ⊆ " << B.getName()
                            << "? " << (A.isSubsetOf(B) ? "Yes" : "No") << endl;
                        break;
                    case 2:
                        cout << A.getName() << " ⊂ " << B.getName()
                            << "? " << (A.isProperSubsetOf(B) ? "Yes" : "No") << endl;
                        break;
                    case 3:
                        cout << A.getName() << " ≠̸ " << B.getName()
                            << "? " << (A.isDisjointWith(B) ? "Yes" : "No") << endl;
                        break;
                    default:
                        cout << "Invalid option.\n";
                        break;
                }
            }

        } while (op != 0);
    }

    // ---------------------------------------------------------
    // TIPO CHAR
    // ---------------------------------------------------------
    else if (typeChoice == 2) {
        vector<shared_ptr<Sets<char>>> sets;

        cout << "\nDo you want to fill sets automatically?";
        int autoFill;
        cin >> autoFill;
        cin.ignore();

        for (int i = 0; i < n; i++) {
            cout << "\nEnter name for set #" << i + 1 << ": ";
            string name;
            getline(cin, name);

            auto s = make_shared<Sets<char>>(name);

            int elementsCount;
            cout << "How many elements? ";
            cin >> elementsCount;
            cin.ignore();

            if (autoFill == 1) {
                while ((int)s->getElements().size() < elementsCount) {
                    char value = 'A' + rand() % 26; // Letras aleatorias A-Z
                    s->addElement(value);
                }
            } else {
                for (int j = 0; j < elementsCount; j++) {
                    char c;
                    cout << "Element " << j + 1 << ": ";
                    cin >> c;
                    cin.ignore();
                    s->addElement(c);
                }
            }

            s->show();
            sets.push_back(s);
        }

        // Crear universo
        Sets<char> universe("Universe");
        for (auto& s : sets)
            universe = universe.unionSet(*s);

        int op;
        do {
            showOperationMenu();
            cout << "Select operation: ";
            cin >> op;
            cin.ignore();

            if (op == 0) break;

            int a, b;
            Sets<char> result("Result");

            if (op >= 1 && op <= 4) {
                cout << "Select first set (1-" << n << "): ";
                cin >> a;
                cout << "Select second set (1-" << n << "): ";
                cin >> b;
                cin.ignore();

                if (a < 1 || b < 1 || a > n || b > n) {
                    cout << "Invalid indices.\n";
                    continue;
                }

                auto& A = *sets[a - 1];
                auto& B = *sets[b - 1];

                switch (op) {
                    case 1: result = A.unionSet(B); break;
                    case 2: result = A.intersectionSet(B); break;
                    case 3: result = A.differenceSet(B); break;
                    case 4: result = A.symmetricDifferenceSet(B); break;
                }

                result.show();
            }
            else if (op == 5) {
                cout << "Select a set (1-" << n << "): ";
                cin >> a;
                cin.ignore();

                if (a < 1 || a > n) {
                    cout << "Invalid index.\n";
                    continue;
                }

                auto& A = *sets[a - 1];
                auto result = A.complementSet(universe);
                result.show();
            }
            else if (op == 6) {
                cout << "\n=== Validations Menu ===\n";
                cout << "1. Check if A ⊆ B\n";
                cout << "2. Check if A ⊂ B\n";
                cout << "3. Check if A ≠̸ B\n";
                cout << "Select validation: ";
                int valOp;
                cin >> valOp;
                cin.ignore();

                cout << "Select first set (A) (1-" << n << "): ";
                cin >> a;
                cout << "Select second set (B) (1-" << n << "): ";
                cin >> b;
                cin.ignore();

                if (a < 1 || b < 1 || a > n || b > n) {
                    cout << "Invalid indices.\n";
                    continue;
                }

                auto& A = *sets[a - 1];
                auto& B = *sets[b - 1];

                switch (valOp) {
                    case 1:
                        cout << A.getName() << " ⊆ " << B.getName()
                            << "? " << (A.isSubsetOf(B) ? "Yes" : "No") << endl;
                        break;
                    case 2:
                        cout << A.getName() << " ⊂ " << B.getName()
                            << "? " << (A.isProperSubsetOf(B) ? "Yes" : "No") << endl;
                        break;
                    case 3:
                        cout << A.getName() << " ≠̸ " << B.getName()
                            << "? " << (A.isDisjointWith(B) ? "Yes" : "No") << endl;
                        break;
                    default:
                        cout << "Invalid option.\n";
                        break;
                }
            }

        } while (op != 0);
    }

    // ---------------------------------------------------------
    // TIPO STRING
    // ---------------------------------------------------------
    else if (typeChoice == 3) {
        vector<shared_ptr<Sets<string>>> sets;

        for (int i = 0; i < n; i++) {
            cout << "\nEnter name for set #" << i + 1 << ": ";
            string name;
            getline(cin, name);

            auto s = make_shared<Sets<string>>(name);

            int elementsCount;
            cout << "How many elements? ";
            cin >> elementsCount;
            cin.ignore();

            for (int j = 0; j < elementsCount; j++) {
                string value;
                cout << "Element " << j + 1 << ": ";
                getline(cin, value);
                s->addElement(value);
            }

            s->show();
            sets.push_back(s);
        }

        Sets<string> universe("Universe");
        for (auto& s : sets)
            universe = universe.unionSet(*s);

        int op;
        do {
            showOperationMenu();
            cout << "Select operation: ";
            cin >> op;
            cin.ignore();

            if (op == 0) break;

            int a, b;
            Sets<string> result("Result");

            if (op >= 1 && op <= 4) {
                cout << "Select first set (1-" << n << "): ";
                cin >> a;
                cout << "Select second set (1-" << n << "): ";
                cin >> b;
                cin.ignore();

                if (a < 1 || b < 1 || a > n || b > n) {
                    cout << "Invalid indices.\n";
                    continue;
                }

                auto& A = *sets[a - 1];
                auto& B = *sets[b - 1];

                switch (op) {
                    case 1: result = A.unionSet(B); break;
                    case 2: result = A.intersectionSet(B); break;
                    case 3: result = A.differenceSet(B); break;
                    case 4: result = A.symmetricDifferenceSet(B); break;
                }

                result.show();
            }
            else if (op == 5) {
                cout << "Select a set (1-" << n << "): ";
                cin >> a;
                cin.ignore();

                if (a < 1 || a > n) {
                    cout << "Invalid index.\n";
                    continue;
                }

                auto& A = *sets[a - 1];
                auto result = A.complementSet(universe);
                result.show();
            }
            else if (op == 6) {
                cout << "\n=== Validations Menu ===\n";
                cout << "1. Check if A ⊆ B\n";
                cout << "2. Check if A ⊂ B\n";
                cout << "3. Check if A ≠̸ B\n";
                cout << "Select validation: ";
                int valOp;
                cin >> valOp;
                cin.ignore();

                cout << "Select first set (A) (1-" << n << "): ";
                cin >> a;
                cout << "Select second set (B) (1-" << n << "): ";
                cin >> b;
                cin.ignore();

                if (a < 1 || b < 1 || a > n || b > n) {
                    cout << "Invalid indices.\n";
                    continue;
                }

                auto& A = *sets[a - 1];
                auto& B = *sets[b - 1];

                switch (valOp) {
                    case 1:
                        cout << A.getName() << " ⊆ " << B.getName()
                            << "? " << (A.isSubsetOf(B) ? "Yes" : "No") << endl;
                        break;
                    case 2:
                        cout << A.getName() << " ⊂ " << B.getName()
                            << "? " << (A.isProperSubsetOf(B) ? "Yes" : "No") << endl;
                        break;
                    case 3:
                        cout << A.getName() << " ≠̸ " << B.getName()
                            << "? " << (A.isDisjointWith(B) ? "Yes" : "No") << endl;
                        break;
                    default:
                        cout << "Invalid option.\n";
                        break;
                }
            }

        } while (op != 0);
    }

    else {
        cout << "Invalid option.\n";
    }

    cout << "Exiting...\n";
    return 0;
}

void showSetTypeMenu() {
    cout << "\nSelect a set type:\n";
    cout << "1. Integers\n";
    cout << "2. Characters\n";
    cout << "3. Strings\n";
}

void showOperationMenu() {
    cout << "\n=== Set Operations ===\n";
    cout << "1. Union\n";
    cout << "2. Intersection\n";
    cout << "3. Difference\n";
    cout << "4. Symmetric Difference\n";
    cout << "5. Complement\n";
    cout << "6. Validations\n";
    cout << "0. Exit\n";
}