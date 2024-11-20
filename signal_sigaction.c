/**
 * File: signal_sigaction.c
 * Modified by: Anish Kusukuntla
 * Lab 10: Signals
 * Brief summary of program:
 * I needed to research the struct for sigaction. 
 * I needed to declare the variable for sigaction and then assign it
 * some info to the sa_flags, register handle_signal to sigaction. I also
 * needed to empty the set for initializing the sigaction after registering. 
 * I used sigaction to allow the user to use the kill command on the PID
 * and then print out the process identification. 
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
//handle_signal would print out that sigaction is occuring and what the process identification is
void handle_signal(int signum, siginfo_t *info, void *context) {
    (void)(context);
    printf("SIGACTION is occuring. The process identification is %d\n", info -> si_pid);
}
int main(int argc, char* argv[]){
    //Initializes action as a sigaction
    struct sigaction action; 
    //Would assign the info to the flags and register the handle_signal to sigaction
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = handle_signal; 
    sigemptyset(&action.sa_mask);
    if(sigaction(SIGUSR1, &action, NULL) == -1){
        perror("Trouble with sigaction");
        return -1;
    }
     //Prints out the output PID after sigaction is registered or sent by the user.
    printf("Waiting for SIGUSR1 signals... (PID: %d)\n", getpid());
    while(1) {
        sleep(1);
    }

    return 0;
    

}
