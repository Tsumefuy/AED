#include <stdio.h>

// Retorna o maior número (corrigir depois, está bugado)

int quickselect(int a[10], const int low, const int high, int k) {

    int i = low;
    const int pivot = a[high-1];

    int maior_que_pivot, menor_que_pivot;

    for (int j = low; j < high; j++) { // 13 3 6 12
        if (a[j] <= pivot) {
            menor_que_pivot = a[j];
            maior_que_pivot = a[i];

            a[i] = menor_que_pivot;
            a[j] = maior_que_pivot;

            i++;
        }
    }

    maior_que_pivot = a[i]; // 3 6 13 12

    a[i] = pivot;
    a[high] = maior_que_pivot; // 3 6 12 13

    if (i < 9) return quickselect(a, i + 1, high, k);
    else return a[k+9];
}
int main() {
    int numbers[10];

    printf("Digite 10 numeros:");
    for (int i = 0; i < 10; i++) scanf("%d", &numbers[i]);

    int maior_numero = quickselect(numbers, 0, 10, 0);
    printf("%d", maior_numero);
    return 0;
}