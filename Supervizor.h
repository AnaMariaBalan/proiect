#include "Angajat.h"

class Supervizor : public Angajat
{
public:
    Supervizor() = default;
    Supervizor(string nume, string prenume, string CNP, tm data_angajare, string oras_domiciliu);
    friend istream &operator>>(istream &dev, Supervizor &s);
    ~Supervizor()=default;

    string rol() const override;
    void citire(istream &dev) override;
    void scriere(ostream &dev) const override;
    void afisare() const override;
    double get_salariu() override;
};
