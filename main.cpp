#include <iostream>
#include "Sets.h"

using namespace std;

int main(int argc, char** argv) {
    Sets<int> A("Set A");
    Sets<char> B("Set B");
    Sets<string> C("Set C");

    A.addElement(10);
    A.addElement(20);
    A.addElement(10);

    B.addElement('x');
    B.addElement('y');
    B.addElement('x');

    C.addElement("hello");
    C.addElement("world");
    C.addElement("world");

    cout << endl;
    A.show();
    B.show();
    C.show();

    return 0;
}