#include "Biblioteka.h"
struct studentas {
    string vardas, pavarde;
    vector<int> paz;
    int egz;
};
void pildymas(studentas &studentai);
double pazymiu_vidurkis(const vector<int>& paz);
double pazymiu_mediana(const vector<int>&pazymiai);
double galBalas (double skaicius_1, int skaicius_2);
void skaitymas_is_failo(vector <studentas>& studentai, const std::string & file_name);
void isvedimas(const vector<studentas>& studentai);
vector<studentas> ivedimas();
bool palygintiStudentus(const studentas& student1, const studentas& student2);
void rusiavimasStudentu(vector<studentas>& studentai);

