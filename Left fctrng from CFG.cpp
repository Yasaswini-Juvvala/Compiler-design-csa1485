#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROD 100 
#define MAX_LEN 100 

char productions[MAX_PROD][MAX_LEN]; 
int num_productions; 

void eliminate_left_factoring() {
    int i, j, k, len;
    char common_prefix[MAX_LEN];
    int prefix_len;
    int num_new_productions = 0;
    char new_productions[MAX_PROD][MAX_LEN];

    for (i = 0; i < num_productions; i++) {
        len = strlen(productions[i]);
        for (j = i + 1; j < num_productions; j++) {
            prefix_len = 0;
            while (productions[i][prefix_len] == productions[j][prefix_len] && prefix_len < len) {
                prefix_len++;
            }
            if (prefix_len > 0) {
                
                strncpy(common_prefix, productions[i], prefix_len);
                common_prefix[prefix_len] = '\0';

                
                char new_symbol[2] = {'A' + num_new_productions, '\0'};
                num_new_productions++;

                
                snprintf(new_productions[num_productions], MAX_LEN, "%s%s", common_prefix, new_symbol);

                
                memmove(productions[i], productions[i] + prefix_len, len - prefix_len + 1);
                memmove(productions[j], productions[j] + prefix_len, len - prefix_len + 1);

                
                snprintf(new_productions[num_productions + 1], MAX_LEN, "%s%s", productions[i], new_symbol);

                
                snprintf(new_productions[num_productions + 2], MAX_LEN, "%s%s", productions[j], new_symbol);

                num_productions += 3;
                i--;
                break;
            }
        }
    }

    
    printf("New set of productions:\n");
    for (i = 0; i < num_productions; i++) {
        printf("%s\n", productions[i]);
    }
}

int main() {
    int i;

    printf("Enter the number of productions: ");
    scanf("%d", &num_productions);

    printf("Enter the productions:\n");
    for (i = 0; i < num_productions; i++) {
        scanf("%s", productions[i]);
    }

    eliminate_left_factoring();

    return 0;
}
