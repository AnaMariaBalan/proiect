#include "FixItNow.h"

using namespace std;

int main()
{
    string f = "./tests/angajati.txt";
    try
    {
        vector<Angajat *> angajati = make_vector_angajati(f);
        vector<Electrocasnic *> electrocasnice;
        vector<CerereReparatie *> cereri;
        FixItNow service(angajati, electrocasnice, cereri);
        /*
        tm data = {};
        data.tm_year = 120; // anul 2020
        data.tm_mon = 5;    // iunie
        data.tm_mday = 15;  // 15 iunie 2020*/
        // angajati.push_back(new Receptioner("Popescu", "Ion", "6060207410071", data, "Bucuresti", {1, 2, 3}));
        // angajati.push_back(new Receptioner("Ionescu", "Maria", "6060207410071", data, "Bucuresti",{4,5} ));

        service.meniu(f);
    }
    catch (const exception &e)
    {
        cerr << "Eroare: " << e.what() << endl;
    }
    return 0;
}