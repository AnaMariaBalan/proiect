#include "Angajat.h"

class Receptioner : public Angajat
{
    vector<int> id_cereri; //lista id cereri
public:
    Receptioner()=default;
    Receptioner(string nume, string prenume, string CNP, tm data_angajare, string oras_domiciliu , vector<int> id_cereri);
    ~Receptioner()=default;

    //adauga la lista de cereri
    void adauga_cerere(int id_cerere);

    void citire(istream &dev) override;
    void scriere(ostream &dev) const override;
    void afisare() const override;
    double get_salariu() override;
};
