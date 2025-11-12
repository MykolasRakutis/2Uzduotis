#include "isvedimas.h"
#include "skaiciavimai.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <iterator>

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

void IsvedimasIFaila(const std::vector<Studentas> &grupe, int rezultatoTipas) {
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
        fout << left << setw(15) << studentas.pavarde()
             << "|" << left << setw(20) << studentas.vardas();

        if (rezultatoTipas == 1 || rezultatoTipas == 3)
            fout << "|" << left << setw(15) << fixed << setprecision(2) << studentas.galutinis_vid();
        if (rezultatoTipas == 2 || rezultatoTipas == 3)
            fout << "|" << left << setw(15) << fixed << setprecision(2) << studentas.galutinis_med();

        fout << endl;
    }

    fout.close();
    cout << "\nRezultatai sekmingai irasyti i faila rezultatai.txt" << endl;
}

void IsvedimasIKonsole(const std::vector<Studentas> &grupe, int rezultatoTipas) {
    cout << "\n" << left << setw(15) << "Pavarde"
         << left << setw(20) << "Vardas";

    if (rezultatoTipas == 1 || rezultatoTipas == 3)
        cout << left << setw(20) << "Galutinis(vid)";
    if (rezultatoTipas == 2 || rezultatoTipas == 3)
        cout << left << setw(20) << "Galutinis(med)";

    cout << endl;
    cout << string(70, '-') << endl;

    for (const auto &studentas : grupe) {
        cout << left << setw(15) << studentas.pavarde()
             << left << setw(20) << studentas.vardas();

        if (rezultatoTipas == 1 || rezultatoTipas == 3)
            cout << left << setw(20) << fixed << setprecision(2) << studentas.galutinis_vid();
        if (rezultatoTipas == 2 || rezultatoTipas == 3)
            cout << left << setw(20) << fixed << setprecision(2) << studentas.galutinis_med();

        cout << endl;
    }
    cout << "...\n" << endl;
}

void Strategija1(std::vector<Studentas> &grupe, bool naudotiVidurki,
                 std::vector<Studentas> &vargsiukai, std::vector<Studentas> &kietiakiai) {
    for (const auto &st : grupe) {
        double galutinis = naudotiVidurki ? st.galutinis_vid() : st.galutinis_med();

        if (galutinis < 5.0) {
            vargsiukai.push_back(st);
        } else {
            kietiakiai.push_back(st);
        }
    }
}

void Strategija2(std::vector<Studentas> &grupe, bool naudotiVidurki,
                 std::vector<Studentas> &vargsiukai) {
    auto it = grupe.begin();
    while (it != grupe.end()) {
        double galutinis = naudotiVidurki ? it->galutinis_vid() : it->galutinis_med();
        if (galutinis < 5.0) {
            vargsiukai.push_back(*it);
            it = grupe.erase(it);
        } else {
            ++it;
        }
    }
}

void Strategija3(std::vector<Studentas> &grupe, bool naudotiVidurki,
                 std::vector<Studentas> &vargsiukai) {
    auto arKietiakas = [naudotiVidurki](const Studentas &st) {
        double galutinis = naudotiVidurki ? st.galutinis_vid() : st.galutinis_med();
        return galutinis >= 5.0;
    };
    auto partition_point = std::partition(grupe.begin(), grupe.end(), arKietiakas);

    vargsiukai.assign(std::make_move_iterator(partition_point),
                      std::make_move_iterator(grupe.end()));

    grupe.erase(partition_point, grupe.end());
}

void SkirstymasIFailus(std::vector<Studentas> &grupe, int skirstymoTipas, int strategija,
                       double &rusiavimolaikas, double &isvedimolaikas,
                       double &vargsiukuLaikas, double &kietiakiuLaikas) {
    bool naudotiVidurki = (skirstymoTipas == 1);

    auto startRusiavimas = std::chrono::high_resolution_clock::now();

    std::vector<Studentas> vargsiukai;
    std::vector<Studentas> kietiakiai;

    if (strategija == 1) {
        Strategija1(grupe, naudotiVidurki, vargsiukai, kietiakiai);
    } else if (strategija == 2) {
        Strategija2(grupe, naudotiVidurki, vargsiukai);
        kietiakiai = grupe;
    } else if (strategija == 3) {
        Strategija3(grupe, naudotiVidurki, vargsiukai);
        kietiakiai = grupe;
    }

    auto rikiavimasPagalBala = [naudotiVidurki](const Studentas &a, const Studentas &b) {
        double a_balas = naudotiVidurki ? a.galutinis_vid() : a.galutinis_med();
        double b_balas = naudotiVidurki ? b.galutinis_vid() : b.galutinis_med();
        return a_balas > b_balas;
    };

    sort(vargsiukai.begin(), vargsiukai.end(), rikiavimasPagalBala);
    sort(kietiakiai.begin(), kietiakiai.end(), rikiavimasPagalBala);

    auto endRusiavimas = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffRusiavimas = endRusiavimas - startRusiavimas;
    rusiavimolaikas = diffRusiavimas.count();

    string stulpelioPav = naudotiVidurki ? "Galutinis(vid)" : "Galutinis(med)";

    auto spausdinti = [&](ofstream &f, const std::vector<Studentas> &grupe) {
        f << left << setw(15) << "Pavarde"
          << "|" << left << setw(20) << "Vardas"
          << "|" << left << setw(15) << stulpelioPav << endl;
        f << string(55, '-') << endl;

        for (const auto &st : grupe) {
            double balas = naudotiVidurki ? st.galutinis_vid() : st.galutinis_med();

            f << left << setw(15) << st.pavarde()
              << "|" << left << setw(20) << st.vardas()
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

    cout << "\nSukurti failai: vargsiukai.txt ir kietiakiai.txt" << endl;
}
