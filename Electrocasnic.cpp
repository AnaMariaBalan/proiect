#include "Electrocasnic.h"

Electrocasnic::Electrocasnic(string tip, string marca, string model, int an_fabricatie, double pret_catalog)
    : marca(marca), model(model), an_fabricatie(an_fabricatie), pret_catalog(pret_catalog)
{
    if (tip == "Frigider" || tip == "frigider" || tip == "tv" || tip == "TV" || tip == "masina-de-spalat" || tip == "Masina-de-spalat")
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
    string marca_temp, model_temp;
    int an_temp;
    double pret_temp;

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
    dev << tip << " "
        << marca << " "
        << model << " "
        << an_fabricatie << " "
        << pret_catalog << " ";
}

void Electrocasnic::set_tip(string tip)
{
    if (tip == "Frigider" || tip == "frigider" || tip == "tv" || tip == "TV" || tip == "masina-de-spalat" || tip == "Masina-de-spalat")
        this->tip = tip;
    else
        throw("Tip electrocasnic invalid.\n");
}

string Electrocasnic::get_info(string interest) // tip/marca/model
{
    if (interest == "tipul" || interest == "tip")
        return tip;
    else if (interest == "marca")
        return marca;
    return model; // default
}