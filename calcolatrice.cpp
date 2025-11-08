/*
Istruzioni
Realizzare un programma che legga tre valori interi (n1, n2, n3) compresi tra 1 e 100, estremi inclusi, e poi presenti a video il seguente menù di operazioni possibili:
A - somma tra n1, n2 e n3

B - prodotto tra n1 e n2
C - sottrazione tra n3 e n1
D - divisione tra n1 e n2 (risultato double). X - uscita dal programma

Legge poi un carattere da tastiera: se il carattere è tra quelli indicati nel menù, si deve eseguire l’operazione richiesta, stampare i numeri utilizzati
nell’operazione e il risultato e poi ripresentare il menù altrimenti il carattere deve essere ignorato e si deve ripresentare solo il menù.

Nel caso il carattere sia X, il programma termina.
Nota: nel caso D è necessaria la conversione di almeno uno dei due operandi.
*/

#include <iostream>
#include <cctype>
using namespace std;

int main(){
    int n1, n2, n3;
    char scelta;

    do{
        cout << "Inserisci il primo numero (1-100): ";
        cin >> n1;
    }while(n1 < 1 || n1 > 100);

    do{
        cout << "Inserisci il secondo numero (1-100): ";
        cin >> n2;
    }while(n2 < 1 || n2 > 100);

    do{
        cout << "Inserisci il terzo numero (1-100): ";
        cin >> n3;
    }while(n3 < 1 || n3 > 100);

    do{
        cout << "\nMenu delle operazioni:\n";
        cout << "A - Somma tra n1, n2 e n3\n";
        cout << "B - Prodotto tra n1 e n2\n";
        cout << "C - Sottrazione tra n3 e n1\n";
        cout << "D - Divisione tra n1 e n2\n";
        cout << "X - Uscita dal programma\n";
        cout << "Scegli un'operazione: ";
        cin >> scelta;

        cout << "\n\n";
        scelta = toupper(scelta);

        switch(scelta){
            case 'A':
                cout << "\tSomma: \n\t " << n1 << " + " << n2 << " + " << n3 << " = " << (n1 + n2 + n3) << endl;
                break;
            case 'B':
                cout << "\tProdotto: \n\t " << n1 << " * " << n2 << " = " << (n1 * n2) << endl;
                break;
            case 'C':
                cout << "\tSottrazione: \n\t " << n3 << " - " << n1 << " = " << (n3 - n1) << endl;
                break;
            case 'D':
                if(n2 != 0){
                    cout << "\tDivisione: \n\t " << n1 << " : " << n2 << " = " << ((float)(n1) / n2) << endl; // da riscrivere da solo
                }else{
                    cout << "\t------------Errore: divisione per zero non permessa.--------------" << endl;
                }
                break;
            case 'X':
                cout << "------------------------------------------------------------------------------" << endl;
                cout << "----------------------------Uscita dal programma.-----------------------------" << endl;
                cout << "------------------------------------------------------------------------------" << endl;
                break;
            default:
                cout << "\t\tOperazione non valida. \n\t\t\tRiprova..." << endl;
        }

        cout << "\n\n";

    }while(scelta != 'X');

    return 0;
}

// soluzione pc (molto divertente)
// int main(){
//     int n1, n2, n3;
//     char scelta;

//     // Input dei tre numeri con validazione
//     do {
//         cout << "Inserisci il primo numero (1-100): ";
//         cin >> n1;
//     } while (n1 < 1 || n1 > 100);

//     do {
//         cout << "Inserisci il secondo numero (1-100): ";
//         cin >> n2;
//     } while (n2 < 1 || n2 > 100);

//     do {
//         cout << "Inserisci il terzo numero (1-100): ";
//         cin >> n3;
//     } while (n3 < 1 || n3 > 100);

//     do {
//         // Presentazione del menu
//         cout << "\nMenu delle operazioni:\n";
//         cout << "A - Somma tra n1, n2 e n3\n";
//         cout << "B - Prodotto tra n1 e n2\n";
//         cout << "C - Sottrazione tra n3 e n1\n";
//         cout << "D - Divisione tra n1 e n2\n";
//         cout << "X - Uscita dal programma\n";
//         cout << "Scegli un'operazione: ";
//         cin >> scelta;

//         switch (scelta) {
//             case 'A':
//             case 'a':
//                 cout << "Somma di " << n1 << ", " << n2 << " e " << n3 << " = " << (n1 + n2 + n3) << endl;
//                 break;
//             case 'B':
//             case 'b':
//                 cout << "Prodotto di " << n1 << " e " << n2 << " = " << (n1 * n2) << endl;
//                 break;
//             case 'C':
//             case 'c':
//                 cout << "Sottrazione di " << n3 << " e " << n1 << " = " << (n3 - n1) << endl;
//                 break;
//             case 'D':
//             case 'd':
//                 if (n2 != 0) {
//                     cout << "Divisione di " << n1 << " per " << n2 << " = " << (static_cast<double>(n1) / n2) << endl;
//                 } else {
//                     cout << "Errore: divisione per zero non permessa." << endl;
//                 }
//                 break;
//             case 'X':
//             case 'x':
//                 cout << "Uscita dal programma." << endl;
//                 break;
//             default:
//                 cout << "Operazione non valida. Riprova." << endl;
//         }
//     } while (scelta != 'X' && scelta != 'x');

//     return 0;
// }