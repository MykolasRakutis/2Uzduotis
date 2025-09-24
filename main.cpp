#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

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

    int n = pirmas.ndpaz.size();
    double vid;
    if (n > 0)
        vid = double(sum) / n;
    else
        vid = 0;

    pirmas.galutinis_vid = vid * 0.4 + pirmas.egzrez * 0.6;

    double med = MedSkaiciavimas(pirmas.ndpaz);
    pirmas.galutinis_med = med * 0.4 + pirmas.egzrez * 0.6;

    return pirmas;
}

int main()
{
    cout << "Laba diena" << endl;
    vector<Studentas> Grupe;
    int m;

    cout << "Kiek studentu grupeje?: ";
    cin >> m;
    cin.ignore(1000, '\n');

    for (int z = 0; z < m; z++)
    {
        Grupe.push_back(Stud_ivestis(z + 1));
    }

    cout << "\nStudento informacija:" << endl;
    cout << left << setw(15) << "Vardas"
         << "|" << left << setw(20) << "Pavarde"
         << "|" << left << setw(15) << "Galutinis(vid)"
         << "|" << left << setw(15) << "Galutinis(med)" << endl;
    cout << string(70, '-') << endl;

    for (const auto &Studentas : Grupe)
    {
        cout << left << setw(15) << Studentas.vardas
             << "|" << left << setw(20) << Studentas.pavarde
             << "|" << left << setw(15) << fixed << setprecision(2) << Studentas.galutinis_vid
             << "|" << left << setw(15) << fixed << setprecision(2) << Studentas.galutinis_med
             << endl;
    }

    return 0;
}
