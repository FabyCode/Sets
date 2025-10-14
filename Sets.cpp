#include "Sets.h"

#include <iostream>

template <typename T>
Sets<T>::Sets(string name) {
    this->name = name;
}

template <typename T>
bool Sets<T>::elementExists(const T& elem) const {
    for (const auto& e : elements) {
        if (e == elem)
            return true;
    }
    return false;
}

template <typename T>
void Sets<T>::addElement(const T& elem) {
    if (!elementExists(elem)) {
        elements.push_back(elem);
    } else {
        cout << "Element '" << elem << "' already exists on " << name << endl;
    }
}

template <typename T>
void Sets<T>::show() const {
    cout << name << ": { ";
    for (const auto& e : elements)
        cout << e << ", ";
    cout << "}" << endl;
}

/*int Sets::interseccion(int n)
{
    return 0;
}
*/