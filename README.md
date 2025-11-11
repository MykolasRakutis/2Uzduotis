# Pirmas-projektas
PROGRAMOS NAUDOJIMO INSTRUKCIJA

1.Programa paleidžiama įprastai terminale ar IDE aplinkoje

2.Paleidus programą, ekrane pasirodys žingsnių seka (interaktyvūs klausimai)

3.Pasirinkimas ar generuoti 5 studentų failus

4.Duomenų įvedimo būdo pasirinkimas

5.Studentų rikiavimo pasirinkimas

6.Galutinio rezultato pasirinkimas

7.Studentų skirstymo į grupes būdo pasirinkimas

8.Strategijos pasirinkimas

9.Sistema išveda laiko matavimus

10.Sukuriami failai.





KIEKVIENO RELEASE APRAŠYMAS

V0.1 RELEASE

leidžia įvesti studentų duomenis rankiniu būdu arba nuskaityti juos iš failo kursiokai.txt;

Automatiškai apskaičiuoti galutinį balą pagal vidurkį ir medianą;

Išvesti tvarkingą lentelę su studentų pavardėmis, vardais ir abiem galutinio balo versijomis.

V0.2 RELEASE

papildyta galimybe automatiškai generuoti didelius studentų duomenų failus (nuo 1000 iki 10 000 000 įrašų);

nuskaityti duomenis iš failų ir saugoti juos vector<Studentas>;

paskirstyti studentus į dvi kategorijas:

„vargšiukai“ – galutinis balas < 5.0

„kietiakiai“ – galutinis balas ≥ 5.0;

kiekvienai grupei sugeneruoti atskirus failus:
vargsiukai.txt ir kietiakiai.txt;

pamatuoti ir parodyti programos veikimo laiką (nuskaitymo, rūšiavimo ir išvedimo).


V0.3 RELEASE

buvo atliktas programos veikimo spartos priklausomai nuo naudojamo konteinerio (List ir Vector)
Testavimas atliekamas su 1000, 10000, 100000, 1000000, 10000000 įrašų.


TESTAVIMAS SU STRATEGIJOMIS:

Šioje versijoje buvo atliktas studentų rūšiavimo (skirstymo) efektyvumo testavimas, taikant tris skirtingas strategijas ir du skirtingus konteinerių tipus — std::vector ir std::list.
Tikslas — nustatyti, kaip pasirinktas konteineris bei strategija įtakoja programos vykdymo spartą.

Rezultatai parodė, kad:

Naudojant 1 strategiją:

Su vector veikia greitai su mažais duomenų kiekiais, bet sulėtėja kai yra daugiau duomenų, o su list veikia šiektiek lėčiau.

Naudojant 2 strategiją:

Su list veikia žymiai greičiau nei su vector.

Naudojant 3 strategiją:

Su vector greitis panašus į 1 strategiją, o su list ši strategija veikia greičiausiai.




<img width="645" height="156" alt="Ekrano kopija 2025-11-11 155917" src="https://github.com/user-attachments/assets/e2bcd7ff-034a-4180-93be-6c3007a38118" />
<img width="671" height="163" alt="Ekrano kopija 2025-11-11 160004" src="https://github.com/user-attachments/assets/4a85b8fe-d59a-4079-b6b2-893bcdf7aa40" />
<img width="668" height="155" alt="Ekrano kopija 2025-11-11 160045" src="https://github.com/user-attachments/assets/5d325cfa-3e97-41dc-acc6-e832fb2e7c63" />
<img width="684" height="160" alt="Ekrano kopija 2025-11-11 160132" src="https://github.com/user-attachments/assets/fed59e9a-d0db-4f5d-a7db-98c9d69fd593" />
<img width="693" height="157" alt="Ekrano kopija 2025-11-11 160417" src="https://github.com/user-attachments/assets/88792b55-63af-4b95-b262-3268db28b361" />

