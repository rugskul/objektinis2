#include "funkcijos.h"

void sortStudentai(vector<studentas>& studentai, string pagal) {
    if (pagal == "1") {
        sort(studentai.begin(), studentai.end(), comparePavarde);
    } else if (pagal == "2") {
        sort(studentai.begin(), studentai.end(), compareEgzas);
    } else if (pagal == "3") {
        sort(studentai.begin(), studentai.end(), compareGalBalas);
    } else {
        sort(studentai.begin(), studentai.end(), comparePavarde);
    }
}