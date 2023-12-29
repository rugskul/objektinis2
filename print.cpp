#include "studentas.h"

void print(vector<studentas> studentai) {
   cout << left << setw(15) << "Vardas" 
        << setw(15) << "Pavardė" 
        << setw(15) << "Galutinis(vid.) " 
        << setw(15) << "Galutinis(med.) " << endl 
        << "--------------------------------------------------------------" << endl;
   for (int i = 0; i < studentai.size(); i++) {
      cout << studentai[i];
   }
}