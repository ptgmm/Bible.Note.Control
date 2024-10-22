#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> 
#include <dirent.h>
#include <string.h>



int main (int argc, char *argv[]) {

    int check;
    int config;
    char fullpath[256];
    char folderCheck[256];

    const char *username = getenv("USER"); //Getting user name
    snprintf(fullpath, sizeof(fullpath), "/home/%s/.config/%s", username, argv[2]); //create full path to .config
    snprintf(folderCheck, sizeof(folderCheck), "/home/%s/.config/", username); //path to .config

    struct stat statbuf;
    if (stat(folderCheck, &statbuf) != 0) {         //Check if .config exist
        config = mkdir(folderCheck, 0777);          //If .config doesn't exist it will be created
    } else if (stat(folderCheck, &statbuf) == 0 && argc > 1) {      //Basically checking if the user entered "init" and folder name 
        if (strcmp(argv[1], "init") == 0 && argc == 3){             //
            check = mkdir(fullpath, 0777);                          // 
            if (check == 0) {                                       //
            printf("Directory created\n");                          //
            } else {                                                //
                perror("Unable to create directory");               //
                exit(1);                                            //
            }                                                       //

        } else {
            printf("To create folder type 'init'\n");
        }

    }  else {
        printf("Too few arguments \n");
    }

    return 0;
}
