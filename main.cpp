#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::fixed;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<int> ndpaz;
    int egzrez;
    double galutinis_vid;
    double galutinis_med;
};

bool tikRaides(const string &s) {
    for (char c : s) {
        if (!isalpha(c)) return false;
    }
    return true;
}


double MedSkaiciavimas(vector<int> paz)
{
    sort(paz.begin(), paz.end());
    int pazsk = paz.size();
    if (pazsk == 0) return 0;

    if (pazsk % 2 == 0)
        return (paz[pazsk / 2 - 1] + paz[pazsk / 2]) / 2.0;
    else
        return paz[pazsk / 2];
}

Studentas Stud_ivestis(int nr)
{
    int laik_paz, sum = 0;
    string eilute;
    Studentas pirmas;

    cout << "\nIveskite " << nr << "-ojo studento duomenis" << endl;
    do {
        cout << "Vardas: ";
        cin >> pirmas.vardas;
        if (!tikRaides(pirmas.vardas)){
                cout << "Varde negali buti skaiciu ar simboliu\n";
        }
    }while (!tikRaides(pirmas.vardas));

    do {
        cout << "Pavarde: ";
        cin >> pirmas.pavarde;
        if (!tikRaides(pirmas.pavarde)) {
            cout << "Pavardeje negali buti skaiciu ar simboliu\n";
        }
    } while (!tikRaides(pirmas.pavarde));

    cin.ignore(1000, '\n');

    int pasirinkimas;
    cout << "\nPasirinkite duomenu ivedimo buda:\n";
    cout << "1. Ivesti rankiniu budu\n";
    cout << "2. Generuoti atsitiktinai\n";
    cout << "Jusu pasirinkimas: ";
    cin >> pasirinkimas;
    cin.ignore(1000, '\n');

    if (pasirinkimas == 2)
    {
        int kiek;
        cout << "Kiek namu darbu pazymiu generuoti?: ";
        cin >> kiek;
        cin.ignore(1000, '\n');

        cout << "Sugeneruoti namu darbu pazymiai: ";
        for (int i = 0; i < kiek; i++)
        {
            laik_paz = rand() % 11;
            pirmas.ndpaz.push_back(laik_paz);
            sum += laik_paz;
            cout << laik_paz << " ";
        }
        cout << endl;

        pirmas.egzrez = rand() % 11;
        cout << "Sugeneruotas egzamino rezultatas: " << pirmas.egzrez << endl;
    }
    else
    {
        cout << "Iveskite namu darbu pazymius (baigti tuscia eilute):" << endl;
while (true)
{
    getline(cin, eilute);
    if (eilute.empty()) break;

    stringstream ss(eilute);
    while (ss >> laik_paz)
    {
        if (laik_paz < 0 || laik_paz > 10) {
            cout << "Pazymys turi buti tarp 0 ir 10\n";
        } else {
            pirmas.ndpaz.push_back(laik_paz);
            sum += laik_paz;
        }
    }

    if (ss.fail() && !ss.eof()) {
        cout << "Pazymys turi buti skaicius\n";
        ss.clear();
    }
}
        while (true) {
            cout << "Iveskite egzamino rezultata: ";
            cin >> eilute;
            bool valid = true;
            for (char c : eilute) {
                if (!isdigit(c)) { valid = false; break; }
            }
            if (valid) {
                pirmas.egzrez = stoi(eilute);
                break;
            } else {
                cout << "Egzaminas turi buti skaicius\n";
            }
        }
        cin.ignore(1000, '\n');
    }

    int n = pirmas.ndpaz.size(); double vid; if (n > 0) vid = double(sum) / n; else vid = 0;
    pirmas.galutinis_vid = vid * 0.4 + pirmas.egzrez * 0.6;

    double med = MedSkaiciavimas(pirmas.ndpaz);
    pirmas.galutinis_med = med * 0.4 + pirmas.egzrez * 0.6;

    return pirmas;
}

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
        int sum=0;
        for (int x : s.ndpaz) sum += x;
        int n = s.ndpaz.size(); double vid; if (n > 0) vid = double(sum) / n; else vid = 0;

        s.galutinis_vid = vid * 0.4 + s.egzrez * 0.6;
        double med = MedSkaiciavimas(s.ndpaz);
        s.galutinis_med = med * 0.4 + s.egzrez * 0.6;
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

    cout << "Sveiki!" << endl;
    cout << "Pasirinkite duomenu gavimo buda:\n";
    cout << "1. Vesti/generuoti patiems\n";
    cout << "2. Nuskaityti is failo\n";
    cout << "Jusu pasirinkimas: ";
    int pasirinkimas;
    cin >> pasirinkimas;
    cin.ignore(1000, '\n');

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
    string failo_pav;
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

        string eilute;
        getline(fin, eilute);
        while (getline(fin, eilute)) {
            if (!eilute.empty()) {
                Grupe.push_back(Failas(eilute));
            }
        }
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

    ofstream fout("rezultatai.txt");
    if (!fout) {
        cerr << "Nepavyko sukurti failo rezultatai.txt" << endl;
        return 1;
    }

    fout << left << setw(15) << "Pavarde"
         << "|" << left << setw(20) << "Vardas";

    if (rezultatoTipas == 1 || rezultatoTipas == 3)
        fout << "|" << left << setw(15) << "Galutinis(vid)";
    if (rezultatoTipas == 2 || rezultatoTipas == 3)
        fout << "|" << left << setw(15) << "Galutinis(med)";

    fout << endl;
    fout << string(70, '-') << endl;

    for (const auto &Studentas : Grupe) {
        fout << left << setw(15) << Studentas.pavarde
             << "|" << left << setw(20) << Studentas.vardas;

        if (rezultatoTipas == 1 || rezultatoTipas == 3)
            fout << "|" << left << setw(15) << fixed << setprecision(2) << Studentas.galutinis_vid;
        if (rezultatoTipas == 2 || rezultatoTipas == 3)
            fout << "|" << left << setw(15) << fixed << setprecision(2) << Studentas.galutinis_med;

        fout << endl;
    }

    fout.close();
    cout << "\nRezultatai sekmingai irasyti i faila rezultatai.txt" << endl;

    int skirstymoTipas;
    cout << "\nPasirinkite pagal ka skirstyti studentus i failus:\n";
    cout << "1. Pagal galutini vidurki\n";
    cout << "2. Pagal galutine mediana\n";
    cout << "Jusu pasirinkimas: ";
    cin >> skirstymoTipas;
    cin.ignore(1000, '\n');

    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;

    bool naudotiVidurki = (skirstymoTipas == 1);

    for (const auto &st : Grupe) {
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

    return 0;
}
