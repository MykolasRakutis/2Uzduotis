#include "failai.h"
#include "skaiciavimai.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>

using std::stringstream;
using std::ofstream;
using std::cerr;
using std::cout;
using std::endl;

Studentas Failas(string eilute)
{
    stringstream ss(eilute);
    string pavarde, vardas;
    ss >> pavarde >> vardas;

    Studentas s;
    s.pavarde_ = pavarde;
    s.vardas_ = vardas;

    int paz;
    vector<int> laikpaz;
    while (ss >> paz) {
        laikpaz.push_back(paz);
    }

    if (!laikpaz.empty()) {
        int egzrez = laikpaz.back();
        laikpaz.pop_back();
        s.ndpaz_ = laikpaz;
        s.egzrez_ = egzrez;
        s.skaiciuotiGalutinius();
    }

    return s;
}

void GeneruotiFaila(const string &failo_pav, int kiekis) {
    ofstream fout(failo_pav);
    if (!fout) {
        cerr << "Nepavyko sukurti failo: " << failo_pav << endl;
        return;
    }

    fout << "Pavarde Vardas ND1 ND2 ND3 ND4 ND5 Egzaminas\n";

    for (int i = 1; i <= kiekis; ++i) {
        fout << "Pavarde" << i << " "
             << "Vardas" << i << " ";

        for (int j = 0; j < 5; ++j) {
            fout << rand() % 11 << " ";
        }

        fout << rand() % 11 << "\n";
    }

    fout.close();
    cout << "Failas sukurtas: " << failo_pav << " (" << kiekis << " irasu)" << endl;
}
