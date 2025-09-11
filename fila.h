#ifndef FILA_H
#define FILA_H
#include <stdio.h>

#define MAX 100

typedef char tp_item;

typedef struct {
    tp_item item[MAX];
    int start, end;
} tp_fila;

void start_fila(tp_fila *f) {
    f->start = f->end = MAX-1;
}

int empty_fila(tp_fila *f) {
    if (f->start == f->end) return 1;
    return 0;
}

int next(int pos) {
    if (pos == MAX-1) return 0;
    return ++pos;
}

int full_fila(tp_fila *f) {
    if (next(f->end) == f->start) return 1;
    return 0;
}

int fila_insert(tp_fila *f, tp_item e) {
    if (full_fila(f)) return 0;
    f->end = next(f->end);
    f->item[f->end] = e;
    return 1;
}

int fila_pop(tp_fila *f, tp_item *e) {
    if (empty_fila(f)) return 0;
    f->start = next(f->start);
    *e = f->item[f->start];
    return 1;
}

int size_fila(tp_fila *f) {
    if (empty_fila(f)) return 0;
    if (f->start < f->end) return f->end - f->start;
    return MAX - f->start + f->end;
}

void print_fila(tp_fila f) {
    tp_item e;
    while (!empty_fila(&f)) {
        fila_pop(&f, &e);
        printf("%c ", e);
    }
}

#endif