#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "unistd.h"

int main(int argc, char * argv[]){
    int fd;
    fd  = open("./text.txt", O_WRONLY);
    if(fd==-1){
        fprintf(stderr,"file open failed\n");
        exit(1);
    }
    int rc = fork();
    if(rc < 0){
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc == 0){
        if(write(fd, "from child\n",11)==-1){
            fprintf(stderr,"file write failed\n");
        }
    }else{
        if(write(fd, "from parent\n",12)==-1){
            fprintf(stderr,"file write failed\n");
        }
    }

    close(fd);
    return 0;
}