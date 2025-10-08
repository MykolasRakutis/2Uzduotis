#include "ivedimas.h"
#include "skaiciavimai.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::stringstream;
using std::stoi;

bool tikRaides(const string &s) {
    for (char c : s) {
        if (!isalpha(c)) return false;
    }
    return true;
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

    int n = pirmas.ndpaz.size();
    double vid;
    if (n > 0) vid = double(sum) / n;
    else vid = 0;
    pirmas.galutinis_vid = vid * 0.4 + pirmas.egzrez * 0.6;

    double med = MedSkaiciavimas(pirmas.ndpaz);
    pirmas.galutinis_med = med * 0.4 + pirmas.egzrez * 0.6;

    return pirmas;
}
