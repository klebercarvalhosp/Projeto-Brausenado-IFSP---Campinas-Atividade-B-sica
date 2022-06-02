#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>


typedef struct _doubly_node {
  char site[100];

  struct _doubly_node * prev;
  struct _doubly_node * next;
}
DoublyNode, Node;

typedef struct _doubly_linked_list {
  Node * begin;
  Node * end;
  size_t size;
  char comparador[100];
  int apontador;
}
DoublyLinkedList, List;

Node * Node_create(char * site) {
  Node * node = (Node * ) calloc(1, sizeof(Node));
  node -> prev = NULL;
  node -> next = NULL;
  strcpy(node -> site, site);

  return node;
}

List * List_create() {
  List * L = (List * ) calloc(1, sizeof(List));
  L -> begin = NULL;
  L -> end = NULL;
  L -> size = 0;
  L -> apontador = 0;

  return L;
}

bool List_is_empty(const List * L) {
  return L -> size == 0;
}

size_t List_size(const List * L) {
  return L -> size;
}

void List_add_last(List * L, char * site) {
  Node * p = Node_create(site);
  p -> prev = L -> end;

  Node * anterior = L -> begin;

  if (L -> apontador < L -> size) {
    for (int i = 1; i <= L -> apontador - 1; i++) {

      anterior = anterior -> next;

    }
    anterior -> next = p;

  } else if (List_is_empty(L)) {
    L -> begin = p;
  } else {
    L -> end -> next = p;
  }
  strcpy(L -> comparador, p -> site);

  L -> size = L -> apontador;
  L -> end = p;
  L -> size++;
  L -> apontador++;

}

void List_print(const List * L) {
//printf("%d",L->size);
if(L->size!=0){
  Node * p = L -> begin;

  int compara = L -> size;

  for (int i = 0; i < compara; i++) {

    if (strcmp(p -> site, L -> comparador) == 0) {

      printf("--> ");
    }

    printf("%s\n", p -> site);

    p = p -> next;

        }
    }
}

void volta_Stack(List * L) {

  if (L -> apontador >= 1) {

    Node * p = L -> begin;

    L -> apontador--;
    if (L -> apontador == 0) {
      L -> apontador++;
    }

    if (L -> apontador == 1) {

      strcpy(L -> comparador, L -> begin -> site);
    } else {
      for (int i = 1; i < L -> apontador; i++) {
        p = p -> next;

        strcpy(L -> comparador, p -> site);
      }
    }

  }

}

void avanca_Stack(List * L) {

  if (L -> apontador != 0) {
    Node * p = L -> begin;
    L -> apontador++;
    if (L -> apontador > L -> size) {
      L -> apontador--;
    }

    if (L -> apontador == L -> size) {

      strcpy(L -> comparador, L -> end -> site);
    } else {
      for (int i = 1; i < L -> apontador; i++) {
        p = p -> next;
        strcpy(L -> comparador, p -> site);

      }
    }

  }
}

typedef struct _stack {
  List * data;
}
Stack;

Stack * Stack_create() {
  Stack * S = (Stack * ) calloc(1, sizeof(Stack));
  S -> data = List_create();

  return S;
}

bool Stack_is_empty(const Stack * S) {
  return List_is_empty(S -> data);
}

size_t Stack_size(const Stack * S) {
  return List_size(S -> data);
}

void acessa(Stack * S, char * site) {
  List_add_last(S -> data, site);
}

void imprime(const Stack * S) {
  List_print(S -> data);

}

void volta(const Stack * S) {
  volta_Stack(S -> data);
}
void avanca(const Stack * S) {
  avanca_Stack(S -> data);
}

int main() {

  Stack * s = Stack_create();

  char cmd[12];

  scanf("%s", cmd);

  while (strcmp(cmd, "encerra") != 0) {
    if (strcmp(cmd, "acessa") == 0) {

      char site[100];
      scanf("%s", site);
      acessa(s, site);

    } else if (strcmp(cmd, "avanca") == 0) {

      avanca(s);
    } else if (strcmp(cmd, "volta") == 0) {

      volta(s);

    } else if (strcmp(cmd, "imprime") == 0) {
      imprime(s);
    puts("");
    }
    scanf("%s", cmd);
  }

  return 0;
}
