#include "Angajat.h"

int Angajat::counter = 1;

Angajat::Angajat(string nume, string prenume, string CNP, tm data_angajare, string oras_domiciliu) : id(counter++)
{
    if (nume.length() < 3 || nume.length() > 30)
        throw invalid_argument("Name exceeds limit(3-30)");
    else
        this->nume = nume;
    if (prenume.length() < 3 || prenume.length() > 30)
        throw invalid_argument("Name exceeds limit(3-30)");
    else
        this->prenume = prenume;

    // validare CNP
    if (isCNPvalid(CNP) == false)
        throw invalid_argument("CNP invalid");
    else
        this->CNP = CNP;
    if (validare_varsta(CNP) == false)
        throw invalid_argument("Varsta sub 16 ani");
    this->data_angajare = data_angajare;
    this->oras_domiciliu = oras_domiciliu;
}

//-----------------------------------------------------------------------------

istream &operator>>(istream &dev, Angajat &a)
{
    a.citire(dev);
    return dev;
}
void Angajat::citire(std::istream &dev)
{
    bool isTastatura = (&dev == &std::cin);
    string nume_temp, prenume_temp, CNP_temp, oras_temp;
    tm data_temp = {};

    if (isTastatura)
        cout << "Nume: ";
    dev >> nume_temp;
    if (nume_temp.length() < 3 || nume_temp.length() > 30)
        throw invalid_argument("Name exceeds limit(3-30)");

    if (isTastatura)
        cout << "Prenume: ";
    dev >> prenume_temp;
    if (prenume_temp.length() < 3 || prenume_temp.length() > 30)
        throw invalid_argument("Name exceeds limit(3-30)");

    if (isTastatura)
        cout << "CNP: ";
    dev >> CNP_temp;
    if (isCNPvalid(CNP_temp) == false)
        throw invalid_argument("CNP invalid");
    if (validare_varsta(CNP_temp) == false)
        throw invalid_argument("Varsta sub 16 ani");

    if (isTastatura)
        cout << "Data angajare (zz ll aaaa): ";
    dev >> data_temp.tm_mday >> data_temp.tm_mon >> data_temp.tm_year;

    if (isTastatura)
        cout << "Oras domiciliu: ";
    dev >> oras_temp;

    data_temp.tm_mon -= 1;     // 0-11
    data_temp.tm_year -= 1900; // 1900 + [...]

    nume = nume_temp;
    prenume = prenume_temp;
    CNP = CNP_temp;
    data_angajare = data_temp;
    oras_domiciliu = oras_temp;
}

void Angajat::scriere(ostream &dev) const
{
    dev << nume << "\n"
        << prenume << "\n"
        << CNP << "\n"
        << data_angajare.tm_mday << " " << data_angajare.tm_mon + 1 << " " << data_angajare.tm_year + 1900 << "\n"
        << oras_domiciliu << endl;
}

//-----------------------------------------------------------------------------

void Angajat::afisare() const
{
    cout << endl;
    cout << "ID: " << id << endl;
    cout << "Nume: " << nume << endl;
    cout << "Prenume: " << prenume << endl;
    cout << "CNP: " << CNP << endl;
    cout << "Data angajare: " << data_angajare.tm_mday << "/" << data_angajare.tm_mon + 1 << "/" << data_angajare.tm_year + 1900 << endl; // luna default e 0, anul default -1900
    cout << "Oras domiciliu: " << oras_domiciliu << endl;
}

double Angajat::get_salariu()
{
    return 4000; // salariu de baza
}

int Angajat::prima_transport()
{
    if (oras_domiciliu == "Bucuresti")
        return 0;
    else
        return 400;
}

//-----------------------------------------------------------------------------

string Angajat::get_CNP()
{
    return CNP;
}

void Angajat::set_nume(string nume)
{
    if (nume.length() < 3 || nume.length() > 30)
        throw invalid_argument("Name exceeds limit(3-30)");
    else
        this->nume = nume;
}

//-----------------------------------------------------------------------------

void Angajat::sortare_nume(vector<Angajat *> &angajati)
{
    if (angajati.empty())
        throw invalid_argument("Vector gol");
    for (size_t i = 0; i < angajati.size() - 1; i++)
        for (size_t j = i + 1; j < angajati.size(); j++)
            if (angajati[i]->nume > angajati[j]->nume)
                swap(angajati[i], angajati[j]);
}

void Angajat::sortare_salariu(vector<Angajat *> &angajati)
{
    if (angajati.empty())
        throw invalid_argument("Vector gol");
    for (size_t i = 0; i < angajati.size() - 1; i++)
        for (size_t j = i + 1; j < angajati.size(); j++)
            if (angajati[i]->get_salariu() > angajati[j]->get_salariu())
                swap(angajati[i], angajati[j]);
}

//-----------------------------------------------------------------------------

bool validare_varsta(string CNP)
{
    // an nastere din CNP
    int an_nastere = 0;
    //cout << CNP << endl;
    if (CNP[1] == '0' || CNP[1] == '1') // 200x si 201x
        an_nastere = 2000 + (CNP[1] - '0') * 10 + (CNP[2] - '0');
    else
        an_nastere = 1900 + (CNP[1] - '0') * 10 + (CNP[2] - '0');
    //cout << an_nastere << endl;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int varsta = ltm->tm_year + 1900 - an_nastere;

    int luna_nastere = stoi(CNP.substr(3, 2));
    if (luna_nastere > ltm->tm_mon)
        varsta--;
    else if (luna_nastere == ltm->tm_mon)
    {
        int zi_nastere = stoi(CNP.substr(5, 2));
        if (zi_nastere > ltm->tm_mday)
            varsta--;
    }
    //cout << varsta << endl;
    if (varsta < 16)
        return false;
    return true;
}

bool isCNPvalid(string CNP)
{
    // lungime
    if (CNP.length() != 13)
        return false;

    // toate caracterele cifre
    for (char c : CNP) // parcurge toate caract cnp
    {
        if (!isdigit(c))
            return false;
    }

    // calcul cifra control
    int componentaC = 0;
    int suma = 0;
    int nr[13] = {2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9};
    for (int i = 0; i < 12; i++)
    {
        suma += (CNP[i] - '0') * nr[i];
    }
    if (suma % 11 < 10)
        componentaC = suma % 11;
    else
        componentaC = 1;
    if (componentaC != (CNP[12] - '0'))
        return false;
    return true;
}

//-----------------------------------------------------------------------------