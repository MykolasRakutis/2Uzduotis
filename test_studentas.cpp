#include "Studentas.h"
#include "skaiciavimai.h"
#include <iostream>
#include <sstream>
#include <cmath>

using std::cout;
using std::endl;

int testai_praejo = 0;
int testai_nepraeio = 0;

bool arArtimas(double a, double b, double epsilon = 0.01) {
    return std::abs(a - b) < epsilon;
}

void TIKRINTI(bool salyga, const std::string& aprasymas) {
    if (salyga) {
        cout << "[PASS] " << aprasymas << endl;
        testai_praejo++;
    } else {
        cout << "[FAIL] " << aprasymas << endl;
        testai_nepraeio++;
    }
}

void test_galutinio_vidurkio() {
    cout << "\n=== Testas 1: Galutinio vidurkio skaiciavimas ===" << endl;
    vector<int> pazymiai = {8, 9, 10};
    Studentas s("Jonaitis", "Jonas", pazymiai, 10);
    TIKRINTI(arArtimas(s.galutinis_vid(), 9.6), "Galutinis vidurkis 9.6");
    cout << "   Gauta: " << s.galutinis_vid() << endl;
}

void test_medianos() {
    cout << "\n=== Testas 2: Medianos skaiciavimas ===" << endl;
    vector<int> pazymiai = {5, 7, 9};
    double mediana = MedSkaiciavimas(pazymiai);
    TIKRINTI(mediana == 7, "Mediana = 7");
    cout << "   Gauta: " << mediana << endl;
}

void test_vardu_validacijos() {
    cout << "\n=== Testas 3: Vardu validacija ===" << endl;
    Studentas s;
    s.setVardas("Jonas123");
    TIKRINTI(s.vardas() == "", "Vardas su skaiciais atmestas");
    s.setVardas("Jonas");
    TIKRINTI(s.vardas() == "Jonas", "Teisingas vardas priimtas");
}

void test_palyginimo() {
    cout << "\n=== Testas 4: Studentu palyginimas ===" << endl;
    vector<int> paz = {8};
    Studentas s1("Adomaitis", "Jonas", paz, 8);
    Studentas s2("Zukauskas", "Petras", paz, 8);
    TIKRINTI(s1 < s2, "Adomaitis < Zukauskas");
}

void test_nuskaitymo() {
    cout << "\n=== Testas 5: Nuskaitymas is srauto ===" << endl;
    std::stringstream ss("Jonaitis Jonas 8 9 7 10 -1");
    Studentas s;
    s.readStudent(ss);
    TIKRINTI(s.pavarde() == "Jonaitis", "Pavarde = Jonaitis");
    TIKRINTI(s.vardas() == "Jonas", "Vardas = Jonas");
    TIKRINTI(s.egzrez() == 10, "Egzaminas = 10");
    TIKRINTI(s.ndpaz().size() == 3, "3 ND pazymiai");
}

int main() {
    cout << "\n===========================================" << endl;
    cout << "     STUDENTU SISTEMOS UNIT TESTAI" << endl;
    cout << "===========================================\n" << endl;
    
    test_galutinio_vidurkio();
    test_medianos();
    test_vardu_validacijos();
    test_palyginimo();
    test_nuskaitymo();
    
    cout << "\n===========================================" << endl;
    cout << "           TESTU REZULTATAI" << endl;
    cout << "===========================================" << endl;
    cout << "PRAEJO:   " << testai_praejo << endl;
    cout << "NEPRAEIO: " << testai_nepraeio << endl;
    cout << "-------------------------------------------" << endl;
    cout << "IS VISO:  " << (testai_praejo + testai_nepraeio) << endl;
    cout << "===========================================\n" << endl;
    
    return (testai_nepraeio == 0) ? 0 : 1;
}