## Pagrindiniai pakeitimai v1.5 versijoje

### Klasių hierarchija

Programos veikimas nepakito, tačiau iš vienos klasės `Studentas` buvo pakeista į dvi:

#### 1. **Bazinė abstrakti klasė `Zmogus`**
- Abstrakti klasė - jos objektų sukurti negalima
- Saugo bendrus duomenis: `vardas_`, `pavarde_`

#### Demonstravimas:

Norint patikrinti ar `Zmogus` klasė tikrai abstrakti reikia:

atkomentuoti `main.cpp` eilutę `// Zmogus z;`

Tai parodo jos tipo objektų kūrimas yra negalimas.


#### 2. **Išvestinė klasė `Studentas`**
- Paveldi iš `Zmogus` klasės: `class Studentas : public Zmogus`
- Saugo specifines studento savybes: `ndpaz_`, `egzrez_`, `galutinis_vid_`, `galutinis_med_`
- Pilnai palaiko Rule of Three




