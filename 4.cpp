
#include <iostream>
#include <string>
using namespace std;

class Restaurant {
private:
    const int id;
    string denumire;
    int nrPreparate;
    float* preturi;

public:
    static int nrRestaurante;

    // Constructor default
    Restaurant() : id(++nrRestaurante) {
        this->denumire = "Restaurant necunoscut";
        this->nrPreparate = 0;
        this->preturi = nullptr;
    }

    // Constructor cu mai multi parametrii
    Restaurant(string denumire, int nrPreparate, float* preturi)
        : id(++nrRestaurante) {

        this->denumire = denumire;
        this->nrPreparate = nrPreparate;

        this->preturi = new float[nrPreparate];

        for (int i = 0; i < this->nrPreparate; i++) {
            this->preturi[i] = preturi[i];
        }

        delete[] preturi;
    }

    // Constructor de copiere
    Restaurant(const Restaurant& copie) : id(++nrRestaurante) {
        this->denumire = copie.denumire;
        this->nrPreparate = copie.nrPreparate;

        if (copie.preturi != nullptr) {
            this->preturi = new float[this->nrPreparate];

            for (int i = 0; i < this->nrPreparate; i++) {
                this->preturi[i] = copie.preturi[i];
            }
        }
        else {
            this->preturi = nullptr;
        }
    }

    // Supraincarcarea operatorului =
    void operator=(const Restaurant& copie) {
        if (this != &copie) {
            this->denumire = copie.denumire;
            this->nrPreparate = copie.nrPreparate;

            if (this->preturi != nullptr) {
                delete[] this->preturi;
                this->preturi = nullptr;
            }

            if (copie.preturi != nullptr) {
                this->preturi = new float[this->nrPreparate];

                for (int i = 0; i < this->nrPreparate; i++) {
                    this->preturi[i] = copie.preturi[i];
                }
            }
            else {
                this->preturi = nullptr;
            }
        }
    }

    // Getter
    float* getPreturi() {
        float* vPreturi = new float[this->nrPreparate];

        for (int i = 0; i < this->nrPreparate; i++) {
            vPreturi[i] = this->preturi[i];
        }

        return vPreturi;
    }

    // Setter
    void setPreturi(float* vPreturi, int dim) {
        this->nrPreparate = dim;

        if (this->preturi != nullptr) {
            delete[] this->preturi;
            this->preturi = nullptr;
        }

        if (vPreturi != nullptr) {
            this->preturi = new float[this->nrPreparate];

            for (int i = 0; i < this->nrPreparate; i++) {
                this->preturi[i] = vPreturi[i];
            }

            delete[] vPreturi;
        }
        else {
            this->preturi = nullptr;
        }
    }

    // Metoda de afisare
    void afisare() {
        cout << endl << "ID: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Nr preparate: " << this->nrPreparate;

        if (this->preturi != nullptr) {
            cout << endl << "Preturi: ";

            for (int i = 0; i < this->nrPreparate; i++) {
                cout << this->preturi[i] << " lei ";
            }
        }

        cout << endl;
    }

    // OperatorulL << (afisare)
    friend void operator<<(ostream& out, const Restaurant& r) {
        out << endl << "ID: " << r.id;
        out << endl << "Denumire: " << r.denumire;
        out << endl << "Nr preparate: " << r.nrPreparate;

        if (r.preturi != nullptr) {
            out << endl << "Preturi: ";

            for (int i = 0; i < r.nrPreparate; i++) {
                out << r.preturi[i] << " lei ";
            }
        }

        out << endl;
    }

    // Supraincarcarea operatorului +=
    void operator+=(float valoareDeAdaugat) {

        // Marim fiecare pret cu valoarea primita
        for (int i = 0; i < this->nrPreparate; i++) {
            this->preturi[i] += valoareDeAdaugat;
        }
    }

    // Dstructor
    ~Restaurant() {
        if (this->preturi != nullptr) {
            delete[] this->preturi;
        }
    }
};

int Restaurant::nrRestaurante = 0;

int main() {

    float* preturi = new float[3]{25, 35, 45};

    Restaurant r1("Restaurant Minerva", 3, preturi);

    cout << endl << "INAINTE DE +=:";
    cout << r1;

    // Testare operator +=
    r1 += 10;

    cout << endl << "DUPA +=:";
    cout << r1;

    return 0;
}
