#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PROD 10
#define MAX_LEN 10

char productions[MAX_PROD][MAX_LEN];
char non_terminal;
int num_productions;

void eliminate_left_recursion() {
    char new_prod[MAX_LEN];
    char alpha[MAX_LEN];
    char beta[MAX_LEN];
    int has_left_recursion = 0;
    int num_new_productions = 0;

    for (int i = 0; i < num_productions; i++) {
        if (productions[i][0] == non_terminal) {
            has_left_recursion = 1;

           
            int j = 1;
            while (productions[i][j] != '\0' && productions[i][j] != '|') {
                alpha[j-1] = productions[i][j];
                j++;
            }
            alpha[j-1] = '\0';
            strcpy(beta, &productions[i][j+1]);

            
            for (int k = 0; k < num_productions; k++) {
                if (productions[k][0] == non_terminal && k != i) {
                    char A[MAX_LEN];
                    strcpy(A, productions[k]);
                    A[strlen(A)-1] = '\0';  

                    sprintf(new_prod, "%s%s'", A+1, beta);
                    strcpy(productions[num_new_productions++], new_prod);

                    sprintf(new_prod, "%s%s'", A+1, alpha);
                    strcpy(productions[num_new_productions++], new_prod);
                }
                else if (productions[k][0] != non_terminal) {
                    sprintf(new_prod, "%s%s'", productions[k], beta);
                    strcpy(productions[num_new_productions++], new_prod);
                }
            }

            
            sprintf(new_prod, "%c%s'", non_terminal, beta);
            strcpy(productions[num_new_productions++], new_prod);

            sprintf(new_prod, "%c%s'", non_terminal, alpha);
            strcpy(productions[num_new_productions++], new_prod);
        }
        else {
            
            strcpy(productions[num_new_productions++], productions[i]);
        }
    }

    num_productions = num_new_productions;

    if (has_left_recursion) {
        printf("\nEliminated left recursion:\n");
        for (int i = 0; i < num_productions; i++) {
            printf("%s\n", productions[i]);
        }
    }
    else {
        printf("\nNo left recursion found.\n");
    }
}

int main() {
    printf("Enter the non-terminal: ");
    scanf("%c", &non_terminal);

    printf("Enter the number of productions: ");
    scanf("%d", &num_productions);

    printf("Enter the productions (use '|' to separate multiple productions):\n");
    for (int i = 0; i < num_productions; i++) {
        scanf("%s", productions[i]);
    }

    printf("\nOriginal grammar:\n");
    for (int i = 0; i < num_productions; i++) {
        printf("%s\n", productions[i]);
    }

    eliminate_left_recursion();

    return 0;
}
