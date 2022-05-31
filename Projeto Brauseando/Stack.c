
#include "list.h"

#include <stdlib.h>
#include <stdio.h>


typedef struct _stack {
    List *data;
} Stack;



Stack *Stack_create() {
    Stack *S = (Stack*) calloc(1, sizeof(Stack));
    S->data = List_create();

    return S;
}


bool Stack_is_empty(const Stack *S) {
    return List_is_empty(S->data);
}


size_t Stack_size(const Stack *S) {
    return List_size(S->data);
}


void Stack_push(Stack *S, char *site) {
    List_add_last(S->data,site);
}


void Stack_print(const Stack *S) {
    List_print(S->data);
}

void Stack_volta(const Stack *S){
    volta_Stack(S->data);


}

int main (){

    Stack *s = Stack_create();
    Stack_push(s,"www.SeEhLocoCachoera.com");
     Stack_push(s,"www.ehtetra.com.br");
      Stack_push(s,"www.olocobixo.gov.br");
    Stack_push(s,"www.iutchubi.com");
    Stack_print(s);
    Stack_volta(s);
    Stack_print(s);


return 0;
}
