#include "funkcijos.h"

template <typename Container>
Container isFailo(string pavadinimas) {
    Container studentai;
    ifstream file(pavadinimas);
    
    if (!file.is_open()) {
        cerr << "Nepavyko atidaryti failo." << endl;
        return studentai;
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
template vector<studentas> isFailo(string pavadinimas);

template <typename Container>
void iFaila(Container studentai, string pavadinimas) {
    ofstream outFile(pavadinimas);
    outFile << "Vardas Pavardė";
    for (int i = 1; i <= studentai[0].pazymiai.size(); ++i) {
        outFile << " ND" << i;
    }
    outFile << " Egz." << endl;
    for (int i = 0; i < studentai.size(); i++) {
        outFile << studentai[i].vardas << " " << studentai[i].pavarde << " ";
        for (int j = 0; j < studentai[i].pazymiai.size(); j++) {
            outFile << studentai[i].pazymiai[j] << " ";
        }
        outFile << studentai[i].egz << endl;
    }
    outFile.close();
}
template void iFaila(vector<studentas> studentai, string pavadinimas);