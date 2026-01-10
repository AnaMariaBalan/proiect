#pragma once
#include <iostream>
#include <string>

using namespace std;
class Electrocasnic
{
protected:
    string tip;
    string marca;
    string model;
    int an_fabricatie;
    double pret_catalog;

public:
    Electrocasnic() = default;
    Electrocasnic(string tip, string marca, string model,int an_fabricatie, double pret_catalog);
    virtual ~Electrocasnic() = default;

    void set_tip(string tip);
    string get_info(string interest); //tip/marca/model

    virtual void citire(istream &dev);
    virtual void scriere(ostream &dev) const;
    virtual void afisare() const;
};