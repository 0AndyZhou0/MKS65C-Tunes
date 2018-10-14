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
    printf(", \n%s - %s", current -> artist, current -> song);
  }
  printf("]\n");
}

//Add alphabetical sorting
struct song_node *insert_front(struct song_node *head, char *artist, char *song){
  struct song_node * new = malloc(sizeof(struct song_node));
  strcpy(new -> artist, head -> artist);
  strcpy(new -> song, head -> song);
  new -> next = head -> next;
  strcpy(head -> artist, artist);
  strcpy(head -> song, song);
  head -> next = new;
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

struct song_node *free_list(struct song_node *node){
  if(node -> next){
    free_list(node -> next);
    free(node -> next);
  }
  return node;
}
