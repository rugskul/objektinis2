#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include <list>
#include <random>

using namespace std;

class studentas {
private:
    string vardas_;
    string pavarde_;
    int egz_;
    vector<int> pazymiai_;
public:
    // default konstruktorius
    studentas() : vardas_(""), pavarde_(""), egz_(0), pazymiai_({}) {}
    // konstruktorius su parametrais
    studentas(const string& vardas, const string& pavarde, const int& egz, const vector<int>& pazymiai): 
        vardas_(vardas), pavarde_(pavarde), egz_(egz), pazymiai_(pazymiai) {}
    // 1. Copy constructor
    studentas(const studentas& other) 
        : vardas_(other.vardas_), pavarde_(other.pavarde_), egz_(other.egz_), pazymiai_(other.pazymiai_) {}
    // 2. Copy assignment operator
    studentas& operator=(const studentas& other) {
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            egz_ = other.egz_;
            pazymiai_ = other.pazymiai_;
        }
        return *this;
    }   
    // 3. destuktorius
    ~studentas() {}

    void setVardas(const string& vardas) { vardas_ = vardas; }
    string getVardas() const { return vardas_; }

    void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    string getPavarde() const { return pavarde_; }

    void setEgz(const int& egz) { egz_ = egz; }
    int getEgz() const { return egz_; }

    void setPazymiai(const vector<int>& pazymiai) { pazymiai_ = pazymiai; }
    vector<int> getPazymiai() const { return pazymiai_; }

    studentas(istream& is);
    double galBalas(string vidmed) const;
    istream& readStudent(istream&);

};
bool comparePavarde(const studentas&, const studentas&);
bool compareEgzas(const studentas&, const studentas&);
bool compareGalBalas(const studentas&, const studentas&);

double vidurkis(vector<int>);
double mediana(vector<int>);

studentas apieStudenta();

vector<studentas> isFailo(string);
void iFaila(vector<studentas>, string);

void sortStudentai(vector<studentas>&, string);

pair<vector<studentas>, vector<studentas>> skirstymas1(vector<studentas>);
vector<studentas> skirstymas2(vector<studentas>&);
vector<studentas> skirstymas3(vector<studentas>&);

void timer();

void print(vector<studentas>);