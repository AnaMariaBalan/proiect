#include "Tehnician.h"

Tehnician::Tehnician(string nume, string prenume, string CNP, tm data_angajare, string oras_domiciliu, multimap<string, string> tip_marca, double bonus) : Angajat(nume, prenume, CNP, data_angajare, oras_domiciliu)
{
    this->tip_marca = tip_marca;
    this->bonus = bonus;
}

//------------------------------------------------------

string Tehnician::rol() const
{
    return "Tehnician";
}

void Tehnician::citire(istream &dev)
{
    Angajat::citire(dev);
    bool isTastatura = (&dev == &std::cin);
    string tip, marca;
    if (isTastatura)
        cout << "Introduceti tipul si marca cu care se specializeaza (tastati 0 pentru finalizare):\n";
    while (true)
    {
        if (isTastatura)
            cout << "Tip: ";
        dev >> tip;
        if (tip == "0" || tip == "\n")
            break;
        if (isTastatura)
            cout << "Marca: ";
        dev >> marca;
        tip_marca.insert({tip, marca});
    }
}

void Tehnician::scriere(ostream &dev) const
{
    Angajat::scriere(dev);
    for (const auto &pair : tip_marca)
    {
        dev << pair.first << " " << pair.second << " ";
    }
    dev << "0\n";
}

void Tehnician::afisare() const
{
    Angajat::afisare();
    cout << "Tipuri si marci cu care se ocupa:" << endl;
    for (const auto &pair : tip_marca)
    {
        cout << "Tip: " << pair.first << ", Marca: " << pair.second << endl;
    }
}
double Tehnician::get_salariu()
{
    // calcul an angajare- an curent
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int ani_angajati = ltm->tm_year - data_angajare.tm_year;
    return Angajat::get_salariu() + ani_angajati * 0.05 * Angajat::get_salariu() + prima_transport() /*+bonus*/;
}

void Tehnician::addBonus(/*pret_reparatie*/)
{
    // bonus += pret_reparatie * 0.02;
}