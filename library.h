#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

//struct song_node *library[27];

void print_library(struct song_node *library[27]){
  for(int i = 0;i < 27;i++){
    printf("%c\n", (char) i + 65);
    print_list(library[i]);
  }
}

void make_library(struct song_node *library[27]){
  for(int i = 0;i < 27;i++){
    library[i] = make_list(0,0);
  }
}

void add_song(struct song_node *library[27], char *artist, char *song){
  int i = 0;
  while(i < 26){
    if(strncmp((char *)i + 65,song,1)){
      if(library[i] -> song != 0){
        library[i] = insert_ordered(library[i],artist,song);
      }else{
        library[i] = free_list(library[i]);
        library[i] = make_list(artist, song);
      }
      //i = 100;
    }
    i++;
  }
  //if(i == 26){
    //library[i] = insert_ordered(library[26],artist,song);
  //}
}
