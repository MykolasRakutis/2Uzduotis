#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Zmogus {
protected:
    string vardas_;
    string pavarde_;

public:
    Zmogus();
    Zmogus(const string& pavarde, const string& vardas);

    Zmogus(const Zmogus& other);
    Zmogus& operator=(const Zmogus& other);

    Zmogus(Zmogus&& other) noexcept;
    Zmogus& operator=(Zmogus&& other) noexcept;

    virtual ~Zmogus();

    inline string vardas() const { return vardas_; }
    inline string pavarde() const { return pavarde_; }

    void setVardas(const string& vardas);
    void setPavarde(const string& pavarde);

    virtual void spausdinti(ostream& os) const = 0;

    friend ostream& operator<<(ostream& os, const Zmogus& zm);
};

ostream& operator<<(ostream& os, const Zmogus& zm);

#endif
