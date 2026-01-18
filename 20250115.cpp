#include<iostream>
#include<cstring>
using namespace std;

//PROVA DI ESAME 15012025 E 10072025

struct VERBALE{
	char[16] codice;
	char[11] data_verbalizzazione; // aaaa-mm-gg
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

int ins_head(NODE *&head, VERBALE verbale){
	NODE *t = new NODE;
	if(t == NULL){
		return -1;
	}
	
	t->info=verbale;
	t->next = head;
	head = t;
	
	return 0;
}


//// NON USATA, INUTILE
//int contaVerbaliConStessoMeseAnnoDataAppello(NODE *verbali, char[] insegnamento, int size){
//	bool isMeseAnnoMatched = true;
//	int conta = 0;
//	
//	for(int j = 0; j < size; j++){
//		if(strcmp(verbali->info.insegnamento, insegnamento)){
//			for(int i = 0; i < 7; i++){
//				if(verbali->info.data_verbalizzazioni[i] != verbali->info.data_appello[i]){
//					isMeseAnnoMatched = false;
//					break;
//				}
//			}
//		}
//	
//		if(isMeseAnnoMatched){
//			conta++;
//		}
//	}
//	
//	return conta;
//}

void CalcolaContatori(NODE *verbali, char[] *insegnamenti, int size, int[] contatori){
	bool isMeseAnnoMatched = true;
	NODE *verbale;
	
	for(int j = 0; j < size; j++){
		contatori[j] = 0; // azzero il contatore prima di incrementarlo
		isMeseAnnoMatched = true;
		verbale = verbali;
		while(verbale != NULL){
			if(strcmp(verbale->info.insegnamento, insegnamenti[j]) == 0){
				for(int i = 0; i < 7; i++){
					if(verbale->info.data_verbalizzazioni[i] != verbale->info.data_appello[i]){
						isMeseAnnoMatched = false;
						break;
					}
				}
				
				if(isMeseAnnoMatched){
					contatori[j]++;
				}
			}
			
			verbale = verbale->next;
		}
	}
}

int estrai_valore(char data[], int start, int len){
	char temp[len+1];
	int i;
	for(i = 0; i < len; i++){
		temp[i] = data[start + i];
	}
	
	temp[i] = '\0';
	return atoi(temp);
}

bool verifica_date(char[] data_appello, char[] data_verbale){
	int anno1, mese1, anno2, mese2;
	anno1 = estrai_valore(data_appello, 0, 4);
	anno2 = estrai_valore(data_appello, 0, 4);
	mese1 = estrai_valore(data_appello, 5, 2);
	mese2 = estrai_valore(data_appello, 5, 2);
	
	if(anno1 == anno2 && mese1 == mese2){
		return true;
	}
	
	return false;
}

bool verifica_date_successive(char[] data_appello, char[] data_verbale){
	int anno1, mese1, anno2, mese2;
	anno1 = estrai_valore(data_appello, 0, 4);
	anno2 = estrai_valore(data_appello, 0, 4);
	mese1 = estrai_valore(data_appello, 5, 2);
	mese2 = estrai_valore(data_appello, 5, 2);
	
	if(anno1 == anno2 && mese1 < mese2){
		return true;
	}
	
	return false;
}

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

int CalcolaMin(int contatori[], int size){
	int min, pos = -1;
	for(int i = 0; i < size; i++){
		if(contatori[i] != 0){
			min = contatori[i];
			break;
		}
	}
	
	if(min == -1)
		return -1;
	
	for(int i = 0; i < size; i++){
		if(min >  contatori[i] && contatori[i] > 0){
			min = contatori[i];
			pos = i;
		}
	}
	
	return pos;
}

NODE *verbaleMeseDiverso(NODE *listaIn, char[] *insegnamenti, int size){
	NODE* listaOut = NULL;
	
	/*
	calcolo il numero di insegnamenti che rispettano le caratteristiche
	trovo l'insegnamento che ha numero min di verbali (>0)
	listaOUt = copio i verbali che rispettano le caratteristiche (<> da quelle di prima)
	return listaOut
	*/
	
	int contatori[size];
	CalcolaContatori(listaIn, insegnamenti, size, contatori);
	int min_pos = CalcolaMin(contatori, size); // torna -1 se errore
	if(min_pos == -1){
		return NULL;
	}
	
	listaOut = copiaVerbali(listaIn, insegnamenti[min_pos]);
	
	return listaOut;
}

int main(){
	
}
