#include <stdio.h>

#define TAM 16

void start_matrix(int m[][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            m[i][j] = 0;
        }
    }
}

int is_safe(int m[][TAM], int row, int col) {
    // Verifica a linha 
    for (int j = 0; j < col; j++) {
        if (m[row][j] == 1) return 0;
    }

    // Verifica diagonal superior esquerda
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if (m[i][j] == 1) return 0;
    }

    // Verifica diagonal inferior esquerda
    for (int i = row+1, j = col-1; i < TAM && j >= 0; i++, j--) {
        if (m[i][j] == 1) return 0;
    }
    return 1;
}

int backtraking_queens(int m[][TAM], int col) {
    if (col == TAM) return 1;

    for (int row = 0; row < TAM; row++) {
        if (is_safe(m, row, col)) {
            m[row][col] = 1;
            if (backtraking_queens(m, col+1)) return 1;
            m[row][col] = 0;
        }
    }
    return 0;
}

/*

1 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

*/

void print_matrix(int m[][TAM]) {
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[TAM][TAM]; // [LINE][COL]

    start_matrix(matrix);

    backtraking_queens(matrix, 0);
 
    print_matrix(matrix);
}