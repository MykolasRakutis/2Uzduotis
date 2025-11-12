#include "Studentas.h"
#include "skaiciavimai.h"
#include <sstream>
#include <algorithm>

using std::stringstream;
using std::sort;

Studentas::Studentas() : vardas_(""), pavarde_(""), egzrez_(0),
                          galutinis_vid_(0), galutinis_med_(0) {
}

Studentas::Studentas(const string& pavarde, const string& vardas,
                      const vector<int>& ndpaz, int egzrez)
    : vardas_(vardas), pavarde_(pavarde), ndpaz_(ndpaz), egzrez_(egzrez),
      galutinis_vid_(0), galutinis_med_(0) {
    skaiciuotiGalutinius();
}

Studentas::Studentas(istream& is) : egzrez_(0), galutinis_vid_(0), galutinis_med_(0) {
    readStudent(is);
}

bool Studentas::arValidusPazymys(int paz) const {
    return paz >= 0 && paz <= 10;
}

void Studentas::setVardas(const string& vardas) {

    bool valid = true;
    for (char c : vardas) {
        if (!isalpha(c)) {
            valid = false;
            break;
        }
    }
    if (valid && !vardas.empty()) {
        vardas_ = vardas;
    }
}

void Studentas::setPavarde(const string& pavarde) {

    bool valid = true;
    for (char c : pavarde) {
        if (!isalpha(c)) {
            valid = false;
            break;
        }
    }
    if (valid && !pavarde.empty()) {
        pavarde_ = pavarde;
    }
}

void Studentas::setNdpaz(const vector<int>& ndpaz) {
    ndpaz_.clear();
    for (int paz : ndpaz) {
        if (arValidusPazymys(paz)) {
            ndpaz_.push_back(paz);
        }
    }
    skaiciuotiGalutinius();
}

void Studentas::setEgzrez(int egzrez) {
    if (arValidusPazymys(egzrez)) {
        egzrez_ = egzrez;
        skaiciuotiGalutinius();
    }
}

void Studentas::skaiciuotiGalutinius() {
    if (ndpaz_.empty()) {
        galutinis_vid_ = 0;
        galutinis_med_ = 0;
        return;
    }

    int sum = 0;
    for (int paz : ndpaz_) {
        sum += paz;
    }
    double vid = static_cast<double>(sum) / ndpaz_.size();
    galutinis_vid_ = vid * 0.4 + egzrez_ * 0.6;

    double med = MedSkaiciavimas(ndpaz_);
    galutinis_med_ = med * 0.4 + egzrez_ * 0.6;
}

istream& Studentas::readStudent(istream& is) {
    string pav_temp, vard_temp;
    is >> pav_temp >> vard_temp;

    setPavarde(pav_temp);
    setVardas(vard_temp);

    int paz;
    vector<int> laikpaz;
    while (is >> paz) {
        if (paz == -1) break;
        laikpaz.push_back(paz);
    }

    if (!laikpaz.empty()) {
        egzrez_ = laikpaz.back();
        laikpaz.pop_back();
        ndpaz_ = laikpaz;
        skaiciuotiGalutinius();
    }

    return is;
}

ostream& operator<<(ostream& os, const Studentas& st) {
    os << "Vardas: " << st.vardas_ << ", Pavarde: " << st.pavarde_
       << ", Egzaminas: " << st.egzrez_
       << ", Galutinis(vid): " << st.galutinis_vid_
       << ", Galutinis(med): " << st.galutinis_med_;
    return os;
}

bool comparePagalPavarde(const Studentas& a, const Studentas& b) {
    if (a.pavarde_ == b.pavarde_)
        return a.vardas_ < b.vardas_;
    return a.pavarde_ < b.pavarde_;
}

bool comparePagalVarda(const Studentas& a, const Studentas& b) {
    if (a.vardas_ == b.vardas_)
        return a.pavarde_ < b.pavarde_;
    return a.vardas_ < b.vardas_;
}

bool comparePagalBala(const Studentas& a, const Studentas& b, bool naudotiVidurki) {
    double a_balas = naudotiVidurki ? a.galutinis_vid_ : a.galutinis_med_;
    double b_balas = naudotiVidurki ? b.galutinis_vid_ : b.galutinis_med_;
    return a_balas > b_balas;
}
