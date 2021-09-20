#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

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
  // FIXME: HOW TO RETURN A ZERO POINTER?????
  return str;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  while(non_space_char(*word++));
  if(*word == '\0') {
    return word;
  }
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
  char *copy;
  copy = (char *) malloc(len+1);
  int i = 0;
  for (i = 0; i < len && (copy[i] = inStr[i]) != '\0'; i++); 
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
  char **p;
  p = (char *) malloc(num_words + 1(char *));

  for(int i = 0; i < num_words; i++) {
    // measure word
    str = word_start(str);
    // COMPUTE SIZE
    //
    int word_length = 5;
    // copy the word
    //p[i] = malloc(word_length +1);
    p[i] = copy_str(str, word_length);
    str = word_terminator(str);
  }
  printf("%d\n", num_words);
  for(int l = 0; l < num_words; l++) {
    printf("%s\n", p[l]);
  }
  return p;
}

void print_tokens(char **tokens)
{
}

void free_tokens(char **tokens)
{
} 

