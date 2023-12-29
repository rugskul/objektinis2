# objektinis1
# v0.1
Programą nuskaito vartotojų įvedamus reikiamus duomenis: studento vardą ir pavardę, namų darbų tarpinius rezultatus ir egzamino rezultatą. Baigus duomenų įvedimą, suskaičiuoja galutinį balą pagal vidurkį arba medianą ir duomenis pateikia į ekraną lentelėje. Duomenis galima ne tik įvesti bet ir nuskaityti iš failo.
# v0.2
Sugeneruoti 5 atsitiktiniai studentų sąrašų failai, sudaryti iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 studentų. Studentai padalinami į dvi kategorijas "vargšiukai" ir "kietekai" pagal galutinį balą ir išvedami į atskirus failus. Atlikta programos veikimo greičio analizė, t.y. kiek laiko užtruko kiekvienas iš žemiau išvardintų žingsnių:
- duomenų nuskaitymą iš failų;
- studentų rūšiavimą į dvi grupes/kategorijas (iš prieš tai sukurto failo);
- surūšiuotų studentų išvedimą į du naujus failus (iš prieš tai sukurto failo).
# v0.3
Atlikta programos veikimo greičio analizė priklausomai nuo naudojamo std::vector arba std::list konteinerio. Testavimas atliekamas su prieš tai sugeneruotais failais.

| Vector      | 1000       | 10000      | 100000     | 1000000    | 10000000   |
|-------------|------------|------------|------------|------------|------------|
| viso testo laikas  | 0.0466783  | 2.49527    | 24.3772    | 247.079    | 2215.49    |
| failo nuskaitymas  | 0.173681   | 0.876461   | 7.21207    | 74.1672    | 396.269    |
| rūšiavimas į dvi grupes | 0.0077262  | 1.2275     | 9.27262    | 87.9569    | 955.315    |
| vargšiukų surašymas į failą  | 0.0111052  | 0.146003   | 3.15828    | 40.7217    | 415.666    |
| kietekų surašymas į failą  | 0.0104786  | 0.245314   | 4.73423    | 44.2331    | 448.243    |


| List       | 1000       | 10000      | 100000     | 1000000    | 10000000   |
|----------------|------------|------------|------------|------------|------------|
| viso testo laikas     | 0.128716   | 5.14071    | 24.0981    | 235.981    | 6393.04    |
| failo nuskaitymas | 0.0092561  | 3.37145    | 5.67912    | 32.259     | 495.206    |
| rūšiavimas į dvi grupes    | 0.0264714  | 0.756946   | 8.63328    | 94.1819    | 4632.75    |
| vargšiukų surašymas į failą     | 0.0439729  | 0.546911   | 4.85692    | 56.1709    | 639.43     |
| kietekų surašymas į failą     | 0.0490157  | 0.465397   | 4.9288     | 53.2688    | 625.654    |

# v1.0
Studentų rūšiavimas į dvi kategorijas ("vargšiukų" ir "kietekų") gali būti vykdomas 3 strategijomis:
1. į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietekų";
2. panaudojant tik vieną naują konteinerį: "vargšiukai";
3. panaudojant greičiausiai veikiančią strategiją (2) įtraukiant į ją "efektyvius" darbo su konteineriais metodus.


Padaryta programos veikimo greičio analizė priklausomai nuo pasirinktos strategijos.

| Vector       | 1000       | 10000      | 100000     | 
|----------------|------------|------------|------------|
| 1 strategija     | 0.0586295   | 3.40423666667    | 28.0859333333    |
| 2 strategija | 0.0762584   | 2.96730666667    | 113.093    |
| 3 strategija  | 0.04300303333  | 1.97779333333   | 14.7547    |


| List       | 1000       | 10000      | 100000     | 
|----------------|------------|------------|------------|
| 1 strategija     | 0.14869966666   | 4.99282666667    | 31.6336    |
| 2 strategija | 0.04408363333   | 1.3294    | 15.5944666667    |
| 3 strategija  | 0.0345008  | 1.350215   | 11.1841933333    |

# v1.1
Struct studentas pakeista į class studentas.
Programos greičio analizės palyginimas naudojant struct iš ankstesniojo darbo ir class iš dabartinės realizacijos. Atlikta su 100000 ir 1000000 dydžio failais, naudojamas vektorius ir greičiausia studentų skirstymo strategija (3).
Atlikita eksperimentinė analizė priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: O1, O2, O3.

| Struct       | 100000       | 1000000      |
|----------------|------------|------------|
| -     | 15.6462   | 176.488    |
| O1     | 63.6034  | 508.621    |
| O2 | 65.115   | 459.14    |
| O3  | 18.8003  | 140.561   |

| Class       | 100000       | 1000000      |
|----------------|------------|------------|
| -     | 34.7665  | 502.029    |
| O1     | 13.4714  | 140.965    |
| O2 | 31.8208   | 250.719    |
| O3  | 31.6903  | 252.082   |

# v1.2
Realizuoti visi reikiami "Rule of three" ir įvesties/išvesties operatoriai studentas klasei.
# v1.5
Sukurta bazinė abstrakti klasė žmogus, skirta bendrai aprašyti žmogų, o studentas klasė yra išvesta iš jos.