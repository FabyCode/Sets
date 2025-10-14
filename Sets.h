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
    //int interseccion(int num);
};

#include "Sets.cpp"

#endif /* SETS_h */