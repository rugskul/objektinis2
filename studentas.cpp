#include "studentas.h"

studentas::studentas(istream& is) { 
    readStudent(is);  
}

double studentas::galBalas(string vidmed) const {
    if (vidmed == "v") {
        return 0.4*vidurkis(pazymiai_) + 0.6*egz_;
    } else if (vidmed == "m") {
        return 0.4*mediana(pazymiai_) + 0.6*egz_;
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