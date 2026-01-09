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
                Receptioner *r = new Receptioner();
                r->citire(f);
                angajati.push_back(r);
            }
            else if (rol == "tehnician" || rol == "Tehnician")
            {
                Tehnician *t = new Tehnician();
                t->citire(f);
                angajati.push_back(t);
            }
            else if (rol == "supervizor" || rol == "Supervizor")
            {
                Supervizor *s = new Supervizor();
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