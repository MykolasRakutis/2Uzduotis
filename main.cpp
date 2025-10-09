#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "studentas.h"
#include "ivedimas.h"
#include "failai.h"
#include "isvedimas.h"
#include <chrono>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::getline;
using std::sort;
using std::setprecision;
using std::fixed;
using std::setw;
using std::left;

int main()
{
    srand(time(0));
    int kurti;
    cout << "Ar norite sugeneruoti 5 studentu failus? (1 - Taip, 0 - Ne): ";
    cin >> kurti;
    cin.ignore(1000, '\n');

    if (kurti == 1) {
        GeneruotiFaila("studentai_1000.txt", 1000);
        GeneruotiFaila("studentai_10000.txt", 10000);
        GeneruotiFaila("studentai_100000.txt", 100000);
        GeneruotiFaila("studentai_1000000.txt", 1000000);
        GeneruotiFaila("studentai_10000000.txt", 10000000);
    }

    vector<Studentas> Grupe;

    cout << "\nSveiki!" << endl;
    cout << "Pasirinkite duomenu gavimo buda:\n";
    cout << "1. Vesti/generuoti patiems\n";
    cout << "2. Nuskaityti is failo\n";
    cout << "Jusu pasirinkimas: ";
    int pasirinkimas;
    cin >> pasirinkimas;
    cin.ignore(1000, '\n');

    double skaitymolaikas = 0;
    double rusiavimolaikas = 0;
    double isvedimolaikas = 0;
    string failo_pav;

    if (pasirinkimas == 1) {
        int m;
        cout << "Kiek studentu yra grupeje?: ";
        cin >> m;
        cin.ignore(1000, '\n');

        for (int z = 0; z < m; z++)
        {
            Grupe.push_back(Stud_ivestis(z + 1));
        }
    }
    else if (pasirinkimas == 2) {
        ifstream fin;

        while (true) {
            cout << "Iveskite failo pavadinima (pvz.: studentai_1000.txt): ";
            cin >> failo_pav;
            fin.open(failo_pav);
            if (!fin) {
                cout << "Nepavyko atidaryti failo: " << failo_pav << ". Bandykite dar karta.\n";
                fin.clear();
            } else {
                break;
            }
        }

        auto startSkaitymas = std::chrono::high_resolution_clock::now();

        string eilute;
        getline(fin, eilute);
        while (getline(fin, eilute)) {
            if (!eilute.empty()) {
                Grupe.push_back(Failas(eilute));
            }
        }
        fin.close();

        auto endSkaitymas = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diffSkaitymas = endSkaitymas - startSkaitymas;
        skaitymolaikas = diffSkaitymas.count();
    }

    int rusiavimas;
    cout << "\nPasirinkite rusiavimo kriteriju:\n";
    cout << "1. Pagal pavarde\n";
    cout << "2. Pagal varda\n";
    cout << "Jusu pasirinkimas: ";
    cin >> rusiavimas;
    cin.ignore(1000, '\n');

    if (rusiavimas == 1) {
        sort(Grupe.begin(), Grupe.end(), [](const Studentas &a, const Studentas &b) {
            if (a.pavarde == b.pavarde)
                return a.vardas < b.vardas;
            return a.pavarde < b.pavarde;
        });
    } else if (rusiavimas == 2) {
        sort(Grupe.begin(), Grupe.end(), [](const Studentas &a, const Studentas &b) {
            if (a.vardas == b.vardas)
                return a.pavarde < b.pavarde;
            return a.vardas < b.vardas;
        });
    }

    int rezultatoTipas;
    cout << "\nPasirinkite kokius galutinius rezultatus isvesti:\n";
    cout << "1. Tik su vidurkiu\n";
    cout << "2. Tik su mediana\n";
    cout << "3. Abu\n";
    cout << "Jusu pasirinkimas: ";
    cin >> rezultatoTipas;
    cin.ignore(1000, '\n');

    IsvedimasIFaila(Grupe, rezultatoTipas);

    int skirstymoTipas;
    cout << "\nPasirinkite pagal ka skirstyti studentus i failus:\n";
    cout << "1. Pagal galutini vidurki\n";
    cout << "2. Pagal galutine mediana\n";
    cout << "Jusu pasirinkimas: ";
    cin >> skirstymoTipas;
    cin.ignore(1000, '\n');

    SkirstymasIFailus(Grupe, skirstymoTipas, rusiavimolaikas, isvedimolaikas);

    if (pasirinkimas == 2) {

 double bendrasLaikas = skaitymolaikas + rusiavimolaikas + isvedimolaikas;

        cout << "\nFailo " << failo_pav << " irasu nuskaitymo laikas: "
             << fixed << setprecision(6) << skaitymolaikas << endl;
        cout << "Failo " << failo_pav << " irasu dalijimo i dvigrupes laikas, panaikinant pradini vektore: "
             << fixed << setprecision(6) << rusiavimolaikas << endl;
        cout << "Failo " << failo_pav << " irasu nelaimingy irasymo i faila laikas: "
             << fixed << setprecision(6) << isvedimolaikas << endl;
        cout << "Bendras laikas: " << fixed << setprecision(6) << bendrasLaikas << endl;
    }

    return 0;
}
