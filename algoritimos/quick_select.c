#include <stdio.h>

#define TAM 5

// Retorna o k-esimo maior número 

int partition(int a[TAM], const int l, const int h) {
    int i = l;
    const int pivot = a[h];

    int maior_que_pivot, menor_que_pivot;

    for (int j = l; j < h; j++) {
        if (a[j] >= pivot) {
            maior_que_pivot = a[j];
            menor_que_pivot = a[i];

            a[i] = maior_que_pivot;
            a[j] = menor_que_pivot;

            i++;
        }
    }

    menor_que_pivot = a[i]; 
    a[i] = pivot;
    a[h] = menor_que_pivot; 

    return i;
}


int quickselect(int a[TAM], const int low, const int high, int k) { 

    int p_index = partition(a, low, high);

    if (p_index > k) return quickselect(a, low, p_index-1, k);
    else if (p_index < k) return quickselect(a, p_index+1, high, k);
    else return a[k];
}

int main() {
    int numbers[TAM], k;

    printf("Digite 10 numeros:");
    for (int i = 0; i < TAM; i++) scanf(" %d", &numbers[i]);

    printf("Digite o k: ");
    scanf(" %d", &k);

    int k_esimo_numero = quickselect(numbers, 0, TAM-1, k-1);
    printf("%d", k_esimo_numero);
    return 0;
}