#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "Zmogus.h"
#include <vector>

using std::vector;
using std::istream;
using std::ostream;

class Studentas : public Zmogus {
private:
    vector<int> ndpaz_;
    int egzrez_;
    double galutinis_vid_;
    double galutinis_med_;

    bool arValidusPazymys(int paz) const;

public:
    Studentas();
    Studentas(const string& pavarde, const string& vardas,
              const vector<int>& ndpaz, int egzrez);
    Studentas(istream& is);

    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);

    Studentas(Studentas&& other) noexcept;
    Studentas& operator=(Studentas&& other) noexcept;

    virtual ~Studentas();

    inline vector<int> ndpaz() const { return ndpaz_; }
    inline int egzrez() const { return egzrez_; }
    inline double galutinis_vid() const { return galutinis_vid_; }
    inline double galutinis_med() const { return galutinis_med_; }

    void setNdpaz(const vector<int>& ndpaz);
    void setEgzrez(int egzrez);

    istream& readStudent(istream& is);
    void skaiciuotiGalutinius();

    virtual void spausdinti(ostream& os) const override;

    friend bool comparePagalPavarde(const Studentas& a, const Studentas& b);
    friend bool comparePagalVarda(const Studentas& a, const Studentas& b);
    friend bool comparePagalBala(const Studentas& a, const Studentas& b, bool);

    friend istream& operator>>(istream& is, Studentas& st);

    bool operator==(const Studentas& other) const;
    bool operator!=(const Studentas& other) const;
    bool operator<(const Studentas& other) const;
    bool operator>(const Studentas& other) const;
    bool operator<=(const Studentas& other) const;
    bool operator>=(const Studentas& other) const;
};

bool comparePagalPavarde(const Studentas& a, const Studentas& b);
bool comparePagalVarda(const Studentas& a, const Studentas& b);
bool comparePagalBala(const Studentas& a, const Studentas& b, bool naudotiVidurki = true);

istream& operator>>(istream& is, Studentas& st);

#endif
