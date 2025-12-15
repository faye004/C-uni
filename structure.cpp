#include <iostream>
#include <cmath>
using namespace std;

struct PUNTO{
    int x = 0;
    int y = 0;
    };

void disegnaGrafico(PUNTO funzione[], int dim);
double distanzaPunti(PUNTO *a, PUNTO b){
    double d;
    d = sqrt(pow(((double)(b.y - (*a).y)), 2) + pow(((double)(b.x - (*a).x)), 2));
    return d;
}

int main(){

    PUNTO a;
    PUNTO b;

    cout << "Inserisci le coordinate del primo PUNTO (x1, y1): ";
    cin >> a.x >> a.y;

    cout << "Inserisci le coordinate del secondo PUNTO (x2, y2): ";
    cin >> b.x >> b.y;

    PUNTO *pa = &a;
    PUNTO *pb = &b;

    double distanza = distanzaPunti(pa, *pb);

    cout << "La distanza tra i due punti e': " << distanza << endl;


    //funzione
    // y = mx + q = 2x   I = [0, 99]
    // int m, q;
    // cout << "y = mx + q \n inserisci la m e la q: (F: I -> [0, 100])" << endl;
    // cin >> m >> q;
    // PUNTO funzione[101];
    // for (int i = 0; i <= 100; i++) {
    //     funzione[i].x = i;
    //     funzione[i].y = (m * i) + q;
    // }
    // disegnaGrafico(funzione, 100);
}

void disegnaGrafico(PUNTO funzione[], int dim){ //non efficiente, ma semplice
    cout << "Grafico della funzione: " << endl;
    for (int i = dim-1; i > 0; i--) {
        for(int j = 0; j < funzione[i].x; j++) {
            cout << " ";
        }
        cout << "*"; // PUNTO della funzione
        for(int j = 0; j < (funzione[i].y-funzione[i-1].y); j++) {
           cout << endl;;
        }
    }

    for(int j = 0; j < funzione[0].x; j++) {
        cout << " ";
    }
    cout << "*"; // PUNTO della funzione
    cout << endl;
}