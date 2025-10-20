#ifndef SETS_H
#define SETS_H

#include <string>
#include <vector>
using namespace std;

template <typename T>
class Sets 
{
private:
    string name;
    vector<T> elements;

public:
    Sets(string name);
    bool elementExists(const T& elem) const;
    void addElement(const T& elem);
    void show() const;
    
    Sets<T> unionSet(const Sets<T>& other) const;
    Sets<T> intersectionSet(const Sets<T>& other) const;
    Sets<T> differenceSet(const Sets<T>& other) const;
    Sets<T> symmetricDifferenceSet(const Sets<T>& other) const;
    Sets<T> complementSet(const Sets<T>& universe) const;

    const vector<T>& getElements() const { return elements; }
    string getName() const { return name; }
};

#include "Sets.cpp"

#endif /* SETS_h */