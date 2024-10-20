#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> 
#include <dirent.h>
#include <string.h>



int main (int argc, char *argv[]) {

    int check;
    char fullpath[256];

    const char *username = getenv("USER");
    snprintf(fullpath, sizeof(fullpath), "/home/%s/.config/%s", username, argv[2]);


    if (argc > 1) { 
        if (strcmp(argv[1], "init") == 0 && argc == 3){
            check = mkdir(fullpath, 0777); 
            if (check == 0) {
            printf("Directory created\n");
            } else {
                perror("Unable to create directory");
                exit(1);
            }

        } else {
            printf("To create folder type 'init'\n");
        }

    }  else {
        printf("Too few arguments \n");
    }

    return 0;
}
