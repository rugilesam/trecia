#ifndef STUDENTAI_H_INCLUDED
#define STUDENTAI_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cctype>
#include <stdexcept>
#include <chrono>

using namespace std;
class Zmogus {
protected:
    string vard_;
    string pav_;
    Zmogus() : vard_(""), pav_("") {}
public:
    string getName() const { return vard_;}
    string getSurname() const {return pav_;}
    void setPerson(string vard, string pav) {vard_=vard; pav_=pav;}
};

class Studentas : public Zmogus {
private:
    string vard_;
    string pav_;
    double egz_;
    vector<int> nd;
    float galutinis_;
    float vid_;
    double* elem;  // Assuming elem is a dynamically allocated array

public:
    Studentas(): Zmogus(), egz_(0), galutinis_(0), elem(nullptr) {};
    ~Studentas(); //destruktorius
    Studentas(const Studentas& other); //copy kontruktorius
    Studentas& operator=(const Studentas& other); //priskyrimo operatorius
    // išvesties operatorius
    friend std::ostream& operator<<(std::ostream& out, const Studentas &a) {
        out <<left<<setw(20)<<a.getName()<<left<<setw(20)<<a.getSurname();
            return out;
        }
    //Įvesties operatorius
    friend std::istream& operator>>(std::istream& in, Studentas &a) {
        string vard, pav;
            in >> vard >> pav;
            a.setStudentas(vard, pav);
            return in;
        }    //Getters
    //std::string getStudentas() const { return vard_, pav_; }
    std::string getName() const { return vard_; }
    std::string getSurname() const { return pav_; }
    vector<int> getNd() const { return nd; }
    int GautiEgzaminas() const { return egz_; }
    float getGalutinis() const { return galutinis_; }
    float getVid() const { return vid_; }
    int GautiDydi() const { return nd.size(); }
    double GP(int, double);
    //setters
    
    void setStudentas(std::string, std::string);
    void setEgzaminas(int);
    void setGalutinis(float);
    void setVid(float);
    void setName(string);
    void setSurname(string);
    void SetNd(int);
    void EmptyNd();
    void SortNd();


};

bool palyginimas(const Studentas& a, const Studentas& b, string rus_index);
void skaiciavimas(int& suma, int nd_sk, Studentas& temp, vector<Studentas>& grupe);
void skaiciavimas_2(int &suma, int nd_sk, Studentas& temp, vector<Studentas>& grupe);
void isvedimas(vector<Studentas> &grupe, string gen, string ats,string rus_index);
void isvedimas_list(list<Studentas> &grupe, string gen, string ats,string rus_index);

int kiek_sk(const string& failas);
void gen_failas(int stud_gen_sk, int stud_gen_nd);
void nuskaitymas(const string& failas, vector<Studentas>& grupe);
void pal_pav( vector<Studentas>& grupe, string rus_index);
void pal_pav_list(vector<Studentas>& grupe, string rus_index);
void padalinimas(vector<Studentas>& grupe, vector<Studentas>& vargsiukai);
void padalinto_spausdinimas(const vector<Studentas>& Studentas, const string& failo_pav);

#endif
