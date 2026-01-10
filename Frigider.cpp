#include "Frigider.h"

Frigider::Frigider(string tip, string marca, string model, int an_fabricatie, double pret_catalog, bool are_congelator)
    : Electrocasnic(tip, marca, model, an_fabricatie, pret_catalog), are_congelator(are_congelator) {}

void Frigider::citire(istream &dev)
{
    Electrocasnic::citire(dev);
    bool isTastatura = (&dev == &std::cin);
    if (isTastatura)
        cout << "Are congelator? (y/n))\n";
    char c;
    dev >> c;
    if (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
        throw("Raspuns invalid.\n");
    else if (c == 'y' || c == 'Y')
        are_congelator = true;
    are_congelator = false;
}
void Frigider::scriere(ostream &dev) const
{
    Electrocasnic::scriere(dev);
    if (are_congelator==true)
        dev << 'y' << endl;
    else
        dev << 'n' << endl;
}

void Frigider::afisare() const
{
    Electrocasnic::afisare();
    cout << "Are congelator? " << (are_congelator ? "Da" : "Nu") << endl; 
}