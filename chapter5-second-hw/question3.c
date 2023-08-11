#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"

void child_process(int pipe_fd[]){
    close(pipe_fd[0]); // close the read end of the pipe, 
                       // since we are not reading anything
    write(pipe_fd[1], "hello", strlen("hello"));
    close(pipe_fd[1]);
    exit(0);

}

void parent_process(int pipe_fd[]){
    close(pipe_fd[1]); // close write, we read
    char buffer[6]; // hello (5) + \0 = 6 bytes
    read(pipe_fd[0], buffer, sizeof(buffer));
    close(pipe_fd[0]);
    printf("%s\n",buffer);
    printf("goodbye\n");
    exit(0);

}

int main(int argc, char * argv[]){
    int pipe_fd[2];
    if(pipe(pipe_fd)==-2){
        fprintf(stderr,"pipe creation error");
        exit(1);
    }
    int rc = fork();
    if(rc < 0){
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc == 0){
        child_process(pipe_fd);
    }else{
        parent_process(pipe_fd);
    }

    return 0;
}