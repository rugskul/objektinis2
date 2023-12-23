#include "funkcijos.h"

void print(vector<studentas> studentai) {
   cout << left << setw(15) << "Vardas" 
        << setw(15) << "Pavardė" 
        << setw(15) << "Galutinis(vid.) " 
        << setw(15) << "Galutinis(med.) " << endl 
        << "--------------------------------------------------------------" << endl;
   for (int i = 0; i < studentai.size(); i++) {
      cout << left << setw(15) << studentai[i].getVardas()
           << setw(15) << studentai[i].getPavarde() 
           << setw(15) << setprecision(2) << studentai[i].galBalas("v") 
           << setw(15) << setprecision(2) << studentai[i].galBalas("m") << endl;
   }
}

int main() {
    string time, duomenys;
    vector<studentas> studentai;
    cout << endl << "Ar rodyti programos veikimo greičio analizę? Jei taip - spausti 't', o jei ne - bet ką kitą. ";
    cin >> time;
    if (time == "t") {
        timer();
    }
    cout << "Studentų duomenys bus įvedami ranka (spausti 'r') ar nuskaitomi iš failo (spausti 'f')? ";
    do {
        cin >> duomenys;
        if (duomenys == "r") {
            int kiek;
            string vidmed;
            do {
                cout << "Studentų skaičius: ";
                if (cin >> kiek) {
                    break;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "Įveskite skaičių. " << endl;
                }
            } while (true);
            cout << endl << "Įveskite studentų informaciją." << endl;
            for (int i = 0; i < kiek; i++) {
                studentai.push_back(apieStudenta());
            }
            print(studentai);
            //pointeris
            cout << "Studentų vektoriaus saugojimo atmintyje adresas: " << &studentai << endl;
        } else if (duomenys == "f") {
            string pavadinimas;
            cout << "Failo pavadinimas: ";
            cin >> pavadinimas;
            studentai = isFailo(pavadinimas);
            print(studentai);
        } else {
            cerr << "Įveskite 'r' arba 'f'. ";
        }
    } while (duomenys != "f" && duomenys != "r");
}