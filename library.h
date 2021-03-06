#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"

//struct song_node *library[27];
char *alphabet[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

void add_song(struct song_node **library, char *artist, char *song){
  int i = 0;
  while(i < 26){
    if(!strncasecmp(alphabet[i],artist,1)){
      if(library[i] -> artist[0] != 0){
        library[i] = insert_ordered(library[i],artist,song);
      }else{
        free_list(library[i]);
        free(library[i]);
        library[i] = make_list(artist, song);
      }
      i = 100;
    }
    i++;
  }
  if(i == 26){
    if(library[26] -> artist[0] != 0){
      library[26] = insert_ordered(library[26],artist,song);
    }else{
      free(library[26]);
      library[26] = make_list(artist, song);
    }
  }
}

void remove_song(struct song_node **library, char *artist, char *song){
  int i = 0;
  while(i < 26){
    if(!strncasecmp(alphabet[i],artist,1)){
      library[i] = remove_artist_song(library[i], artist, song);
      i = 100;
    }
    i++;
  }
  if(i == 26){
    library[26] = remove_artist_song(library[26], artist, song);
  }
}

struct song_node *find_song(struct song_node **library, char *artist, char *song){
  int i = 0;
  while(i < 26){
    if(!strncasecmp(alphabet[i],artist,1)){
      return find_artist_song(library[i],artist,song);
    }
    i++;
  }
  if(i == 26){
    return find_artist_song(library[26],artist,song);
  }
  return 0;
}

void make_library(struct song_node **library){
  for(int i = 0;i < 27;i++){
    library[i] = malloc(sizeof(struct song_node));
  }
}

void clear_library(struct song_node **library){
  for(int i = 0;i < 27;i++){
    library[i] = free_list(library[i]);
    free(library[i]);
  }
  make_library(library);
}

void free_library(struct song_node **library){
  for(int i = 0;i < 27;i++){
    library[i] = free_list(library[i]);
    free(library[i]);
  }
}

void print_library(struct song_node **library){
  for(int i = 0;i < 26;i++){
    printf("%c\n", (char) i + 65);
    print_list(library[i]);
  }
  printf("%c\n", '~');
  print_list(library[26]);
}

void print_letter(struct song_node **library, char *letter){
  int i = 0;
  for(;i<26;i++){
    if(!strncasecmp(alphabet[i],letter,1)){
      printf("%c\n", (char) i + 65);
      print_list(library[i]);
      i = 100;
    }
  }
  if(i == 26){
    printf("%c\n", '~');
    print_list(library[i]);
  }
}

void print_artist(struct song_node **library, char *artist){
  int i = 0;
  while(i < 26){
    if(!strncasecmp(alphabet[i],artist,1)){
       struct song_node *current = find_artist(library[i],artist);
       printf("[");
       while(current && !strcasecmp(current -> artist,artist)){
         printf("%s - %s, ", current -> artist, current -> song);
         current = current-> next;
       }
       printf("]\n");
       i = 100;
    }
    i++;
  }
  if(i == 26){
    struct song_node *current = find_artist(library[i],artist);
    printf("[");
    while(current && !strcasecmp(current -> artist,artist)){
      printf("%s - %s, ", current -> artist, current -> song);
      current = current-> next;
    }
    printf("]\n");
  }
}

void print_shuffle(struct song_node **library){
  struct song_node *current;
  for(int i = 0;i < 20;){
    current = random_song(library[rand() % 27]);
    if(current != 0 && current -> artist[0] != 0){
      if(i == 0){
        printf("[%s - %s", current -> artist, current -> song);
        i++;
      }else{
        printf(", \n%s - %s", current -> artist, current -> song);
        i++;
      }
    }
  }
  printf("]\n");
}