| Vector  1 strategija       | 1000     | 10000    | 100000   | 1000000  | 10000000  |
| -------------------------- | -------- | -------- | -------- | -------- | --------- |
| Nuskaitymas                | 0.002840 | 0.027335 | 0.148758 | 1.341297 | 14.017588 |
| Rūšiavimas                 | 0.001066 | 0.010960 | 0.093369 | 0.933095 | 11.739986 |
| Išvedimas                  | 0.014543 | 0.034865 | 0.244626 | 2.553664 | 25.521644 |
| Bendras laikas             | 0.018448 | 0.073161 | 0.486754 | 4.828055 | 51.279218 |


<img width="673" height="156" alt="Ekrano kopija 2025-11-11 160900" src="https://github.com/user-attachments/assets/3b9e10b5-43b2-49e7-a936-1c596da566ed" />
<img width="661" height="161" alt="Ekrano kopija 2025-11-11 160656" src="https://github.com/user-attachments/assets/d459cc54-da88-41e6-83d0-be93db43fc15" />
<img width="648" height="152" alt="Ekrano kopija 2025-11-11 160525" src="https://github.com/user-attachments/assets/ec0c37fb-c16b-4126-ab45-18c8c9c61366" />

| Vector  2 strategija       | 1000     | 10000    | 100000    | 1000000 | 10000000 |
| ---------------------------| -------- | -------- | --------- | ------- | -------- |
| Nuskaitymas                | 0.003971 | 0.026320 | 0.172781  | –       | –        |
| Rūšiavimas                 | 0.015746 | 0.950475 | 92.259605 | –       | –        |
| Išvedimas                  | 0.057271 | 0.025911 | 0.257685  | –       | –        |
| Bendras laikas             | 0.076989 | 1.002706 | 92.690071 | –       | –        |

<img width="674" height="157" alt="Ekrano kopija 2025-11-11 173214" src="https://github.com/user-attachments/assets/52bd5669-f879-4774-94c5-a4e771e6cd78" />
<img width="665" height="157" alt="Ekrano kopija 2025-11-11 173135" src="https://github.com/user-attachments/assets/3ccb4187-a226-45a6-bdda-5210a673b8ce" />
<img width="662" height="160" alt="Ekrano kopija 2025-11-11 173053" src="https://github.com/user-attachments/assets/125f3801-233c-4a7b-975b-6a612f4ef3c2" />
<img width="646" height="153" alt="Ekrano kopija 2025-11-11 173024" src="https://github.com/user-attachments/assets/124d9748-5984-4b55-afba-d5f8e796a687" />
<img width="700" height="155" alt="Ekrano kopija 2025-11-11 173528" src="https://github.com/user-attachments/assets/4bada42b-2952-470f-8aa0-0c4b6ecf4175" />

| Vector  3 strategija       | 1000     | 10000    | 100000   | 1000000  | 10000000  |
| -------------------------- | -------- | -------- | -------- | -------- | --------- |
| Nuskaitymas                | 0.004264 | 0.026707 | 0.154110 | 1.365846 | 13.985962 |
| Rūšiavimas                 | 0.000875 | 0.011194 | 0.083616 | 0.949838 | 11.697415 |
| Išvedimas                  | 0.064281 | 0.046744 | 0.251714 | 2.493916 | 25.131776 |
| Bendras laikas             | 0.069419 | 0.084645 | 0.489440 | 4.809599 | 50.815152 |

<img width="675" height="156" alt="Ekrano kopija 2025-11-11 173826" src="https://github.com/user-attachments/assets/5a595b23-dc70-419d-9ef7-e9ce6aa6eba3" />
<img width="662" height="154" alt="Ekrano kopija 2025-11-11 173739" src="https://github.com/user-attachments/assets/10ff3949-bf8a-4af1-9962-dee50f70890c" />
<img width="666" height="159" alt="Ekrano kopija 2025-11-11 173652" src="https://github.com/user-attachments/assets/dfcbc900-e48c-42a4-8c1f-e82e27726fa0" />
<img width="644" height="153" alt="Ekrano kopija 2025-11-11 173624" src="https://github.com/user-attachments/assets/397ea094-ab56-4aaa-a65b-e8d8562e6482" />
<img width="700" height="156" alt="Ekrano kopija 2025-11-11 174036" src="https://github.com/user-attachments/assets/07940fe9-3669-417f-82ae-d5c5df71da43" />

