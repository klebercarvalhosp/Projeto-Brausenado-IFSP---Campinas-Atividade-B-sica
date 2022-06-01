
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

typedef struct _doubly_node {
    char site [50];
    char comparador[50];
    struct _doubly_node *prev;
    struct _doubly_node *next;
} DoublyNode, Node;

typedef struct _doubly_linked_list {
    Node *begin;
    Node *end;
    size_t size;
    int apontador;
} DoublyLinkedList, List;


Node *Node_create(char *site) {
    Node *node = (Node*) calloc(1, sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    strcpy(node->site , site);

    return node;
}

List *List_create() {
    List *L = (List*) calloc(1, sizeof(List));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;
    L->apontador = 0;

    return L;
}


bool List_is_empty(const List *L) {
    return L->size == 0;
}


size_t List_size(const List *L) {
    return L->size;
}


void List_add_last(List *L, char *site) {
    Node *p = Node_create(site);
    p->prev = L->end;

    if (List_is_empty(L)) {
        L->begin = p;
    }
    else {
        L->end->next = p;
    }

    L->end = p;
    L->size++;
    L->apontador++;


}



void List_print(const List *L) {
    Node *p = L->begin;
    // enquanto p não chegou ao fim da lista, isto é,
    // enquanto p estiver apontando para um nó da lista
    int compara = L->size-1;

    for (int i=0;i < compara ;i++) {
            //printf("ENTROU AQUI");
        printf("%s \n", p->site);
        if (strcmp(p->site,"www.ehtetra.com.br")==0){
            printf("-->");

        }

        p = p->next;
    }

    if (L->end == NULL) {
        printf("-> NULL\n");
    }

    else {
        //puts("");
        printf(L->end->site);
    }

   // printf("Size: %d\n", L->size);
    puts("");
}


void volta_Stack(List *L){

    Node *p = L->begin;
    L->apontador--;

    //printf("resoltado %d", L->apontador);

    for(int i=1;i < L->apontador-1;i++){
        p = p->next;

    }
        L->end = p;

}
