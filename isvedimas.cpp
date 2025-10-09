#include "isvedimas.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <chrono>

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

void SkirstymasIFailus(vector<Studentas> &grupe, int skirstymoTipas, double &rusiavimolaikas, double &isvedimolaikas, double &vargsiukuLaikas, double &kietiakiuLaikas) {
    bool naudotiVidurki = (skirstymoTipas == 1);

    auto startRusiavimas = std::chrono::high_resolution_clock::now();

    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;

    vargsiukai.reserve(grupe.size() / 2);
    kietiakiai.reserve(grupe.size() / 2);

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

    auto endRusiavimas = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffRusiavimas = endRusiavimas - startRusiavimas;
    rusiavimolaikas = diffRusiavimas.count();

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

    auto startIsvedimas = std::chrono::high_resolution_clock::now();

    auto startVargsiukai = std::chrono::high_resolution_clock::now();
    ofstream foutV("vargsiukai.txt");
    if (!foutV) {
        cerr << "Nepavyko sukurti failo vargsiukai.txt" << endl;
        return;
    }
    spausdinti(foutV, vargsiukai);
    foutV.close();
    auto endVargsiukai = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffVargsiukai = endVargsiukai - startVargsiukai;
    vargsiukuLaikas = diffVargsiukai.count();

    auto startKietiakiai = std::chrono::high_resolution_clock::now();
    ofstream foutK("kietiakiai.txt");
    if (!foutK) {
        cerr << "Nepavyko sukurti failo kietiakiai.txt" << endl;
        return;
    }
    spausdinti(foutK, kietiakiai);
    foutK.close();
    auto endKietiakiai = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffKietiakiai = endKietiakiai - startKietiakiai;
    kietiakiuLaikas = diffKietiakiai.count();

    auto endIsvedimas = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffIsvedimas = endIsvedimas - startIsvedimas;
    isvedimolaikas = diffIsvedimas.count();

}
