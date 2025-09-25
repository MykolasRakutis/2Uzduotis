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
    cout << "Vardas: ";
    cin >> pirmas.vardas;
    cout << "Pavarde: ";
    cin >> pirmas.pavarde;

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
                pirmas.ndpaz.push_back(laik_paz);
                sum += laik_paz;
            }
        }

        cout << "Iveskite egzamino rezultata: ";
        cin >> pirmas.egzrez;
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

int main()
{
    srand(time(0));
    vector<Studentas> Grupe;

    cout << "Sveiki!" << endl;
    cout << "Pasirinkite duomenu gavimo buda:\n";
    cout << "1. Vesti/generuoti patiems\n";
    cout << "2. Nuskaityti is failo (studentai.txt)\n";
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
        string failo_pav = "kursiokai.txt";
        ifstream fin(failo_pav);
        if (!fin) {
            cerr << "Nepavyko atidaryti failo: " << failo_pav << endl;
            return 1;
        }

        string eilute;
        getline(fin, eilute);
        while (getline(fin, eilute)) {
            if (!eilute.empty()) {
                Grupe.push_back(Failas(eilute));
            }
        }
    }
    sort(Grupe.begin(), Grupe.end(), [](const Studentas &a, const Studentas &b) {
    return a.pavarde < b.pavarde;
    });

    cout << "\nStudento informacija:" << endl;
    cout << left << setw(15) << "Pavarde"
         << "|" << left << setw(20) << "Vardas"
         << "|" << left << setw(15) << "Galutinis(vid)"
         << "|" << left << setw(15) << "Galutinis(med)" << endl;
    cout << string(70, '-') << endl;

    for (const auto &Studentas : Grupe)
    {
        cout << left << setw(15) << Studentas.pavarde
             << "|" << left << setw(20) << Studentas.vardas
             << "|" << left << setw(15) << fixed << setprecision(2) << Studentas.galutinis_vid
             << "|" << left << setw(15) << fixed << setprecision(2) << Studentas.galutinis_med
             << endl;
    }

    return 0;
}
