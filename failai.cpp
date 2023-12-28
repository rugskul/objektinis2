#include "studentas.h"

vector<studentas> isFailo(string failas) {
    vector<studentas> studentai;
    ifstream file(failas);
    string line;

    // ignoruoja headeri
    getline(file, line);

    while (getline(file, line)) {
        istringstream iss(line);
        studentas stud;
        stud.readStudent(iss);
        studentai.push_back(stud);
    }

    return studentai;
}

void iFaila(vector<studentas> studentai, string failas) {
    ofstream outFile(failas);

    outFile << "Vardas Pavardė";
    for (int i = 1; i <= studentai.begin()->getPazymiai().size(); ++i) {
        outFile << " ND" << i;
    }
    outFile << " Egz." << endl;

    for (auto& studentas : studentai) {
        outFile << studentas.getVardas() << " " << studentas.getPavarde() << " ";
        for (int pazymys : studentas.getPazymiai()) {
            outFile << pazymys << " ";
        }
        outFile << studentas.getEgz() << "\n";
    }
}