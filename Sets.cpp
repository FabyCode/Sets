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

template <typename T>
Sets<T> Sets<T>::unionSet(const Sets<T>& other) const {
    Sets<T> result("Union(" + name + "," + other.name + ")");
    for (const auto& e : elements)
        result.addElement(e);
    for (const auto& e : other.getElements())
        if (!result.elementExists(e))
            result.addElement(e);
    return result;
}

template <typename T>
Sets<T> Sets<T>::intersectionSet(const Sets<T>& other) const {
    Sets<T> result("Inter(" + name + "," + other.name + ")");
    for (const auto& e : elements)
        if (other.elementExists(e))
            result.addElement(e);
    return result;
}

// --------------------------------------------------------------
// ESTA FUNCIÓN TIENE BUGS Y NECESITA CORREGIRSE A LA BREVEDAD!!!
// --------------------------------------------------------------
template <typename T>
Sets<T> Sets<T>::differenceSet(const Sets<T>& other) const {
    Sets<T> result("Diff(" + name + "," + other.name + ")");
    for (const auto& e : elements)
        if (!other.elementExists(e))
            result.addElement(e);
    return result;
}

template <typename T>
Sets<T> Sets<T>::symmetricDifferenceSet(const Sets<T>& other) const {
    Sets<T> result("SymDiff(" + name + "," + other.name + ")");
    for (const auto& e : elements)
        if (!other.elementExists(e))
            result.addElement(e);
    for (const auto& e : other.getElements())
        if (!elementExists(e))
            result.addElement(e);
    return result;
}

template <typename T>
Sets<T> Sets<T>::complementSet(const Sets<T>& universe) const {
    Sets<T> result("Comp(" + name + ")");
    for (const auto& e : universe.getElements())
        if (!elementExists(e))
            result.addElement(e);
    return result;
}