
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class BibliotecaDigitala {
private:
    const int id;
    string denumire;
    int nrCarti;
    float* preturiCarti;

public:
    static int nrBiblioteci;

    // Constructor default
    BibliotecaDigitala() : id(++nrBiblioteci) {
        this->denumire = "Biblioteca necunoscuta";
        this->nrCarti = 0;
        this->preturiCarti = nullptr;
    }

    // Constructor cu mai multi parametri
    BibliotecaDigitala(string denumire, int nrCarti, float* preturiCarti)
        : id(++nrBiblioteci) {

        this->denumire = denumire;
        this->nrCarti = nrCarti;

        if (preturiCarti != nullptr && nrCarti > 0) {
            this->preturiCarti = new float[nrCarti];

            for (int i = 0; i < this->nrCarti; i++) {
                this->preturiCarti[i] = preturiCarti[i];
            }
        }
        else {
            this->nrCarti = 0;
            this->preturiCarti = nullptr;
        }
    }

    // Constructor de copiere
    BibliotecaDigitala(const BibliotecaDigitala& copie)
        : id(++nrBiblioteci) {

        this->denumire = copie.denumire;
        this->nrCarti = copie.nrCarti;

        if (copie.preturiCarti != nullptr) {
            this->preturiCarti = new float[this->nrCarti];

            for (int i = 0; i < this->nrCarti; i++) {
                this->preturiCarti[i] = copie.preturiCarti[i];
            }
        }
        else {
            this->preturiCarti = nullptr;
        }
    }

    // Supraincarcarea operatorului =
    void operator=(const BibliotecaDigitala& copie) {
        if (this != &copie) {
            this->denumire = copie.denumire;
            this->nrCarti = copie.nrCarti;

            if (this->preturiCarti != nullptr) {
                delete[] this->preturiCarti;
                this->preturiCarti = nullptr;
            }

            if (copie.preturiCarti != nullptr) {
                this->preturiCarti = new float[this->nrCarti];

                for (int i = 0; i < this->nrCarti; i++) {
                    this->preturiCarti[i] = copie.preturiCarti[i];
                }
            }
            else {
                this->preturiCarti = nullptr;
            }
        }
    }

    // Getter pentru vectorul dinamic
    float* getPreturiCarti() {
        float* vPreturi = new float[this->nrCarti];

        for (int i = 0; i < this->nrCarti; i++) {
            vPreturi[i] = this->preturiCarti[i];
        }

        return vPreturi;
    }

    // Setter pentru vectorul dinamic
    void setPreturiCarti(float* vPreturi, int dim) {
        if (dim < 0 || (dim > 0 && vPreturi == nullptr)) {
            throw invalid_argument("Vector invalid");
        }

        float* preturiNoi = nullptr;

        if (dim > 0) {
            preturiNoi = new float[dim];

            for (int i = 0; i < dim; i++) {
                preturiNoi[i] = vPreturi[i];
            }
        }

        if (this->preturiCarti != nullptr) {
            delete[] this->preturiCarti;
        }

        this->preturiCarti = preturiNoi;
        this->nrCarti = dim;
    }

    // Metoda de afisare
    void afisare() {
        cout << endl << "ID: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Nr carti: " << this->nrCarti;

        if (this->preturiCarti != nullptr) {
            cout << endl << "Preturi carti: ";

            for (int i = 0; i < this->nrCarti; i++) {
                cout << this->preturiCarti[i] << " lei ";
            }
        }
        cout << endl;
    }

    // Operatorul << (afisare)
    friend void operator<<(ostream& out, const BibliotecaDigitala& b) {
        out << endl << "ID: " << b.id;
        out << endl << "Denumire: " << b.denumire;
        out << endl << "Nr carti: " << b.nrCarti;

        if (b.preturiCarti != nullptr) {
            out << endl << "Preturi carti: ";

            for (int i = 0; i < b.nrCarti; i++) {
                out << b.preturiCarti[i] << " lei ";
            }
        }
        out << endl;
    }

    // SUPRAINCARCAREA OPERATORULUI []
    float& operator[](int index) {
        if (index >= 0 && index < this->nrCarti) {
            return this->preturiCarti[index];
        }
        else {
            throw out_of_range("Index invalid");
        }
    }

    // Destructor
    ~BibliotecaDigitala() {
        if (this->preturiCarti != nullptr) {
            delete[] this->preturiCarti;
        }
    }
};

int BibliotecaDigitala::nrBiblioteci = 0;

int main() {

    // Testare constructor default
    BibliotecaDigitala b1;

    // Testare constructor cu parametri
    float preturi[] = {30, 45, 60};
    BibliotecaDigitala b2("Biblioteca Online", 3, preturi);

    // Testare constructor de copiere
    BibliotecaDigitala b3(b2);

    // Testare operator =
    b1 = b2;

    // Testare getter
    float* preturiCopiate = b2.getPreturiCarti();
    cout << endl << "Primul pret din getter: "
         << preturiCopiate[0] << " lei";
    delete[] preturiCopiate;

    // Testare setter
    float preturiNoi[] = {40, 55, 70};
    b3.setPreturiCarti(preturiNoi, 3);

    // Testare metoda de afisare
    b3.afisare();

    // Testare operator <<
    cout << b2;

    // TESTARE OPERATOR []
    cout << endl << "Pretul cartii de pe pozitia 1: "
         << b2[1] << " lei";

    // Modificarea pretului folosind operatorul []
    b2[1] = 100;

    cout << endl << "DUPA MODIFICARE:";
    cout << b2;

    return 0;
}
