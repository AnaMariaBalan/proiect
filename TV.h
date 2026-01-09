#include "Electrocasnic.h"

class TV : public Electrocasnic
{
private:
    int dim_diagonala;
public:
    TV() = default;
    TV(string tip, string marca, string model, int an_fabricatie, double pret_catalog, int dim_diagonala);
    ~TV() override = default;

    void citire(istream &dev) override;
    void scriere(ostream &dev) const override;
    void afisare() const override;
};