#include "mylib.h"

void apiestudenta(studentas &studentas) {
    cout << "Vardas ir pavardė: ";
    cin >> studentas.vardas >> studentas.pavarde;
    cout << "Namų darbų pažymiai (baigti 2 kartus paspaudus ENTER): " << endl;

    //pazymiu ivedimas su enter
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
            studentas.pazymiai.push_back(pazymys);
        }
    }
    int nd = studentas.pazymiai.size();

    //galutinis (vid)
    double suma = 0;
    for (int i; i < studentas.nd; i++) {
        suma += studentas.pazymiai[i];
    }
    studentas.galvid = 0.4*(suma/studentas.nd)+0.6*studentas.egz;

    //galutinis (med)
    sort(studentas.pazymiai.begin(), studentas.pazymiai.end());
    if (studentas.nd % 2 == 0) {
        studentas.mediana = (double)(studentas.pazymiai[nd/2-1] + studentas.pazymiai[nd/2])/2;
    } else {
        studentas.mediana = studentas.pazymiai[nd/2];
    }
    studentas.galmed = 0.4*studentas.mediana+0.6*studentas.egz;
}

int main() {
    int kiek;
    cout << "Studentų skaičius: ";
    cin >> kiek;

    vector<studentas> studentai;

    for (int i = 0; i < kiek; i++) {
        studentas s;
        apiestudenta(s);
        studentai.push_back(s);
    }

    string vidmed;
    cout << "Galutinis balas pagal vidurkį(v) ar medianą(m)? ";
    cin >> vidmed;
    
    //printina lentele
    if (vidmed == "v") {
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavardė" << setw(10) << "Galutinis" << endl << 
        "---------------------------------------" << endl;
        for (int i = 0; i < studentai.size(); i++) {
            cout << left << setw(15) << studentai[i].vardas << setw(15) << studentai[i].pavarde << studentai[i].galvid;
            cout << endl;
        }
    }
    if (vidmed == "m") {
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavardė" << setw(10) << "Galutinis" << endl << 
        "---------------------------------------" << endl;
        for (int i = 0; i < studentai.size(); i++) {
            cout << left << setw(15) << studentai[i].vardas << setw(15) << studentai[i].pavarde << studentai[i].galmed;
            cout << endl;
        }
    }
}