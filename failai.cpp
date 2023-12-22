#include "failai.h"

vector<studentas> readStudentsFromFile(string failas) {
    cout << "Reading students from file " << endl;
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