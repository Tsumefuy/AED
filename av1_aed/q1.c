#include <stdio.h>
#include <string.h>
#include "../bibliotecas/fila.h"
#include <ctype.h>

#define TAM 11

int next_is_priority(tp_fila *f_exp, int num) {
    tp_item next = f_exp->item[f_exp->start+1];

    switch (next) {
        case '*':
            fila_pop(f_exp, &next);
            fila_pop(f_exp, &next);
            num = num * (next - '0');
            return next_is_priority(f_exp, num);
        
        case '/':
            fila_pop(f_exp, &next);
            fila_pop(f_exp, &next);
            num = num / (next - '0');
            return next_is_priority(f_exp, num);
        
        default:
            return num;    
    }
}

int exp_result(char exp[TAM]) {
    tp_fila exp_fila;

    start_fila(&exp_fila);

    for (int i = 0; i < TAM; i++) {
        fila_insert(&exp_fila, exp[i]);
    }

    tp_item e;
    int result = 0, num2;

    while (!empty_fila(&exp_fila)) {
        fila_pop(&exp_fila, &e);
        if (isdigit(e)) {
            result = e - '0';
        } else {
            switch (e) {
            case '+':
                fila_pop(&exp_fila, &e);

                num2 = e - '0';

                result += next_is_priority(&exp_fila, num2);
                
                break;

            case '-':
                fila_pop(&exp_fila, &e);

                num2 = e - '0';

                result -= next_is_priority(&exp_fila, num2);
            
                break;

            case '*':
                fila_pop(&exp_fila, &e);

                num2 = e - '0';

                result *= num2;

                break;

            case '/':
                fila_pop(&exp_fila, &e);

                num2 = e - '0';

                result = result / num2;

                break;
            
            default:
                break;
            }
        }
    }

    return result;
}

int main() {
    char expression[TAM];

    printf("Write a math exp: ");
    scanf(" %s", expression);

    int result = exp_result(expression);

    printf("This math exp is equal to: %d", result);

    return 0;
}