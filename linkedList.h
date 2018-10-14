#include <stdio.h>
#include <stdlib.h>

struct song_node {
  char name[100];
  char artist[100];
  struct node *next;
};

void print_list(struct node *current){
  printf("[%s - %s", current -> artist, surrent -> name);
  while(current = current -> next){
    printf(", %s - %s", current -> artist, surrent -> name);
  }
  printf("]\n");
}

//Add alphabetical sorting
struct node *insert_front(struct node *head, char *name, char *artist){
  struct node * new = malloc(sizeof(struct node));
  new -> next = head -> next;
  new -> name = head -> name;
  new -> artist = head -> artist;
  head -> next = new;
  head -> name = name;
  head -> artist = artist;
  return head;
}

char *find_artist(struct node *head, char *artist){
  while(head){
    if(head -> artist == artist){
      return head -> song;
    }
    head = head -> next
  }
  return 0;
}

struct node *free_list(struct node *node){
  if(node -> next){
    free_list(node -> next);
    free(node -> next);
  }
  return node;
}
