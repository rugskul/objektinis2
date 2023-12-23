#include "failai.h"

void print(vector<studentas> studentai) {
    cout << left << setw(15) << "Vardas" 
              << setw(15) << "Pavardė" 
              << setw(15) << "Galutinis(med.) " << endl 
              << "--------------------------------------------------------------" << endl;
    for (int i = 0; i < studentai.size(); i++) {
        cout << left << setw(15) << studentai[i].getVardas() 
                  << setw(15) << studentai[i].getPavarde() 
                  << setw(15) << setprecision(2) << studentai[i].galBalas() << endl;
    }
}

int main() {
    vector<studentas> studentai = isFailo("kursiokai1000.txt");
    sortStudentai(studentai, "3");
    vector<studentas> vargsiukai = skirstymas3(studentai);
    iFaila(studentai, "kietekai.txt");
    print(studentai);
    return 0;
}