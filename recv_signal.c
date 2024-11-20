/**
 * File: recv_signal.c
 * Modified by: Anish Kusukuntla
 * Lab 10: Signals
 * Brief summary of program:
 * I needed to declare the variable for sigaction and then assign it
 * some info to the sa_flags, register handle_signal to sigaction. I also
 * needed to empty the set for initializing the sigaction after registering. 
 * I this time used sigaction to allow the user to use the kill command 
 * on the PID for retrieving the sival_int value from the user and then 
 * printing out the value from the PID. 
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
//handle_signal would tell that sigaction is occuring and the value of
//sival int would be printed.
void handle_signal(int signum, siginfo_t *info, void *context) {
    (void)(context);
    int val = info -> si_value.sival_int;
    printf("SIGACTION is occuring. %d\n", val);
}
int main(int argc, char* argv[]){
    //Initializes action as a sigaction
    struct sigaction action; 

    //Would assign the info to the flags and register the handle_signal to sigaction
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = handle_signal;
    sigemptyset(&action.sa_mask);
    if(sigaction(SIGUSR1, &action, NULL) == -1){
        perror("Trouble with SIGACTION");
        return -1;
    }
    printf("Waiting for the user signals... (PID: %d)\n", getpid());
    while(1){
        sleep(1);
    }
    return 0;
}