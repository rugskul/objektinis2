#include "funkcijos.h"
#include <iomanip>

int main() {
    string time, duomenys;
    vector<studentas> studentai;
    cout << endl << "Ar rodyti programos veikimo greicio analize? Jei taip - spausti 't', o jei ne - spausti bet ką kitą. ";
    cin >> time;
    if (time == "t") {
        timer();
    }
    cout << "Studentų duomenys bus įvedami ranka (spausti 'r') ar nuskaitomi iš failo (spausti 'f')? ";
    cin >> duomenys;
    if (duomenys == "r") {
        int kiek;
        string vidmed;
        cout << "Studentų skaičius: ";
        cin >> kiek;
        cout << endl << "Įveskite studentų informaciją." << endl;
        for (int i = 0; i < kiek; i++) {
            studentas s;
            apieStudenta(s);
            studentai.push_back(s);
        }
        cout << "Galutinis balas pagal vidurkį (spausti 'v') ar medianą (spausti 'm')? ";
        cin >> vidmed;
        printr(studentai, vidmed);
    } else if (duomenys == "f") {
        string pavadinimas;
        cout << "Failo pavadinimas: ";
        cin >> pavadinimas;
        studentai = isFailo(pavadinimas);
        printf(studentai);
    }
}