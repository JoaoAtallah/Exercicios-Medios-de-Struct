#include <iostream>
using namespace std;

template <typename T>
T maior(T vetor[], int N) {
    T maiorValor = vetor[0];

    for (int i = 1; i < N; i++) {
        if (vetor[i] > maiorValor) {
            maiorValor = vetor[i];
        }
    }

    return maiorValor;
}

int main() {
    float notas[30];

    for (int i = 0; i < 30; i++) {
        cout << "Digite a nota do aluno " << i + 1 << ": ";

        while (!(cin >> notas[i])) {
            cout << "Digite uma nota valida: ";

            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    cout << "\nMaior nota: " << maior(notas, 30) << endl;

    return 0;
}