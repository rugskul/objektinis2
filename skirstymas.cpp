#include "funkcijos.h"

// template <typename Container>
// pair<Container, Container> skirstymas(Container studentai) {
//     using Studentas = typename Container::value_type;
//     Container vargsiukai;
//     Container kietekai;
//     for (auto studentas : studentai) {
//         if (studentas.galvid > 5) {
//             kietekai.push_back(studentas);
//         } else {
//             vargsiukai.push_back(studentas);
//         }
//     }
//     return make_pair(vargsiukai, kietekai);
// }
// template pair<vector<studentas>, vector<studentas>> skirstymas(vector<studentas> studentai);
// template pair<list<studentas>, list<studentas>> skirstymas(list<studentas> studentai);

template <typename Container>
pair<Container, Container> skirstymas1(Container studentai) {
    Container vargsiukai;
    Container kietekai;
    for (auto studentas : studentai) {
        if (studentas.galvid > 5) {
            kietekai.push_back(studentas);
        } else {
            vargsiukai.push_back(studentas);
        }
    }
    return make_pair(vargsiukai, kietekai);
}
template pair<vector<studentas>, vector<studentas>> skirstymas1(vector<studentas> studentai);
template pair<list<studentas>, list<studentas>> skirstymas1(list<studentas> studentai);

template <typename Container>
Container skirstymas2(Container& studentai) {
    Container vargsiukai;
    auto it = studentai.begin();
    while (it != studentai.end()) {
        if (it->galvid <= 5) {
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        } else {
            it++;
        }
    }
    return vargsiukai;
}
template vector<studentas> skirstymas2(vector<studentas>& studentai);
template list<studentas> skirstymas2(list<studentas>& studentai);