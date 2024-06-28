#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<dirent.h>

int main(int argc, char **argv){
    DIR * dirp;
    struct dirent *dptr;
    printf("\n DIRECTERY CONTENTS");
    dirp=opendir(".");
    if(dirp==NULL){
        printf("\nDIRECTORY DOESNT EXIST");
        exit(0);
    }
    while((dptr=readdir(dirp))!=NULL){
        printf("%s\n",dptr->d_name);
        //printf("%ld\n",dptr->d_ino);
    }
    closedir(dirp);
    return 0;
}