#ifndef ISVEDIMAS_H
#define ISVEDIMAS_H

#include "studentas.h"

void IsvedimasIFaila(const CONTAINER<Studentas> &grupe, int rezultatoTipas);
void IsvedimasIKonsole(const CONTAINER<Studentas> &grupe, int rezultatoTipas);
void SkirstymasIFailus(CONTAINER<Studentas> &grupe, int skirstymoTipas, int strategija,
                       double &rusiavimolaikas, double &isvedimolaikas,
                       double &vargsiukuLaikas, double &kietiakiuLaikas);

#endif
