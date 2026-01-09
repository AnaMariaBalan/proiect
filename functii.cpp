#include "FixItNow.h"

// meniu

void adauga_angajat(string location)
{
    fstream f(location, ios::app); // se pozitioneaza la finalul fisierului
    if (!f)
    {
        cerr << "Eroare la deschiderea fisierului " << location << endl;
        return;
    }

    char rol = 'x';
    do
    {
        cout << "Rolul angajatului: (r/R receptioner, t/T tehnician, s/S supervizor)" << endl;
        cin >> rol;
    } while (rol != 'r' && rol != 'R' && rol != 't' && rol != 'T' && rol != 's' && rol != 'S');

    if (rol == 'r' || rol == 'R')
    {
        // scriere angajat in fisier
        Receptioner r; // moare dupa
        r.citire(cin);
        f << "\nReceptioner\n";
        r.scriere(f);
    }
    else if (rol == 't' || rol == 'T')
    {
        // scriere angajat in fisier
        Tehnician t;
        t.citire(cin);
        f << "\nTehnician\n";
        t.scriere(f);
    }
    else if (rol == 's' || rol == 'S')
    {
        // scriere angajat in fisier
        Supervizor s;
        s.citire(cin);
        f << "\nSupervizor\n";
        s.scriere(f);
    }
    f.close();
}

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