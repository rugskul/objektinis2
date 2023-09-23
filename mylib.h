#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstdlib> 
#include <time.h>
#include <fstream>

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    int nd;
    vector<int> pazymiai;
    double galvid, galmed, egz, vidurkis, mediana;
};