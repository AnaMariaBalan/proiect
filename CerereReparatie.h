#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class CerereReparatie
{
private:
    static int ID;
    string model;
    string marca;
    string detalii;
    //timestamp depunere cerere (data + ora) unic
    int complexitate; //1-5
    int durata_estimata;
    int pret;
public:
    CerereReparatie() = default;
    CerereReparatie(string model, string marca, string detalii, /*timestamp*/ int complexitate, int durata_estimata, int pret);
    ~CerereReparatie() = default;
    void afisare() const;
};
