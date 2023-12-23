#include "funkcijos.h"

int failoGeneravimas(int kiek) {
    srand(time(0));
    string pavadinimas = "kursiokai" + to_string(kiek) + ".txt";
    ofstream outputFile(pavadinimas);
    outputFile << "Vardas Pavardė";
    int nd = rand()%15+1;
    for (int i = 1; i <= nd; ++i) {
        outputFile << " ND" << i;
    }
    outputFile << " Egz." << endl;
    for (int i = 1; i <= kiek; ++i) {
        outputFile << "Vardas" << to_string(i) << " " << "Pavardė" << to_string(i);
        for (int j = 1; j <= nd; ++j) {
            int pazymys = rand()%10+1;
            outputFile << " " << pazymys;
        }
        outputFile << " " << rand()%10+1 << endl;
    }
    outputFile.close();
    cout << "Failas kursiokai" << to_string(kiek) << ".txt" <<  " sugeneruotas. " << endl;
    return 0;
}
void timer() {
    string arGen, pagal, strategija;
    chrono::high_resolution_clock::time_point start0, start1, start2, start3, start4, stop0, stop1, stop2, stop3, stop4;
    chrono::duration<double> trukme0, trukme1, trukme2, trukme3, trukme4;
    cout << "Ar generuoti studentų failus? Jei taip - spausti 'g', o jei ne - spausti bet ką kitą. ";
    cin >> arGen;
    cout << endl;
    if (arGen == "g") {
        failoGeneravimas(1000);
        failoGeneravimas(10000);
        failoGeneravimas(100000);
        failoGeneravimas(1000000);
        failoGeneravimas(10000000);
    }
    cout << "Rūšiuoti duomenis pagal pavardę (spausti 1), egzamino rezultatą (spausti 2) ar galutinį balą (spausti 3)? ";
    cin >> pagal;
    if (pagal != "1" && pagal != "2" && pagal != "3") {
        cout << "Įvestas netinkamas rūšiavimo kriterijus. Bus rūšiuojama pagal pavardę. " << endl;
    }
    cout << "Kurią strategiją naudoti (1, 2 ar 3)? ";
    cin >> strategija;

    cout << endl << "PROGRAMOS VEIKIMO GREIČIO ANALIZĖ: " << endl << endl;

    for (int i = 1000; i <= 100000; i = i * 10) {
        string pavadinimas = "kursiokai" + to_string(i) + ".txt";
        string vargsiukai = "vargsiukai" + to_string(i) + ".txt";
        string kietekai = "kietekai" + to_string(i) + ".txt";

        if (strategija == "1") {

            start0 = chrono::high_resolution_clock::now();

            start1 = chrono::high_resolution_clock::now();
            vector<studentas> studentai = isFailo(pavadinimas);
            stop1 = chrono::high_resolution_clock::now();

            sortStudentai(studentai, pagal);

            start2 = chrono::high_resolution_clock::now();
            pair<vector<studentas>, vector<studentas>> suskirstyti = skirstymas1(studentai);
            stop2 = chrono::high_resolution_clock::now();

            start3 = chrono::high_resolution_clock::now();
            iFaila(suskirstyti.first, vargsiukai);
            stop3 = chrono::high_resolution_clock::now();

            start4 = chrono::high_resolution_clock::now();
            iFaila(suskirstyti.second, kietekai);
            stop4 = chrono::high_resolution_clock::now();

            stop0 = chrono::high_resolution_clock::now();

        } else if (strategija == "2") {

            start0 = chrono::high_resolution_clock::now();

            start1 = chrono::high_resolution_clock::now();
            vector<studentas> studentai = isFailo(pavadinimas);
            stop1 = chrono::high_resolution_clock::now();

            sortStudentai(studentai, pagal);

            start2 = chrono::high_resolution_clock::now();
            vector<studentas> vargsiukaii = skirstymas2(studentai);
            stop2 = chrono::high_resolution_clock::now();

            start3 = chrono::high_resolution_clock::now();
            iFaila(vargsiukaii, vargsiukai);
            stop3 = chrono::high_resolution_clock::now();

            start4 = chrono::high_resolution_clock::now();
            iFaila(studentai, kietekai);
            stop4 = chrono::high_resolution_clock::now();

            stop0 = chrono::high_resolution_clock::now();
            
        } else if (strategija == "3") {

            start0 = chrono::high_resolution_clock::now();

            start1 = chrono::high_resolution_clock::now();
            vector<studentas> studentai = isFailo(pavadinimas);
            stop1 = chrono::high_resolution_clock::now();

            sortStudentai(studentai, pagal);

            start2 = chrono::high_resolution_clock::now();
            vector<studentas> vargsiukaii = skirstymas3(studentai);
            stop2 = chrono::high_resolution_clock::now();

            start3 = chrono::high_resolution_clock::now();
            iFaila(vargsiukaii, vargsiukai);
            stop3 = chrono::high_resolution_clock::now();

            start4 = chrono::high_resolution_clock::now();
            iFaila(studentai, kietekai);
            stop4 = chrono::high_resolution_clock::now();

            stop0 = chrono::high_resolution_clock::now();
        }
        trukme0 = stop0 - start0;
        trukme1 = stop1 - start1;
        trukme2 = stop2 - start2;
        trukme3 = stop3 - start3;
        trukme4 = stop4 - start4;

        cout << "Failo " << pavadinimas << " nuskaitymo laikas: " << trukme1.count() << endl
        << "Studentu rusiavimo i dvi grupes laikas: " << trukme2.count() << endl
        << "Vargsiuku surasymo i faila laikas: " << trukme3.count() << endl
        << "Kieteku surasymo i faila laikas: " << trukme4.count() << endl
        << "Viso testo laikas: " << trukme0.count() << endl << endl;
    }
}