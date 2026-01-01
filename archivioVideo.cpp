/*
Scrivere da tastiera che legge il nominativo di un file ed un numero intero che indichi quanti nomitativi leggere
leggere i nominativi nel numero indicato precedentemente
Salvare il nome sul file (file di cui il nome  stato scritto/ricevuto precedentemente) in ordine alfabetico



QUELLO CHE DOBBIAMO FARE è in sostanza, creare un file con un nome, salvarci dei nomi su questo file in ordine alfabetico

salvare i nomi sul file NON è complicato, (basta copiare sulle slide)

IL PROBLEMA è salvarlo in ordine alfabetico
conviene usare una lista di array char

per essere in ordine alfabetico, devi usare il metodo delle liste: inserimento_ordinato

inserimento ordinato

inserimento in :
-LISTA VUOTA: crei un nodo, ci metti il dato, la head = nodo nuovo 

-testa: crei un nodo, ci metti il dato, il next (successivo) di questo nodo è la head iniziale. DOPO QUESTO, il nuovo nodo diventa la nuova head

-coda : crei un nodo, ci metti il dato, scorri la lista finchè non arrivi all'ultimo nodo (della lista), DOPO DI CHE' aggiungi il nuovo nodo




-ordinato: in base all'ordine, tu devi capire se devi usare un:
    -ins-lista vuota
    -ins-testa
    -ins-coda
    -ins tra i nodi
    
*/


#include <fstream>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
 
struct VIDEO {
	char codice[11];
	char titolo[31];
	char regista [31];
	int anno_produzione;
};
 
struct NODE {
	VIDEO dato;
	NODE *next;
};

void carica_da_file(NODE *& head);
void salva_archivio(NODE *head);
void inserisci_video(NODE *&head);
void stampa(NODE *head);
int ins_ordinato(NODE *&head, VIDEO video);
int ins_coda(NODE *&head, VIDEO video);

int main(){
	
}

int ins_oridinato(NODE *&head, VIDEO video){
	 // 1. Creo il nuovo NODE
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
