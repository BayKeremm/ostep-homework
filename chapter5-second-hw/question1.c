#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int main(int argc, char * argv[]){
    int x = 0;
    x = 100;
    int rc = fork();
    if(rc < 0){
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc == 0){
        x = 5;
        printf("The value of x in child: %d\n",x);
    }else{
        x = 4;
        printf("The value of x parent: %d\n",x);
    }

    return 0;
}