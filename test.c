#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

int main(){
  struct song_node library;
  library = *make_list("YUC'E","Future Candy");
  //print_list(&library);
  //printf("\n");
  library = *insert_ordered(&library, "succducc", "me & u");
  //print_list(&library);
  //printf("\n");
  library = *insert_ordered(&library, "Camellia", "Exit This Earth's Atmosphere");
  //print_list(&library);
  //printf("\n");
  library = *insert_ordered(&library, "Igorrr & Ruby My Dear", "Maigre");
  //print_list(&library);
  //printf("\n");
  library = *insert_ordered(&library, "YUC'E", "Future Cake");
  //print_list(&library);
  //printf("\n");
  library = *insert_ordered(&library, "Z", "E");
  library = *insert_ordered(&library, "A", "E");
  library = *insert_ordered(&library, "J", "E");
  print_list(&library);
  return 0;
}
