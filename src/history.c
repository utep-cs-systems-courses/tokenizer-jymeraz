#include <stdlib.h>
#include <stdio.h>
#include  "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history */
List* init_history()
{
  struct s_List *list = (struct s_List *) malloc(sizeof(struct s_List));
  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  struct s_Item *item = (struct s_Item *) malloc(sizeof(struct s_Item));

  char *char_temp = str;
  while (*char_temp != '\0') {
    char_temp++;
  }
  int len = char_temp - str;
  char *new_str = copy_str(str, len);

  item->str = new_str;
  struct s_Item *temp = list->root;
  if (temp == NULL) {
    item->id = 1;
    list->root = item;
  }
  else {
    while (temp->next != NULL) {
      temp = temp->next;
    }
    item->id = temp->id + 1;
    temp->next = item;
  }
}

/* Retrieve the string stored in the node where Item->id == id
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  struct s_Item *temp = list->root;
  int count = 1;
  while (temp) {
    if (count == id) {
      return temp->str;
    }
    temp = temp->next;
    count++;
  }
  return "Index out of bounds, try again!";
}

/* Print the entire contents of the list */
void print_history(List *list)
{
  struct s_Item *temp = list->root;
  while (temp) {
    printf("H[%d]: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

/* Free the history list and the strings it references */
void free_history(List *list)
{
  struct s_Item *temp = list->root;
  struct s_Item *temp_next;
  while (temp) {
    temp_next = temp->next;
    free(temp);
    temp = temp_next;
  }
  free(list);
}
