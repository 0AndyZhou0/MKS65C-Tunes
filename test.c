#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "library.h"

int main(){
  srand(time(0));
  struct song_node *library[27];
  make_library(library);

  //Random songs you don't know
  add_song(library,"YUC'E","Future Candy");
  add_song(library,"succducc", "me & u");
  add_song(library,"Camellia", "Exit This Earth's Atmosphere");
  add_song(library,"Igorrr & Ruby My Dear", "Maigre");
  add_song(library,"YUC'E", "Future Cake");

  //Random letters for songs
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

  //Remove examples
  /*
  remove_song(library,"'A","E");
  remove_song(library,"B","E");
  remove_song(library,"YUC'E", "Future Cake");
  remove_song(library,"Z","E");
  print_library(library);
  */

  //print individual letters
  /*
  print_letter(library,"a");
  print_letter(library,"b");
  print_letter(library,"c");
  print_letter(library,"y");
  print_letter(library,"z");
  print_letter(library,"'");
  print_letter(library,"65huhu");
  */

  //Print artists
  /*
  print_artist(library,"YUC'E");
  print_artist(library,"Camellia");
  print_artist(library,"Z");
  print_artist(library,"Jones");
  */

  //Print random lists
  print_shuffle(library);

  //struct song_node *song = find_song(library,"YUC'E","Future Candy");
  //printf("%s - %s\n", song -> artist, song -> song);
  free_library(library);
  return 0;
}
