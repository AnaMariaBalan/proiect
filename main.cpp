
#include "Receptioner.h"
#include "Tehnician.h"
#include "Supervizor.h"
#include <fstream>
#include <vector>
using namespace std;

void adauga_angajat()
{
    fstream f("./tests/angajati.txt", ios::app); // se pozitioneaza la finalul fisierului
    if (!f)
    {
        cerr << "Eroare la deschiderea fisierului!" << endl;
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
        Receptioner r;
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

vector<Angajat *> make_vector_angajati()
{
    cout << "vector uwu";
    // citire angajati din fisier
    fstream f("./tests/angajati.txt");
    if (!f.is_open())
        throw runtime_error("Nu s-a putut deschide fisierul.");
    vector<Angajat *> angajati;
    while (!f.eof())
    {
        // citire rol angajat
        string rol;
        f >> rol;
        if (rol == "Receptioner" || rol == "receptioner")
        {
            Angajat *a = new Receptioner();
            a->citire(f);
            angajati.push_back(a);
        }
        else if (rol == "Tehnician" || rol == "tehnician")
        {
            Angajat *a = new Tehnician();
            a->citire(f);
            angajati.push_back(a);
        }
        else if (rol == "Supervizor" || rol == "supervizor")
        {
            Angajat *a = new Supervizor();
            a->citire(f);
            angajati.push_back(a);
        }
        else
        {
            throw invalid_argument("Rol angajat necunoscut.");
        }
    }
    return angajati;
}

void modificare_nume_angajat() // poate si pentru domiciliu
{
    cout << "Introduceti CNP:";
    string CNP;
    cin >> CNP;
    if (!isCNPvalid(CNP))
        throw invalid_argument("CNP invalid");
    vector<Angajat *> angajati = make_vector_angajati();
    for (const auto &angajat : angajati)
    {
        if (CNP.compare(angajat->get_CNP()) == 0)
        {
            string name;
            cout << "Introduceti nume actual:";
            cin >> name;
            angajat->set_nume(name);
            break;
        }
    }
    ofstream f("./tests/angajati.txt");
    if (!f.is_open())
        throw runtime_error("Nu s-a putut deschide fisierul.");

    for (const auto &angajat : angajati)
    {
        angajat->scriere(f);
    }
}

/*
void search_by_CNP()
{
    cout << "Introduceti CNP:";
    string CNP;
    cin >> CNP;
    if (!isCNPvalid(CNP))
        throw invalid_argument("CNP invalid");
    vector<Angajat *> angajati = make_vector_angajati();
    for (const auto &angajat : angajati)
    {
        if(CNP.compare(angajat->get_CNP())==0)
            {
                //am gasit si fac ce trebuie
                break;
            }
    }
}*/

void meniu()
{
    while (true) // ca sa pot da back in submeniuri
    {
        int choice = 0;
        // pot adauga bool first time ca sa apara eroare daca nu e prima data cand intra in dowhile si sa afiseze input gresit
        do
        {
            cout << "\nAlege actiunea:\n";
            cout << "1. Gestiune angajati\n";
            cout << "2. Gestiune electrocasnice\n";
            cout << "3. Procesare cereri\n";
            cout << "4. Raportari\n";
            cout << "5. Exit\n";
            cout << "Optiune: ";
            cin >> choice;
        } while (choice < 1 || choice > 5);

        if (choice == 5)
            return;
        int subchoice = 0;

        switch (choice)
        {
        case 1:
        {
            bool back = false;
            while (!back)
            {
                int subchoice = 0;
                do
                {
                    cout << "\n--- Gestiune angajati ---\n";
                    cout << "1. Adaugare angajat\n";
                    cout << "2. Modificare nume angajat\n";
                    cout << "3. Stergere angajat\n";
                    cout << "4. Afisare date si calcul curent angajat\n";
                    cout << "5. Afisare lista angajati\n";
                    cout << "6. Back\n";
                    cout << "Optiune: ";
                    cin >> subchoice;
                } while (subchoice < 1 || subchoice > 6);

                switch (subchoice)
                {
                case 1:
                    // adaugare angajat
                    adauga_angajat();
                    break;
                case 2:
                    // modificare nume angajat
                    // modificare_nume_angajat();
                    break;
                case 3:
                    // stergere angajat
                    break;
                case 4:
                    // afisare date si calcul curent angajat
                    break;
                case 5:
                    // afisare lista angajati
                    break;
                case 6:
                    // back
                    back = true;
                    break;
                }
            }
            break;
        }

        case 2:
        {
            bool back = false;
            while (!back)
            {
                int subchoice = 0;
                do
                {
                    cout << "\n--- Gestiune electrocasnice ---\n";
                    cout << "1. Adaugare model/marca acceptata\n";
                    cout << "2. Modificare model/marca acceptata\n";
                    cout << "3. Stergere model/marca acceptata\n";
                    cout << "4. Afisare date aparate reparate\n";
                    cout << "5. Afisare date aparate din afara listei\n";
                    cout << "6. Back\n";
                    cout << "Optiune: ";
                    cin >> subchoice;
                } while (subchoice < 1 || subchoice > 6);

                switch (subchoice)
                {
                case 1:
                    // adaugare model/marca
                    break;
                case 2:
                    // modificare model/marca
                    break;
                case 3:
                    // stergere model/marca
                    break;
                case 4:
                    // afisare aparate reparate
                    break;
                case 5:
                    // afisare aparate din afara listei
                    break;
                case 6:
                    // back
                    back = true;
                    break;
                }
            }
            break;
        }

        case 3:
        {
            bool back = false;
            while (!back)
            {
                int subchoice = 0;
                do
                {
                    cout << "\n--- Procesare cereri ---\n";
                    cout << "1. Simulare primire cereri\n";
                    cout << "2. Alocare automata cereri valide\n";
                    cout << "3. Simulare reparatie\n";
                    cout << "4. Back\n";
                    cout << "Optiune: ";
                    cin >> subchoice;
                } while (subchoice < 1 || subchoice > 4);

                switch (subchoice)
                {
                case 1:
                    // simulare primire cereri
                    break;
                case 2:
                    // alocare automata
                    break;
                case 3:
                    // simulare reparatie
                    break;
                case 4:
                    // back
                    back = true;
                    break;
                }
            }
            break;
        }

        case 4:
        {
            bool back = false;
            while (!back)
            {
                int subchoice = 0;
                do
                {
                    cout << "\n--- Raportari ---\n";
                    cout << "1. Top 3 angajati\n";
                    cout << "2. Tehnician cu cea mai lunga reparatie\n";
                    cout << "3. Afisare cereri in asteptare\n";
                    cout << "4. Back\n";
                    cout << "Optiune: ";
                    cin >> subchoice;
                } while (subchoice < 1 || subchoice > 4);

                switch (subchoice)
                {
                case 1:
                    // top 3 angajati
                    break;
                case 2:
                    // tehnician max durata
                    break;
                case 3:
                    // afisare cereri in asteptare
                    break;
                case 4:
                    // back
                    back = true;
                    break;
                }
            }
            break;
        }
        }
    }
}

int main()
{
    // adauga try si catch in jurul actiunilor
    vector<Angajat *> angajati;

    tm data = {};
    data.tm_year = 120; // anul 2020
    data.tm_mon = 5;    // iunie
    data.tm_mday = 15;  // 15 iunie 2020

    try
    {
        // angajati.push_back(new Receptioner("Popescu", "Ion", "6060207410071", data, "Bucuresti", {1, 2, 3}));
        // angajati.push_back(new Receptioner("Ionescu", "Maria", "6060207410071", data, "Bucuresti",{4,5} ));
        fstream f("./tests/angajati.txt"); // se pozitioneaza la finalul fisierului
        if (!f)
        {
            cout << "Eroare la deschiderea fisierului!" << endl;
            exit(1);
        }
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
        // meniu();

        // afisare angajati
        for (int i = 0; i < angajati.size(); i++)
        {
            angajati[i]->afisare();
            cout << "Salariu: " << angajati[i]->get_salariu() << endl;
            cout << "------------------------" << endl;
        }

        //  fin.close();
    }
    catch (const exception &e)
    {
        cerr << "Eroare: " << e.what() << endl;
    }
    return 0;
}