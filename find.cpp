/*RICERCA DICOTOMICA*/
#include <iostream>
#include<cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define SIZE 10

void stampaArray(int vett[], int size);
int ricerca(int vett[], int size, int v);

int main(){
	srand(time(0));
	int x = 0;
	int arr[SIZE];

	arr[0] = rand()%10 + 1;
	for(int i = 1; i < SIZE; i++){
		arr[i] = rand()%10 + arr[i-1];
	}
	stampaArray(arr, SIZE);

	while(x >= 0){
		cout << "Inserisci un numero: ";
		cin >> x;
	
		cout << endl << "posizione nell'array: " << ricerca(arr, SIZE, x) << endl << endl << endl; 
	}
	
	return 0;
}

void stampaArray(int vett[], int size){
	for(int i = 0; i < size; i++){
		cout << "\t" << vett[i];
	}
	cout << endl;
}

int ricerca(int vett[], int size, int v){
	int p_finale = size, p_iniziale = 0, pos = 0;
	
	while((p_finale-1) != p_iniziale){
		pos = round(((p_finale-1)+p_iniziale)/2);
		
		if(vett[pos] == v){
			return pos;
		}else if(vett[pos] > v){
			p_finale = pos+1;
		}else{
			p_iniziale = pos+1;
		}
	}
	
	if(vett[p_iniziale] == v){
		return p_iniziale;
	}
	return -1;
}
