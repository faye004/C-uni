/*Generare un codice che vada a calcolare il fattoriale di un numero (grazie giulia) intero in maniera ricorsiva*/

#include <iostream>
using namespace std;

int fattoriale(int n);

int main(){
    int numero;

    cout << "Inserisci un numero intero positivo per calcolarne il fattoriale: ";
    cin >> numero;

    if (numero < 0) {
        cout << "Errore: il fattoriale non e' definito per numeri negativi." << endl;
    } else {
        int risultato = fattoriale(numero);
        cout << "Il fattoriale di " << numero << " e': " << risultato << endl;
    }

    return 0;
}

int fattoriale(int n){
    if(n == 1){
        return 1;
    }

    return fattoriale(n-1) * n;
}