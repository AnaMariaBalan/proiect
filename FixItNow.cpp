#include "FixItNow.h"

FixItNow::FixItNow(vector<Angajat *> angajati, vector<Electrocasnic *> electrocasnice, vector<CerereReparatie *> cereri) : angajati(angajati), electrocasnice(electrocasnice), cereri(cereri) {}

//----------------------------------------------------------------------------------

void FixItNow::meniu(string file_angajati, string file_electrocasnice, string file_cereri, string file_raportari)
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
                    cout << "4. Afisare date si calcul salariu angajat curent\n";
                    cout << "5. Afisare lista angajati\n";
                    cout << "6. Back\n";
                    cout << "Optiune: ";
                    cin >> subchoice;
                } while (subchoice < 1 || subchoice > 6);

                switch (subchoice)
                {
                case 1:
                    // adaugare angajat
                    try
                    {
                        adauga_angajat(file_angajati);
                    }
                    catch (const exception &e)
                    {
                        cerr << "Eroare: " << e.what() << endl;
                    }
                    break;
                case 2:
                    // modificare nume angajat
                    try
                    {
                        modificare_nume_angajat(file_angajati);
                    }
                    catch (const exception &e)
                    {
                        cerr << "Eroare: " << e.what() << endl;
                    }
                    break;
                case 3:
                    // stergere angajat
                    try
                    {
                        stergere_angajat(file_angajati);
                    }
                    catch (const exception &e)
                    {
                        cerr << "Eroare: " << e.what() << endl;
                    }
                    break;
                case 4:
                    // afisare date si calcul curent angajat
                    try
                    {
                        afisare_date_angajat();
                    }
                    catch (const exception &e)
                    {
                        cerr << "Eroare: " << e.what() << endl;
                    }
                    break;
                case 5:
                    // afisare lista angajati
                    try
                    {
                        afisare_lista_angajati();
                    }
                    catch (const exception &e)
                    {
                        cerr << "Eroare: " << e.what() << endl;
                    }
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
                    cout << "2. Stergere model/marca acceptata\n";
                    cout << "3. Afisare date aparate reparate\n";
                    cout << "4. Afisare date aparate din afara listei\n";
                    cout << "5. Back\n";
                    cout << "Optiune: ";
                    cin >> subchoice;
                } while (subchoice < 1 || subchoice > 6);

                switch (subchoice)
                {
                case 1:
                    // adaugare model/marca
                    try
                    {
                        adauga_electrocasnic(file_electrocasnice);
                    }
                    catch (const exception &e)
                    {
                        cerr << "Eroare: " << e.what() << endl;
                    }
                    break;
                case 2:
                    // stergere model/marca
                    try
                    {
                        stergere_electrocasnic(file_electrocasnice);
                    }
                    catch (const exception &e)
                    {
                        cerr << "Eroare: " << e.what() << endl;
                    }
                    break;
                case 3:
                    // afisare aparate reparate
                    break;
                case 4:
                    // afisare aparate din afara listei
                    break;
                case 5:
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

void FixItNow::adauga_angajat(string location)
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
        Angajat *r = new Receptioner();
        r->citire(cin);
        f << "\nReceptioner\n";
        r->scriere(f);
        angajati.push_back(r);
    }
    else if (rol == 't' || rol == 'T')
    {
        // scriere angajat in fisier
        Angajat *t = new Tehnician();
        t->citire(cin);
        f << "\nTehnician\n";
        t->scriere(f);
        angajati.push_back(t);
    }
    else if (rol == 's' || rol == 'S')
    {
        // scriere angajat in fisier
        Angajat *s = new Supervizor();
        s->citire(cin);
        f << "\nSupervizor\n";
        s->scriere(f);
        angajati.push_back(s);
    }
    f.close();
}

void FixItNow::modificare_nume_angajat(string location) // poate si pentru domiciliu
{
    string CNP = ask_for_CNP();

    int poz = search_by_CNP(angajati, CNP);
    if (poz == -1)
        throw("CNP-ul nu se regaseste in lista");

    string name;
    cout << "introduceti nume actual: ";
    cin >> name;

    angajati[poz]->set_nume(name);

    // update list
    ofstream f(location);
    if (!f.is_open())
        throw runtime_error("Nu s-a putut deschide fisierul.");

    for (int i = 0; i < angajati.size(); i++)
    {
        f << angajati[i]->rol() << endl; // sau cu typeid(...).name() si elimin primele caractere pana dau de litera
        angajati[i]->scriere(f);
        if (i != angajati.size() - 1)
            f << endl;
    }
}

