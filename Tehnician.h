#include "Angajat.h"
#include <map>

class Tehnician : public Angajat
{
    multimap<string, string> tip_marca; // multimap tip si marca cu care se pricepe
    double bonus = 0;

public:
    Tehnician() = default;
    Tehnician(string nume, string prenume, string CNP, tm data_angajare, string oras_domiciliu, multimap<string, string> tip_marca, double bonus = 0);
    ~Tehnician() = default;

    void addBonus();

    void citire(istream &dev) override;
    void scriere(ostream &dev) const override;
    void afisare() const override;
    double get_salariu() override;
};
