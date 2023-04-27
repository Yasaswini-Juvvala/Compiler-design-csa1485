#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 100
#define MAX_SYMBOLS 100

typedef struct {
    char name;
    int count;
    char symbols[MAX_SYMBOLS];
} rule;

rule rules[MAX_RULES];
int num_rules = 0;

int is_non_terminal(char c) {
    return isupper(c);
}

int is_terminal(char c) {
    return islower(c) || c == '$' || c == '\0';
}

void add_symbol_to_rule(char name, char symbol) {
    int i;
    for (i = 0; i < num_rules; i++) {
        if (rules[i].name == name) {
            rules[i].symbols[rules[i].count++] = symbol;
            return;
        }
    }
    rules[num_rules].name = name;
    rules[num_rules].count = 1;
    rules[num_rules].symbols[0] = symbol;
    num_rules++;
}

void print_first_set(char symbol) {
    int i, j, k;
    char first_set[MAX_SYMBOLS];
    int first_set_size = 0;
    for (i = 0; i < num_rules; i++) {
        if (rules[i].name == symbol) {
            for (j = 0; j < rules[i].count; j++) {
                if (is_terminal(rules[i].symbols[j])) {
                    first_set[first_set_size++] = rules[i].symbols[j];
                } else {
                    for (k = 0; k < num_rules; k++) {
                        if (rules[k].name == rules[i].symbols[j]) {
                            print_first_set(rules[k].name);
                            int l;
                            for (l = 0; l < rules[k].count; l++) {
                                if (rules[k].symbols[l] != 'e') {
                                    first_set[first_set_size++] = rules[k].symbols[l];
                                }
                            }
                            break;
                        }
                    }
                }
            }
            break;
        }
    }
    printf("FIRST(%c) = { ", symbol);
    for (i = 0; i < first_set_size; i++) {
        printf("%c ", first_set[i]);
    }
    printf("}\n");
}

int main() {
    int i, j;
    char input[100];
    printf("Enter grammar rules (enter 'q' to quit):\n");
    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        if (input[0] == 'q') {
            break;
        }
        char name = input[0];
        for (i = 3; i < strlen(input); i++) {
            if (input[i] == '|') {
                i++;
            }
            if (is_non_terminal(input[i])) {
                add_symbol_to_rule(name, input[i]);
            } else if (is_terminal(input[i])) {
                add_symbol_to_rule(name, input[i]);
                break;
            } else if (input[i] == 'e') {
                add_symbol_to_rule(name, 'e');
                break;
            }
        }
    }
    for (i = 0; i < num_rules; i++) {
        print_first_set(rules[i].name);
    }
    return 0;
}
