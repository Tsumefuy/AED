#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/pilha.h"

int main() {
    char exp[100];

    tp_pilha p;
    tp_item e;

    int incorrect, tam;
    
    while(scanf(" %s", exp) != EOF) {
        start_pilha(&p);
        incorrect = 0;

        tam = strlen(exp);

        for (int i  = 0; i < tam; i++) {
            if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') 
                push(&p, exp[i]);
            else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
                if (pop(&p, &e)) {
                    switch (exp[i]) {
                        case '(':
                            if (e != ')')
                                incorrect = 1;
                            break;
                        case '[':
                            if (e != ']')
                                incorrect = 1;
                            break;
                        case '{':
                            if (e != '}')
                                incorrect = 1;
                            break;
                        default:
                            break;
                    }
                    
                } else 
                    incorrect = 1;
            }
        }

        if (!empty_pilha(&p) || incorrect) printf("incorrect\n");
        else printf("correct\n");
    }
}   