/*
Creare un codice capace di trovare i numeri equilibrati conpresi in un intervallo [a,b] inserito dall'utente. Un numero e' detto equilibrato se la somma delle cifre pari e' uguale alla somma delle cifre dispari.
Ad esempio, 1210 e' un numero equilibrato in quanto (1+1) = (2+0), mentre 1230 non lo e' in quanto (1+3) != (2+0).
*/

#include <iostream>
using namespace std;

bool isNumeroEquilibrato(int n);

int main() {
    int a, b, count = 0;

    cout << "Inserisci l'intervallo [a,b]: " << endl;
    cin >> a;
    cin >> b;

    cout << "Numeri equilibrati nell'intervallo [" << a << ", " << b << "]: ";
    for(int i = a; i <= b; i++){
        if(isNumeroEquilibrato(i)){
            cout << i << "  ";
            count++;
        }
    }

    cout << endl << endl;

    if( count ){
        cout << endl << "Totale numeri equilibrati trovati: " << count << endl;
    } else {
        cout << "Nessun numero equilibrato trovato nell'intervallo specificato.[" << a << ", " << b << "]..." << endl;
    }
}

// le cifre di n si possono esprimere come:
// 3456 = 3 * 1000 + 4 * 100 + 5 * 10 + 6 * 1
// dove ogni cifra e' moltiplicata per la sua posizione (1, 10, 100, 1000, ...)
// trovo la posizione piu' alta, e poi scendo di posizione in posizione, trovando ogni cifra


bool isNumeroEquilibrato(int n){
    if(n == 0){ // caso particolare
        return true; // il numero 0 e' equilibrato
    }

    bool founded = false;

    int sommaPari = 0, sommaDispari = 0, posizione = 1, cifra;

    // trovo la posizione piu' alta
    do{
        posizione *= 10;
    }while((float)(n / posizione) >= 1); // se n / posizione < 1, allora la posizione esatta e' la precedente (operazione eseguita nel do while successivo)

    do{ // mi trovo tutte le cifre, partendo da quella piu' alta
        posizione /= 10; // scendo di una posizione (dalla prima all'ultima)

        // calcolo la cifra in posizione
        cifra = 0;
        do{
            cifra++;
        }while((float)(n / (cifra * posizione)) >= 1);
        cifra--;  // riporto la cifra corretta

        if(cifra % 2){
            // cifra dispari
            sommaDispari += cifra;
        } else {
            // cifra pari
            sommaPari += cifra;
        }

        n = n - (cifra * posizione); // rimuovo la cifra trovata da n
    }while(posizione != 1); // ripeto finche' non arrivo all'ultima cifra

    if(sommaPari == sommaDispari){
        founded = true;
    }

    return founded;
}
