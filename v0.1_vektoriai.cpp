#include "Biblioteka.h"
struct studentas {
    string vardas, pavarde;
    vector<int> paz;
    int egz;
};
void pildymas(studentas &studentai) {
    cout << "Iveskite varda ir pavarde: ";
    cin >> studentai.vardas >> studentai.pavarde;
    cout << "Pasirinkite kaip ivesite pazymius: " << endl;
    cout << "1. Ranka " << endl;
    cout << "2. Atsitiktinai sugeneruoti " << endl;
    cout << "Iveskite skaiciu: ";
    int pasirinkimas;
    while (cin >> pasirinkimas) {
        if (pasirinkimas != 1 && pasirinkimas != 2) {
            cout << "Pasirinkite 1 arba 2: ";
            continue;
        }
        break;
    }
    if (pasirinkimas == 1) {
        int pazymys;
        cout << "Iveskite pazymius (baigti su bet kuriuo kita mygtuku): ";
        while (cin >> pazymys) {
            if (pazymys < 1 || pazymys > 10) {
                cout << "Ivestas pazymys turi buti nuo 1 iki 10. Veskite is naujo" << endl;
                continue;
            }
            studentai.paz.push_back(pazymys);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Iveskite egzamino pazymi (nuo 1 iki 10): ";
        while (cin>>studentai.egz) {
                if (!cin.fail() && studentai.egz >= 1 && studentai.egz <= 10) {
                    break;
                }
                else {
                    cout << "Neteisingas pazymys. Iveskite skaiciu nuo 1 iki 10: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
        }
    }
    if (pasirinkimas==2){
        studentai.paz.resize(5);//pasirinkti skaiciu kieki, kurie bus randomizinti
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        default_random_engine generator(seed);
        uniform_int_distribution<int> distribution(1, 10); //nuo kiek iki kiek generuojami skaiciai
        for (int i = 0; i < studentai.paz.size(); i++) {
            studentai.paz[i] = distribution(generator); 
            cout<<"Atsitiktinai sugeneruotas pazymys: "<<studentai.paz[i]<<endl;
        }
        studentai.egz = distribution(generator);
        cout << "Atsitiktinai sugeneruotas egzamino pazymys: " << studentai.egz << endl;
    }
}
double pazymiu_vidurkis(const vector<int>& paz) {
    double sum = 0;
    for (const auto& pazymys : paz) {
        sum += pazymys;
    }
    return sum/ static_cast<double>(paz.size());
}
double pazymiu_mediana(const vector<int>&pazymiai) {
    vector<int> sorted_pazymiai = pazymiai; // copy the vector
    sort(sorted_pazymiai.begin(), sorted_pazymiai.end()); // sort the copy
    int dydis = sorted_pazymiai.size();
    if (dydis % 2 == 0) {
        return (sorted_pazymiai[dydis / 2 - 1] + sorted_pazymiai[dydis / 2]) / 2.0;
    }
    else {
        return sorted_pazymiai[dydis / 2];
    }
}
double galBalas (double skaicius_1, int skaicius_2) {
    return static_cast<double>(skaicius_1*0.4+skaicius_2*0.6);
}
void isvedimas(const vector<studentas>& studentai) {
    cout << "Vardas    Pavarde     Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "---------------------------------------------------------" << endl;
    for (const studentas& temp : studentai) {
        cout << temp.vardas << setw(14) <<
            temp.pavarde << setw(7) << fixed << setprecision(2) <<
            galBalas(pazymiu_vidurkis(temp.paz), temp.egz) << setw(19) << fixed <<
            setprecision(2) << galBalas(pazymiu_mediana(temp.paz), temp.egz) << endl;
    }
}
vector<studentas> ivedimas() {
    const int MAXAS = 100;//reguliuoti kiek galima ivesti studentu
    vector<studentas> studentai;
    string input;
    while (true) {
        studentas temp;
        pildymas(temp);
        studentai.push_back(temp);
        cout << "Irasykite 't' jei daugiau nenoresite nieko vesti, arba paspauskite bet kuri kita mygtuka, kad butu galima toliau vesti: ";
        cin >> input;
        if (input == "t" || studentai.size() == MAXAS) {
            break;
        }
    }
    return studentai;
}
int main() {
    vector<studentas> stud= ivedimas();
    isvedimas(stud);
    return 0;
}