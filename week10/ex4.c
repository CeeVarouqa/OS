//This code is incomplete

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct dirent *dp;
    struct stat *stt;
    
    DIR * directory = opendir("tmp");
    while ((dp = readdir(directory))!= NULL)
    {
        stt = malloc(sizeof(struct stat));
        char* path = calloc(1024, sizeof(char));
        strcpy(path,"tmp/");
        strcpy(path+4, dp->d_name);
        stat(path, stt)
    }
}