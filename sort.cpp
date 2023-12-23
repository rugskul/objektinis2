#include "studentas.h"

void sortStudentai(vector<studentas>& studentai, string pagal) {
    if (pagal == "1") {
        sort(studentai.begin(), studentai.end(), comparePavarde);
    } else if (pagal == "2") {
        sort(studentai.begin(), studentai.end(), comparePagalEgza);
    } else if (pagal == "3") {
        sort(studentai.begin(), studentai.end(), compareGalBalas);
    } else {
        cout << "Įvestas netinkamas rūšiavimo kriterijus. Bus rūšiuojama pagal pavardę. " << endl;
        sort(studentai.begin(), studentai.end(), comparePavarde);
    }
}