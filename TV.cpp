#include "TV.h"

TV::TV(string tip, string marca, string model, int an_fabricatie, double pret_catalog, int dim_diagonala)
    : Electrocasnic(tip, marca, model, an_fabricatie, pret_catalog), dim_diagonala(dim_diagonala) {}
void TV::afisare() const
{
    Electrocasnic::afisare();
    cout << "Dimensiune diagonala: " << dim_diagonala << " cm" << endl;
}


void TV::citire(istream &dev)
{
    Electrocasnic::citire(dev);
    bool isTastatura = (&dev == &std::cin);
    if (isTastatura)
        cout << "Introduceti dimensiune diagonala: ";
    dev>>dim_diagonala;
}
void TV::scriere(ostream &dev) const
{
    Electrocasnic::scriere(dev);
    dev<<dim_diagonala<<endl;
}