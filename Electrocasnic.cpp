#include "Electrocasnic.h"

Electrocasnic::Electrocasnic(string tip, string marca, string model, int an_fabricatie, double pret_catalog)
    : tip(tip), marca(marca), model(model), an_fabricatie(an_fabricatie), pret_catalog(pret_catalog) {}

void Electrocasnic::afisare() const
{
    cout << "Tip: " << tip << "\nMarca: " << marca << "\nModel: " << model << "\nAn fabricatie: " 
    << an_fabricatie << "\nPret catalog: " << pret_catalog << endl;
}