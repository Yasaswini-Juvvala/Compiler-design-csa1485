#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_ALPHABET_SIZE 10

typedef struct {
    int transitions[MAX_ALPHABET_SIZE][MAX_STATES];
    int num_states;
    int start_state;
    int accepting_states[MAX_STATES];
    int num_accepting_states;
} nfa_t;


nfa_t regexp_to_nfa(char *regexp) {

}

int main() {
    char regexp[100];
    printf("Enter a regular expression: ");
    scanf("%s", regexp);

    nfa_t nfa = regexp_to_nfa(regexp);


    return 0;
}

