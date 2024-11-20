/**
 * File: send_signal.c
 * Modified by: Anish Kusukuntla
 * Lab 10: Signals
 * Brief summary of program:
 * I needed to make sure the user formats the command line correctly with 
 * argc being 2 where the first word would be the executable and the second word
 * would be the PID. I needed to set the time as random and then get random value
 * from the program. I needed to research sigqueue on the parameters it needed. 
 * I needed to declare a union sigval and then assign the random value to it. 
 * I used sigqueue just so that I was able to include the PID, SIGUSR1, and 
 * random value for the output PID to be recieved and then print out. 
 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]){
    //Would make sure the user enters the correct formatted command line.
    if (argc != 2){
        fprintf(stderr, "Incorrect command: %s\n", argv[0]);
        return 1;
    }
    pid_t pid = atoi(argv[1]);
    //Has the random time as NULL
    srand(time(NULL)); 
    //Generates a random integer stored in val
    int val = rand() % 100;

    printf("SIGUSR1 is being sent to PID %d with value of %d\n", pid, val);

    union sigval sig;
    sig.sival_int = val;
    //Registers the signal by using sigqueue
    if(sigqueue(pid, SIGUSR1, sig) == -1){
        perror("Error with the signal");
        return 1;
    }
    //Prints out the output process identification
    printf("The PID is %d\n", getpid());
    return 0;
}
