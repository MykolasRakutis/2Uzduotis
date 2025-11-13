KLASĖS:

<img width="666" height="140" alt="Ekrano kopija 2025-11-12 183424" src="https://github.com/user-attachments/assets/391a45cb-88c7-4412-8f44-e7359c0d298c" />
<img width="670" height="133" alt="Ekrano kopija 2025-11-12 183605" src="https://github.com/user-attachments/assets/6d879855-ab4e-4b1a-91c7-c03fd3294c82" />

VEKTORIAI:

<img width="665" height="157" alt="Ekrano kopija 2025-11-11 173135" src="https://github.com/user-attachments/assets/b65ed0ed-cde3-4f01-9a2e-9a61070c83f5" />
<img width="674" height="157" alt="Ekrano kopija 2025-11-11 173214" src="https://github.com/user-attachments/assets/0106d586-1346-4500-b199-393433148fae" />

| Konteineris / Duomenų kiekis | Nuskaitymo laikas (s) | Dalijimo (rūšiavimo) laikas (s) | Išvedimo laikas (s) | Bendras laikas (s) |
| ---------------------------- | --------------------- | ------------------------------- | ------------------- | ------------------ |
| **`std::vector` – 100000**   | 0.154110              | 0.083616                        | 0.251714            | **0.489440**       |
| **`std::vector` – 1000000**  | 1.365846              | 0.949838                        | 2.493916            | **4.809599**       |
| **Klasės – 100000**          | 0.153601              | 0.087528                        | 0.253198            | **0.494326**       |
| **Klasės – 1000000**         | 1.533729              | 0.920790                        | 2.615805            | **5.070324**       |

IŠVADA:

Su 100000 duomenų vector ir klasės laikas labai panašus, o su 1000000 duomenų vector šiek tiek greitesnis (apie 5-6%).

LAIKO PRIKLAUSOMAI NUO KOMPILIATORIAUS OPTIMIZAVIMO LYGIO MATAVIMAI:

VECTOR:

<img width="660" height="174" alt="Ekrano kopija 2025-11-12 194136" src="https://github.com/user-attachments/assets/c3f737c9-9625-4d51-9120-5e0ede38877c" />
<img width="669" height="177" alt="Ekrano kopija 2025-11-12 194212" src="https://github.com/user-attachments/assets/7cc50599-f2b6-46e8-b322-61a4d51d880a" />
<img width="671" height="174" alt="Ekrano kopija 2025-11-12 194312" src="https://github.com/user-attachments/assets/93c0e74c-a1e3-4cf4-ad7d-7e9c779386ab" />
<img width="670" height="175" alt="Ekrano kopija 2025-11-12 194502" src="https://github.com/user-attachments/assets/6c26d8ed-67f4-4661-bd1e-eec03a3f3001" />
<img width="663" height="176" alt="Ekrano kopija 2025-11-12 194833" src="https://github.com/user-attachments/assets/37ae309c-7954-468a-861b-0f3ffd67483f" />
<img width="673" height="176" alt="Ekrano kopija 2025-11-12 194924" src="https://github.com/user-attachments/assets/f0042e03-8323-4412-b3f7-ca38d38fba39" />

| Kompiliavimo flag    | Duomenų kiekis | Nuskaitymo laikas (s) | Dalijimo laikas (s) | Išvedimo laikas (s) | Bendras laikas (s) |
| -------------------- | -------------- | --------------------- | ------------------- | ------------------- | ------------------ |
| **-O1 (Bazinis)**    | 100 000        | 0.107795              | 0.023607            | 0.246897            | **0.378299**       |
| **-O1 (Bazinis)**    | 1 000 000      | 0.826251              | 0.221444            | 2.558637            | **3.606332**       |
| **-O2 (Vidutinis)**  | 100 000        | 0.090061              | 0.028645            | 0.268889            | **0.387596**       |
| **-O2 (Vidutinis)**  | 1 000 000      | 0.849475              | 0.224988            | 2.549217            | **3.623680**       |
| **-O3 (Maksimalus)** | 100 000        | 0.098247              | 0.020151            | 0.246951            | **0.365349**       |
| **-O3 (Maksimalus)** | 1 000 000      | 0.819198              | 0.218159            | 2.656032            | **3.693389**       |

std::vector su optimizavimo flagais veikia šiektiek greičiau, bet skirtumai tarp -O1, -O2, -O3 yra minimalūs.

KLASĖ:

<img width="667" height="156" alt="Ekrano kopija 2025-11-12 192448" src="https://github.com/user-attachments/assets/7b2d5c7e-3bcc-4031-ba70-12f975a232a3" />
<img width="675" height="157" alt="Ekrano kopija 2025-11-12 192518" src="https://github.com/user-attachments/assets/a0caf603-d5c5-4d32-b6a3-5fd0900d0d5e" />
<img width="660" height="155" alt="Ekrano kopija 2025-11-12 192719" src="https://github.com/user-attachments/assets/47b5dc61-235e-4539-bbec-a1ef06fb464d" />
<img width="671" height="155" alt="Ekrano kopija 2025-11-12 192806" src="https://github.com/user-attachments/assets/7870016b-77b0-433a-801f-4bb3ee8d7856" />
<img width="659" height="154" alt="Ekrano kopija 2025-11-12 192903" src="https://github.com/user-attachments/assets/e0408df9-38e8-4b56-b03b-1b55c6501263" />
<img width="671" height="158" alt="Ekrano kopija 2025-11-12 193342" src="https://github.com/user-attachments/assets/ffdf0c78-ec76-422c-bf70-c073237ec53b" />

| Kompiliavimo flag    | Duomenų kiekis | Nuskaitymo laikas (s) | Dalijimo laikas (s) | Išvedimo laikas (s) | Bendras laikas (s) |
| -------------------- | -------------- | --------------------- | ------------------- | ------------------- | ------------------ |
| **-O1 (Bazinis)**    | 100 000        | 0.126791              | 0.028535            | 0.281762            | **0.437088**       |
| **-O1 (Bazinis)**    | 1 000 000      | 0.900298              | 0.269834            | 2.534508            | **3.704639**       |
| **-O2 (Vidutinis)**  | 100 000        | 0.114340              | 0.025663            | 0.254347            | **0.394350**       |
| **-O2 (Vidutinis)**  | 1 000 000      | 0.844134              | 0.242318            | 2.548001            | **3.634453**       |
| **-O3 (Maksimalus)** | 100 000        | 0.092441              | 0.028131            | 0.254416            | **0.374988**       |
| **-O3 (Maksimalus)** | 1 000 000      | 0.865431              | 0.244686            | 2.572646            | **3.682764**       |

Klasės realizacijoje optimizavimo flagai daro labai mažą įtaką veikimo laikui.

IŠVADA:

Kompiliatoriaus optimizavimo flagai nežymiai pagreitina veikimą, nes didžiąją dalį laiko užima failų skaitymas ir rašymas.
