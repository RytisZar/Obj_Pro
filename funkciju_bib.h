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
void sukurimas_random_failo(const std::string&failo_pav, int studentu_skaicius);
bool studentuPalyginimas(const studentas& s1, const studentas& s2);
void spausdintiStudentus(const vector<studentas>& studentai, ofstream& outfile);
void rusiuotiStudentus(const vector<studentas>& studentai);

