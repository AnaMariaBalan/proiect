#include "Electrocasnic.h"

class MasinaSpalat : public Electrocasnic
{
    double capacitate; // kg
public:
    MasinaSpalat() = default;
    MasinaSpalat(string tip, string marca, string model, int an_fabricatie, double pret_catalog, double capacitate);
    ~MasinaSpalat() override = default;

    void citire(istream &dev) override;
    void scriere(ostream &dev) const override;
    void afisare() const override;
};