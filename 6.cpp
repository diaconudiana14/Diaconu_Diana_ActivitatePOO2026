
#include <iostream>
#include <string>
using namespace std;

class Parcare {
private:
    const int id;
    string denumire;
    int nrLocuri;
    float tarifOra;

public:
    static int nrParcari;

    // CONSTRUCTOR DEFAULT
    Parcare() : id(++nrParcari) {
        this->denumire = "Parcare necunoscuta";
        this->nrLocuri = 0;
        this->tarifOra = 0;
    }

    // CONSTRUCTOR CU MAI MULTI PARAMETRI
    Parcare(string denumire, int nrLocuri, float tarifOra)
        : id(++nrParcari) {

        this->denumire = denumire;
        this->nrLocuri = nrLocuri;
        this->tarifOra = tarifOra;
    }

    // CONSTRUCTOR DE COPIERE
    Parcare(const Parcare& copie) : id(++nrParcari) {
        this->denumire = copie.denumire;
        this->nrLocuri = copie.nrLocuri;
        this->tarifOra = copie.tarifOra;
    }

    // SUPRAINCARCAREA OPERATORULUI =
    void operator=(const Parcare& copie) {
        this->denumire = copie.denumire;
        this->nrLocuri = copie.nrLocuri;
        this->tarifOra = copie.tarifOra;
    }

    // GETTER
    float getTarifOra() {
        return this->tarifOra;
    }

    // SETTER
    void setTarifOra(float tarifNou) {
        if (tarifNou >= 0) {
            this->tarifOra = tarifNou;
        }
    }

    // METODA DE AFISARE
    void afisare() {
        cout << endl << "ID: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Nr locuri: " << this->nrLocuri;
        cout << endl << "Tarif pe ora: " << this->tarifOra << " lei";
        cout << endl;
    }

    // OPERATORUL << (AFISARE)
    friend void operator<<(ostream& out, const Parcare& p) {
        out << endl << "ID: " << p.id;
        out << endl << "Denumire: " << p.denumire;
        out << endl << "Nr locuri: " << p.nrLocuri;
        out << endl << "Tarif pe ora: " << p.tarifOra << " lei";
        out << endl;
    }

    // SUPRAINCARCAREA OPERATORULUI ()
    float operator()(int nrOre) {
        return this->tarifOra * nrOre;
    }

    // DESTRUCTOR
    ~Parcare() {
    }
};

int Parcare::nrParcari = 0;

int main() {

    // Constructor default
    Parcare p1;

    // Constructor cu parametri
    Parcare p2("Parcare Centrala", 100, 5);

    cout << endl << "DATE PARCARE:";
    cout << p2;

    // TESTARE OPERATOR ()
    cout << endl << "Cost pentru 3 ore: " << p2(3) << " lei";

    cout << endl << "Cost pentru 5 ore: " << p2(5) << " lei";

    return 0;
}
