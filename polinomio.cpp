#include <iostream>
#include <cmath>
using namespace std;

#define DIM  10

int main(){
	int grado;
	float x, y = 0;
	float v[DIM];
	
	do{
		cout << "inserisci il grado del polinomio: " << endl;
		cin >> grado;
	}while(grado <= 0 || grado >= DIM);
	
	
	cout << "inserisci la x del polinomio: " << endl;
	cin >> x;
	
	for(int i = grado; i >= 0; i--){
		cout << "inserisci il coefficiente n. " << i+1 << " del polinomio: "<< endl;
		cin >> v[i];
	}
	
	cout << "\n\n\n\n\n\n";
	cout << "y = ";
	for(int i = grado; i > 0; i--){
		cout << "(" << v[i] << "x^" << (grado-i) << ") + "; 
	}
	cout << "(" << v[0] << ")" << endl;
	cout << "x = " << x << "\n\n";
	
	// y = 3x^2 + 1x^1 + 0x^0
	for(int i= grado; i >= 0; i--){
		y = y + (v[i] * pow(x, i));
		cout << "(" << v[i] << "x^" << (grado-i) << ") + ";
	}
	
	cout << "risultato y = " << y;
	
	return 0;
}