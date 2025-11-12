#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::istream;
using std::ostream;

class Studentas {
private:
    string vardas_;
    string pavarde_;
    vector<int> ndpaz_;
    int egzrez_;
    double galutinis_vid_;
    double galutinis_med_;

    bool arValidusPazymys(int paz) const;

    friend Studentas Failas(std::string eilute);

public:

    Studentas();
    Studentas(const string& pavarde, const string& vardas,
              const vector<int>& ndpaz, int egzrez);
    Studentas(istream& is);

    inline string vardas() const { return vardas_; }
    inline string pavarde() const { return pavarde_; }
    inline vector<int> ndpaz() const { return ndpaz_; }
    inline int egzrez() const { return egzrez_; }
    inline double galutinis_vid() const { return galutinis_vid_; }
    inline double galutinis_med() const { return galutinis_med_; }

    void setVardas(const string& vardas);
    void setPavarde(const string& pavarde);
    void setNdpaz(const vector<int>& ndpaz);
    void setEgzrez(int egzrez);

    istream& readStudent(istream& is);
    void skaiciuotiGalutinius();

    friend bool comparePagalPavarde(const Studentas& a, const Studentas& b);
    friend bool comparePagalVarda(const Studentas& a, const Studentas& b);
    friend bool comparePagalBala(const Studentas& a, const Studentas& b, bool);
    friend ostream& operator<<(ostream& os, const Studentas& st);
};

bool comparePagalPavarde(const Studentas& a, const Studentas& b);
bool comparePagalVarda(const Studentas& a, const Studentas& b);
bool comparePagalBala(const Studentas& a, const Studentas& b, bool naudotiVidurki = true);

#endif
