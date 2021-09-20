#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main()
{
  char userInput[100];
  puts("Welcome!");
  while(1) {
    printf("> ");
    fgets(userInput,100, stdin);
    printf("%s\n", userInput);
  }
  return 0;
}
