#include "Studentas.h"
#include "skaiciavimai.h"
#include <sstream>
#include <algorithm>

using std::stringstream;
using std::sort;

Studentas::Studentas()
    : Zmogus(), egzrez_(0), galutinis_vid_(0), galutinis_med_(0) {
}

Studentas::Studentas(const string& pavarde, const string& vardas,
                      const vector<int>& ndpaz, int egzrez)
    : Zmogus(pavarde, vardas), ndpaz_(ndpaz), egzrez_(egzrez),
      galutinis_vid_(0), galutinis_med_(0) {
    skaiciuotiGalutinius();
}

Studentas::Studentas(istream& is)
    : Zmogus(), egzrez_(0), galutinis_vid_(0), galutinis_med_(0) {
    readStudent(is);
}

Studentas::Studentas(const Studentas& other)
    : Zmogus(other),
      ndpaz_(other.ndpaz_),
      egzrez_(other.egzrez_),
      galutinis_vid_(other.galutinis_vid_),
      galutinis_med_(other.galutinis_med_) {
}

Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        Zmogus::operator=(other);
        ndpaz_ = other.ndpaz_;
        egzrez_ = other.egzrez_;
        galutinis_vid_ = other.galutinis_vid_;
        galutinis_med_ = other.galutinis_med_;
    }
    return *this;
}

Studentas::Studentas(Studentas&& other) noexcept
    : Zmogus(std::move(other)),
      ndpaz_(std::move(other.ndpaz_)),
      egzrez_(other.egzrez_),
      galutinis_vid_(other.galutinis_vid_),
      galutinis_med_(other.galutinis_med_) {
    other.egzrez_ = 0;
    other.galutinis_vid_ = 0;
    other.galutinis_med_ = 0;
}

Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this != &other) {
        Zmogus::operator=(std::move(other));
        ndpaz_ = std::move(other.ndpaz_);
        egzrez_ = other.egzrez_;
        galutinis_vid_ = other.galutinis_vid_;
        galutinis_med_ = other.galutinis_med_;

        other.egzrez_ = 0;
        other.galutinis_vid_ = 0;
        other.galutinis_med_ = 0;
    }
    return *this;
}

Studentas::~Studentas() {
}

bool Studentas::arValidusPazymys(int paz) const {
    return paz >= 0 && paz <= 10;
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

void Studentas::spausdinti(ostream& os) const {
    os << "Vardas: " << vardas_ << ", Pavarde: " << pavarde_
       << ", Egzaminas: " << egzrez_
       << ", Galutinis(vid): " << galutinis_vid_
       << ", Galutinis(med): " << galutinis_med_;
}

istream& operator>>(istream& is, Studentas& st) {
    return st.readStudent(is);
}

bool Studentas::operator==(const Studentas& other) const {
    return vardas_ == other.vardas_ &&
           pavarde_ == other.pavarde_ &&
           egzrez_ == other.egzrez_ &&
           ndpaz_ == other.ndpaz_;
}

bool Studentas::operator!=(const Studentas& other) const {
    return !(*this == other);
}

bool Studentas::operator<(const Studentas& other) const {
    if (pavarde_ != other.pavarde_)
        return pavarde_ < other.pavarde_;
    return vardas_ < other.vardas_;
}

bool Studentas::operator>(const Studentas& other) const {
    return other < *this;
}

bool Studentas::operator<=(const Studentas& other) const {
    return !(*this > other);
}

bool Studentas::operator>=(const Studentas& other) const {
    return !(*this < other);
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
