#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

int main(){
  struct song_node *library[27];
  make_library(library);
  add_song(library,"YUC'E","Future Candy");
  add_song(library,"succducc", "me & u");
  add_song(library,"Camellia", "Exit This Earth's Atmosphere");
  add_song(library,"Igorrr & Ruby My Dear", "Maigre");
  add_song(library,"YUC'E", "Future Cake");
  
  add_song(library,"Z", "E");
  add_song(library,"A", "E");
  add_song(library,"J", "E");
  add_song(library,"Z", "A");
  add_song(library,"Z", "Z");
  add_song(library,"'Z'", "E");
  add_song(library,"'A", "E");
  add_song(library,"'J", "E");
  add_song(library,"'Z", "A");
  add_song(library,"'Z", "Z");

  //print_library(library);
  remove_song(library,"'A","E");
  remove_song(library,"YUC'E", "Future Cake");
  remove_song(library,"Z","E");
  print_library(library);
  //struct song_node *song = find_song(library,"YUC'E","Future Candy");
  //printf("%s - %s\n", song -> artist, song -> song);
  free_library(library);
  return 0;
}
