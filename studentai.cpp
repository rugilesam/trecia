#include "studentai.h"


//konstruktorius
//Studentas::Studentas() {
 //   egz_=0;
 //   elem = new double [egz_];
//}
//destruktorius
Studentas::~Studentas() {
    delete[] elem;
   // cout<<"Objektas istrintas"<<endl;
}
// Copy Constructor
Studentas::Studentas(const Studentas& other) {
    
    vard_ = other.vard_;
    pav_ = other.pav_;
    egz_ = other.egz_;
    nd = other.nd;
    galutinis_ = other.galutinis_;
    vid_ = other.vid_;
    // Deep copy of the dynamic array elem
    if (other.elem != nullptr) {
        elem = new double[other.nd.size()];
        std::copy(other.elem, other.elem + other.nd.size(), elem);
    } else {
        elem = nullptr;
    }
}
 //priskyrimo operatorius
Studentas& Studentas::operator=(const Studentas& other)  {
    if (this != &other) {
        // Perform deep copy of resources
        vard_ = other.vard_;
        pav_ = other.pav_;
        egz_ = other.egz_;
        nd = other.nd;
        galutinis_ = other.galutinis_;
        vid_ = other.vid_;
        // Deallocate existing dynamic array
        delete[] elem;
        // Deep copy of the dynamic array elem
        if (other.elem != nullptr) {
            elem = new double[other.nd.size()];
            std::copy(other.elem, other.elem + other.nd.size(), elem);
        } else {
            elem = nullptr;
        }
    }
    return *this;
}



        void Studentas::setStudentas(std::string vard,std::string pav)
        {
            vard_ = vard;
            pav_ = pav;
        }

        void Studentas::setName(std::string vard)
        {
            vard_ = vard;
        }
        void Studentas::setSurname(string pav){
            pav_ = pav;
        }
        
        void Studentas::setEgzaminas(int egz) {
            egz_ = egz;
        }
        void Studentas::setGalutinis(float galutinis) {
            galutinis_ = galutinis;
        }
        void Studentas::setVid(float vid) {
            vid_ = vid;
        }
        
        void Studentas::SetNd(int Score)
        {
            nd.push_back(Score);
        }
        
        void Studentas::EmptyNd()
        {
            nd.clear();
        }
        void Studentas::SortNd() {
            sort(nd.begin(), nd.end());
        }
        
        int kiek_sk(const string& failas) {
            int kiekis = 0;
            string numberPart;
            bool rastas_sk = false;
            
            for (char c : failas) {
                if (rastas_sk) {
                    if (std::isdigit(c)) {
                        numberPart += c;
                    }
                    else {
                        break;  // Sustoja kai suranda ne skaiciu
                    }
                }
                else if (std::isdigit(c)) {
                    rastas_sk = true;
                    numberPart += c;
                }
            }
            
            if (!numberPart.empty()) {
                // Surinktas skaicius is eilutes paverciamas i sveikajo skaiciu
                std::istringstream(numberPart) >> kiekis;
            }
            
            return kiekis;
        }
        
        //Palyginimas pagal P,V,G
        bool palyginimas(const Studentas& a, const Studentas& b, string rus_index) {
            if (rus_index == "p") {
                return a.getSurname() < b.getSurname();
            }
            else if (rus_index == "v") {
                return a.getName() < b.getName();
            }
            else if (rus_index == "g") {
                return a.getGalutinis() < b.getGalutinis();
            }
            else {
                // Automatinis nustatymas, kai rus_index neatpazintas
                return false;
            }
        }
        void pal_pav( vector<Studentas>& grupe, string rus_index) {
            sort(grupe.begin(), grupe.end(), [rus_index](const Studentas& a, const Studentas& b) {
                return palyginimas(a, b, rus_index);
            });
        }
        
        void pal_pav_list(vector<Studentas>& grupe, string rus_index) {
            std::sort(grupe.begin(), grupe.end(), [rus_index](const Studentas& a,const  Studentas& b) {
                return palyginimas(a, b, rus_index);
            });
        }
        
        void skaiciavimas(int& suma, int nd_sk, Studentas& temp, vector<Studentas>& grupe) {
            double sumaNd = 0;
            
            for (int i = 0; i < temp.GautiDydi(); i++) {
                sumaNd += temp.getNd()[i];
            }
            
            temp.setGalutinis(0.4*(sumaNd / temp.GautiDydi() + 0.6 * temp.GautiEgzaminas()));
            grupe.push_back(temp);
            temp.getNd().clear();
            suma = 0;
        }
        
        void skaiciavimas_2(int &suma, int nd_sk, Studentas& temp, vector<Studentas>& grupe) {
            
            double vidurkis = static_cast<float>(suma) / nd_sk;
            // temp.getVid(static_cast<float>(suma)/nd_sk);
            temp.setGalutinis(vidurkis * 0.4 + temp.GautiEgzaminas() * 0.6);
            grupe.push_back(temp);
            temp.getNd().clear();
            suma = 0;
        }
        
        
        void nuskaitymas(const string& failas, vector<Studentas>& grupe) {
            std::ifstream in(failas);
            if (!in.is_open()) {
                std::cerr << "Klaida: Failas nerastas." << std::endl;
                return;
            }
            Studentas stud;
            string pavadinimas, praleidziam;
            getline(in, pavadinimas);
            // Studentas temp;
            int laik_kint, suma = 0, m = 0;
            double nd_sk = 0;
            int raidziu_sk = 0;
            for (char ch : pavadinimas) {
                if (isalpha(ch)) {
                    raidziu_sk++;
                }
            }
            
            nd_sk = (raidziu_sk - 6 - 7 - 3) / 2;
            
            string vard, pav;
            int egz;
            while (in >> vard >> pav) {
                stud.setName(vard);
                stud.setSurname(pav);
                for (int i = 0; i < nd_sk; i++) {
                    in >> laik_kint;
                    stud.SetNd(laik_kint);
                    suma+=laik_kint;
                }
                
                in >> egz;
                stud.setEgzaminas(egz);
                getline(in, praleidziam);
                
                skaiciavimas_2(suma,nd_sk,stud,grupe);
                m++;
            }
            
            in.close();
        }
        
        
        
        void padalinimas(vector<Studentas>& grupe, vector<Studentas>& vargsiukai) {
            
            // Iš pradinio konteinerio perkeliami vargšiukai į naująjį "vargšiukai" konteinerį
            auto partitionPoint = std::partition(grupe.begin(), grupe.end(), [](const Studentas& a) {
                return a.getGalutinis() > 5;
            });
            
            vargsiukai.insert(vargsiukai.end(), partitionPoint, grupe.end());
            
            // Iš pradinio konteinerio ištrinami vargšiukai
            grupe.erase(partitionPoint, grupe.end());
        }
        
        //spausdinimo funkcija kietiakam ir vargsiukam
        
        void padalinto_spausdinimas(const vector<Studentas>& Studentas, const string& failo_pav) {
            ofstream out(failo_pav);
            
            out << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis" << endl;
            out << endl;
            
            for (const auto& stud : Studentas) {
                out << left << setw(20) << stud.getSurname() << setw(20) << stud.getName() << setw(20) << fixed << setprecision(2) << stud.getGalutinis() << endl;
                
                
            }
            out.close();
        }
    
