#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char tp_item;
#define MAX 100

typedef struct {
	int top;
	tp_item item[MAX];
} tp_pilha;

void start_pilha(tp_pilha *p) {
	p->top = -1;
}

int empty_pilha(tp_pilha *p) {
	if (p->top==-1) return 1;
	return 0;
}

int full_pilha(tp_pilha *p) {
	if (p->top==MAX-1) return 1;
	return 0;
}

int push(tp_pilha *p, tp_item e) {
	if (full_pilha(p)) return 0;
	p->top++;
	p->item[p->top] = e;
	return 1;
}

int pop(tp_pilha *p, tp_item *e) {
	if (empty_pilha(p)) return 0;
	*e = p->item[p->top];
	p->top--;
	return 1;
}

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