| List  1 strategija       | 1000     | 10000    | 100000   | 1000000  | 10000000  |
| ------------------------ | -------- | -------- | -------- | -------- | --------- |
| Nuskaitymas              | 0.001890 | 0.021707 | 0.154462 | 1.378058 | 13.628755 |
| Rūšiavimas               | 0.000558 | 0.005755 | 0.061297 | 0.772691 | 11.775360 |
| Išvedimas                | 0.066694 | 0.035177 | 0.263249 | 2.742326 | 26.232194 |
| Bendras laikas           | 0.069141 | 0.062639 | 0.479008 | 4.893075 | 51.636308 |



<img width="658" height="157" alt="Ekrano kopija 2025-11-11 174205" src="https://github.com/user-attachments/assets/2045755c-f6bd-4cf7-be3b-4b6a5315ca99" />
<img width="642" height="154" alt="Ekrano kopija 2025-11-11 174138" src="https://github.com/user-attachments/assets/90a46626-1187-4cee-9cd4-a21ce1486d64" />
<img width="691" height="155" alt="Ekrano kopija 2025-11-11 174710" src="https://github.com/user-attachments/assets/04b4459d-98c6-4f59-8dc5-ca56453521c6" />
<img width="676" height="157" alt="Ekrano kopija 2025-11-11 174341" src="https://github.com/user-attachments/assets/c9375712-343c-496f-8b33-69c08ee9334c" />
<img width="663" height="153" alt="Ekrano kopija 2025-11-11 174258" src="https://github.com/user-attachments/assets/b9bd7ad4-b3b8-46f3-9cc9-4cf4e3f3dfae" />

| List  2 strategija       | 1000     | 10000    | 100000   | 1000000  | 10000000  |
| ------------------------ | -------- | -------- | -------- | -------- | --------- |
| Nuskaitymas              | 0.004569 | 0.017534 | 0.166005 | 1.477767 | 14.289753 |
| Rūšiavimas               | 0.000646 | 0.005610 | 0.062179 | 0.757407 | 11.790258 |
| Išvedimas                | 0.056857 | 0.038141 | 0.259056 | 2.621518 | 25.908615 |
| Bendras laikas           | 0.062072 | 0.061285 | 0.487241 | 4.856692 | 51.988625 |


<img width="669" height="156" alt="Ekrano kopija 2025-11-11 175515" src="https://github.com/user-attachments/assets/b2d5b240-066d-49fd-945e-c0be90464353" />
<img width="658" height="154" alt="Ekrano kopija 2025-11-11 175425" src="https://github.com/user-attachments/assets/da88714e-e2ae-46a0-8691-c0ad732735a1" />
<img width="661" height="156" alt="Ekrano kopija 2025-11-11 175330" src="https://github.com/user-attachments/assets/1632e60e-8242-447c-8e19-7eb34cdbc106" />
<img width="645" height="153" alt="Ekrano kopija 2025-11-11 175117" src="https://github.com/user-attachments/assets/39996830-8e3d-4772-bab5-058479e9b6db" />
<img width="692" height="154" alt="Ekrano kopija 2025-11-11 175708" src="https://github.com/user-attachments/assets/d17bd1ae-125c-4855-8212-18b8ce9a1aa8" />

| List  3 strategija       | 1000     | 10000    | 100000   | 1000000  | 10000000  |
| ------------------------ | -------- | -------- | -------- | -------- | --------- |
| Nuskaitymas              | 0.002944 | 0.020028 | 0.151338 | 1.375042 | 13.639044 |
| Rūšiavimas               | 0.000387 | 0.005630 | 0.061834 | 0.703942 | 11.081989 |
| Išvedimas                | 0.053895 | 0.037015 | 0.270790 | 2.605164 | 26.270296 |
| Bendras laikas           | 0.057225 | 0.062672 | 0.483963 | 4.684147 | 50.991329 |

