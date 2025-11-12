#include <iostream>
using namespace std;

struct punto{
    int x = 0;
    int y = 0;
    };

void disegnaGrafico(punto funzione[], int dim);

int main(){

    punto a;
    punto b;

    cout << "Inserisci le coordinate del primo punto (x1, y1): ";
    cin >> a.x >> a.y;

    cout << "Inserisci le coordinate del secondo punto (x2, y2): ";
    cin >> b.x >> b.y;

    int dx = b.x - a.x;
    int dy = b.y - a.y;

    double distanza = (float)(b.y - a.y) / (float)(b.x - a.x);

    cout << "La distanza tra i due punti e': " << distanza << endl;


    //funzione
    // y = mx + q = 2x   I = [0, 99]
    punto funzione[100];
    for (int i = 0; i < 100; i++) {
        funzione[i].x = i;
        funzione[i].y = 2 * i;
    }

    disegnaGrafico(funzione, 100);
}

void disegnaGrafico(punto funzione[], int dim){ //non efficiente, ma semplice
    cout << "Grafico della funzione: " << endl;
    for (int i = dim-1; i > 0; i--) {
        for(int j = 0; j < funzione[i].x; j++) {
            cout << " ";
        }
        cout << "*"; // punto della funzione
        for(int j = 0; j < (funzione[i].y-funzione[i-1].y); j++) {
           cout << endl;;
        }
    }

    for(int j = 0; j < funzione[0].x; j++) {
        cout << " ";
    }
    cout << "*"; // punto della funzione
    cout << endl;
}