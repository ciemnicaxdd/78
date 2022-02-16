
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


string skrotZopisem(string wiadomosc) {
    int S[8] = { int('A'), int('L'), int('G'), int('O'), int('R'), int('Y'), int('T'), int('M') };

    int length = wiadomosc.length();
    int rest = length % 8;
    
    for (int i = 0; i < 8-rest; i++) {
        wiadomosc += ".";
    }
    length = wiadomosc.length();
    for (int i = 0; i < length; i++) {
        S[i % 8] = (S[i % 8] + int(wiadomosc[i])) % 128;
    }
    for (int j = 0; j < 8; j++) {
        cout << S[j] << " ";
    }
    cout << endl;
    cout << wiadomosc.length()<<endl;
    string wynik = "";
    for (int i = 0; i < 8; i++) {
        wynik += char(65 + S[i] % 26);
    }
    return wynik;
}

string skrot(string wiadomosc) {
    int S[8] = { int('A'), int('L'), int('G'), int('O'), int('R'), int('Y'), int('T'), int('M') };

    int length = wiadomosc.length();
    int rest = length % 8;

    for (int i = 0; i < 8 - rest; i++) {
        wiadomosc += ".";
    }
    length = wiadomosc.length();
    for (int i = 0; i < length; i++) {
        S[i % 8] = (S[i % 8] + int(wiadomosc[i])) % 128;
    }
    string wynik = "";
    for (int i = 0; i < 8; i++) {
        wynik += char(65 + S[i] % 26);
    }
    return wynik;
}

string deszyfr(int d, int n, int szyfr[8]) {
    string wynik ="";
    for (int i = 0; i < 8; i++) {
        wynik += char(szyfr[i] * d % n);
    }
    return wynik;
}

int main()
{
    ifstream fIn1;
    ifstream fIn2;
    ofstream fOut;

    fIn1.open("C:\\podpisy.txt");
    fIn2.open("C:\\wiadomosci.txt");
    fOut.open("C:\\epodpis_wynik.txt");
    string napis1;

    getline(fIn2, napis1);
    fIn2.close();
    fIn2.open("C:\\wiadomosci.txt");
    cout << skrotZopisem(napis1)<<endl;
    cout << endl;
    for (int i = 0; i < 11; i++) {
        int tab[8];
        string napis;
        getline(fIn2, napis);
        for (int j = 0; j < 8; j++) {
            int temp;
            fIn1 >> temp;
            tab[j] = temp;
        }
        cout << deszyfr(3, 200, tab)<<endl;  
    }
    fIn1.close();
    fIn2.close();
    fIn1.open("C:\\podpisy.txt");
    fIn2.open("C:\\wiadomosci.txt");
    cout << endl;
    for (int i = 0; i < 11; i++) {
        int tab[8];
        string napis;
        getline(fIn2, napis);
        for (int j = 0; j < 8; j++) {
            int temp;
            fIn1 >> temp;
            tab[j] = temp;
        }

        if (deszyfr(3, 200, tab) == skrot(napis)) {
            cout << i + 1 << endl;
        }
    }
    
}
