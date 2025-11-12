#ifndef ISVEDIMAS_H
#define ISVEDIMAS_H

#include "Studentas.h"
#include <vector>

void IsvedimasIFaila(const std::vector<Studentas> &grupe, int rezultatoTipas);
void IsvedimasIKonsole(const std::vector<Studentas> &grupe, int rezultatoTipas);
void SkirstymasIFailus(std::vector<Studentas> &grupe, int skirstymoTipas, int strategija,
                       double &rusiavimolaikas, double &isvedimolaikas,
                       double &vargsiukuLaikas, double &kietiakiuLaikas);

#endif
