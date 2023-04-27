#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char identifier[50];
    int isValid = 1;

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        isValid = 0;
    }

    
    for (int i = 1; i < strlen(identifier); i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            isValid = 0;
            break;
        }
    }

    
    if (isValid) {
        printf("%s is a valid identifier.\n", identifier);
    } else {
        printf("%s is not a valid identifier.\n", identifier);
    }

    return 0;
}
