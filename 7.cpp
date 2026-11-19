
#include <iostream>
#include <string>
using namespace std;

class Telefon {
private:
    const int id;
    string model;
    int nrAplicatii;
    float* dimensiuniAplicatii;

public:
    static int nrTelefoane;

    // Constructor default
    Telefon() : id(++nrTelefoane) {
        this->model = "Necunoscut";
        this->nrAplicatii = 0;
        this->dimensiuniAplicatii = nullptr;
    }

    // Constructor cu mai multi parametri
    Telefon(string model, int nrAplicatii, float* dimensiuniAplicatii)
        : id(++nrTelefoane) {

        this->model = model;
        this->nrAplicatii = nrAplicatii;

        this->dimensiuniAplicatii = new float[nrAplicatii];

        for (int i = 0; i < this->nrAplicatii; i++) {
            this->dimensiuniAplicatii[i] = dimensiuniAplicatii[i];
        }

        delete[] dimensiuniAplicatii;
    }

    // Constructor de copiere
    Telefon(const Telefon& copie) : id(++nrTelefoane) {
        this->model = copie.model;
        this->nrAplicatii = copie.nrAplicatii;

        if (copie.dimensiuniAplicatii != nullptr) {
            this->dimensiuniAplicatii = new float[this->nrAplicatii];

            for (int i = 0; i < this->nrAplicatii; i++) {
                this->dimensiuniAplicatii[i] = copie.dimensiuniAplicatii[i];
            }
        }
        else {
            this->dimensiuniAplicatii = nullptr;
        }
    }

    // Supraincarcarea operatorului =
    void operator=(const Telefon& copie) {
        if (this != &copie) {
            this->model = copie.model;
            this->nrAplicatii = copie.nrAplicatii;

            if (this->dimensiuniAplicatii != nullptr) {
                delete[] this->dimensiuniAplicatii;
                this->dimensiuniAplicatii = nullptr;
            }

            if (copie.dimensiuniAplicatii != nullptr) {
                this->dimensiuniAplicatii = new float[this->nrAplicatii];

                for (int i = 0; i < this->nrAplicatii; i++) {
                    this->dimensiuniAplicatii[i] = copie.dimensiuniAplicatii[i];
                }
            }
            else {
                this->dimensiuniAplicatii = nullptr;
            }
        }
    }

    // Getter pentru vectorul dinamic
    float* getDimensiuniAplicatii() {
        float* vDimensiuni = new float[this->nrAplicatii];

        for (int i = 0; i < this->nrAplicatii; i++) {
            vDimensiuni[i] = this->dimensiuniAplicatii[i];
        }

        return vDimensiuni;
    }

    // Setter pentru vectorul dinamic
    void setDimensiuniAplicatii(float* vDimensiuni, int dim) {
        this->nrAplicatii = dim;

        if (this->dimensiuniAplicatii != nullptr) {
            delete[] this->dimensiuniAplicatii;
            this->dimensiuniAplicatii = nullptr;
        }

        if (vDimensiuni != nullptr) {
            this->dimensiuniAplicatii = new float[this->nrAplicatii];

            for (int i = 0; i < this->nrAplicatii; i++) {
                this->dimensiuniAplicatii[i] = vDimensiuni[i];
            }

            delete[] vDimensiuni;
        }
        else {
            this->dimensiuniAplicatii = nullptr;
        }
    }

    // Metoda de afisare
    void afisare() {
        cout << endl << "ID: " << this->id;
        cout << endl << "Model: " << this->model;
        cout << endl << "Nr aplicatii: " << this->nrAplicatii;

        if (this->dimensiuniAplicatii != nullptr) {
            cout << endl << "Dimensiuni aplicatii: ";

            for (int i = 0; i < this->nrAplicatii; i++) {
                cout << this->dimensiuniAplicatii[i] << " MB ";
            }
        }
        cout << endl;
    }

    // Operatorul << (afisare)
    friend void operator<<(ostream& out, const Telefon& t) {
        out << endl << "ID: " << t.id;
        out << endl << "Model: " << t.model;
        out << endl << "Nr aplicatii: " << t.nrAplicatii;

        if (t.dimensiuniAplicatii != nullptr) {
            out << endl << "Dimensiuni aplicatii: ";

            for (int i = 0; i < t.nrAplicatii; i++) {
                out << t.dimensiuniAplicatii[i] << " MB ";
            }
        }
        out << endl;
    }

    // SUPRAINCARCAREA OPERATORULUI !
    bool operator!() {
        return this->nrAplicatii == 0;
    }

    // Destructor
    ~Telefon() {
        if (this->dimensiuniAplicatii != nullptr) {
            delete[] this->dimensiuniAplicatii;
        }
    }
};

int Telefon::nrTelefoane = 0;

int main() {

    // Constructor default
    Telefon t1;

    // Constructor cu parametri
    float* dimensiuni = new float[3]{120, 250, 80};
    Telefon t2("Samsung Galaxy", 3, dimensiuni);

    // Constructor de copiere
    Telefon t3(t2);

    // Testare operator =
    t1 = t2;

    // Testare getter
    float* valori = t2.getDimensiuniAplicatii();
    cout << endl << "Prima aplicatie: " << valori[0] << " MB";
    delete[] valori;

    // Testare setter
    t3.setDimensiuniAplicatii(new float[2]{150, 300}, 2);

    // Testare metoda de afisare
    t3.afisare();

    // Testare operator <<
    cout << t2;

    // TESTARE OPERATOR !
    if (!t2) {
        cout << endl << "Telefonul nu are aplicatii!";
    }
    else {
        cout << endl << "Telefonul are aplicatii!";
    }

    // Testare operator ! pe un telefon fara aplicatii
    Telefon t4;

    if (!t4) {
        cout << endl << "Telefonul nu are aplicatii!";
    }
    else {
        cout << endl << "Telefonul are aplicatii!";
    }

    return 0;
}
