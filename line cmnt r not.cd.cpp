#include <stdio.h>
#include <string.h>

int main() {
  char line[100];
  printf("Enter a line: ");
  fgets(line, sizeof(line), stdin); 
  
  if (line[0] == '/') {
    if (line[1] == '/') {
      printf("The line is a single-line comment\n");
    } else if (line[1] == '*') {
      printf("The line is a multi-line comment\n");
    } else {
      printf("The line is not a comment\n");
    }
  } else {
    printf("The line is not a comment\n");
  }

  return 0;
}
