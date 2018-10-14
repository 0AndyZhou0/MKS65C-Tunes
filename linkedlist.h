#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node {
  char song[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *current){
  printf("[%s - %s", current -> artist, current -> song);
  while(current = current -> next){
    printf(", %s - %s", current -> artist, current -> song);
  }
  printf("]\n");
}

//Add alphabetical sorting
struct song_node *insert_front(struct song_node *head, char *song, char *artist){
  struct song_node * new = malloc(sizeof(struct song_node));
  new -> next = head -> next;
  strcpy(new -> song, head -> song);
  strcpy(new -> artist, head -> artist);
  head -> next = new;
  strcpy(head -> song, song);
  strcpy(head -> artist, artist);
  return head;
}

char *find_artist(struct song_node *head, char *artist){
  while(head){
    if(head -> artist == artist){
      return head -> song;
    }
    head = head -> next;
  }
  return 0;
}

struct node *free_list(struct song_node *node){
  if(node -> next){
    free_list(node -> next);
    free(node -> next);
  }
  return node;
}
