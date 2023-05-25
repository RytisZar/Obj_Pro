#include "Biblioteka.h"
struct studentas {
    string vardas, pavarde;
    int* paz;
    int kiekis;
    int egz;
};
void pild(studentas& temp) {
    cout << "Iveskite varda ir pavarde: ";
    cin >> temp.vardas >> temp.pavarde;
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
        temp.paz = new int[1];
        int pazymys, i = 0, pazymiuSkaicius = 1;
        cout << "Iveskite pazymius (baigti su bet kuriuo kita mygtuku): ";
        while (cin >> pazymys) {
            if (pazymys < 1 || pazymys > 10) { // Patikrinama ar pazymys yra nuo 1 iki 10
                cout << "Ivestas pazymys turi buti nuo 1 iki 10. Veskite is naujo" << endl;
                continue;
            }
            if (i == pazymiuSkaicius) {
                pazymiuSkaicius *= 2;
                int* naujasPaz = new int[pazymiuSkaicius];
                for (int j = 0; j < i; j++) {
                    naujasPaz[j] = temp.paz[j];
                }
                delete[] temp.paz;
                temp.paz = naujasPaz;
            }
            temp.paz[i++] = pazymys;
        }
        temp.kiekis = i;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Iveskite egzamino pazymi (nuo 1 iki 10): ";
        while (cin>>temp.egz) {
                if (!cin.fail() && temp.egz>=1 && temp.egz<=10) {
                    break;
                }
                else {
                    cout << "Neteisingas egzamino pazymys. Iveskite skaiciu nuo 1 iki 10: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
        }
    }
    else if (pasirinkimas==2){
        temp.kiekis = 5;
        temp.paz = new int[temp.kiekis];
        // Sugeneruoja atsitiktinius skaicius
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        default_random_engine generator(seed);
        uniform_int_distribution<int> distribution(1, 10);
        for (int i = 0; i < temp.kiekis; i++) {
            temp.paz[i] = distribution(generator);
        }
        temp.egz = distribution(generator);
        cout << "Atsitiktinai sugeneruotas egzamino pazymys: " << temp.egz << endl;
    }
}
double pazymiu_vidurkis(int* paz, int kiekis) {
    double sum = 0;
    for (int i = 0; i < kiekis; i++) {
        sum += paz[i];
    }
    return sum / kiekis;
}
double pazymiu_mediana(int* paz, int kiekis) {
    sort(paz, paz + kiekis);
    if (kiekis % 2 == 0) {
        return (paz[kiekis / 2 - 1] + paz[kiekis / 2]) / 2.0;
    }
    else {
        return paz[kiekis / 2];
    }
}
double galBalas (double skaicius1, int skaicius2) {
    return static_cast<double>(skaicius1*0.4+skaicius2*0.6);
}
void isvedimas(studentas *mas, int n) {
    cout << "Vardas    Pavarde     Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "---------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << mas[i].vardas << setw(14) << mas[i].pavarde << setw(7) << fixed << setprecision(2) << 
        galBalas(pazymiu_vidurkis(mas[i].paz, mas[i].kiekis), mas[i].egz) << setw(19) << 
        fixed << setprecision(2) << galBalas(pazymiu_mediana(mas[i].paz, mas[i].kiekis), mas[i].egz) << endl;
    }
    delete[] mas;
}
void ivedimas_terminale(){
    const int MAX_STUDENTS = 100;
    studentas mas[MAX_STUDENTS];
    int n = 0;
    string input;
    while (true) {
        pild(mas[n]);
        n++;
        cout << "Irasykite 't' jei daugiau nenoresite nieko vesti, arba paspauskite bet kuri kita mygtuka, kad butu galima toliau vesti: ";
        cin >> input;
        if (input == "t") {
            break;
        }
        if (n == MAX_STUDENTS) {
            cout << "Pasiektas studentu limitas.\n";
            break;
        }
    }
    isvedimas(mas, n);
}
int main() {
    ivedimas_terminale();
    return 0;
}
