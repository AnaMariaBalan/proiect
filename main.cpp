#include "FixItNow.h"

using namespace std;

int main()
{
    string f="./tests/angajati.txt";
    vector<Angajat *> angajati = make_vector_angajati(f);
    vector<Electrocasnic *> electrocasnice;
    vector<CerereReparatie *> cereri;
    FixItNow service(angajati, electrocasnice, cereri);
    try
    {
        /*
        tm data = {};
        data.tm_year = 120; // anul 2020
        data.tm_mon = 5;    // iunie
        data.tm_mday = 15;  // 15 iunie 2020*/
        // angajati.push_back(new Receptioner("Popescu", "Ion", "6060207410071", data, "Bucuresti", {1, 2, 3}));
        // angajati.push_back(new Receptioner("Ionescu", "Maria", "6060207410071", data, "Bucuresti",{4,5} ));

        service.meniu(f);

        // afisare angajati
        /*
        for (int i = 0; i < angajati.size(); i++)
        {
            angajati[i]->afisare();
            cout << "Salariu: " << angajati[i]->get_salariu() << endl;
            cout << "------------------------" << endl;
        }*/

        //  fin.close();
    }
    catch (const exception &e)
    {
        cerr << "Eroare: " << e.what() << endl;
    }
    return 0;
}