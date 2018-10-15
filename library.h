#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

struct song_node *library[27];

struct song_node **make_library(){
  for(int i = 0;i < 27;i++){
    library[i] = malloc(sizeof(struct song_node));
  }
  return library;
}

struct song_node *add_song(char *artist, char *library){

}
