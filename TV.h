#include "Electrocasnic.h"

class Tv : public Electrocasnic
{
private:
    int dim_diagonala;
    public:
    Tv() = default;
    Tv(string tip, string marca, string model, int an_fabricatie, double pret_catalog, int dim_diagonala);
    ~Tv() override = default;
    void afisare() const override;
};