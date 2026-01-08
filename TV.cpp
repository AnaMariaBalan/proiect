#include "TV.h"

Tv::Tv(string tip, string marca, string model, int an_fabricatie, double pret_catalog, int dim_diagonala)
    : Electrocasnic(tip, marca, model, an_fabricatie, pret_catalog), dim_diagonala(dim_diagonala) {}
void Tv::afisare() const
{
    Electrocasnic::afisare();
    cout << "Dimensiune diagonala: " << dim_diagonala << " cm" << endl;
}