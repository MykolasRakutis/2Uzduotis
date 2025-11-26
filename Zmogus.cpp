#include "Zmogus.h"

Zmogus::Zmogus() : vardas_(""), pavarde_("") {
}

Zmogus::Zmogus(const string& pavarde, const string& vardas)
    : vardas_(vardas), pavarde_(pavarde) {
}

Zmogus::Zmogus(const Zmogus& other)
    : vardas_(other.vardas_), pavarde_(other.pavarde_) {
}

Zmogus& Zmogus::operator=(const Zmogus& other) {
    if (this != &other) {
        vardas_ = other.vardas_;
        pavarde_ = other.pavarde_;
    }
    return *this;
}

Zmogus::Zmogus(Zmogus&& other) noexcept
    : vardas_(std::move(other.vardas_)),
      pavarde_(std::move(other.pavarde_)) {
}

Zmogus& Zmogus::operator=(Zmogus&& other) noexcept {
    if (this != &other) {
        vardas_ = std::move(other.vardas_);
        pavarde_ = std::move(other.pavarde_);
    }
    return *this;
}

Zmogus::~Zmogus() {
}

void Zmogus::setVardas(const string& vardas) {
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

void Zmogus::setPavarde(const string& pavarde) {
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

ostream& operator<<(ostream& os, const Zmogus& zm) {
    zm.spausdinti(os);
    return os;
}
