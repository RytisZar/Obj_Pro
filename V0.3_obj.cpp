#include "funkciju_bib.h"

int main() {
    int ivestis;
    cout<<"Pasirinkite kaip norite gauti studentu duomenis: "<<endl;
    cout<<"1. Suvedimas ranka \n"<<"2. Failo skaitymas\n";
    cout<<"Jusu pasirinkimas: ";
    while (cin>>ivestis) {
        if (ivestis != 1 && ivestis != 2) {
            cout << "Pasirinkite 1 arba 2: ";
            continue;
        }
        break;
    }
    if (ivestis==1) {
        vector<studentas>stud= ivedimas();
        isvedimas(stud);
    }
    else if (ivestis==2) {
        vector<studentas>stud;
        skaitymas_is_failo(stud, "studentai100000.txt");
        rusiavimasStudentu(stud);
        isvedimas(stud);
    }
    return 0;
}