void FixItNow::stergere_angajat(string location)
{
    string CNP = ask_for_CNP();

    int poz = search_by_CNP(angajati, CNP);
    if (poz == -1)
        throw("CNP-ul nu se regaseste in lista");

    angajati.erase(angajati.begin() + poz);

    // update list
    ofstream f(location);
    if (!f.is_open())
        throw runtime_error("Nu s-a putut deschide fisierul.");

    for (int i = 0; i < angajati.size(); i++)
    {
        f << angajati[i]->rol() << endl; // sau cu typeid(...).name() si elimin primele caractere pana dau de litera
        angajati[i]->scriere(f);
        if (i != angajati.size() - 1)
            f << endl;
    }
}

void FixItNow::stergere_date_angajat(string location)
{
    string CNP = ask_for_CNP();

    int poz = search_by_CNP(angajati, CNP);
    if (poz == -1)
        throw("CNP-ul nu se regaseste in lista");

    // set date anonime [noname,000000000,nonexistent]?
    // update list
}

void FixItNow::afisare_date_angajat()
{
    string CNP = ask_for_CNP();

    int poz = search_by_CNP(angajati, CNP);
    if (poz == -1)
        throw("CNP-ul nu se regaseste in lista");

    cout << "------------------------" << endl;
    angajati[poz]->afisare();
    cout << "Salariu: " << angajati[poz]->get_salariu() << endl;
    cout << "------------------------" << endl;
}

void FixItNow::afisare_lista_angajati()
{
    for (int i = 0; i < angajati.size(); i++)
    {
        // cout<<angajati[i]->rol()<<endl;
        angajati[i]->afisare();
        // cout << "Salariu: " << angajati[i]->get_salariu() << endl;
        cout << "------------------------" << endl;
    }
}

void FixItNow::adauga_electrocasnic(string location)
{
    fstream f(location, ios::app); // se pozitioneaza la finalul fisierului
    if (!f)
    {
        cerr << "Eroare la deschiderea fisierului " << location << endl;
        return;
    }

    char tip = 'x';
    do
    {
        cout << "Tipul electrocasnicului: (t/T TV, f/F Frigider, m/M Masina de spalat)" << endl;
        cin >> tip;
    } while (tip != 't' && tip != 'T' && tip != 'f' && tip != 'F' && tip != 'm' && tip != 'M');

    if (tip == 'f' || tip == 'F')
    {
        // scriere angajat in fisier
        Electrocasnic *fr = new Frigider();
        fr->citire(cin);
        fr->set_tip("Frigider");
        fr->scriere(f);
        electrocasnice.push_back(fr);
    }
    else if (tip == 't' || tip == 'T')
    {
        // scriere angajat in fisier
        Electrocasnic *t = new TV();
        t->citire(cin);
        t->set_tip("TV");
        t->scriere(f);
        electrocasnice.push_back(t);
    }
    else if (tip == 'm' || tip == 'M')
    {
        // scriere angajat in fisier
        Electrocasnic *ms = new MasinaSpalat();
        ms->citire(cin);
        ms->set_tip("Masina-de-spalat");
        ms->scriere(f);
        electrocasnice.push_back(ms);
    }
    f.close();
}

void FixItNow::stergere_electrocasnic(string location)
{
    cout << "Introduceti tipul electrocasnicului: (TV/Frigider/Masina-de-spalat) ";
    string tip;
    cin >> tip;
    // caut primul tip bun, continui cu marca. nu convine? next!
    cout << "Introduceti marca electrocasnicului: ";
    string marca;
    cin >> marca;
    cout << "Doriti sa eliminati toate aparitiile acestei marci? (y/n) ";
    char c = 'x';
    do
    {
        cin >> c;
    } while (c != 'y' && c != 'n');
    string model;
    if (c == 'n')
    {
        cout << "Introduceti modelul dorit: ";
        cin >> model;
    }
    bool found = 0;

    for (int i = 0; i < electrocasnice.size(); i++)
        if (tip == electrocasnice[i]->get_info("tip"))
        {
            if (marca == electrocasnice[i]->get_info("marca"))
            {
                if (c == 'y' || model==electrocasnice[i]->get_info("model"))
                {
                    found =1;
                    delete electrocasnice[i];
                    electrocasnice.erase(electrocasnice.begin()+i);
                    i--;
                }
            }
        }
    if (!found)
    {
        cout << "NU s-a regasit" << endl;
        return;
    }
    cout<<"Electrocasnic eliminat!\n";
    ofstream f(location);
    if(!f)
    {
        cerr<<"Eroare la deschiderea fisierului "<<location<<endl;
        return;
    }
    for (int i = 0; i < electrocasnice.size(); i++)
        electrocasnice[i]->scriere(f);
}