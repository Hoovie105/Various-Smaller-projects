#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int usr_interrupt = 0;


void signalHandler(int sigNum) {
    signal(SIGUSR1, signalHandler);
    usr_interrupt = 1;
}

void child1(const char *name,
            const char *fifoPathname) {
 
    srand(getpid() * time(NULL));

    int fifoFd;
    char fifoData;


    int dice;
    int points = 0;


    while(1) {
      
        fifoFd = open(fifoPathname, O_RDONLY);
        read(fifoFd, &fifoData, 1);
        close(fifoFd);

      
        printf("%s: playing my dice\n", name);
        dice = rand() % 10 + 1;
        printf("%s: got %d dice\n", name, dice);
        points += dice;
        printf("%s: Total so far %d\n\n", name, points);

        if(points >= 50) {
            printf("%s: game over I won\n", name);
            kill(0, SIGTERM);
        }

      
        sleep(5); 
        fifoFd = open(fifoPathname, O_WRONLY);
        write(fifoFd, &fifoData, 1);
        close(fifoFd);
    }
}

void child2(const char *name,
            int pipeChildReadFd[2],
            int pipeChildWriteFd[2]) {
   
    srand(getpid() * time(NULL));

    
    char pipeData;
    close(pipeChildReadFd[1]);
    close(pipeChildWriteFd[0]);

  
    int dice;
    int points = 0;

    
    while(1) {
        
        read(pipeChildReadFd[0],
             &pipeData,
             1);

       
        printf("%s: playing my dice\n", name);
        dice = rand() % 10 + 1;
        printf("%s: got %d dice\n", name, dice);
        points += dice;
        printf("%s: Total so far %d\n\n", name, points);

        if(points >= 50) {
            printf("%s: game over I won\n", name);
            kill(0, SIGTERM);
        }

        
        sleep(5);
        write(pipeChildWriteFd[1],
              &pipeData,
              1);
    }
}

void child3(const char *name) {
    srand(getpid() * time(NULL));

    signal(SIGUSR1, signalHandler);

    int dice;
    int points = 0;

    while(1) {
        
        while(!usr_interrupt);
        usr_interrupt = 0;

       
        printf("%s: playing my dice\n", name);
        dice = rand() % 10 + 1;
        printf("%s: got %d dice\n", name, dice);
        points += dice;
        printf("%s: Total so far %d\n\n", name, points);

        if(points >= 50) {
            printf("%s: game over I won\n", name);
            kill(0, SIGTERM);
        }

        sleep(5);
        kill(getppid(), SIGUSR1);
    }
}

int main() {
    printf("This is a 3-player game with a referee\n");

   
    const char *fifoPathname = "fifo";
    int fifoFd;
    mode_t fifoMode = 0666;
    char fifoData;
    mkfifo(fifoPathname, fifoMode);

    int pipeParentReadFd[2];
    int pipeParentWriteFd[2];
    char pipeData;
    pipe(pipeParentReadFd);
    pipe(pipeParentWriteFd);

  
    signal(SIGUSR1, signalHandler);

    
    pid_t pidChild1;
    pid_t pidChild2;
    pid_t pidChild3;

    pidChild1 = fork();
    if(!pidChild1)
        child1("Child1",
               fifoPathname);

    pidChild2 = fork();
    if(!pidChild2)
        child2("Child2",
               pipeParentWriteFd,
               pipeParentReadFd);

    pidChild3 = fork();
    if(!pidChild3)
        child3("Child3");

   
    close(pipeParentReadFd[1]);
    close(pipeParentWriteFd[0]);

  
    while(1) {
    
        printf("\nReferee: Child1 plays\n\n");
        fifoFd = open(fifoPathname, O_WRONLY);
        write(fifoFd, &fifoData, 1);
        close(fifoFd);

        
        fifoFd = open(fifoPathname, O_RDONLY);
        read(fifoFd, &fifoData, 1);
        close(fifoFd);

      
        printf("\nReferee: Child2 plays\n\n");
        write(pipeParentWriteFd[1],
              &pipeData,
              1);

        read(pipeParentReadFd[0],
             &pipeData,
             1);

    
        printf("\nReferee: Child3 plays\n\n");
        kill(pidChild3, SIGUSR1);

       
        while(!usr_interrupt);
        usr_interrupt = 0;
    }

    return 0;
}
