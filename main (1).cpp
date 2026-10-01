#include <iostream>
using namespace std;

struct Ponto {
    int x;
    int y;
};

template <typename T>
void trocar(T &a, T &b) {
    T aux = a;
    a = b;
    b = aux;
}

int main() {
    int a = 10;
    int b = 20;

    cout << "Antes: a = " << a << ", b = " << b << endl;

    trocar(a, b);

    cout << "Depois: a = " << a << ", b = " << b << endl;

    Ponto p1 = {1, 2};
    Ponto p2 = {3, 4};

    cout << "\nAntes:" << endl;
    cout << "p1 = (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "p2 = (" << p2.x << ", " << p2.y << ")" << endl;

    trocar(p1, p2);

    cout << "\nDepois:" << endl;
    cout << "p1 = (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "p2 = (" << p2.x << ", " << p2.y << ")" << endl;

    return 0;
}