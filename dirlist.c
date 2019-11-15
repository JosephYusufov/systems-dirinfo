#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main(){
    DIR * this_dir;
    this_dir = opendir(".");
    struct dirent *files = readdir(this_dir);
    int index = 0;
    while(file != NULL){
        printf("%s\n", file->d_name);
        *(files + index) = readdir(this_dir);
        index++;
    }
    return 0;
}
