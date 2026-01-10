#include "FixItNow.h"

using namespace std;

int main()
{
    string fa = "./tests/angajati.txt";
    string fe = "./tests/electrocasnice.txt";
    string fc = "./tests/cereri.txt";
    string fr = "./tests/raportari.txt";

    try
    {
        vector<Angajat *> angajati = make_vector_angajati(fa);
        vector<Electrocasnic *> electrocasnice= make_vector_electrocasnice(fe);
        vector<CerereReparatie *> cereri;
        FixItNow service(angajati, electrocasnice, cereri);
        
        /*tm data = {};
        data.tm_year = 120; // anul 2020
        data.tm_mon = 5;    // iunie
        data.tm_mday = 15;  // 15 iunie 2020*/
        // angajati.push_back(new Receptioner("Popescu", "Ion", "6060207410071", data, "Bucuresti", {1, 2, 3}));
        // angajati.push_back(new Receptioner("Ionescu", "Maria", "6060207410071", data, "Bucuresti",{4,5} ));

        service.meniu(fa,fe,fc,fr);
    }
    catch (const exception &e)
    {
        cerr << "Eroare: " << e.what() << endl;
    }
    return 0;
}