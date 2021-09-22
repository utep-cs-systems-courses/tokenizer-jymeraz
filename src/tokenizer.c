#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero if c is a whitespace character
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  return ((c == '\t' || c == ' ') && c != '\0') ? 1 : 0;
}

/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c)
{
  return (c != '\t' && c != ' ' && c != '\0') ? 1 : 0;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str. Return a zero pointer if
   str does not contain any words. */
char *word_start(char *str)
{
  while(space_char(*str++));

  if(*str == '\0') {
    char *p = NULL;
    return p;
  }
  str--;
  return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  while(non_space_char(*word++));
  word--;
  return word;
}

/* Counts the number of words in the string argument */
int count_words(char *str)
{
  int count = 0;
  str = word_start(str);
  while (str && *str) {
    count++;
    str = word_terminator(str);
    str = word_start(str);
  }
  return count;
}

/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *copy = (char *) malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len && inStr[i] != '\0'; i++) {
    copy[i] = inStr[i];
  }
  copy[i] = '\0';
  return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
      tokens[0] = "hello"
      tokens[1] = "world"
      tokens[2] = "string"
      tokens[3] = 0 
   
   First, find the number of words and allocate space for it.
   Second, for each word, find the number of letters and allocate space for it.
   copy this word.
*/
char **tokenize(char* str)
{
  int num_words = count_words(str);
  char **p = (char **) malloc((num_words + 1) * sizeof(char));

  int i;
  for(i = 0; i < num_words; i++) {
    str = word_start(str);
    p[i] = copy_str(str, word_terminator(str) - str);
    str = word_terminator(str);
  }
  p[i] = copy_str('\0', 0);
  return p;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  while (**tokens != '\0') {
    printf("%s\n", *tokens);
    tokens++;
  }
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens)
{
  int i = 0;
  while (*tokens[i] != '\0') {
    free(tokens[i]);
    i++;
  }
  free(tokens);
} 

