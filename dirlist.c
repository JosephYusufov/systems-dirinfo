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
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(int argc, char *argv[]){

  // Default path is this directory, otherwise user can provide a path as a command line argument
  char *path = ".";
  if(argc > 1){
    path = argv[1];
  }

  // Print assignment header
  printf("**********\n");
  printf("Joseph Yusufov dirinfo Assignment\nDirectory: \"%s\"\nDue: 2019-11-19\n", path);
  printf(ANSI_COLOR_GREEN "NOTE: " ANSI_COLOR_RESET "Pass a path as an argument to view the info of that directory\n");
  printf("(e.g: $ ./dirinfo ~)\n");
  printf("**********\n");
  DIR * this_dir = NULL;
  this_dir = opendir(path);

  // If opendir fails, return the proper error msg.
  if(this_dir == NULL){
    printf("%s: %s: \"%s\"\n", argv[0], strerror(errno), argv[1]);
    return 0;
  }

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
