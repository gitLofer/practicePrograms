#include <stdio.h>
#include <stdlib.h>

typedef struct artikal{
        int sifra;
        char naziv[20];
        int cena;
}Artikal;

typedef struct prodavnica{
        char naziv[20];
        int brojArtikala;
        Artikal *artikli;
}Prodavnica;

Prodavnica *p;
Artikal *b;

void printMenu ();
void postaviNaziv ();
void dodajArtikal ();
void prikazArtikala ();
void artiklPoSifri (int input);
void obrisiPoSifri (int input);
void obrisiSve ();

int indexPoSifri (int sifra);

int main()
{
    p = malloc(sizeof(Prodavnica));
    p[0].artikli = malloc(sizeof(Artikal));
    p[0].brojArtikala = 0;
    p[0].naziv[0] = '\0';
    int input;

    do {
        printMenu();
        printf("> ");
        scanf("%i", &input);
        printf("\n");

        switch(input){
        int x;
    case 1:
        postaviNaziv();
        break;
    case 2:
        dodajArtikal();
        break;
    case 3:
        printf("> ");
        scanf("%i", &x);
        printf("\n");
        obrisiPoSifri(x);
        break;
    case 4:
        obrisiSve();
        break;
    case 5:
        printf("> ");
        scanf("%i", &x);
        printf("\n");
        artiklPoSifri(x);
        break;
    case 6:
        prikazArtikala();
        break;
    case 7:
        break;
    default:
        printf("Uneta opcija ne postoji, pokusajte ponovo\n");
        break;
        }

    }while (input != 7);

    return 0;
}

void printMenu () {
        printf("\n");
        printf("1) Postavi naziv prodavnice\n");
        printf("2) Dodaj artikal\n");
        printf("3) Obrisi artikal putem sifre\n");
        printf("4) Obrisi sve artikle\n");
        printf("5) Pronadji artikal putem sifre\n");
        printf("6) Prikazi artikle\n");
        printf("7) Kraj rada programa\n");
        printf("\n");
        return;
}

void postaviNaziv () {
    char x[20];

    printf("> ");
    scanf("%s", x);

    int i;
    for (i = 0; x[i] != '\0'; ++i) {
        p[0].naziv[i] = x[i];
    }
    p[0].naziv[i] = '\0';
    return;
}

void dodajArtikal () {
    p[0].brojArtikala++;
    b = malloc(sizeof(Artikal) * p[0].brojArtikala);

    int cena,sifra;
    char naziv[20];

    printf("Sifra: ");
    scanf("%i", &sifra);
    fflush(stdin);
    printf("Naziv: ");
    scanf("%s", naziv);
    fflush(stdin);
    printf("Cena: ");
    scanf("%i", &cena);
    fflush(stdin);

    //Prebacivanje iz p u b
    int len = 0;
    for(; len < p[0].brojArtikala - 1; ++len){

        b[len].cena = p[0].artikli[len].cena;
        b[len].sifra = p[0].artikli[len].sifra;
        int i;
        for (i = 0; p[0].artikli[len].naziv[i] != '\0'; ++i) {
            b[len].naziv[i] = p[0].artikli[len].naziv[i];
        }
        b[len].naziv[i] = '\0';
    }

    //Dodavanje novog artikla
    b[len].cena = cena;
    b[len].sifra = sifra;

    int k;
    for (k = 0; naziv[k] != '\0'; ++k) {
        b[len].naziv[k] = naziv[k];
    }
    b[len].naziv[k] = '\0';

    //Gotovo prebacivanje
    free(p[0].artikli);
    p[0].artikli = malloc (sizeof(Artikal) * p[0].brojArtikala);

    for(; len >= 0; --len){

        p[0].artikli[len].cena = b[len].cena;
        p[0].artikli[len].sifra = b[len].sifra;
        int i;
        for (i = 0; b[len].naziv[i] != '\0'; ++i) {
             p[0].artikli[len].naziv[i] = b[len].naziv[i];
        }
        p[0].artikli[len].naziv[i] = '\0';
    }
    free(b);
    return;
}

void prikazArtikala () {

    if (p[0].brojArtikala == 0) {
        printf("Trenutno nema artikala\n");
        return;
    }

    printf("Prodavnica %s\n", p[0].naziv);

    for (int tracker = 0; tracker < p[0].brojArtikala; ++tracker) {
        printf("ARTIKL %i: ", tracker+1);
        printf("%i\t", p[0].artikli[tracker].sifra);
        printf("%s\t", p[0].artikli[tracker].naziv);
        printf("%i\n", p[0].artikli[tracker].cena);
    }
    return;
}

void artiklPoSifri (int input) {
    int z = indexPoSifri(input);

    if (z == -1) {
        printf("Uneta sifra ne postoji\n");
        return;
    }

    printf("ARTIKL %i: ", z + 1);
    printf("%i\t", p[0].artikli[z].sifra);
    printf("%s\t", p[0].artikli[z].naziv);
    printf("%i\n", p[0].artikli[z].cena);

    return;
}

void obrisiPoSifri (int input) {
    int z = indexPoSifri(input);

    if (z == -1) {
        printf("Uneta sifra ne postoji\n");
        return;
    }

    p[0].brojArtikala--;
    b = malloc(sizeof(Artikal) * p[0].brojArtikala);

    for (int k = 0, i = 0; k < p[0].brojArtikala; ++k, ++i) {
        if (i == z) {
            k--;
            continue;
        }

        b[k].cena = p[0].artikli[i].cena;
        b[k].sifra = p[0].artikli[i].sifra;

        int s;
        for (s = 0; p[0].artikli[i].naziv[s] != '\0'; ++s) {
            b[k].naziv[s] = p[0].artikli[i].naziv[s];
        }
        b[k].naziv[s] = '\0';

    }

    free(p[0].artikli);
    p[0].artikli = malloc(sizeof(Artikal) * p[0].brojArtikala);

    for(int len = p[0].brojArtikala - 1; len >= 0; --len){

        p[0].artikli[len].cena = b[len].cena;
        p[0].artikli[len].sifra = b[len].sifra;

        int i;
        for (i = 0; b[len].naziv[i] != '\0'; ++i) {
             p[0].artikli[len].naziv[i] = b[len].naziv[i];
        }
        p[0].artikli[len].naziv[i] = '\0';
    }

    free(b);
    return;
}

void obrisiSve () {
    free(p[0].artikli);
    p[0].brojArtikala = 0;
    p[0].artikli = malloc(sizeof(Artikal));
    return;
}

int indexPoSifri (int sifra) {
    int index = 0;

    if (p[0].brojArtikala == 0)
        return -1;

    for (; index < p[0].brojArtikala; index++) {
        if (sifra == p[0].artikli[index].sifra) {
            return index;
        }
    }
    return -1;
}
