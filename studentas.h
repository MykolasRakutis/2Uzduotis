#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<int> ndpaz;
    int egzrez;
    double galutinis_vid;
    double galutinis_med;
};

#endif
