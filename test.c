#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
  struct song_node library;
  library.next = 0;
  strcpy(library.artist, "YUC'E");
  strcpy(library.song, "Future Candy");
  print_list(&library);
  library = *insert_front(&library, "succducc", "me & u");
  print_list(&library);
  library = *insert_front(&library, "Igorrr & Ruby My Dear", "Maigre");
  print_list(&library);
  return 0;
}
