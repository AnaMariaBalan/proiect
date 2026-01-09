#include "Electrocasnic.h"

Electrocasnic::Electrocasnic(string tip, string marca, string model, int an_fabricatie, double pret_catalog)
    : marca(marca), model(model), an_fabricatie(an_fabricatie), pret_catalog(pret_catalog)
{
    if (tip == "Frigider" || tip == "frigider" || tip == "tv" || tip == "TV" || tip == "masina de spalat" || tip == "Masina de spalat")
        this->tip = tip;
    else
        throw("Tip electrocasnic invalid.\n");
}

void Electrocasnic::afisare() const
{
    cout << "Tip: " << tip << "\nMarca: " << marca << "\nModel: " << model << "\nAn fabricatie: "
         << an_fabricatie << "\nPret catalog: " << pret_catalog << endl;
}

void Electrocasnic::citire(istream &dev)
{
    bool isTastatura = (&dev == &std::cin);
    string tip_temp, marca_temp, model_temp;
    int an_temp, pret_temp;

    if (isTastatura)
        cout << "Tip: ";
    dev >> tip_temp;
    if (tip == "Frigider" || tip == "frigider" || tip == "tv" || tip == "TV" || tip == "masina de spalat" || tip == "Masina de spalat")
        tip = tip_temp;
    else
        throw("Tip electrocasnic invalid.\n");
    // pt modificare usoara in caz ca sunt mai multe restrangeri ulterior
    if (isTastatura)
        cout << "Marca: ";
    dev >> marca_temp;
    if (isTastatura)
        cout << "Model: ";
    dev >> model_temp;
    if (isTastatura)
        cout << "An fabricatie: ";
    dev >> an_temp;
    if (isTastatura)
        cout << "Pret catalog: ";
    dev >> pret_temp;

    marca = marca_temp;
    model = model_temp;
    an_fabricatie = an_temp;
    pret_catalog = pret_temp;
}

void Electrocasnic::scriere(ostream &dev) const
{
    dev << tip << "\n"
        << marca << "\n"
        << model << "\n"
        << an_fabricatie << "\n"
        << pret_catalog << endl;
}