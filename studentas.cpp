#include "studentas.h"

double vidurkis(vector<int> v) {
    double suma = 0;
    for (int i=0; i < v.size(); i++) {
        suma += v[i];
    }
    return suma/v.size();
}
double mediana(vector<int> v) {
    sort(v.begin(), v.end());
    int n = v.size();
    if (n % 2 == 0) {
        return (v[(n - 1) / 2] + v[n / 2]) / 2.0;
    } else {
        return v[n / 2];
    }
}

studentas::studentas(istream& is) { 
    readStudent(is);  
}

double studentas::galBalas(string vidmed) const {
    if (vidmed == "v") {
        return 0.4*vidurkis(pazymiai_) + 0.6*egz_;
    } else if (vidmed == "m") {
        return 0.4*mediana(pazymiai_) + 0.6*egz_;
    } else {
        throw invalid_argument("Netinkamas parametras. Iveskite 'v' arba 'm'.");
    }
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
    return a.galBalas("v") < b.galBalas("v");
}