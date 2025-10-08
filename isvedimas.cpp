#include "isvedimas.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

using std::ofstream;
using std::cout;
using std::endl;
using std::cerr;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::string;
using std::sort;

void IsvedimasIFaila(const vector<Studentas> &grupe, int rezultatoTipas) {
    ofstream fout("rezultatai.txt");
    if (!fout) {
        cerr << "Nepavyko sukurti failo rezultatai.txt" << endl;
        return;
    }

    fout << left << setw(15) << "Pavarde"
         << "|" << left << setw(20) << "Vardas";

    if (rezultatoTipas == 1 || rezultatoTipas == 3)
        fout << "|" << left << setw(15) << "Galutinis(vid)";
    if (rezultatoTipas == 2 || rezultatoTipas == 3)
        fout << "|" << left << setw(15) << "Galutinis(med)";

    fout << endl;
    fout << string(70, '-') << endl;

    for (const auto &studentas : grupe) {
        fout << left << setw(15) << studentas.pavarde
             << "|" << left << setw(20) << studentas.vardas;

        if (rezultatoTipas == 1 || rezultatoTipas == 3)
            fout << "|" << left << setw(15) << fixed << setprecision(2) << studentas.galutinis_vid;
        if (rezultatoTipas == 2 || rezultatoTipas == 3)
            fout << "|" << left << setw(15) << fixed << setprecision(2) << studentas.galutinis_med;

        fout << endl;
    }

    fout.close();
    cout << "\nRezultatai sekmingai irasyti i faila rezultatai.txt" << endl;
}

void SkirstymasIFailus(const vector<Studentas> &grupe, int skirstymoTipas) {
    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;

    bool naudotiVidurki = (skirstymoTipas == 1);

    for (const auto &st : grupe) {
        double galutinis;
        if (naudotiVidurki) {
            galutinis = st.galutinis_vid;
        } else {
            galutinis = st.galutinis_med;
        }

        if (galutinis < 5.0) {
            vargsiukai.push_back(st);
        } else {
            kietiakiai.push_back(st);
        }
    }

    auto rikiavimasPagalBala = [naudotiVidurki](const Studentas &a, const Studentas &b) {
        double a_balas, b_balas;
        if (naudotiVidurki) {
            a_balas = a.galutinis_vid;
            b_balas = b.galutinis_vid;
        } else {
            a_balas = a.galutinis_med;
            b_balas = b.galutinis_med;
        }
        return a_balas > b_balas;
    };

    sort(vargsiukai.begin(), vargsiukai.end(), rikiavimasPagalBala);
    sort(kietiakiai.begin(), kietiakiai.end(), rikiavimasPagalBala);

    ofstream foutV("vargsiukai.txt");
    ofstream foutK("kietiakiai.txt");

    string stulpelioPav;
    if (naudotiVidurki) {
        stulpelioPav = "Galutinis(vid)";
    } else {
        stulpelioPav = "Galutinis(med)";
    }

    auto spausdinti = [&](ofstream &f, const vector<Studentas> &grupe) {
        f << left << setw(15) << "Pavarde"
          << "|" << left << setw(20) << "Vardas"
          << "|" << left << setw(15) << stulpelioPav << endl;
        f << string(55, '-') << endl;

        for (const auto &st : grupe) {
            double balas;
            if (naudotiVidurki) {
                balas = st.galutinis_vid;
            } else {
                balas = st.galutinis_med;
            }

            f << left << setw(15) << st.pavarde
              << "|" << left << setw(20) << st.vardas
              << "|" << left << setw(15) << fixed << setprecision(2) << balas
              << endl;
        }
    };

    spausdinti(foutV, vargsiukai);
    spausdinti(foutK, kietiakiai);

    foutV.close();
    foutK.close();

    cout << "\nSukurti failai: vargsiukai.txt ir kietiakiai.txt (skirstyta pagal ";
    if (naudotiVidurki) {
        cout << "vidurki";
    } else {
        cout << "mediana";
    }
    cout << ")" << endl;
}
