/*
STRING, compito
Scrivere un programma che acquisita una frase permetta a scelta dell'utente di (attraverso un menu):

1. Stamparla
2. Stamparla invertita
3. Stampare la stringa in maiuscolo
4. Stamparla eliminando gli spazi
5. Contare il numero di parole presenti6. Permetta di sostituire un carattere con un altro
7. Calcoli la ricorrenza di una determinata lettera dell'alfabeto sia essa minuscola o maiuscola
8. Uscire dal programma
*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define DIM 100

void stampa(char frase[]);
bool isLetter(char x);
int contaParole(char frase[]);
void sostituisciChar(char frase[], char previous_char, char new_char);
int ricorrenzaChar(char frase[], char letter);

int main (){
    char frase[DIM];
    int scelta = 0, size;
    char vecchia_lettera, nuova_lettera, lettera;
    cout << "Inserisci una frase: " << endl;
    cin.getline(frase, DIM, '\n');
    size = strlen(frase);

    do{
        cout << endl << endl;
        cout << "Menu delle operazioni:" << endl;
        cout << "1. Stampa stringa" << endl;
        cout << "2. Stampa stringa invertita" << endl;
        cout << "3. Stampa la stringa in maiuscolo" << endl;
        cout << "4. Stamparla eliminando gli spazi" << endl;
        cout << "5. Contare il numero di parole presenti" << endl;
        cout << "6. Permetta di sostituire un carattere con un altro" << endl;
        cout << "7. Calcoli la ricorrenza di una determinata lettera dell'alfabeto sia essa minuscola o maiuscola" << endl;
        cout << "8 - Uscita dal programma" << endl;
        cout << "Scegli un'operazione: ";
        cin >> scelta;

        cout << endl << endl;

        switch(scelta){
            case 1:
                cout << "\t";
                stampa(frase);
                break;
            case 2:
                cout << "frase: \t";
                stampa(frase);
                cout << endl << "frase invertita: \t";
                for(int i = size-1; i >= 0; i--){
                    cout << frase[i];
                }
                break;
            case 3:
                cout << "frase: \t";
                stampa(frase);
                cout << endl << "frase in maiuscolo: \t";
                for(int i = 0; i < size; i++){
                    cout << (char)toupper(frase[i]); //cout << (char)toupper(frase[i]); è meglio, ti assicura non errori
                }
                break;
            case 4:
                cout << "frase: \t";
                stampa(frase);
                cout << endl << "frase senza spazi: \t";
                for(int i = 0; i < size; i++){
                    if(frase[i] != ' ')
                        cout << frase[i];
                }
                break;
            case 5:
                cout << "Il numero di parole presenti è uguale a : " << contaParole(frase) << "." << endl;
                cout << "frase: \t";
                stampa(frase);
                cout << endl;
                break;
            case 6:
                cout << "\t";
                stampa(frase);
                cout << endl << "Inserisci il carattere da sostituire: ";
                cin >> vecchia_lettera;
                cout << "Inserisci il nuovo carattere: ";
                cin >> nuova_lettera;

                sostituisciChar(frase, vecchia_lettera, nuova_lettera);
                cout << endl << "frase dopo: \t";
                stampa(frase);
                cout << endl;

                cout << "Operazione riuscita." << endl;
                break;
            case 7:
                cout << "\t";
                stampa(frase);
                cout << endl <<"Inserisci il carattere di cui si vuole sapere la ricorrenza: ";
                cin >> lettera;

                cout << endl;
                cout << "La lettera " << lettera << " o " << (lettera+32) << " è presente all'interno della frase " << ricorrenzaChar(frase, lettera) << " volte." << endl;
                stampa(frase);
                cout << endl;
                break;
            case 8:
                cout << "------------------------------------------------------------------------------" << endl;
                cout << "----------------------------Uscita dal programma.-----------------------------" << endl;
                cout << "------------------------------------------------------------------------------" << endl;
                break;
            default:
                cout << "\t\tOperazione non valida. \n\t\t\tRiprova..." << endl;
        }

        cout << endl << endl << endl;

    }while(scelta != 8);

    return 0;
}

// bool isLetter(char x){
//     if(x != ' ' && x != '.' && x != ',' && x != ';' && x != '?' && x != '?' && x != '?' && x != '?' && x != '?' && x != '?' && x != '?' && !isNumero(x) && x == '0' && x == '1' && x == '2' && x == '3' && x == '4' && x == '5' && x == '6' && x == '7' && x == '8' && x == '9')
//         return 1;
//     return 0;
// }

void stampa(char frase[]){
    int size = strlen(frase);
    for(int i = 0; i < size; i++){
        cout << frase[i];
    }
}

bool isLetter(char x){
    if((x > 64 && x < 91) || (x > 96 && x < 123))
        return 1;
    return 0;
}

int contaParole(char frase[]){
    int count = 0;
    int size = strlen(frase);
    for(int i = 0; i < size; i++){
        if(isLetter(frase[i])){
            i++;
            while(isLetter(frase[i])){
                i++;
            }
            count++;
        }
    }
    return count;
}

void sostituisciChar(char frase[], char previous_char, char new_char){
    int size = strlen(frase);
    for(int i = 0; i < size; i++){
        if(frase[i] == previous_char)
            frase[i] = new_char;
    }
}

int ricorrenzaChar(char frase[], char letter){
    int count = 0;
    int size = strlen(frase);
    for(int i = 0; i < size; i++){
        if(frase[i] == letter || frase[i] == (letter+32)) //sia maiuscola che minuscola
            count++;
    }

    return count;
}