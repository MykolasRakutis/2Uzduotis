#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;

struct Studentas
{
    string vardas;
    string pavarde;
    vector <int> ndpaz;
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
    {
        return (paz[pazsk / 2 - 1] + paz[pazsk / 2]) / 2.0;
    } else {
        return paz[pazsk / 2];
    }
}


Studentas Stud_ivestis(int nr)
{
    int n, laik_paz, sum = 0;
    Studentas pirmas;
    cout << "\nIveskite " << nr << "-ojo studento duomenis" << endl;
    cout << "Vardas ";
    cin >> pirmas.vardas;
    cout << "Pavarde: ";
    cin >> pirmas.pavarde;
    cout << "Kiek namu darbu jis turi? ";
    cin >> n;

    for (int a = 0; a < n; a++)
    {
        cout << a + 1 << ": ";
        cin >> laik_paz;
        pirmas.ndpaz.push_back(laik_paz);
        sum += laik_paz;
    }

    cout << "Iveskite egzamino rezultata: ";
    cin >> pirmas.egzrez;
    pirmas.galutinis_vid = double(sum) / double(n) * 0.4 + pirmas.egzrez * 0.6;
    double med = MedSkaiciavimas(pirmas.ndpaz);
    pirmas.galutinis_med = med * 0.4 + pirmas.egzrez * 0.6;
    return pirmas;
}

int main()
{
    cout << "Laba diena" << endl;
    vector<Studentas> Grupe;
    cout << "Kiek studentu grupeje?: ";
    int m;
    cin >> m;

    for (auto z = 0; z < m; z++)
    {
        Grupe.push_back(Stud_ivestis(z+1));
    }

    cout << "\nStudento informacija:" << endl;
    cout << left << setw(15) << "Vardas"
         << "|" << left << setw(20) << "Pavarde"
         << "|" << left << setw(15) << "Galutinis(vid)"
         << "|" << left << setw(15) << "Galutinis(med)" << endl;
    cout << string(65, '-') << endl;

    for (const auto &Studentas : Grupe) {
        cout << left << setw(15) << Studentas.vardas
             << "|" << left << setw(20) << Studentas.pavarde
             << "|" << left << setw(15) << fixed << setprecision(2) << Studentas.galutinis_vid
             << "|" << left << setw(15) << fixed << setprecision(2) << Studentas.galutinis_med
             << endl;
    }

    return 0;
}
