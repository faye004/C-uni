/*Istruzioni
Scrivere un programma per gestire un array di numeri interi.

In particolare il problema si occupa di generare un array di 50 numeri casuali compresi fra 1 e 100 e offrire a menu le seguenti scelte:
1. Calcolare la media
2. Visualizzare il massimo
3. Visualizzare il minimo
4. Rigenerare l’array
5. Visualizzare i valori che distano meno di 4 dalla media
6. Calcolare la moda
7. Uscire dal programma

nb. per generare numeri casuali usare vedere http://www.cplusplus.com/reference/cstdlib/srand/ */

#include <iostream>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()
using namespace std;

#define DIM 50

void popolaArrayCasuale(int v[DIM]){
    for(int i = 0; i < DIM; i++){
        v[i] = rand()%100 + 1;
    }
}

double calcolaMedia(int v[DIM]){
    double media = 0.0;
    int somma = 0;

    for(int i = 0; i < DIM; i++){
        somma += v[i];
    }

    media = (double)somma / DIM;
    return media;
}

int findIndexMax1Min0(int v[DIM], bool find = true){ // 1  = true (max), 0 = false (min)
    int extreme = v[0];
    int index = 0;

    if(find == 0) { //cercare il minimo
        for(int i = 1; i< DIM; i++){
            if(v[i] < extreme){
                extreme = v[i];
                index = i;
            }
        }
    } else { //cercare il massimo
        for(int i = 1; i< DIM; i++){
            if(v[i] > extreme){
                extreme = v[i];
                index = i;
            }
        }
    }

    return index;
}

int moda(int v[DIM]){
    int arr[DIM];
    int temp;

    for(int i = 0; i < DIM; i++){
        int temp = 0;
        for(int j = 0; j < DIM; j++){
            if(v[i] == v[j]){
                temp++;
            }
        }
        arr[i] = temp;
    }

    int index = findIndexMax1Min0(arr, true);
    return v[index]; // moda array
}



int main() {
  // Get a different random number each time the program runs
  srand(time(0));
  
  // Generate a random number between 0 and 100
    //   int randomNum = rand() % 101;

    int v[DIM];
    int scelta = 0;
    double media = 0.0;

    popolaArrayCasuale(v); //cosa succede con &v

    // //controllo
    // for(int i = 0; i< DIM; i++){
    //     cout << v[i] << ", ";
    // }

    do{
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "\nMenu delle operazioni:\n";
        cout << "1 - Calcolare la media\n";
        cout << "2 - Visualizzare il massimo\n";
        cout << "3 - Visualizzare il minimo\n";
        cout << "4 - Rigenerare l’array\n";
        cout << "5 - Visualizzare i valori che distano meno di 4 dalla media\n";
        cout << "6 - Calcolare la moda\n";
        cout << "7 - Uscire dal programma\n";
    
        cout << "Scegli un'operazione: ";
        cin >> scelta;

        cout << "\n\n";

        switch(scelta){
            case 1:
            cout << "La media dei valori dell'array e': " << calcolaMedia(v) << endl;
                break;
            case 2:
                cout << "Il valore massimo dell'array e': " << v[findIndexMax1Min0(v, 1)] << endl; // la funzione trova l'indice dell'estremo ricercato (true = massimo, false = minimo)
                break;
            case 3:
                cout << "Il valore minimo dell'array e': " << v[findIndexMax1Min0(v, 0)] << endl;// la funzione trova l'indice dell'estremo ricercato (true = massimo, false = minimo)
                break;
            case 4:
                for(int i = 0; i< DIM; i++){
                    cout << v[i] << "\t";
                }
                cout << "------------------------------------------------------------------------------" << endl;
                popolaArrayCasuale(v);
                cout << "Array rigenerato con successo!" << endl;
                cout << "------------------------------------------------------------------------------" << endl;
                for(int i = 0; i< DIM; i++){
                    cout << v[i] << "\t";
                }
                break;
            case 5:
                media = calcolaMedia(v);
                cout << "I valori che distano meno di 4 dalla media (" << media << ") sono: " << endl;
                for(int i = 0; i < DIM; i++) {
                    if(abs(v[i] - media) < 4) { // ✅ uso abs per gestire anche valori sotto la media
                        cout << v[i] << "\t";
                    }
                }
                cout << endl;
                break;
            case 6: 
                cout << "La moda dell'array e': " << moda(v) << endl;
                break;
            case 7:
                cout << "------------------------------------------------------------------------------" << endl;
                cout << "----------------------------Uscita dal programma.-----------------------------" << endl;
                cout << "------------------------------------------------------------------------------" << endl;
                break;
            default:
                cout << "\t\tOperazione non valida. \n\t\t\tRiprova..." << endl;
                break;
        }
        cout << "------------------------------------------------------------------------------" << endl;

        cout << "\n\n\n\n";

    }while(scelta != 7);
    
  return 0;
}