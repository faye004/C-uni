/*
scrivere un programma che verifica se una parola inserita dall'utente è palindroma o meno.
Una parola è palindroma se si legge allo stesso modo sia da sinistra verso destra sia da destra verso sinistra.
Ad esempio, "anna" e "radar" sono parole palindrome, mentre "ciao" non lo è.
*/

#include <iostream>
#include <cstring>
using namespace std;

bool isPalindroma(char parola[]);

int main() {
    
    char parola[80];

    do{
        cout << "Inserisci una parola: ";
    cin.getline(parola, 80, '\n');

    if (isPalindroma(parola)) {
        cout << parola << " e' una parola palindroma." << endl;
    } else {
        cout << parola << " non e' una parola palindroma." << endl;
        break;
    }
    }while(true);

    return 0;
}

bool isPalindroma(char parola[]) {
    int lunghezza = strlen(parola);
    for (int i = 0; i < lunghezza / 2; i++) {
        if (parola[i] != parola[lunghezza - 1 - i]) {
            return false; // Non è palindroma
        }
    }
    return true; // È palindroma
}


























// bool isPalindroma(string parola) {
//     int lunghezza = parola.length();
//     for (int i = 0; i < lunghezza / 2; i++) {
//         if (parola[i] != parola[lunghezza - 1 - i]) {
//             return false; // Non è palindroma
//         }
//     }
//     return true; // È palindroma
// }