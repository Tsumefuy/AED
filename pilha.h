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
	printf("\n");
	while (!empty_pilha(&p)) {
		pop(&p, &e);
		printf("%d ", e);
	}
	printf("\n");
}
#endif