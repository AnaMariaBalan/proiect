#include "FixItNow.h"

// meniu

vector<Angajat *> make_vector_angajati(string source)
{
    fstream f(source);
    if (!f)
    {
        cout << "Eroare la deschiderea fisierului!" << " [inside make_vector]" << endl;
        exit(1);
    }
    vector<Angajat *> angajati;
    string rol;
    while (getline(f, rol))
    {
        try
        {
            if (rol == "receptioner" || rol == "Receptioner")
            {
                Angajat *r = new Receptioner();
                r->citire(f);
                angajati.push_back(r);
            }
            else if (rol == "tehnician" || rol == "Tehnician")
            {
                Angajat *t = new Tehnician();
                t->citire(f);
                angajati.push_back(t);
            }
            else if (rol == "supervizor" || rol == "Supervizor")
            {
                Angajat *s = new Supervizor();
                s->citire(f);
                angajati.push_back(s);
            }
        }
        catch (const exception &e)
        {
            cerr << "Eroare: " << e.what() << endl;
        }
    }
    f.close();
    return angajati;
}

int search_by_CNP(vector<Angajat *> a, string CNP)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (CNP.compare(a[i]->get_CNP()) == 0) // CNP==get_CNP
            return i;
    }
    return -1;
}

string ask_for_CNP()
{
    cout << "Introduceti CNP:";
    string CNP;
    cin >> CNP;
    if (!isCNPvalid(CNP))
        throw invalid_argument("CNP invalid");
    return CNP;
}

vector<Electrocasnic *> make_vector_electrocasnice(string source) // sau cu template
{
    fstream f(source);
    if (!f)
    {
        cout << "Eroare la deschiderea fisierului!" << " [inside make_vector]" << endl;
        exit(1);
    }
    vector<Electrocasnic *> electrocasnice;

    string tip;
    while (f >> tip)
    {
        try
        {
            if (tip == "TV" || tip == "tv")
            {
                Electrocasnic *tv = new TV();
                tv->citire(f);
                tv->set_tip(tip);
                electrocasnice.push_back(tv);
            }
            else if (tip == "frigider" || tip == "Frigider")
            {
                Electrocasnic *fr = new Frigider();
                fr->citire(f);
                fr->set_tip(tip);
                electrocasnice.push_back(fr);
            }
            else if (tip == "masina-de-spalat" || tip == "Masina-de-spalat")
            {
                Electrocasnic *ms = new MasinaSpalat();
                ms->citire(f);
                ms->set_tip(tip);
                electrocasnice.push_back(ms);
            }
        }
        catch (const exception &e)
        {
            cerr << "Eroare: " << e.what() << endl;
        }
    }
    f.close();
    return electrocasnice;
}

vector<int> seek_for_aparate(vector<Electrocasnic *> electrocasnice, string interest, string denumire) // interest poate fi tipul/marca/model
{
    // returnez un vector in care se gasesc doar poz elem ce satisfac cond
    vector<int> v;
    for (int i = 0; i < electrocasnice.size(); i++)
        if (denumire == electrocasnice[i]->get_info(interest))
            v.push_back(i);
    return v;
}

bool is_service_operational(vector<Angajat *> a)
{
    int r = 0, t = 0, s = 0;
    for (int i = 0; i < a.size(); i++)
        if ((a[i]->rol()) == "Receptioner")
            r++;
        else if ((a[i]->rol()) == "Tehnician")
            t++;
        else
            s++;
    if (r > 1 && t > 3 && s > 1)
        return true;
    return false;
}