
#include <iostream>
#include <string>
using namespace std;

class Cinema {
private:
    const int id;
    string denumire;
    int nrBilete;
    float* preturiBilete;

public:
    static int nrCinematografe;

    // CONSTRUCTOR DEFAULT
    Cinema() : id(++nrCinematografe) {
        this->denumire = "Cinema necunoscut";
        this->nrBilete = 0;
        this->preturiBilete = nullptr;
    }

    // CONSTRUCTOR CU MAI MULTI PARAMETRI
    Cinema(string denumire, int nrBilete, float* preturiBilete)
        : id(++nrCinematografe) {

        this->denumire = denumire;
        this->nrBilete = nrBilete;

        this->preturiBilete = new float[nrBilete];

        for (int i = 0; i < this->nrBilete; i++) {
            this->preturiBilete[i] = preturiBilete[i];
        }

        delete[] preturiBilete;
    }

    // CONSTRUCTOR DE COPIERE
    Cinema(const Cinema& copie) : id(++nrCinematografe) {
        this->denumire = copie.denumire;
        this->nrBilete = copie.nrBilete;

        if (copie.preturiBilete != nullptr) {
            this->preturiBilete = new float[this->nrBilete];

            for (int i = 0; i < this->nrBilete; i++) {
                this->preturiBilete[i] = copie.preturiBilete[i];
            }
        }
        else {
            this->preturiBilete = nullptr;
        }
    }

    // SUPRAINCARCAREA OPERATORULUI =
    void operator=(const Cinema& copie) {

        // Copiem atributele simple
        this->denumire = copie.denumire;
        this->nrBilete = copie.nrBilete;

        // Stergem vectorul vechi
        if (this->preturiBilete != nullptr) {
            delete[] this->preturiBilete;
            this->preturiBilete = nullptr;
        }

        // Alocam memorie si copiem vectorul nou
        if (copie.preturiBilete != nullptr) {
            this->preturiBilete = new float[this->nrBilete];

            for (int i = 0; i < this->nrBilete; i++) {
                this->preturiBilete[i] = copie.preturiBilete[i];
            }
        }
        else {
            this->preturiBilete = nullptr;
        }
    }

    // GETTER PENTRU VECTORUL DINAMIC
    float* getPreturiBilete() {
        float* vPreturi = new float[this->nrBilete];

        for (int i = 0; i < this->nrBilete; i++) {
            vPreturi[i] = this->preturiBilete[i];
        }

        return vPreturi;
    }

    // SETTER PENTRU VECTORUL DINAMIC
    void setPreturiBilete(float* vPreturi, int dim) {
        this->nrBilete = dim;

        if (this->preturiBilete != nullptr) {
            delete[] this->preturiBilete;
            this->preturiBilete = nullptr;
        }

        if (vPreturi != nullptr) {
            this->preturiBilete = new float[this->nrBilete];

            for (int i = 0; i < this->nrBilete; i++) {
                this->preturiBilete[i] = vPreturi[i];
            }

            delete[] vPreturi;
        }
        else {
            this->preturiBilete = nullptr;
        }
    }

    // METODA DE AFISARE
    void afisare() {
        cout << endl << "ID: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Nr bilete: " << this->nrBilete;

        if (this->preturiBilete != nullptr) {
            cout << endl << "Preturi bilete: ";

            for (int i = 0; i < this->nrBilete; i++) {
                cout << this->preturiBilete[i] << " lei ";
            }
        }
        cout << endl;
    }

    // OPERATORUL << (AFISARE)
    friend void operator<<(ostream& out, const Cinema& c) {
        out << endl << "ID: " << c.id;
        out << endl << "Denumire: " << c.denumire;
        out << endl << "Nr bilete: " << c.nrBilete;

        if (c.preturiBilete != nullptr) {
            out << endl << "Preturi bilete: ";

            for (int i = 0; i < c.nrBilete; i++) {
                out << c.preturiBilete[i] << " lei ";
            }
        }
        out << endl;
    }

    // DESTRUCTOR
    ~Cinema() {
        if (this->preturiBilete != nullptr) {
            delete[] this->preturiBilete;
        }
    }
};

int Cinema::nrCinematografe = 0;

int main() {

    // Constructor default
    Cinema c1;

    // Constructor cu parametri
    float* preturi = new float[3]{25, 30, 40};
    Cinema c2("Cinema City", 3, preturi);

    cout << endl << "INAINTE DE ATRIBUIRE:";
    cout << c1;

    // TESTARE OPERATOR =
    c1 = c2;

    cout << endl << "DUPA ATRIBUIRE:";
    cout << c1;

    cout << endl << "OBIECTUL SURSA:";
    cout << c2;

    return 0;
}
