/*RICERCA DICOTOMICA*/
#include <iostream>
#include<cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define SIZE 10

void stampaArray(int vett[], int size);
int ricerca(int vett[], int size, int v); // find
int find(int vett[], int size, int v); // find ricorsivo
int trova(int vett[], int size, int v){
	// if(size%2 == 1){
	// 	size++;
	// }

	int meta = (size/2);
	if(vett[meta] == v)
		return meta;
	
	if(meta <= 0){
		if(vett[0] != v || size < 0)
			return -1;
		return 0;
	}

	if(vett[meta] > v)
		return trova(vett, meta, v);
	
	int result = trova(&vett[meta], meta, v);
	if(result < 0)
		return result;
	return result + meta;

}

int main(){
	srand(time(0));
	int x = 0;
	int arr[SIZE];

	arr[0] = rand()%10 + 1;
	for(int i = 1; i < SIZE; i++){
		arr[i] = rand()%10 + arr[i-1] + 1;
	}

	while(x >= 0){
		stampaArray(arr, SIZE);
		cout << "Inserisci un numero: ";
		cin >> x;
	
		cout << endl << "posizione nell'array con metodo ricerca: " << ricerca(arr, SIZE, x) << endl; 
		cout << "posizione nell'array con metodo find (ricorsivo): " << trova(arr, SIZE, x) << endl << endl; 
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

int find(int vett[], int size, int v){
	int pos = round((size-1)/2), result = 0, increment = 0;
	int *pos_iniziale;
		// while((p_finale-1) != p_iniziale){
	if(vett[pos] == v){ // posizione trovata
		return pos;
	}else{
		if(pos == 0 || pos == size){ // il numero v non si trova all'interno dell'array, fine ricerca
			return -1;
		}

		if(vett[pos] > v){
			pos_iniziale = vett;	// pos_finale = pos+1;
		}else{
			pos_iniziale = &vett[pos+1];		// pos_iniziale = pos+1;
			increment += pos + 1;
		}
	}

	result = find(pos_iniziale, pos, v);
	if(result < 0){
		return -1;
	}

	return (increment + result);
}
