#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <string.h>

using namespace std;

class Angajat
{
protected:
    static int counter;
    const int id = counter++; // nemodificabil si atribuit la angajare
    string nume;              // intre 3 si 30 de caractere
    string prenume;           // intre 3 si 30 de caractere
    string CNP;               // sa fie valid
    tm data_angajare;
    string oras_domiciliu;

public:
    Angajat() = default;
    Angajat(string nume, string prenume, string CNP, tm data_angajare, string oras_domiciliu);
    friend istream &operator>>(istream &dev, Angajat &a);
    virtual ~Angajat() = default;

    int prima_transport();
    string get_CNP();
    void set_nume(string nume);

    // sortare dupa nume
    void sortare_nume(vector<Angajat *> &angajati);
    // sortare dupa salariu
    void sortare_salariu(vector<Angajat *> &angajati); // pt top 3

    virtual void citire(istream &dev);
    virtual void scriere(ostream &dev) const;
    virtual void afisare() const;
    virtual double get_salariu();
};

bool validare_varsta(string CNP);
bool isCNPvalid(string CNP);