#include <iostream>
#include <string>
using namespace std;

struct Livro {
    string titulo;
    string autor;
    int paginas;
};

int contaLivros(Livro livros[], int quantidade, int numeroPaginas) {
    int contador = 0;

    for (int i = 0; i < quantidade; i++) {
        if (livros[i].paginas > numeroPaginas) {
            contador++;
        }
    }

    return contador;
}

int main() {
    Livro livros[15];

    // Preenchendo os 15 livros
    for (int i = 0; i < 15; i++) {
        cout << "Livro " << i + 1 << endl;

        cout << "Titulo: ";
        getline(cin, livros[i].titulo);

        cout << "Autor: ";
        getline(cin, livros[i].autor);

        cout << "Paginas: ";
        cin >> livros[i].paginas;
        cin.ignore();
    }

    int numeroPaginas;
    cout << "\nDigite um numero de paginas: ";
    cin >> numeroPaginas;

    int resultado = contaLivros(livros, 15, numeroPaginas);

    cout << "\nQuantidade de livros com mais de "
         << numeroPaginas << " paginas: " << resultado << endl;

    return 0;
}