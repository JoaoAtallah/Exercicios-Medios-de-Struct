#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

struct TData {
    int Dia;
    int Mes;
    int Ano;
};

struct Pessoa {
    string Nome;
    TData Nascimento;
};

void CriaData(TData &D) {
    D.Mes = 1 + (rand() % 12);
    D.Ano = 1940 + (rand() % 74);
    D.Dia = 1 + (rand() % 30);
}

bool Bissexto(int ano) {
    if (ano % 400 == 0)
        return true;

    if (ano % 100 == 0)
        return false;

    if (ano % 4 == 0)
        return true;

    return false;
}

bool DataValida(TData D) {

    if (D.Mes < 1 || D.Mes > 12)
        return false;

    if (D.Dia < 1)
        return false;

    int dias;

    if (D.Mes == 2) {
        if (Bissexto(D.Ano))
            dias = 29;
        else
            dias = 28;
    }
    else if (D.Mes == 4 || D.Mes == 6 ||
             D.Mes == 9 || D.Mes == 11) {
        dias = 30;
    }
    else {
        dias = 31;
    }

    if (D.Dia > dias)
        return false;

    return true;
}

int CalculaIdade(TData nascimento, int anoReferencia) {
    return anoReferencia - nascimento.Ano;
}


void ListaIdades(Pessoa pessoas[], int quantidade, int anoReferencia) {

    cout << "\n--- Nomes e idades ---\n";

    for (int i = 0; i < quantidade; i++) {
        int idade = CalculaIdade(pessoas[i].Nascimento, anoReferencia);

        cout << pessoas[i].Nome << " - "
             << idade << " anos" << endl;
    }
}

void ListaMaisVelhos(Pessoa pessoas[], int quantidade, int idade) {

    cout << "\n--- Pessoas com mais de "
         << idade << " anos ---\n";

    for (int i = 0; i < quantidade; i++) {

        int idadePessoa = 2026 - pessoas[i].Nascimento.Ano;

        if (idadePessoa > idade) {
            cout << pessoas[i].Nome << endl;
        }
    }
}

int main() {

    srand(time(NULL));

    Pessoa pessoas[10];
    int quantidade;
    int anoReferencia;
    int idade;

    cout << "Quantas pessoas deseja cadastrar (maximo 10)? ";
    cin >> quantidade;

    if (quantidade > 10)
        quantidade = 10;

    for (int i = 0; i < quantidade; i++) {

        cout << "\nDigite o nome da pessoa " << i + 1 << ": ";
        cin >> pessoas[i].Nome;
        
        do {
            CriaData(pessoas[i].Nascimento);
        } while (!DataValida(pessoas[i].Nascimento));

        cout << "Data gerada: "
             << pessoas[i].Nascimento.Dia << "/"
             << pessoas[i].Nascimento.Mes << "/"
             << pessoas[i].Nascimento.Ano << endl;
    }
    
    cout << "\nDigite o ano de referencia: ";
    cin >> anoReferencia;

    ListaIdades(pessoas, quantidade, anoReferencia);


    cout << "\nDigite uma idade: ";
    cin >> idade;

    ListaMaisVelhos(pessoas, quantidade, idade);

    return 0;
}