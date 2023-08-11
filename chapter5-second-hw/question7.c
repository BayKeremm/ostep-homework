#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "sys/wait.h"
#include "errno.h"

void child_process(){
    close(STDOUT_FILENO);
    printf("some output\n");
    printf("%s\n", strerror(errno));
    exit(0);
}

void parent_process(){
    exit(0);
}

int main(int argc, char * argv[]){
    int rc = fork();
    if(rc < 0){
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc == 0){
        child_process();
    }else{
        parent_process();
    }

    return 0;
}