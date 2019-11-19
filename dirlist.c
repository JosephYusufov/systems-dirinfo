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
  char *path = ".";
  if(argc > 1){
    path = argv[1];
  }

  printf("**********\n");
  printf("Joseph Yusufov dirinfo Assignment\nDirectory: \"%s\"\nDue: 2019-11-19\n", path);
  printf(ANSI_COLOR_GREEN "NOTE: " ANSI_COLOR_RESET "Pass a path as an argument to view the info of that directory\n");
  printf("**********\n");
  DIR * this_dir;
  this_dir = opendir(path);
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
