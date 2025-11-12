#include "ivedimas.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

bool tikRaides(const string &s) {
    for (char c : s) {
        if (!isalpha(c)) return false;
    }
    return true;
}

Studentas Stud_ivestis(int nr)
{
    string vardas_temp, pavarde_temp;
    Studentas st;

    cout << "\nIveskite " << nr << "-ojo studento duomenis" << endl;

    do {
        cout << "Vardas: ";
        cin >> vardas_temp;
        if (!tikRaides(vardas_temp)) {
            cout << "Varde negali buti skaiciu ar simboliu\n";
        }
    } while (!tikRaides(vardas_temp));

    do {
        cout << "Pavarde: ";
        cin >> pavarde_temp;
        if (!tikRaides(pavarde_temp)) {
            cout << "Pavardeje negali buti skaiciu ar simboliu\n";
        }
    } while (!tikRaides(pavarde_temp));

    st.setVardas(vardas_temp);
    st.setPavarde(pavarde_temp);
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

        vector<int> pazymiai;
        cout << "Sugeneruoti namu darbu pazymiai: ";
        for (int i = 0; i < kiek; i++)
        {
            int paz = rand() % 11;
            pazymiai.push_back(paz);
            cout << paz << " ";
        }
        cout << endl;

        st.setNdpaz(pazymiai);

        int egz = rand() % 11;
        st.setEgzrez(egz);
        cout << "Sugeneruotas egzamino rezultatas: " << egz << endl;
    }
    else
    {
        cout << "Iveskite namu darbu pazymius (baigti -1):" << endl;
        vector<int> pazymiai;
        int paz;
        while (cin >> paz && paz != -1) {
            if (paz < 0 || paz > 10) {
                cout << "Pazymys turi buti tarp 0 ir 10\n";
            } else {
                pazymiai.push_back(paz);
            }
        }
        st.setNdpaz(pazymiai);
        cin.ignore(1000, '\n');

        cout << "Iveskite egzamino rezultata: ";
        cin >> paz;
        st.setEgzrez(paz);
        cin.ignore(1000, '\n');
    }

    return st;
}
