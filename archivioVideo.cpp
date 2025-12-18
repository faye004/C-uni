#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
 
struct VIDEO {
	char codice[11];
	char titolo[31];
	char regista [31];
	int anno_produzione;
};
 
struct NODO {
	VIDEO info;
	NODO *next;
};

void carica_da_file(NODO *& head);
void salva_archivio(NODO *head);
void inserisci_video(NODO *&head);
void stampa(NODO *head);
int ins_ordinato(NODO *&head, VIDEO video);
int ins_coda(NODO *&head, VIDEO video);

int main(){
	
}

int ins_oridinato(NODO *&head, VIDEO video){
	 // 1. Creo il nuovo nodo
    NODE* new_node = new NODE;
    if(new_node == NULL){
        cout << "Spazio in memoria esaurito" << endl;
        return 0;
    }
    new_node->dato = video;

    // 2. Lista vuota o inserimento in testa
    if (head == NULL || strcmp(video.codice, head->dato.codice) < 0) {
        new_node->next = head;
        head = new_node;
        return 1;
    }

    // 3. Cerco la posizione corretta
    NODE *p = head;
    int size = strlen(video.codice);
    
    while (p->next != NULL || strcmp(video.codice, p->next->dato.codice) < 0) {
        p = p->next;
    }
    
//    while (p->next != NULL && p->next->dato.codice < video.codice) {
//        p = p->next;
//    }

    // 4. Inserimento tra p e p->next (o in coda)
    new_node->next = p->next;
    p->next = new_node;
    return 1;
}
