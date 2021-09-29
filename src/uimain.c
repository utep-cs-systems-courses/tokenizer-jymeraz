#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char user_input[100];
  struct s_List *list = init_history();
  int cont = 1; 
  puts("Welcome!\n");
  while (cont) {
    puts("Input a string to tokenize it of !<num> for a special character, !h for full history, !q for to quit:\n");
    printf("> ");
    fgets(user_input,100, stdin);
    
    if (user_input[0] == '!' && user_input[1] == 'h') {
      print_history(list);
    }
    else if (user_input[0] == '!' && user_input[1] == 'q') {
      cont = 0;
      printf("Thank you, Goodbye :)\n");
    }
    else if (user_input[0] == '!') {
      char *history_val = get_history(list, user_input[1] - '0');
      printf("H[%d] %s\n", user_input[1] - '0', history_val);
    }
    else {
      char **tokens = tokenize(user_input);
      printf("%s\n", tokens[0]);
      print_tokens(tokens);
      add_history(list, user_input);
    }
  }
  free_history(list);
  return 0;
}
