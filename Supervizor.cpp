#include "Supervizor.h"

Supervizor::Supervizor(string nume, string prenume, string CNP, tm data_angajare, string oras_domiciliu) : Angajat(nume, prenume, CNP, data_angajare, oras_domiciliu) {}

istream &operator>>(istream &dev, Supervizor &s)
{
    s.citire(dev);
    return dev;
}

string Supervizor::rol() const
{
    return "Supervizor";
}

void Supervizor::citire(istream &dev)
{
    Angajat::citire(dev);
}

void Supervizor::scriere(ostream &dev) const
{
    Angajat::scriere(dev);
}

void Supervizor::afisare() const
{
    Angajat::afisare();
}

double Supervizor::get_salariu()
{
    // calcul an angajare- an curent
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int ani_angajati = ltm->tm_year - data_angajare.tm_year;
    return Angajat::get_salariu() + (ani_angajati * 0.05 + 0.2) * Angajat::get_salariu() + prima_transport();
}