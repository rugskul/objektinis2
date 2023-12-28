#include "studentas.h"

pair<vector<studentas>, vector<studentas>> skirstymas1(vector<studentas> studentai) {
    vector<studentas> vargsiukai, kietekai;
    for (auto& studentas : studentai) {
        if (studentas.galBalas("v") > 5) {
            kietekai.push_back(studentas);
        } else {
            vargsiukai.push_back(studentas);
        }
    }
    return make_pair(vargsiukai, kietekai);
}

vector<studentas> skirstymas2(vector<studentas>& studentai) {
    vector<studentas> vargsiukai;
    auto it = studentai.begin();
    while (it != studentai.end()) {
        if (it->galBalas("v") <= 5) {
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        } else {
            it++;
        }
    }
    return vargsiukai;
}

vector<studentas> skirstymas3(vector<studentas>& studentai) {
    vector<studentas> vargsiukai;
    auto partitionIt = stable_partition(studentai.begin(), studentai.end(), [](studentas& studentas) { return studentas.galBalas("v") > 5; });
    vargsiukai.insert(vargsiukai.end(), make_move_iterator(partitionIt), make_move_iterator(studentai.end()));
    studentai.erase(partitionIt, studentai.end());
    return vargsiukai;
}