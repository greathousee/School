#include <stdio.h>
#include <stdlib.h>

#include "square.h"

char IGNORE[] = {'.', ' ', ',', 0x27, ':'}; 

FILE *open_message_file () {
  return fopen("SEKRETS.txt", "r");
}

void close_message_file(FILE *fp) {
  if (fp != NULL) {
    fclose(fp);
  }
}

int get_number_of_messages () {
  FILE *fp;
  int line_count;
  
  fp = open_message_file();
  line_count = 0;
  
  while (!feof(fp)) {
    int c = getc(fp);
    if (c == '\n') {
      line_count++;
    }
  }
  
  close_message_file(fp);
  return line_count;
}

FILE *advance_to_msg (int msg_ndx) {
  FILE *fp;
  int line_count;
  
  fp = open_message_file();
  line_count = 0;
  
  while (!feof(fp) && line_count < msg_ndx) {
    int c = getc(fp);
    if (c == '\n') {
      line_count++;
    }
  }
  
  return fp;
}

int get_message_length (int msg_ndx) {
  FILE *fp;
  int length = 0;
  char c;
  
  fp = advance_to_msg (msg_ndx);
  
  while((c = getc(fp)) != '\n') {
    int OK = 1;
    for (int i = 0; i < sizeof(IGNORE); i++) {
      if (c == IGNORE[i]) {
        OK = 0;
      }
    }
    if (OK) {
      length++;
    }
  }
  
  close_message_file(fp);
  return length;
}

char *read_message (int msg_ndx) {
  FILE *fp;
  char *msg;
  int ndx;
  int length;
  char c;
  
  ndx = 0;
  length = get_message_length(msg_ndx);
  fp = advance_to_msg(msg_ndx);
  
  msg = (char*) malloc(length * sizeof(char));
  
  while((c = getc(fp)) != '\n') {
    int OK = 1;
   
    for (int i = 0; i < sizeof(IGNORE); i++) {
      /* printf("CHECKING %c vs %c\n", c, IGNORE[i]); */
      if (c == IGNORE[i]) {
        OK = 0;
      }
    }
    
    if (OK) {
      msg[ndx] = c;
      ndx += 1;
    }
  }
 
  close_message_file(fp);
  
  return msg;
}
