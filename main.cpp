#include <iostream>
using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

bool bissexto(int ano) {
    if (ano % 400 == 0)
        return true;
    if (ano % 100 == 0)
        return false;
    if (ano % 4 == 0)
        return true;

    return false;
}

bool dataValida(Data data) {

    if (data.ano <= 0 || data.mes < 1 || data.mes > 12)
        return false;

    int diasNoMes;

    if (data.mes == 1 || data.mes == 3 || data.mes == 5 ||
        data.mes == 7 || data.mes == 8 || data.mes == 10 ||
        data.mes == 12) {
        diasNoMes = 31;
    }
    
    else if (data.mes == 2) {
        if (bissexto(data.ano))
            diasNoMes = 29;
        else
            diasNoMes = 28;
    }
    else {
        diasNoMes = 30;
    }

    if (data.dia >= 1 && data.dia <= diasNoMes)
        return true;

    return false;
}

int main() {
    Data data;

    cout << "Digite o dia: ";
    cin >> data.dia;

    cout << "Digite o mes: ";
    cin >> data.mes;

    cout << "Digite o ano: ";
    cin >> data.ano;

    if (dataValida(data))
        cout << "Data valida!" << endl;
    else
        cout << "Data invalida!" << endl;

    return 0;
}