
#include <iostream>
#include <string>
using namespace std;

class Hotel {
private:
    const int id;
    string denumire;
    int nrCamere;
    float* preturiCamere;

public:
    static int nrHoteluri;

    // Constructor default
    Hotel() : id(++nrHoteluri) {
        this->denumire = "Hotel necunoscut";
        this->nrCamere = 0;
        this->preturiCamere = nullptr;
    }

    // Constructor cu mai multi parametrii
    Hotel(string denumire, int nrCamere, float* preturiCamere)
        : id(++nrHoteluri) {

        this->denumire = denumire;
        this->nrCamere = nrCamere;

        this->preturiCamere = new float[nrCamere];

        for (int i = 0; i < this->nrCamere; i++) {
            this->preturiCamere[i] = preturiCamere[i];
        }

        delete[] preturiCamere;
    }

    // Constructor de copiere
    Hotel(const Hotel& copie) : id(++nrHoteluri) {
        this->denumire = copie.denumire;
        this->nrCamere = copie.nrCamere;

        if (copie.preturiCamere != nullptr) {
            this->preturiCamere = new float[this->nrCamere];

            for (int i = 0; i < this->nrCamere; i++) {
                this->preturiCamere[i] = copie.preturiCamere[i];
            }
        }
        else {
            this->preturiCamere = nullptr;
        }
    }

    // Supraincarcarea operatorului =
    void operator=(const Hotel& copie) {
        if (this != &copie) {
            this->denumire = copie.denumire;
            this->nrCamere = copie.nrCamere;

            if (this->preturiCamere != nullptr) {
                delete[] this->preturiCamere;
                this->preturiCamere = nullptr;
            }

            if (copie.preturiCamere != nullptr) {
                this->preturiCamere = new float[this->nrCamere];

                for (int i = 0; i < this->nrCamere; i++) {
                    this->preturiCamere[i] = copie.preturiCamere[i];
                }
            }
            else {
                this->preturiCamere = nullptr;
            }
        }
    }

    // Getter 
    float* getPreturiCamere() {
    float* vPreturi = new float[this->nrCamere];

    for (int i = 0; i < this->nrCamere; i++) {
        vPreturi[i] = this->preturiCamere[i];
    }

    return vPreturi;
}

// Setter
void setPreturiCamere(float* vPreturi, int dim) {
    this->nrCamere = dim;

    if (this->preturiCamere != nullptr) {
        delete[] this->preturiCamere;
        this->preturiCamere = nullptr;
    }

    if (vPreturi != nullptr) {
        this->preturiCamere = new float[this->nrCamere];

        for (int i = 0; i < this->nrCamere; i++) {
            this->preturiCamere[i] = vPreturi[i];
        }

        delete[] vPreturi;
    }
    else {
        this->preturiCamere = nullptr;
    }
}

    // Metoda de afisare
    void afisare() {
        cout << endl << "ID: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Nr camere: " << this->nrCamere;

        if (this->preturiCamere != nullptr) {
            cout << endl << "Preturi camere: ";

            for (int i = 0; i < this->nrCamere; i++) {
                cout << this->preturiCamere[i] << " lei ";
            }
        }
        cout << endl;
    }

    // Operatorul << (afisare)
    friend void operator<<(ostream& out, const Hotel& h) {
        out << endl << "ID: " << h.id;
        out << endl << "Denumire: " << h.denumire;
        out << endl << "Nr camere: " << h.nrCamere;

        if (h.preturiCamere != nullptr) {
            out << endl << "Preturi camere: ";

            for (int i = 0; i < h.nrCamere; i++) {
                out << h.preturiCamere[i] << " lei ";
            }
        }
        out << endl;
    }

    // Operatorul postincrementare: obiect++
    Hotel operator++(int) {
        Hotel copie = *this;
        for (int i = 0; i < this->nrCamere; i++) {
            this->preturiCamere[i]++;
        }
        return copie;
    }

    // DESTRUCTOR
    ~Hotel() {
        if (this->preturiCamere != nullptr) {
            delete[] this->preturiCamere;
        }
    }
};

int Hotel::nrHoteluri = 0;

int main() {

    Hotel h1;

    float* preturi = new float[3]{100, 120, 250};
    Hotel h2("Hotel Mercur", 3, preturi);

    cout << endl << "INAINTE DE POSTINCREMENTARE:";
    cout << h2;

    Hotel h3 = h2++;

    cout << endl << "H3 - VALORILE VECHI:";
    cout << h3;

    cout << endl << "H2 - VALORILE NOI:";
    cout << h2;

    return 0;
}
