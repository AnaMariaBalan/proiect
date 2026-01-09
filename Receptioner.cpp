#include "Receptioner.h"

Receptioner::Receptioner(string nume, string prenume, string CNP, tm data_angajare, string oras_domiciliu, vector<int> id_cereri) : Angajat(nume, prenume, CNP, data_angajare, oras_domiciliu)
{
    this->id_cereri = id_cereri;
}

//------------------------------------------------------

istream &operator>>(istream &dev, Receptioner &r)
{
    r.citire(dev);
    return dev;
}


string Receptioner::rol() const
{
    return "Receptioner";
}

void Receptioner::citire(istream &dev) // CEREILE SE ADUAGA PE PARCURS cu adauga_cerere
{
    Angajat::citire(dev);
    // id_cereeri nula
}

void Receptioner::scriere(ostream &dev) const
{
    Angajat::scriere(dev);
    for (int id : id_cereri)
        dev << id << " ";
}

//------------------------------------------------------

void Receptioner::afisare() const
{
    Angajat::afisare();
    cout << "Cereri atribuite: ";
    for (int id : id_cereri)
        cout << id << " ";
    cout << endl;
}

double Receptioner::get_salariu()
{
    // calcul an angajare- an curent
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int ani_angajati = ltm->tm_year - data_angajare.tm_year;
    return Angajat::get_salariu() + ani_angajati * 0.05 * Angajat::get_salariu() + prima_transport();
}

//------------------------------------------------------

void Receptioner::adauga_cerere(int id_cerere)
{
    id_cereri.push_back(id_cerere);
}