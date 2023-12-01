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
| rūšiavimas į dvi grupe | 0.0077262  | 1.2275     | 9.27262    | 87.9569    | 955.315    |
| vargšiukų surašymas į failą  | 0.0111052  | 0.146003   | 3.15828    | 40.7217    | 415.666    |
| kietekų surašymas į failą  | 0.0104786  | 0.245314   | 4.73423    | 44.2331    | 448.243    |


| List       | 1000       | 10000      | 100000     | 1000000    | 10000000   |
|----------------|------------|------------|------------|------------|------------|
| viso testo laikas     | 0.128716   | 5.14071    | 24.0981    | 235.981    | 6393.04    |
| failo nuskaitymas | 0.0092561  | 3.37145    | 5.67912    | 32.259     | 495.206    |
| rūšiavimas į dvi grupe    | 0.0264714  | 0.756946   | 8.63328    | 94.1819    | 4632.75    |
| vargšiukų surašymas į failą     | 0.0439729  | 0.546911   | 4.85692    | 56.1709    | 639.43     |
| kietekų surašymas į failą     | 0.0490157  | 0.465397   | 4.9288     | 53.2688    | 625.654    |

