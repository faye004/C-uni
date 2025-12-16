/*Istruzioni
Si scriva un programma C che legga due serie di dati e li memorizzi in due vettori di strutture. Nel primo vettore M (di dimensione TOT_STUDENTI) vengono memorizzati dati del tipo:
<matricola, nome, cognome>. Si noti che la matricola identifica univocamente uno studente e che non ci sono due strutture che contengono lo stesso numero di matricola.

Nel secondo vettore V (di dimensione TOT_ESAMI) vengono memorizzati dati del tipo: <matricola, esame, voto>. Possono esserci più record con lo stesso numero di matricola che denotano
diversi esami fatti dallo stesso studente.

Si scriva un programma che tramite opportune procedure legga i dati in ingresso e li inserisca nei due vettori. Successivamente per ogni studente con matricola
X contenuto nel vettore M sommi tutti i suoi voti ottenuti negli esami contenuti nel vettore V.
*/

#include<iostream>
#include<cstring>

using namespace std;

#define TOT_STUDENTI 3
#define TOT_ESAMI 7

#define DIM_ESAMI 30
#define DIM_NOMI 20


struct STUDENTE{
	int matricola;
	char nome[DIM_NOMI];
	char cognome[DIM_NOMI];
};

struct ESAME{
	int matricola;
	char nome_esame[DIM_ESAMI];
	int voto;
};

void chiediStudenti(STUDENTE studenti[], int size);
void chiediEsami(ESAME esami[], int size);

int main(){
	STUDENTE studenti[TOT_STUDENTI];
	ESAME esami[TOT_ESAMI];
	int somma_voti;

	chiediStudenti(studenti, TOT_STUDENTI);
	cout << "Ora si chiederanno i voti degli studenti appartenenti a questo corso" << endl << endl;
	chiediEsami(esami, TOT_ESAMI);
	cout << endl << endl;

	//Somma dei voti
	for(int i = 0; i < TOT_STUDENTI; i++){
		cout << endl << endl;
		somma_voti = 0;
		for(int j = 0; j < TOT_ESAMI; j++){
			if(studenti[i].matricola == esami[j].matricola){
				somma_voti = somma_voti + esami[j].voto;
			}
		}
		cout << "Somma dei voti dello studente di nome-> " << studenti[i].nome << ", cognome-> " << studenti[i].cognome << ", matricola -> " << studenti[i].matricola << " = " << somma_voti << endl << endl;
	}

	return 0;
}

void chiediStudenti(STUDENTE studenti[], int size){
	bool new_matricola;
	for(int i = 0; i < size; i++){
		do{
			new_matricola = true;
			cout << "Inserisci la matricola del " << (i+1) << " studente: ";
			cin >> studenti[i].matricola;
			for(int j = 0; j < i; j++){
				if(studenti[i].matricola == studenti[j].matricola){
					new_matricola = false;
					cout << endl << "\tERRORRE, matricola già presente (" << studenti[j].nome << " " << studenti[j].cognome << ") ... RIPROVA" << endl;
				}
			}
		}while(!new_matricola);
		cin.ignore();
		
		cout << "Inserisci il nome del " << (i+1) << " studente: ";
		cin.getline(studenti[i].nome, DIM_NOMI);
		
		cout << "Inserisci il cognome del " << (i+1) << " studente: ";
		cin.getline(studenti[i].cognome, DIM_NOMI);
	}

	cout << endl << endl;
}

void chiediEsami(ESAME esami[], int size){
	for(int i = 0; i < size; i++){
		cout << "Inserisci la matricola dello studente: ";
		cin >> esami[i].matricola;
		cin.ignore();
		
		cout << "Inserisci l'esame di questo studente (" << (i+1) << " esame segnato nell'array): ";
		cin.getline(esami[i].nome_esame, DIM_ESAMI);
		
		cout << "Inserisci il voto dello studente: ";
		cin >> esami[i].voto;
	}
	cout << endl << endl;
}
