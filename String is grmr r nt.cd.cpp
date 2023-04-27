
  #include <stdio.h>
#include <string.h>

#define STACK_SIZE 100

char stack[STACK_SIZE];
int top = 0;

void push(char c) {
    if (top < STACK_SIZE) {
        stack[top++] = c;
    }
}

char pop() {
    if (top > 0) {
        return stack[--top];
    }
    return '\0';
}

int main() {
    char input[STACK_SIZE];
    int i;

    printf("Enter a string: ");
    scanf("%s", input);


    push('S');


    for (i = 0; i < strlen(input); i++) {
        char current = input[i];


        char top_symbol = pop();

        if (top_symbol == 'S') {
           
            if (current == 'a') {
                push('b');
                push('S');
                push('a');
            } else {
                push(top_symbol);
            }
        } else if (top_symbol == 'a') {
            
            if (current != 'a') {
                printf("Error: Unexpected symbol '%c'\n", current);
                return 1;
            }
        } else if (top_symbol == 'b') {

            if (current != 'b') {
                printf("Error: Unexpected symbol '%c'\n", current);
                return 1;
            }
        } else {
            
            printf("Error: Invalid symbol '%c'\n", top_symbol);
            return 1;
        }
    }


    if (pop() != '\0') {
        printf("Error: Stack not empty\n");
        return 1;
    }

    printf("Input string is valid\n");

    return 0;
}
