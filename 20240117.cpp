#include <iostream>
#include <cstring>
using namespace std;

struct PRENOTAZIONE {
    char codice[11];
    char data_emissione[11]; // aaaa-mm-gg
    char data_inizio[11];
    int giorni;
    char codice_albergo[11];
    int numero_camera;
    float prezzo;
    int stato; // 1 indica che la prenotazione è attiva, 2 indica che il soggiorno è avvenuto, 3 indica che la prenotazione è stata annullata
};

struct NODE{
    PRENOTAZIONE data;
    NODE *next;
};

int ins_testa(NODE *&head, PRENOTAZIONE prenotazione){
    NODE *t = new NODE;
    if(t == NULL){
        return -1;
    }

    t->data = prenotazione;
    t->next = head;
    head = t;
    
    return 0;
}

int contaPrenotazioniALbergo(NODE *lista, char albergo[]){
    NODE *p = lista;
    int conta = 0;
    while(p != NULL){
        if(strcmp(p->data.codice_albergo, albergo) == 0){
            conta++;
        }
        p = p->next;
    }

    return conta;
}

int CercaAlbergoAffollato(NODE *&listaIn, char dataSoggiorno[], char *alberghi[], int size, int contatori[]){
    int pos = -1;
    int max = 0;
    for(int i = 0; i < size; i++){
        contatori[i] = contaPrenotazioniALbergo(listaIn, alberghi[i]);
    }

    for(int i = 0; i < size; i++){
        if(contatori[i] > max){
            pos = i;
            max = contatori[max];
        }
    }

    return pos;
}

NODE* PrenotazioniAlbergoDopoDataSoggiorno(NODE *listaIn, char albergo[], char dataSoggiorno[], int size){
    NODE *listaOut = NULL;
    NODE *p = listaIn;

    while(p != NULL){
        if(strcmp(p->data.codice_albergo, albergo) == 0){
            if(strcmp(p->data.data_inizio, dataSoggiorno) >= 0)
                if(ins_testa(listaOut, p->data) == -1){
                    return NULL;
                }
        }
        p = p->next;
    }

    return listaOut;

}

NODE *PrenotazioneAlbergoAffollato(NODE *&listaIn, char dataSoggiorno[], char *alberghi[], int size){
    NODE *listaOut = NULL;
    int contatori[size];
    for(int i = 0; i < size; i++){
        contatori[i] = 0;
    }

    // trovare l'albergo con il maggior numero di prenotazioni possibili dalla data dataSOGGIORNO
    int pos_albergo = CercaAlbergoAffollato(listaIn, dataSoggiorno, alberghi, size, contatori);
    
    //inserire tutte le prenotazioni di questo albergo (che iniziano da data soggiorno) nella lista listaOut
    if(pos_albergo != -1){
        listaOut = PrenotazioniAlbergoDopoDataSoggiorno(listaIn, alberghi[pos_albergo], dataSoggiorno, size);
    }
    return listaOut;
}

int main(){

}
