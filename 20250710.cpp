#include<iostream>
#include<cstring>
using namespace std;

//PROVA DI ESAME 10072025
//manca la funzione cerca data

struct VERBALE{
	char[16] codice;
	char[11] data_emissione; // aaaa-mm-gg
	char[11] data_appello;
	char[11] data_superamento;
	char[11] insegnamento; //codice di 10 caratteri
	char[51] docente; //nome_docente
	char[8] matricola;
	int voto; // 31 = lode
};

struct NODE{
	VERBALE info;
	NODE *next;
};

NODE *copiaVerbali(NODE *listaIn, char[] insegnamento){
	NODE *listaOut = new NODE;
	while(listaIn != NULL){
		if(strcmp(listaIn->info.insegnamento, insegnamento) == 0){
			if(verifica_date_successive(listaIn->info.data_appello, listaIn->info.data_verbale)){
				if(ins_head(listaOut, listaIn->info) == -1){
					return NULL;
				}
			}
		}
		listaIn = listaIn->next;
	}
	
	return listaOut;
}

void CalcolaConteggi(NODE *lista, char[] *dateEmissione, int[] conteggi, int size){
	NODE *p = lista;
	for(int i = 0; i < size; i++){
		while(p != NULL){
			if(strcmp(lista->info.data_emissione, dateEmissione[i]) == 0){
				conteggi[i]++;
			}
			
			p = p->next;
		}
	}
}

int copia(NODE *lista, char[] *dateEmissione, int[] conteggi, int size, float media_conteggi, NODE *&listaOut){
	NODE *p = lista;
	int pos_data;
	
	while(p != NULL){
		pos_data = cerca_data(p->info.data_emissione, dateEmissione, size);
		if(pos_data > -1){
			if(ins_head(listaOut, p->info) == -1){
				return NULL;
			}
		}
	}
	return 1;
}

float calcolaMedia(int conteggi[], int size){
	int somma = 0;
	for(int i = 0; i < size; i++){
		somma += conteggi[i];
	}
	return (float)somma/size;
}

NODE *CopiaAlcuniVerbali(NODE *lista1, NODE *lista2, char[] *dateEmissione, size){  //prova di luglio
	NODE *listaOut = NULL;
	int[size] conteggi;
	for(int i = 0; i < size; i++){
		conteggi[i] = 0;
	}
	
	CalcolaConteggi(lista1, dateEmissione, conteggi, size);
	CalcolaConteggi(lista2, dateEmissione, conteggi, size);
	float media_conteggi = calcolaMedia(conteggi, size);
	
	if(copia(lista1, dataEmissione, conteggi, size, media_conteggi, listaOut) == -1){
		return NULL;
	}
	
	if(copia(lista2, dataEmissione, conteggi, size, media_conteggi, listaOut) == -1){
		return NULL;
	}
	
	return listaOut;
}

int main(){
	
}
