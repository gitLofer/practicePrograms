#include <iostream>

using namespace std;

enum TipPreliva {COKOLADNI, COKOLADNI_SA_SLAGOM};
enum KolacState {U_PRIPREMI, PRIPREMLJEN, PECE_SE, ZAGOREO};

class Preliv {
private:
    TipPreliva tip;
public:
    Preliv(){
        tip = COKOLADNI;
    }
    Preliv(TipPreliva preliv) {
        tip = preliv;
    }
    Preliv(Preliv &preliv) {
        tip = preliv.tip;
    }
    bool dodajSlag (){
        if (tip == COKOLADNI) {
            tip = COKOLADNI_SA_SLAGOM;
            return 1;
        }
        return 0;
    }
    bool ukloniSlag (){
        if (tip == COKOLADNI_SA_SLAGOM) {
            tip = COKOLADNI;
            return 1;
        }
        return 0;
    }
    TipPreliva getPreliv () const{
        return tip;
    }
    void ispisPreliva(const Preliv &preliv) const{
        TipPreliva a = preliv.getPreliv();
        printf("Preliv: ");
        if (a == COKOLADNI)
            printf("COKOLADNI\n");
        else if (a == COKOLADNI_SA_SLAGOM)
            printf("COKOLADNI SA SLAGOM\n");
        return;
    }
};

class Kolac {
private:
    KolacState state;
    int temperatura;
    Preliv preliv;
public:
    /// Konstruktori
    Kolac() : preliv() {
    temperatura = 20;
    state = U_PRIPREMI;
    }
    Kolac(KolacState stanje, int celsius, Preliv preliv1) {
        state = stanje;
        temperatura = celsius;
        preliv = preliv1;
    }
    Kolac(const Kolac &kolacic) {
        state = kolacic.state;
        temperatura = kolacic.temperatura;
        preliv = kolacic.preliv;
    }
    /// Metode
    bool staviDaSePece (){
        if (state == U_PRIPREMI && preliv.getPreliv() == COKOLADNI){
            state = PECE_SE;
            return 1;
        }
        return 0;
    }
    bool ispeciKolac (){
        if (state == PECE_SE){
            state = U_PRIPREMI;
            temperatura = 20;
            return 1;
        }
        return 0;
    }
    bool zavrsiKolac (){
        if (state == U_PRIPREMI){
            state = PRIPREMLJEN;
            return 1;
        }
        return 0;
    }
    bool povecajTemp () {
        if (state == PECE_SE){
            temperatura += 20;
            if (temperatura > 100) {
                temperatura = 20;
                state = ZAGOREO;
            }
            return 1;
        }
        return 0;
    }
    bool smanjiTemp () {
        if (state == PECE_SE && temperatura >= 60) {
            temperatura -= 20;
            return 1;
        }
        return 0;
    }
    bool dodajSlag () {
        return preliv.dodajSlag();
    }
    bool ukloniSlag () {
        return preliv.ukloniSlag();
    }

    void ispisKolaca (const Kolac &kolacic) {
        printf("Stanje: ");
        switch(kolacic.state) {
    case ZAGOREO:
        printf("ZAGOREO\n");
        break;
    case U_PRIPREMI:
        printf("U_PRIPREMI\n");
        break;
    case PECE_SE:
        printf("PECE_SE\n");
        break;
    case PRIPREMLJEN:
        printf("PRIPREMLJEN\n");
        break;
    }
        printf("Temperatura: %i", kolacic.temperatura);
        kolacic.preliv.ispisPreliva(kolacic.preliv);
    }

};

int main()
{
    return 0;
}
