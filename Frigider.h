#include "Electrocasnic.h"

class Frigider : public Electrocasnic
{
private:
    bool are_congelator; // 1 true , 0 false
public:
    Frigider() = default;
    Frigider(string tip, string marca, string model, int an_fabricatie, double pret_catalog, bool are_congelator);
    ~Frigider() override = default;

    void citire(istream &dev) override;
    void scriere(ostream &dev)const override;
    void afisare() const override;
};