#include <iostream>
#include <array>
using namespace std;

#define DIM 10

//SBAGLIATO, non puoi dichiarare che una funzione restituisce int[] così. 
//devi usare array<int, DIM> nomefunzione(array<int, DIM> arr, int dim){...}
// CORREGGERE

std::array<int, DIM> popolaArray();
std::array<int, DIM> copiaArray(std::array<int, DIM> arr);
void stampaArray(std::array<int, DIM> arr);
std::array<int, DIM> selectionSort(std::array<int, DIM> arr);
std::array<int, DIM> bubbleSort(std::array<int, DIM> arr);


int main(){
	std::array<int, DIM> v = popolaArray();
	std::array<int, DIM> array_selection_sorted;
	std::array<int, DIM> array_bubble_sorted;

	cout << "stampa array originale : ";
	stampaArray(v);
	cout << "\n\n\n";
	
	array_selection_sorted = selectionSort(v);
	cout << "stampa array ordinato con SELECTION SORT : ";
	stampaArray(array_selection_sorted);
	cout << "\n\n\n";
	
	
	array_bubble_sorted = bubbleSort(v);
	cout << "stampa array ordinato con BUBBLE SORT : ";
	stampaArray(array_bubble_sorted);
	cout << "\n\n\n";

	cout << "Array originale per confronto: ";
	for(int i = 0; i < DIM; i++){
		cout << v[i] << ", ";
	}

	cout << "\n\n\n\n\n\n";

	return 0;
	
}


// FUNZIONI
/*Premessa, alcune funzioni potrebbero essere anche messe void, ma per esercizio ho deciso di restituire int[]*/

std::array<int, DIM> popolaArray(){
	std::array<int, DIM> array;
	
	cout << "\n\n\n";
	for(int i=0; i < DIM; i++){
		cout << "Inserisci il " << (i+1) << "o numero nell'array: " << endl;
		cin >> array[i];
	}
	cout << "\n\n\n";
	
	return array;
}

void stampaArray(std::array<int, DIM> array){
	cout << "\n\n\n";
	for(int i=0; i < DIM; i++){
		cout << "\t" << array[i];
	}
	cout << "\n\n\n";
}

std::array<int, DIM> copiaArray(array<int, DIM> arr){
	std::array<int, DIM> new_array;
	
	for(int i = 0; i < arr.size(); i++){
		new_array[i] = arr[i];
	}
	
	return new_array;
}

std::array<int, DIM> selectionSort(std::array<int, DIM> arr){
	std::array<int, DIM> v = copiaArray(arr);
	int temp = 0, index_min;
	
	for(int i = 0; i < (arr.size()-1); i++){
		index_min = i;
		for(int j = (i+1); j < arr.size(); j++){
			if(v[index_min] > v[j]){
				index_min = j;
			}
		}
		if(i != index_min){
			temp = v[i];
			v[i] = v[index_min];
			v[index_min] = temp;
		}
	}
	
	return v;
}

array<int, DIM> bubbleSort(array<int, DIM> array){ 			//soluzione mia più veloce e pulita
	int last = array.size(), temp = 0;
	std::array<int, DIM> v = copiaArray(array);
	bool sorted;
	
	do{
		sorted = true;
		for(int i = 0; i < (last-1); i++){
			if(v[i] > v[i+1]){
				temp = v[i+1];
				v[i+1] = v[i];
				v[i] = temp;
				sorted = false;
			}
		}
		last--;
	}while(sorted == false);
	
	return v;
}

// bubble sort soluzione del prof
//	for(int j = 0; j < DIM; j++){
//		for(int i = 0; i < (DIM-j); i++){
//			if(v[i] > v[i+1]){
//				temp = v[i+1];
//				v[i+1] = v[i];
//				v[i] = temp;
//			}
//		}
//	}
