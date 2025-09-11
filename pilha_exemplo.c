#include "bibliotecas/pilha.h"

int main() {
    tp_pilha pilha, pilha2;
    
    int e;
    char ans = '\0';
    
    start_pilha(&pilha);
    start_pilha(&pilha2);

    printf("Pilhas is started!\n");
    
    while (ans != 'x') {
        printf("\nWhat do you want to do?\nPush (h)\nPop (p)\nPrint(t)\nDelete Impar (i)\nExit (x)\n-> ");
        scanf(" %c", &ans);
        
        switch(ans) {
            case 'h':
                printf("Element: ");
                scanf(" %d", &e);
                
                if (push(&pilha, e))
                    printf("Sucess! Element add: %d\n", e); 
                else 
                    printf("Warning: Pilha is full!\n");	
            break;
            
            case 'p':
                if (pop(&pilha, &e))
                    printf("Sucess! Element removed: %d\n", e);
                else 
                    printf("Warning: Pilha is empty!\n");
            break;
            
            case 't':
                print_pilha(pilha);
            break;

            case 'i':
                delete_impar(&pilha);
                printf("Impares removed!\n");
            break;

            case 'e':
                equal(pilha, pilha2);
            break;
        }
        
    }    
}