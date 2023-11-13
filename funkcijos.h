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

using namespace std;

struct studentas {
    string vardas, pavarde;
    int egz;
    vector<int> pazymiai;
    double galvid, galmed;
};

void timer();

vector<studentas> isFailo(string);
void iFaila(vector<studentas>, string);

double vidurkis(vector<int>, int);
double mediana(vector<int>, int);
void apieStudenta(studentas&);
vector<vector<studentas>> skirstymas(vector<studentas>);

void printr(vector<studentas>, string);
void printf(vector<studentas>);