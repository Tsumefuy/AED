#ifndef PILHA_H

#include <stdio.h>

#define PILHA_H
#define MAX 10

typedef int tp_item;

typedef struct {
	int top;
	tp_item item[MAX];
} tp_pilha;

void start_pilha(tp_pilha *p) {
	p->top = -1;
}

int full_pilha(tp_pilha *p) {
	if (p->top==MAX-1) return 1;
	return 0;
}

int empty_pilha(tp_pilha *p) {
	if (p->top==-1) return 1;
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

int top(tp_pilha *p, tp_item*e) {
	if (empty_pilha(p)) return 0;
	*e = p->item[p->top];
	return 1;
}

void print_pilha(tp_pilha p) {
	tp_item e;
	printf("\nElements: ");
	while (!empty_pilha(&p)) {
		pop(&p, &e);
		printf("%d ", e);
	}
	printf("\n");
}

void delete_impar(tp_pilha *p) {
    tp_pilha pilha_par;
    tp_item e;

    start_pilha(&pilha_par);

    while (!empty_pilha(p)) {
        pop(p, &e);

        if (e % 2 == 0)
            push(&pilha_par, e);
    }

    while(!empty_pilha(&pilha_par)) {
        pop(&pilha_par, &e);
        push(p, e);
    }
}

int height(tp_pilha *p) {
    return p->top+1;
}

int equal(tp_pilha p1, tp_pilha p2) {
    tp_item e1, e2;

    if (height(&p1) != height(&p2))
        return 0;

    while(!empty_pilha(&p1)) {
        pop(&p1, &e1);
        pop(&p2, &e2);

        if (e1 != e2) 
            return 0;
    }

    return 1;
}

void concat(tp_pilha *p1, tp_pilha *p2) {
    tp_item e;
    tp_pilha paux;

    while(!empty_pilha(p2)) {
        pop(p2, &e);
        push(&paux, e);
    }

    while(!empty_pilha(&paux)) {
        pop(&paux, &e);
        push(p2, e);
    }
}

#endif