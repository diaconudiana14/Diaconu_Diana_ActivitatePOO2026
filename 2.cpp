#include <iostream>
#include <cstring>
using namespace std;

class Biblioteca {
public:
    const int idBiblioteca;
    char* nume;
    int nrCarti;
    float* preturiCarti;

    // Constructor default
    Biblioteca() : idBiblioteca(0) {
        this->nume = nullptr;
        this->nrCarti = 0;
        this->preturiCarti = nullptr;
    }

    // Constructor cu mai multi parametri
    Biblioteca(int idBiblioteca, const char* nume, int nrCarti, float* preturiCarti) : idBiblioteca(idBiblioteca) {
        if (nume != nullptr) {
            this->nume = new char[strlen(nume) + 1];
            strcpy(this->nume, nume);
        }
        else {
            this->nume = nullptr;
        }

        if (preturiCarti != nullptr && nrCarti > 0) {
            this->nrCarti = nrCarti;
            this->preturiCarti = new float[nrCarti];

            for (int i = 0; i < nrCarti; i++) {
                this->preturiCarti[i] = preturiCarti[i];
            }
        }
        else {
            this->preturiCarti = nullptr;
        }
    }

    // Constructor de copiere
    Biblioteca(const Biblioteca& copie) : idBiblioteca(copie.idBiblioteca) {
        if (copie.nume != nullptr) {
            this->nume = new char[strlen(copie.nume) + 1];
            strcpy(this->nume, copie.nume);
        }
        else {
            this->nume = nullptr;
        }

        this->nrCarti = copie.nrCarti;

        if (copie.preturiCarti != nullptr   && copie.nrCarti > 0) {
            this->preturiCarti = new float[copie.nrCarti];

            for (int i = 0; i < copie.nrCarti; i++) {
                this->preturiCarti[i] = copie.preturiCarti[i];
            }
        }
        else {
            this->preturiCarti = nullptr;
        }
    }

    // Getter pentru atributul constant
    int getIdBiblioteca() {
        return this->idBiblioteca;
    }

    // Setter pentru atributul alocat dinamic
    void setNume(const char* numeNou) {
        char* copie = nullptr;

        if (numeNou != nullptr) {
            copie = new char[strlen(numeNou) + 1];
            strcpy(copie, numeNou);
        }
        if(this->nume != nullptr){
          delete[] this->nume;
        }
        this->nume = copie;
    }

    // Operatorul =
    void operator=(const Biblioteca& copie) {

    if (this != &copie) {
        if (this->nume != nullptr) {
            delete[] this->nume;
            this->nume = nullptr;
        }

        if (copie.nume != nullptr) {
            this->nume = new char[strlen(copie.nume) + 1];
            strcpy(this->nume, copie.nume);
        }
        else {
            this->nume = nullptr;
        }

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

    // Operatorul + adauga pretul unei carti
    Biblioteca operator+(float pretNou) const {
        Biblioteca rezultat(*this);

        float* preturiNoi = new float[rezultat.nrCarti + 1];

        for (int i = 0; i < rezultat.nrCarti; i++) {
            preturiNoi[i] = rezultat.preturiCarti[i];
        }

        preturiNoi[rezultat.nrCarti] = pretNou;

        delete[] rezultat.preturiCarti;

        rezultat.preturiCarti = preturiNoi;
        rezultat.nrCarti++;

        return rezultat;
    }

    // Operatorul () afiseaza atributele
    void operator()() const {
        cout << "ID Biblioteca: " << this->idBiblioteca << endl;

        if (this->nume != nullptr) {
            cout << "Nume: " << this->nume << endl;
        }

        cout << "Numar carti: " << this->nrCarti << endl;

        cout << "Preturi carti: ";
        for (int i = 0; i < this->nrCarti; i++) {
            cout << this->preturiCarti[i] << " ";
        }

        cout << endl;
    }

    // Destructor
    ~Biblioteca() {
        delete[] this->nume;
        delete[] this->preturiCarti;
    }
};

int main() {

    float preturi[] = {50, 80, 100};

    // Constructor cu parametri
    Biblioteca b1(1, "Biblioteca Metropolitana Bucuresti ", 3, preturi);

    // Testare getter
    cout << b1.getIdBiblioteca() << endl;

    // Testare setter
    b1.setNume("Biblioteca Judeteana Alexandru si Aristia Aman");

    // Testare operator +
    b1 = b1 + 120;

    // Testare operator ()
    b1();

    return 0;
}