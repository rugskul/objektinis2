#include "funkcijos.h"

vector<studentas> isFailo(string pavadinimas) {
    vector<studentas> studentai;
    ifstream file(pavadinimas);
    if (!file.is_open()) {
        cerr << "Nepavyko atidaryti failo." << endl;
    }
    string pirma;
    getline(file, pirma);
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        studentas studentas;
        int pazymys;
        if (iss >> studentas.vardas >> studentas.pavarde) {
            while (iss >> pazymys) {
                studentas.pazymiai.push_back(pazymys);
            }
            if (!studentas.pazymiai.empty()) {
                studentas.egz = studentas.pazymiai.back();
                studentas.pazymiai.pop_back();
                studentas.galvid = vidurkis(studentas.pazymiai, studentas.egz);
                studentas.galmed = mediana(studentas.pazymiai, studentas.egz);
            }
            studentai.push_back(studentas);
        }
    }
    file.close();
    return studentai;
}

void iFaila(vector<studentas> v, string pavadinimas) {
    ofstream outFile(pavadinimas);
    outFile << "Vardas Pavardė";
    for (int i = 1; i <= v[0].pazymiai.size(); ++i) {
        outFile << " ND" << i;
    }
    outFile << " Egz." << endl;
    for (int i = 0; i < v.size(); i++) {
        outFile << v[i].vardas << " " << v[i].pavarde << " ";
        for (int j = 0; j < v[i].pazymiai.size(); j++) {
            outFile << v[i].pazymiai[j] << " ";
        }
        outFile << v[i].egz << endl;
    }
    outFile.close();
}