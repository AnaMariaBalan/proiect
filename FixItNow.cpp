#include "FixItNow.h"

FixItNow::FixItNow(vector<Angajat *> angajati, vector<Electrocasnic *> electrocasnice, vector<CerereReparatie *> cereri) : angajati(angajati), electrocasnice(electrocasnice), cereri(cereri) {}

//----------------------------------------------------------------------------------

void FixItNow::meniu(string file)
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
                    try
                    {
                        adauga_angajat(file);
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
                        modificare_nume_angajat(file);
                    }
                    catch (const exception &e)
                    {
                        cerr << "Eroare: " << e.what() << endl;
                    }
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

void FixItNow::modificare_nume_angajat(string location) // poate si pentru domiciliu
{
    string CNP=ask_for_CNP();

    int poz = search_by_CNP(angajati, CNP);
    if(poz==-1)
        throw("CNP-ul nu se regaseste in lista");

    string name;
    cout << "introduceti nume actual: ";
    cin >> name;

    angajati[poz]->set_nume(name);

    // update list
    ofstream f(location);
    if (!f.is_open())
        throw runtime_error("Nu s-a putut deschide fisierul.");

    for (const auto &angajat : angajati)
    {
        angajat->scriere(f);
    }
}

void FixItNow::stergere_angajat(string location)
{
    string CNP=ask_for_CNP();

    int poz = search_by_CNP(angajati, CNP);
    if(poz==-1)
        throw("CNP-ul nu se regaseste in lista");
    delete [] angajati[poz];

    // update list
    ofstream f(location);
    if (!f.is_open())
        throw runtime_error("Nu s-a putut deschide fisierul.");

    for (const auto &angajat : angajati)
    {
        angajat->scriere(f);
    }
}

void FixItNow::stergere_date_angajat(string location)
{
    string CNP=ask_for_CNP();

    int poz = search_by_CNP(angajati, CNP);
    if(poz==-1)
        throw("CNP-ul nu se regaseste in lista");

    //set date anonime [noname,000000000,nonexistent]?
    //update list
}
