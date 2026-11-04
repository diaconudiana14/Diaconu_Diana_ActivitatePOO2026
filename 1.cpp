#include<iostream>
#include<string>
using namespace  std;

//Definirea clasei si a atributelor

class Masina{
  public:
  const int id;
  string model;
  int nrMasini;
  float* pret;

  // Constructor default

  Masina(): id(0){
    this->model = "Necunoscut";
    this->nrMasini = 0;
    this->pret = nullptr;
  }

  // Constructor cu mai multi parametrii

  Masina(int id, string model, int nrMasini, float* pret) : id(id){
    this->model = model;
    this->nrMasini = nrMasini;
    if(pret!=nullptr &&nrMasini>0){
      this->pret=new float[nrMasini];
      for(int i=0; i<nrMasini; i++)
      this->pret[i]=pret[i];
      }
    }

    //Constructor de copiere
     Masina(const Masina& copie) : id(0) {
    this->model = copie.model;
    this->nrMasini = copie.nrMasini;
    if (copie.pret != nullptr) {
        this->pret = new float[this->nrMasini];
        for (int i = 0; i < this->nrMasini; i++) {
            this->pret[i] = copie.pret[i];
        }
    }
    else {
        this->pret = nullptr;
    } 
  }

  // Metoda GET pentru un atribut alocat dinamic
  float* getPret(){
    if(this->pret==nullptr){
      return nullptr;
    }
    float* vPret=new float[this->nrMasini];
    for(int i=0; i<this->nrMasini; i++){
      vPret[i]=this->pret[i];
    }
    return vPret;
  }

  //Metoda SET pentru un atribut alocat dinamic

  void setModel(string modelNou){
    this->model=modelNou;
  }
// Operatorul =
    Masina& operator=(const Masina& copie) {
        if (this != &copie) {
            this->model = copie.model;
            float* pretNou = nullptr;
            if (copie.pret != nullptr) {
                pretNou = new float[copie.nrMasini];
                for (int i = 0; i < copie.nrMasini; i++) {
                    pretNou[i] = copie.pret[i];
                }
            }
            if (this->pret != nullptr) {
                delete[] this->pret;
            }
            this->pret = pretNou;
            this->nrMasini = copie.nrMasini;
        }
        return *this;
    }

    // Operatorul afisare ()
    void operator()(int pozitie, float pretNou) {
        if (pozitie >= 0 && pozitie < this->nrMasini && this->pret != nullptr) {
            this->pret[pozitie] = pretNou;
        }
        else {
            throw exception();
        }
    }
    // Destructor
    ~Masina() {
        if (this->pret != nullptr) {
            delete[] this->pret;
        }
    }
};

int main() {

    // Testare constructor default
    Masina m1;
    float preturi[] = { 12000, 16000, 25000 };
    Masina m2(1, "BMW", 3, preturi);
    Masina m3(m2);
    m1.setModel("Audi");
    float* valori = m3.getPret();
    cout<<m3.nrMasini<<" ";
    for (int i = 0; i < m3.nrMasini; i++) {
        cout << valori[i] << " ";
    }
// Testare operator functie ()
    m2(1, 18000);
    float* valoriNoi = m2.getPret();
    for (int i = 0; i < m2.nrMasini; i++) {
        cout << valoriNoi[i] << " ";
    }

    delete[] valori;

    m1 = m2;

    return 0;
}



