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

struct studentas {
    string vardas, pavarde;
    int egz;
    vector<int> pazymiai;
    double galvid, galmed;
};

template <typename Container>
void timer();

template <typename Container>
Container isFailo(string pavadinimas);
template <typename Container>
void iFaila(Container studentai, string pavadinimas);

double vidurkis(vector<int>, int);
double mediana(vector<int>, int);
void apieStudenta(studentas&);
template <typename Container>
pair<Container, Container> skirstymas(Container studentai);

void printr(vector<studentas>, string);
void printf(vector<studentas>);