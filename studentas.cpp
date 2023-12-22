#include "studentas.h"

// konstruktoriaus realizacija
studentas::studentas(istream& is) { 
    readStudent(is);  
}

double studentas::galBalas() const {
    double mediana;
    vector<int> v = pazymiai_;
    sort(v.begin(), v.end());
    int n = v.size();
    if (n % 2 == 0) {
        mediana = (v[(n - 1) / 2] + v[n / 2]) / 2.0;
    } else {
        mediana = v[n / 2];
    }
    return mediana*0.4 + egz_*0.6;
}

// Studentas::readStudent realizacija
istream& studentas::readStudent(istream& is) {
    string vardas, pavarde;
    int pazymys;
    if (is >> vardas >> pavarde) {
        setVardas(vardas); // set the student's first name
        setPavarde(pavarde); // set the student's last name
        pazymiai_.clear(); // clear the grades vector
        while (is >> pazymys) {
            pazymiai_.push_back(pazymys); // add the grade to the student's grades
        }
        if (!pazymiai_.empty()) {
            setEgz(pazymiai_.back()); // set the student's exam score
            pazymiai_.pop_back(); // remove the last grade, which is now the exam score
        }
    }
    return is;
}

// Ne Studentas member funkcija, bet dirba su Studentas objektais, todėl realizacija čia
bool compare(const studentas& a, const studentas& b) {
    return a.galBalas() < b.galBalas();
}

bool comparePagalPavarde(const studentas& a, const studentas& b) {
    return a.getPavarde() < b.getPavarde();
}

bool comparePagalEgza(const studentas& a, const studentas& b) {
    return a.getEgz() < b.getEgz();
}