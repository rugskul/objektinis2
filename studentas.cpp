#include "studentas.h"

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

istream& studentas::readStudent(istream& is) {
    string vardas, pavarde;
    int pazymys;
    if (is >> vardas >> pavarde) {
        setVardas(vardas); 
        setPavarde(pavarde); 
        pazymiai_.clear(); 
        while (is >> pazymys) {
            pazymiai_.push_back(pazymys); 
        }
        if (!pazymiai_.empty()) {
            setEgz(pazymiai_.back()); 
            pazymiai_.pop_back(); 
        }
    }
    return is;
}

bool comparePavarde(const studentas& a, const studentas& b) {
    return a.getPavarde() < b.getPavarde();
}
bool compareEgzas(const studentas& a, const studentas& b) {
    return a.getEgz() < b.getEgz();
}
bool compareGalBalas(const studentas& a, const studentas& b) {
    return a.galBalas() < b.galBalas();
}