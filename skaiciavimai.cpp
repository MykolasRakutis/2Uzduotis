#include "skaiciavimai.h"
#include <algorithm>

using std::sort;

double MedSkaiciavimas(vector<int> paz)
{
    sort(paz.begin(), paz.end());
    int pazsk = paz.size();
    if (pazsk == 0) return 0;

    if (pazsk % 2 == 0)
        return (paz[pazsk / 2 - 1] + paz[pazsk / 2]) / 2.0;
    else
        return paz[pazsk / 2];
}
