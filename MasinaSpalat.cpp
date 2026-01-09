#include "MasinaSpalat.h"

MasinaSpalat::MasinaSpalat(string tip, string marca, string model, int an_fabricatie, double pret_catalog, double capacitate)
    : Electrocasnic(tip, marca, model, an_fabricatie, pret_catalog), capacitate(capacitate) {} 
void MasinaSpalat::afisare() const
{
    Electrocasnic::afisare();
    cout << "Capacitate: " << capacitate << " kg" << endl;
}   

void MasinaSpalat::citire(istream &dev)
{
    Electrocasnic::citire(dev);
    bool isTastatura = (&dev == &std::cin);
    if (isTastatura)
        cout << "Introduceti capacitate (in kg): ";
    dev>>capacitate;
}
void MasinaSpalat::scriere(ostream &dev) const
{
    Electrocasnic::scriere(dev);
    dev<<capacitate<<endl;
}