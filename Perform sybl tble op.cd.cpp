#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 100

struct Symbol {
    char name[20];
    int value;
};

struct Symbol symbolTable[MAX_SYMBOLS];
int numSymbols = 0;

int lookupSymbol(char *name) {
    int i;
    for (i = 0; i < numSymbols; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void addSymbol(char *name, int value) {
    if (numSymbols < MAX_SYMBOLS) {
        strcpy(symbolTable[numSymbols].name, name);
        symbolTable[numSymbols].value = value;
        numSymbols++;
    } else {
        printf("Symbol table full!\n");
    }
}

void printSymbolTable() {
    int i;
    printf("Symbol Table:\n");
    printf("-------------\n");
    for (i = 0; i < numSymbols; i++) {
        printf("%s\t%d\n", symbolTable[i].name, symbolTable[i].value);
    }
}

int main() {
    addSymbol("x", 10);
    addSymbol("y", 20);
    addSymbol("z", 30);
    printSymbolTable();
    int index = lookupSymbol("y");
    if (index != -1) {
        printf("Found symbol at index %d\n", index);
    } else {
        printf("Symbol not found!\n");
    }
    return 0;
}
