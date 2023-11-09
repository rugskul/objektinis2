#include "funkcijos.h"

double vidurkis(vector<int> v, int e) {
    double suma = 0;
    for (int i=0; i < v.size(); i++) {
        suma += v[i];
    }
    return 0.4*(suma/v.size())+0.6*e;
}
double mediana(vector<int> v, int e) {
    double mediana;
    sort(v.begin(), v.end());
    int n = v.size();
    if (n % 2 == 0) {
        mediana = (v[(n - 1) / 2] + v[n / 2]) / 2.0;
    } else {
        mediana = v[n / 2];
    }
    return mediana*0.4+e*0.6;
}

void apieStudenta(studentas &studentas) {
    cout << endl << "Vardas ir pavardė: ";
    cin >> studentas.vardas >> studentas.pavarde;
    string arAtsitiktinai;
    cout << "Ar namų darbai generuojami atsitiktinai (spausti 'a'), ar įvedami ranka (spausti 'r')? ";
    cin >> arAtsitiktinai;
    if (arAtsitiktinai == "a") {
        //atsitiktiniai namu darbu pazymiai
        srand(time(0));
        for (int j = 0; j < rand()%10+1; j++) {
            studentas.pazymiai.push_back(rand() % 10 + 1);
        }        
    } else if (arAtsitiktinai == "r") {
        //pazymiu ivedimas su enter
        cout << "Namų darbų pažymiai (baigti 2 kartus paspaudus ENTER): " << endl;
        int pazymys;
        string p;
        while (true) {
            getline(cin, p);
            if (p.empty()) {
                if (cin.peek() == '\n') {
                    break;
                }
            } else {
                pazymys = stoi(p);
                while (pazymys < 1 || pazymys > 10) {
                    cerr << "Netinkamas pažymys. Įveskite pažymį nuo 1 iki 10. " << endl;
                    cin >> pazymys;
                }
                studentas.pazymiai.push_back(pazymys);
            }
        }
    }
    cout << "Egzamino rezultatas: ";
    cin >> studentas.egz;
    while (studentas.egz < 1 || studentas.egz > 10) {
        cerr << "Netinkamas pažymys. Įveskite egzamino rezultatą nuo 1 iki 10. ";
        cin >> studentas.egz;
    }
    studentas.galvid = vidurkis(studentas.pazymiai, studentas.egz);
    studentas.galmed = mediana(studentas.pazymiai, studentas.egz);
}

vector<vector<studentas>> skirstymas(vector<studentas> studentai) {
    vector<studentas> vargsiukai;
    vector<studentas> kietekai;
    for (int i = 0; i < studentai.size(); i++) {
        if (studentai[i].galvid > 5) {
            kietekai.push_back(studentai[i]);
        } else {
            vargsiukai.push_back(studentai[i]);
        }
    }
    vector<vector<studentas>> suskirstyti = {vargsiukai, kietekai};
    return suskirstyti;
}