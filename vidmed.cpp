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