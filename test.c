#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
  struct song_node this_is_library;
  this_is_library.next = 0;
  strcpy(this_is_library.artist, "YUC'E");
  strcpy(this_is_library.song, "Future Candy");
  print_list(&this_is_library);
  return 0;
}
