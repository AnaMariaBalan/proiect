// angajati
#include "Receptioner.h"
#include "Tehnician.h"
#include "Supervizor.h"
// electrocasnice
#include "Electrocasnic.h"
// cereri
#include "CerereReparatie.h"
//
#include "functii.h"

using namespace std;

class FixItNow
{
    vector<Angajat *> angajati;
    vector<Electrocasnic *> electrocasnice;
    vector<CerereReparatie *> cereri;

public:
    FixItNow() = default;
    FixItNow(vector<Angajat *> angajati, vector<Electrocasnic *> electrocasnice, vector<CerereReparatie *> cereri);
    ~FixItNow() = default;

    // functii meniu
    void meniu(string file);

    void modificare_nume_angajat(string location);
    void stergere_angajat(string location);      // delete
    void stergere_date_angajat(string location); // anonimizez
    void afisare_date_angajat();                 //+salariu
    void afisare_lista_angajati();               // toti!
};
