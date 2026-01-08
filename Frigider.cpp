#include "Frigider.h"

Frigider::Frigider(string tip, string marca, string model, int an_fabricatie, double pret_catalog, bool are_congelator)
    : Electrocasnic(tip, marca, model, an_fabricatie, pret_catalog), are_congelator(are_congelator) {}

void Frigider::afisare() const
{
    Electrocasnic::afisare();
    cout << "Are congelator: " << (are_congelator ? "Da" : "Nu") << endl;
}