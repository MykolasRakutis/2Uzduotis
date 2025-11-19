DUOMENŲ ĮVESTIS

Sistema turi tris būdus įvesti studentų duomenis:

Rankinė Įvestis:

Rankinio įvedimo metu naudotojo prašoma įvesti studento vardą, pavardę, namų darbų pažymius ir egzamino rezultatą. Programa validuoja, kad vardas ir pavardė būtų sudaryti tik iš raidžių, o pažymiai būtų skaičiai nuo 0 iki 10. Šis metodas saugiai naudoja setVardas(), setPavarde(), setNdpaz() ir setEgzrez() metodus, kurie patikrina duomenų teisingumą prieš juos išsaugodami.

Automatinė Įvestis:

Automatinės įvesties metu programa sugeneruoja atsitiktinius pažymius nuo 0 iki 10 iš standarčios knygynos rand() funkcijos. Naudotojas nurodo, kiek namų darbų pažymių reikia sugeneruoti, o programa automatiškai sukuria ir egzamino rezultatą.

Įvestis iš Failo:

Programoje realuzuota failo nuskaitymo funkcija, kuri skaito eilutes iš tekstinio failo, kur kiekviena eilutė turi studento pavardę, vardą, namų darbų pažymius ir egzamino rezultatą. Failai gali turėti tūkstančius ar net milijonus studentų. Sistema matuoja nuskaitymo laiką ir saugiai apdoroja kiekvieną eilutę konvertuodama ją į Studentas objektą.

DUOMENŲ IŠVESTIS

Sistema turi du duomenų išvesties būdus:

Išvestis į Konsolę:

Šis metodas išveda studentų duomenis tiesiai į ekraną suformatuotu pavidalu su lentelės struktūra. Išvedama studento pavardė, vardas ir galutiniai rezultatai (vidurkis ir/arba mediana priklausomai nuo naudotojo pasirinkimo). Duomenys išvedami naudojant cout ir manipuliatorius (setw, left, fixed, setprecision), kad būtų pasiekta tvari ir skaitoma išvestis.

Išvestis į Failą:

Duomenys taip pat gali būti išvesti į tekstinius failus. Programa sukuria rezultatai.txt failą, kuriame saugo visus studentų duomenis ir vargsiukai.txt ir kietiakai.txt failus į kuriuos surūšiuoja studentus pagal vidurkį. Visos operacijos su ofstream turi klaidų tikrinimą, todėl jei nepavyksta atidaryti arba sukurti failo, programa informuoja naudotoją apie klaidą. Duomenys failuose išsaugomi tuo pačiu formatu kaip ir konsolės išvestis, taip pat suformatuoti ir skaitomi.
