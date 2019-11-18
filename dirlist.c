#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(){
  printf("**********\n");
  printf("Joseph Yusufov\n\nThis Directory\n\nDue: 2019-11-18\n");
  printf("**********\n");
  DIR * this_dir;
  this_dir = opendir(".");
  struct dirent *files = readdir(this_dir);
  for(;files!= NULL; files = readdir(this_dir)){

    // Make a buffer to hold stat info
    struct stat statbuff;
    if(files->d_type == 4){
      // Print size, and whether or not is dir
      stat(files->d_name, &statbuff);
      printf("d-\t%lld", statbuff.st_size);
      printf(ANSI_COLOR_CYAN); 
      printf("\t%s/\n", files->d_name);
      printf(ANSI_COLOR_RESET);
    } else {
      stat(files->d_name, &statbuff);
      printf("--\t%lld", statbuff.st_size); 
      printf("\t%s\n", files->d_name);
    }
  }
  return 0;
}
