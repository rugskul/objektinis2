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

class zmogus {
protected:
    string vardas_;
    string pavarde_;
public:
    zmogus(string vardas = "", string pavarde = "") : vardas_{vardas}, pavarde_{pavarde} {}
    virtual ~zmogus() = default;

    virtual void setVardas(const string& vardas) = 0;
    virtual string getVardas() const = 0;

    virtual void setPavarde(const string& pavarde) = 0;
    virtual string getPavarde() const = 0;
};

class studentas : public zmogus {
private:
    int egz_;
    vector<int> pazymiai_;
public:
    // default konstruktorius
    studentas() : egz_(0), pazymiai_({}) {}
    // konstruktorius su parametrais
    studentas(const string& vardas, const string& pavarde, const int& egz, const vector<int>& pazymiai)
        : zmogus(vardas, pavarde), egz_(egz), pazymiai_(pazymiai) {}
    // 1. Copy constructor
    studentas(const studentas& other)
        : zmogus(other), egz_(other.egz_), pazymiai_(other.pazymiai_) {}
    // 2. Copy assignment operator
    studentas& operator=(const studentas& other) {
        if (this != &other) {
            zmogus::operator=(other);
            egz_ = other.egz_;
            pazymiai_ = other.pazymiai_;
        }
        return *this;
    } 
    // 3. destuktorius
    ~studentas() override {}

    void setVardas(const string& vardas) { vardas_ = vardas; }
    string getVardas() const { return vardas_; }

    void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    string getPavarde() const { return pavarde_; }

    void setEgz(const int& egz) { egz_ = egz; }
    int getEgz() const { return egz_; }

    void setPazymiai(const vector<int>& pazymiai) { pazymiai_ = pazymiai; }
    vector<int> getPazymiai() const { return pazymiai_; }
    
    friend ostream& operator<<(ostream& out, const studentas& s) {
        out << fixed;
        out << setw(15) << left << s.vardas_ << setw(15) << left << s.pavarde_ << setw(15) << left << setprecision(2) << s.galBalas("v") << setw(15) << left << setprecision(2) << s.galBalas("m") << "\n";
        return out;
    }
    friend istream& operator>>(istream& in, studentas& s) {
        in >> s.vardas_ >> s.pavarde_;
        return in;
    }

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