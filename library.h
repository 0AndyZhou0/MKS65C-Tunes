#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

struct song_node *library[27];

struct song_node **make_library(){
    for(int i = 0;i < 27;i++){
    library[i] = make_list(0, 0);
  }
  return library;
}

struct song_node **add_song(char *artist, char *song){
  int i = 0;
  while(i < 26){
    if(!strncmp((char *)i + 65,song,1)){
      library[i] = insert_ordered(library[i],artist,song);
      i = 100;
    }
  }
  if(i == 26){
    library[i] = insert_ordered(library[26],artist,song);
  }
  return library;
}
