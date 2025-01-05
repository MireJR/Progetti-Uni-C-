//Programma che svolge varie operazioni sulle liste
/*
L'utente puo' scegliere tra:
0 - Aggiungi in coda
1 - Aggiungi in testa
2 - Rimuovi il primo elemento
3 - Rimuovi l'ultimo elemento
4 - Rimuovi un elemento a scelta elemento
*/
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void stampaLista(node* list) { //Funzione che prende in input una lista e stampa i suoi elementi, se e' vuota stampa "Lista vuota"
    if(list == NULL){
        cout << "Lista vuota" << endl;
    }
    else {
        cout << "Lista aggiornata: ";
        while(list != NULL) {
            cout << list->data;
            if(list->next != NULL)
                cout << " -> ";
            list = list->next;
        }
    }

    cout << endl;
}

void aggiungiTesta(node* &list, int n) { //Funzione che aggiunge un elemento inserito dall'utente in testa alla lista
    node* temp = new node;
    temp->data = n;
    temp->next = list;
    list = temp;
}

void aggiungiCoda(node* &list, int n) { //Funzione che aggiunge un elemento inserito dall'utente in coda alla lista
    node* new_node = new node;
    new_node->data = n;
    new_node->next = NULL;

    if(list == NULL) {
        list = new_node;
        return;
    }
    else {
        node* temp = list;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
    }
}

void rimuoviTesta(node* &list) { //Funzione che rimuove il primo elemento della lista
    if(list == NULL) {
        cout << "Lista gia' vuota" << endl;
        return;
    }

    else if(list->next == NULL) {
        list = NULL;
        cout << "Lista vuota" << endl;
        return;
    }
    
    else {
        node* new_list = new node;
        new_list = list->next;
        delete list;
        list = new_list;
        stampaLista(list);
    }
}

void rimuoviCoda(node* &list) { //Funzione che rimuove l'ultimo elemento dalla lista
    node* new_list = list;
    node* prev = NULL;

    if(list == NULL) {
        cout << "Lista gia' vuota" << endl;
        return;
    }

    else if(list->next == NULL) {
        list = NULL;
        cout << "Lista vuota" << endl;
        return;
    }

    else {
        while(list->next != NULL) {
            prev = list;
            list = list->next;
        }

        prev->next = NULL;
        list = new_list;
        stampaLista(list);
    }
}

void rimuoviScelta(node* &list, int n){ //Funzione che prende in input un numero dall'utente e rimuove dalla lista tutti gli elementi uguali
    if(list == NULL) {
        cout << "Lista gia' vuota" << endl;
        return;
    }

    else if(list->next == NULL) {
        list = NULL;
        cout << "Lista vuota" << endl;
    }

    else {
        node* temp = list;
        node* prev = NULL;
        while(list != NULL){
            if (list->data == n) {
                if(prev == NULL){
                    temp = list->next;
                    list = list->next;
                    continue;
                }

                list = list->next;
                prev->next = list;
                continue;
            }
            prev = list;
            list = list->next;
        }
        list = temp;
    }

    stampaLista(list);
}

int main() {
    node* n1 = new node;
    n1 = NULL;
    int x, s;
    
    do{ //Menu' principale che chiede all'utente quale operazione svolgere sulla lista
        cout << endl << "Che operazione vuoi svolgere sulla lista?" << endl;
        cout << "0 - Aggiungi in coda" << endl;
        cout << "1 - Aggiungi in testa" << endl;
        cout << "2 - Rimuovi il primo elemento" << endl;
        cout << "3 - Rimuovi l'ultimo elemento" << endl;
        cout << "4 - Rimuovi un elemento a scelta elemento" << endl;
        cout << "5 - Esci" << endl;
        cin >> s;

        if(s < 0 || s > 5) {
            cout << "Numero inserito non valido, riprovare" << endl << endl;
            continue;
        }

        else if(s == 0) {
            cout << "Digita l'elemento che vuoi inserire in coda: ";
            cin >> x;
            aggiungiCoda(n1, x);
            stampaLista(n1);
        }

        else if(s == 1) {
            cout << "Digita l'elemento che vuoi inserire in testa: ";
            cin >> x;
            aggiungiTesta(n1, x);
            stampaLista(n1);
        }

        else if(s == 2) {
            rimuoviTesta(n1);
        }

        else if(s == 3) {
            rimuoviCoda(n1);
        }

        else if(s == 4) {
            cout << "Digita l'elemento che vuoi rimuovere: ";
            cin >> x;
            rimuoviScelta(n1, x);
        }

        else if(s == 5) {
            break;
        }

    }while(true);
    
    stampaLista(n1);

    return 0;
}
