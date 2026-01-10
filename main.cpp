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
        if (!is_service_operational(angajati))
        {
            cerr << "Service-ul nu are numarul corespunzator de angajati!\n";
            exit(1);
        }
        vector<Electrocasnic *> electrocasnice = make_vector_electrocasnice(fe);
        vector<CerereReparatie *> cereri;
        vector<Electrocasnic *> aparate_reparate; 
        vector<Electrocasnic *> aparate_in_afara_listei;
        FixItNow service(angajati, electrocasnice, cereri, aparate_reparate, aparate_in_afara_listei);

        /*tm data = {};
        data.tm_year = 120; // anul 2020
        data.tm_mon = 5;    // iunie
        data.tm_mday = 15;  // 15 iunie 2020*/
        // angajati.push_back(new Receptioner("Popescu", "Ion", "6060207410071", data, "Bucuresti", {1, 2, 3}));
        // angajati.push_back(new Receptioner("Ionescu", "Maria", "6060207410071", data, "Bucuresti",{4,5} ));

        service.meniu(fa, fe, fc, fr);
    }
    catch (const exception &e)
    {
        cerr << "Eroare: " << e.what() << endl;
    }
    return 0;
}