#include <iostream>
#include <time.h>

#define CARD_AMOUNT 54

using namespace std;

int* GenerateKey ();
char* Decrypt(char*, int**);
char* Encrypt(char*, int**);

int main()
{
    srand(time(0));
    int* key = GenerateKey();
    for (int i = 0; i < CARD_AMOUNT; ++i)
    {
        printf("%i\n", key[i]);
    }


    return 0;
}

// A = 53, B = 54
int* GenerateKey () {

    int* cardList =(int*) calloc(CARD_AMOUNT, sizeof(int));

    for (int j = 1; j <= CARD_AMOUNT; ++j) {
        cardList[j-1] = j;
    }

    for (int i = CARD_AMOUNT-1; i > 0; --i){
        int r = rand() % i + 1;
        int k = cardList[i];
        cardList[i] = cardList[r];
        cardList[r] = k;
    }

    return cardList;
}

char* EncryptChar(char* plaintext, int** key) {
    int* cutA =(int*) calloc(CARD_AMOUNT-1, sizeof(int));
    int* cutB =(int*) calloc(CARD_AMOUNT-1, sizeof(int));
    int* cutC =(int*) calloc(CARD_AMOUNT-1, sizeof(int));
    int* newKey2 =(int*) calloc(CARD_AMOUNT, sizeof(int));

    int* newKey = *key;
    int j = 0;
    for (int i = 0; i < CARD_AMOUNT && j == 0; ++i) {
        if (newKey[i] == 53) {
            if (i == 0) {
                int k = newKey[0];
                newKey[0] = newKey[53];
                cardList[53] = newKey[0];
            }else{
                int k = newKey[i];
                newKey[i] = newKey[i-1];
                cardList[i-1] = newKey[i];
                j =
            }
        }
    }

    for (int i = 0, j = 0; i < CARD_AMOUNT && j == 0; ++i) {
        if (newKey[i] == 54) {
            if (i == 1) {
                int k = newKey[1];
                newKey[1] = newKey[53];
                cardList[53] = newKey[0];
            }else{
                int k = newKey[i];
                newKey[i] = newKey[i-2];
                cardList[i-2] = newKey[i];
            }
            j = 1;
        }
    }
    int a, b, c;
    int a1, b1;
    for (int i = 0, n = 0; i < CARD_AMOUNT; ++i) {
        if (n == 0) {
            if (newKey[i] == 53 || newKey[i] == 54) {
                a1 = newKey[i]
                n = 1;
                a = i;
                continue;
            }
            cutA[i] = newKey[i];
        }
        else if (n == 1) {
            if (newKey[i] == 53 || newKey[i] == 54) {
                b1 = newKey[i]
                n = 2;
                b = i-a;
                continue;
            }
            cutB[i-a] = newKey[i];
        }
        else {
            cutC[i-a-b] = newKey[i];
        }
    }

    for (int h = 0; h < a; h++) {
        newKey[h] = cutC[h];
    }
    newKey[a] = b1;
    for (int h = a+1; h < b; h++) {
        newKey[h] = cutB[h];
    }
    newKey[b] = a1;
    for (int h = b+1; h < CARD_AMOUNT; h++) {
        newKey[h] = cutA[h];
    }

    int gap = newKey[0];
    int memory = newKey[53];
    for (int g = gap; g < CARD_AMOUNT-1; ++g) {
        newKey2[g - gap] = newKey[g];
    }
    for (int s = 0; s < gap; ++s) {
        newKey2[CARD_AMOUNT - gap + s] = newKey[s];
    }

}
