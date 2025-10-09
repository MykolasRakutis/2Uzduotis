#include "failai.h"
#include "skaiciavimai.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>

using std::stringstream;
using std::ofstream;
using std::cerr;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

Studentas Failas(string eilute)
{
    Studentas s;
    stringstream ss(eilute);
    ss >> s.pavarde >> s.vardas;

    int paz;
    vector<int> laikpaz;
    while (ss >> paz) laikpaz.push_back(paz);

    if (!laikpaz.empty()) {
        s.egzrez = laikpaz.back();
        laikpaz.pop_back();
        s.ndpaz = laikpaz;
        int sum = 0;
        for (int x : s.ndpaz) sum += x;
        int n = s.ndpaz.size();
        double vid;
        if (n > 0) vid = double(sum) / n;
        else vid = 0;

        s.galutinis_vid = vid * 0.4 + s.egzrez * 0.6;
        double med = MedSkaiciavimas(s.ndpaz);
        s.galutinis_med = med * 0.4 + s.egzrez * 0.6;
    }
    return s;
}

void GeneruotiFaila(const string &failo_pav, int kiekis) {
    auto start = std::chrono::high_resolution_clock::now();

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

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    cout << "Failas sukurtas: " << failo_pav << " (" << kiekis << " irasu)" << endl;
    cout << "Sugaista laiko: " << fixed << setprecision(6) << diff.count() << " sekundziu" << endl << endl;
}
