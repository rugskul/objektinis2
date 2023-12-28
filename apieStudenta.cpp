#include "studentas.h"

studentas apieStudenta() {
    studentas studentas;
    string vardas, pavarde, arAtsitiktinai;
    int pazymys, egz;
    vector<int> pazymiai;

    cout << endl << "Vardas ir pavardė: ";
    cin >> vardas >> pavarde;
    studentas.setVardas(vardas);
    studentas.setPavarde(pavarde);
    cout << "Ar pažymiai generuojami atsitiktinai (spausti 'a'), ar įvedami ranka (spausti 'r')? ";
    do {
        cin >> arAtsitiktinai;
        if (arAtsitiktinai == "a") {
            //atsitiktiniai namu darbu pazymiai ir egzamino rezultatas
            random_device rd; 
            mt19937 gen(rd());
            uniform_int_distribution<> dis(1, 10);
            for (int j = 0; j < dis(gen); j++) {
                pazymys = dis(gen);
                pazymiai.push_back(pazymys);
            }
            studentas.setEgz(dis(gen));
        } else if (arAtsitiktinai == "r") {
            //pazymiu ivedimas su enter
            cout << "Namų darbų pažymiai (baigti 2 kartus paspaudus ENTER): " << endl;
            while (true) {
                string p;
                getline(cin, p);
                if (p.empty()) {
                    if (cin.peek() == '\n') {
                        break;
                    }
                } else {
                    try {
                        pazymys = stoi(p);
                        if (pazymys < 1 || pazymys > 10) {
                            cerr << "Netinkamas pažymys. Įveskite pažymį nuo 1 iki 10. " << endl;
                        } else {
                            pazymiai.push_back(pazymys);
                        }
                    } catch (const invalid_argument& e) {
                        cerr << "Netinkamas pažymys. Įveskite skaičių." << endl;
                    }
                }
            }
            do {
                cout << "Egzamino rezultatas: ";
                cin >> egz;
                if (cin.fail() || egz < 1 || egz > 10) {
                    cerr << "Netinkamas pažymys. Iveskite skaičių nuo 1 iki 10." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    studentas.setEgz(egz);
                    break;
                }
            } while (true);
        } else {
            cerr << "Įveskite 'a' arba 'r'. ";
        }
        studentas.setPazymiai(pazymiai);
    } while (arAtsitiktinai != "a" && arAtsitiktinai != "r");
    return studentas;
}