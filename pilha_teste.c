#include "pilha.h"

int main() {
	tp_pilha pilha;
	
	start_pilha(&pilha);
	
	int e;
	char ans;
	
	if (empty_pilha(&pilha)) printf("Pilha is empty!\n");
	
	while (ans != 'x') {
		printf("\nWhat do you want to do?\nPush (h)\nPop (p)\nPrint(t)\nExit (x)\n-> ");
		scanf(" %c", &ans);
		
		switch(ans) {
			case 'h':
				printf("Element: ");
				scanf(" %d", &e);
				
				if (push(&pilha, e))
					printf("Sucess! Element add: %d\n", e); 
				else 
					printf("Warning: Pilha is full!");	
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
		}
		
	}
	
	
		
}