#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node{
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

struct song_node *make_list(char *artist, char *song){
  struct song_node *library = malloc(sizeof(struct song_node));
  library -> next = 0;
  strcpy(library -> artist, artist);
  strcpy(library -> song, song);
  return library;
}

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

struct song_node *insert_ordered(struct song_node *head, char *artist, char *song){
  struct song_node *temp = head;
  while(temp && strcasecmp(temp -> artist, artist) < 0){
    temp = temp -> next;
  }
  if(temp && strcasecmp(temp -> artist, artist) == 0){
    while(temp && strcasecmp(temp -> song, song) < 0){
      temp = temp -> next;
    }
  }
  if(!temp){
    temp = head;
    while(temp -> next){
      temp = temp -> next;
    }
    struct song_node * new = malloc(sizeof(struct song_node));
    strcpy(new -> artist, artist);
    strcpy(new -> song, song);
    new -> next = 0;
    temp -> next = new;
  }else{
    temp = insert_front(temp, artist, song);
  }
  return head;
}

struct song_node *find_artist_song(struct song_node *head, char *artist, char *song){
  while(head){
    if(!strcasecmp(head -> artist, artist) && !strcasecmp(head -> song, song)){
      return head;
    }
    head = head -> next;
  }
  return 0;
}

struct song_node *find_artist(struct song_node *head, char *artist){
  while(head){
    if(!strcasecmp(head -> artist, artist)){
      return head;
    }
    head = head -> next;
  }
  return 0;
}

struct song_node *remove_artist_song(struct song_node *head, char *artist, char *song){
  struct song_node *temp = head;
  if(!strcmp(head -> artist, artist) && !strcmp(head -> song, song)){
    head = head -> next;
    free(temp);
    return head;
  }
  temp = temp -> next;
  struct song_node *temp2 = head;
  struct song_node *next_song;
  while(temp && (strcmp(temp -> artist, artist) || strcmp(temp -> song, song))){
    if(!strcmp(temp -> artist, artist) && !strcmp(temp -> song, song)){
      next_song = temp -> next;
    }else{
      temp2 = temp;
      temp = temp -> next;
    }
  }
  if(temp2 -> next != 0){
    free(temp2 -> next);
    temp2 -> next = next_song;
  }
  return head;
}

struct song_node *random_song(struct song_node *node){
  srand(time(NULL));
  struct song_node *temp = node;
  int i = 0;
  while(temp){
    temp = temp -> next;
    i++;
  }
  temp = node;
  int r = rand() % (i-1);
  for(;r > 0;r--){
    temp = temp -> next;
  }
  return temp;
}

struct song_node *free_list(struct song_node *node){
  if(node -> next){
    free_list(node -> next);
    free(node -> next);
  }
  return node;
}
