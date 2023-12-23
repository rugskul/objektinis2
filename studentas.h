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

using namespace std;

class studentas {
private:
    string vardas_;
    string pavarde_;
    int egz_;
    vector<int> pazymiai_;
public:
    studentas() : vardas_(""), pavarde_(""), egz_(0), pazymiai_({}) {}
    studentas(const string& vardas, const string& pavarde, const double& egz, const vector<int>& pazymiai): 
        vardas_(vardas), pavarde_(pavarde), egz_(egz), pazymiai_(pazymiai) {}

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