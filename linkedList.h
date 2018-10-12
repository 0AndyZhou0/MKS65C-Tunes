#include <stdio.h>
#include <stdlib.h>

struct node {
  char name[100];
  char artist[100];
  struct node *next;
};

void print_list(struct node *current){
  printf("[%d", current -> i);
  while(current = current -> next){
    printf(", %d", current -> i);
  }
  printf("]\n");
}

//Add alphabetical sorting
struct node * insert_front(struct node *head, char *name, char *artist){
  struct node * new = malloc(sizeof(struct node));
  new -> next = head -> next;
  new -> name = head -> name;
  new -> artist = head -> artist;
  head -> next = new;
  head -> name = name;
  head -> artist = artist;
  return head;
}

struct node * free_list(struct node *node){
  if(node -> next){
    free_list(node -> next);
    free(node -> next);
  }
  return node;
}
