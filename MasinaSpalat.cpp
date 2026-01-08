#include "MasinaSpalat.h"

MasinaSpalat::MasinaSpalat(string tip, string marca, string model, int an_fabricatie, double pret_catalog, double capacitate)
    : Electrocasnic(tip, marca, model, an_fabricatie, pret_catalog), capacitate(capacitate) {} 
void MasinaSpalat::afisare() const
{
    Electrocasnic::afisare();
    cout << "Capacitate: " << capacitate << " kg" << endl;
}   