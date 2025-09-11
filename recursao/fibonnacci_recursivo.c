#include <stdio.h>

int fibonnacci(int n) {
    if (n==1 || n==2) return 1;
    return fibonnacci(n-2) + fibonnacci(n-1);
}

int main() {
    int fib = fibonnacci(100);
    printf(" %d", fib);
}