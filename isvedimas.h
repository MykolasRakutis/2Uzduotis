#ifndef ISVEDIMAS_H
#define ISVEDIMAS_H

#include "studentas.h"
#include <vector>

using std::vector;

void IsvedimasIFaila(const vector<Studentas> &grupe, int rezultatoTipas);

void SkirstymasIFailus(const vector<Studentas> &grupe, int skirstymoTipas);

#endif
