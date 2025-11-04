#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

#define USE_VECTOR

#ifdef USE_LIST
    #define CONTAINER list
    #define CONTAINER_TYPE "std::list"
#else
    #define CONTAINER vector
    #define CONTAINER_TYPE "std::vector"
#endif

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
